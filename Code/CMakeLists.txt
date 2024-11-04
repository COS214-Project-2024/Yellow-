cmake_minimum_required(VERSION 3.28)
project(Code)

set(CMAKE_CXX_STANDARD 26)

file(GLOB SOURCES
        *.h
        *.cpp
)

add_executable(ClionProject ${SOURCE_FILES} ${SOURCES})
