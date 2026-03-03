#################################################################################
# NOTE:
# This is a dummy file to make CLion happy when editing the engine code.
# Actual compilation happens via Makefiles / Pyrite64's build system.
#
# The (actually used) cmake file for the editor itself is in the main directory.
#
#################################################################################

cmake_minimum_required(VERSION 3.30)
project(magnet)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

include_directories(C:/msys64/pyrite64-tmp/tiny3d/src)
include_directories(C:/msys64/pyrite64-tmp/libdragon/include)
include_directories(${CMAKE_SOURCE_DIR}/engine/include)

add_executable(magnet
        src/p64/assetTable.h
        src/p64/sceneTable.h
        #src/p64/CA20630FE536B54B.cpp
        src/user/Feur.cpp
        src/p64/scriptTable.cpp
        src/p64/sceneTable.cpp
        src/p64/globalScriptTable.cpp
)