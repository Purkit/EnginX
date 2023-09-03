cmake_minimum_required(VERSION 3.14)

project(EnginX 
        VERSION 1.0.1 
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Build type not set explicitely - Defaulting to 'Release'")
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(enginx)
#add_subdirectory(Application)
#add_subdirectory(tests)