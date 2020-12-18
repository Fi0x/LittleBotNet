cmake_minimum_required(VERSION 3.19)
project(LittleBotNet C)

set(CMAKE_C_STANDARD 11)

include_directories(src/main)

add_executable(LittleBotNet
        src/main/main.c
        src/main/client/clientStorage.c
        )
