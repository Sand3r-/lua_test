#include <iostream>
#include <string>
#include <map>

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

struct Vector3f
{
    float x, y, z;
};

bool CheckLua(lua_State *L, int r)
{
	if (r != LUA_OK)
	{
		std::string errormsg = lua_tostring(L, -1);
		std::cout << errormsg << std::endl;
		return false;
	}
	return true;
}

int lua_HostFunction(lua_State *L)
{
    const char* obj_name = (const char*)lua_tostring(L, 1);
	std::cout << "Object " << obj_name << " destroyed" << std::endl;
	return 0;
}

int lua_GetPosition(lua_State* L)
{
    std::map<std::string, Vector3f> obj_positions;
    obj_positions["Box"] = {0.0f, 2.0f, 0.0f};
    obj_positions["Gate"] = {1.0f, 0.0f, -1.0f};

    const char* obj_name = (const char*)lua_tostring(L, 1);
    std::cout << "Obtaining position of " << obj_name  << std::endl;

    if (obj_positions.count(obj_name) == 0)
    {
        lua_pushstring(L, "Well, well, well. Lua failed upon"
                          "requesting inexistant object pos");
        lua_error(L);
        return 0;
    }

    Vector3f position = obj_positions[obj_name];
    lua_pushnumber(L, position.x);
    lua_pushnumber(L, position.y);
    lua_pushnumber(L, position.z);

    return 3;
}

int lua_SpawnParticles(lua_State *L)
{
    const char* efx_name = (const char*)lua_tostring(L, 1);
    float x = (float)lua_tonumber(L, 2);
    float y = (float)lua_tonumber(L, 3);
    float z = (float)lua_tonumber(L, 4);
	std::cout << "Effect " << efx_name << " spawned at " << 
                 x << ' ' << y << ' ' << z << ' ' << std::endl;
	return 0;
}

int main()
{
    lua_State* L = luaL_newstate();

    luaL_openlibs(L);
    lua_register(L, "DestroyObject", lua_HostFunction);
    lua_register(L, "GetPosition", lua_GetPosition);
    lua_register(L, "SpawnParticleEffects", lua_SpawnParticles);
    if (CheckLua(L, luaL_dofile(L, "../test.lua")))
    {
        std::cout << "Lua executed well" << std::endl;
    }
    else
    {
        std::cout << "Lua executed not so well" << std::endl;
    }
    
    std::cout << "memory used in KB: " << lua_gc(L, LUA_GCCOUNT) << std::endl;
    lua_close(L);
    return 0;
}
