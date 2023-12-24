cmake_minimum_required(VERSION 3.10)

# Setze den Namen des Projekts und die verwendete C++-Standardversion
project(WeinAchtWichtel)
set(CMAKE_CXX_STANDARD 17)

#Compiler
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_CXX_COMPILER "clang++")

# Gib an, wo die Header-Dateien zu finden sind
include_directories(inc/WeinAchtsWichtel/)

# Gib an, welche Quelldateien für das Projekt benötigt werden
add_executable(WeinAchtWichtel main.cpp src/Spiel.cpp src/Spielstand.cpp src/Wichtel.cpp src/Spielfeld.cpp )

# Optional: Definiere Compiler-Flags
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
#x86_64-w64-mingw32-g++ dein_programm.cpp -o dein_programm.exe
