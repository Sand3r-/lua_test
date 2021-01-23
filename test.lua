local obj_name = "Gate" -- change to "xD" for error handling
local x, y, z = GetPosition(obj_name)
print("Got position of " .. obj_name .. ": " .. x .. " " .. y .. " " .. z)
DestroyObject(obj_name)
SpawnParticleEffects("Splinters", x, y, z)