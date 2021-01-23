## Description
A simple testing playground designed for interacting with lua scripts through C++.

## Building
1. Clone recursively
```
git clone --recurse-submodules git://github.com/Sand3r-/lua_test
```
2. Make a build dir and run cmake
```
mkdir build && cd build && cmake .. & cmake --build . -j
```
3. Run (from build directory)
```
./Debug/lua_test.exe
```
or
```
./Debug/lua_test
```
if on linux.