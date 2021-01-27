# cmake version
cmake_minimum_required(VERSION 3.17)
# project name
project(find_cycle)
# cpp version
set(CMAKE_CXX_STANDARD 11)

# headers directory
include_directories(src)
# third_party headers
include_directories(third_party)

file(GLOB IOGlob src/io/*.cpp)
file(GLOB AlgorithmGlob src/algorithm/*.cpp)
file(GLOB NetworkGlob src/network/*.cpp)
file(GLOB TestGlob src/test/*.cpp)
file(GLOB UtilGlob src/util/*.cpp)

add_library(IO_OBJ OBJECT ${IOGlob})
add_library(ALGORITHM_OBJ OBJECT ${AlgorithmGlob})
add_library(NETWORK_OBJ OBJECT ${NetworkGlob})
add_library(TEST_OBJ OBJECT ${TestGlob})
add_library(UTIL_GOBJ OBJECT ${UtilGlob})

# compile configuration
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

# add executable -- find_cycle
add_executable(find_cycle src/app/main.cpp
        $<TARGET_OBJECTS:IO_OBJ>
        $<TARGET_OBJECTS:ALGORITHM_OBJ>
        $<TARGET_OBJECTS:NETWORK_OBJ>
        $<TARGET_OBJECTS:TEST_OBJ>
        $<TARGET_OBJECTS:UTIL_GOBJ>)
# add executable -- generate
add_executable(generate src/app/generate.cpp
        $<TARGET_OBJECTS:IO_OBJ>
        $<TARGET_OBJECTS:NETWORK_OBJ>
        $<TARGET_OBJECTS:UTIL_GOBJ>)
# add executable -- test
add_executable(test src/app/test.cpp
        $<TARGET_OBJECTS:IO_OBJ>
        $<TARGET_OBJECTS:NETWORK_OBJ>
        $<TARGET_OBJECTS:ALGORITHM_OBJ>
        $<TARGET_OBJECTS:TEST_OBJ>
        $<TARGET_OBJECTS:UTIL_GOBJ>)