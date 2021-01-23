cmake_minimum_required (VERSION 3.14)
project (LuaTest CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(external/Lua)

set(TARGET lua_test)
add_executable(${TARGET} Main.cpp)
target_link_libraries(${TARGET} PRIVATE lua_static)
# target_include_directories(${TARGET} PRIVATE external/Lua/lua-5.4.0/include)