# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build

# Include any dependencies generated for this target.
include CMakeFiles/WeinAchtWichtel.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WeinAchtWichtel.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WeinAchtWichtel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WeinAchtWichtel.dir/flags.make

CMakeFiles/WeinAchtWichtel.dir/main.cpp.o: CMakeFiles/WeinAchtWichtel.dir/flags.make
CMakeFiles/WeinAchtWichtel.dir/main.cpp.o: ../main.cpp
CMakeFiles/WeinAchtWichtel.dir/main.cpp.o: CMakeFiles/WeinAchtWichtel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WeinAchtWichtel.dir/main.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeinAchtWichtel.dir/main.cpp.o -MF CMakeFiles/WeinAchtWichtel.dir/main.cpp.o.d -o CMakeFiles/WeinAchtWichtel.dir/main.cpp.o -c /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/main.cpp

CMakeFiles/WeinAchtWichtel.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WeinAchtWichtel.dir/main.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/main.cpp > CMakeFiles/WeinAchtWichtel.dir/main.cpp.i

CMakeFiles/WeinAchtWichtel.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WeinAchtWichtel.dir/main.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/main.cpp -o CMakeFiles/WeinAchtWichtel.dir/main.cpp.s

CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.o: CMakeFiles/WeinAchtWichtel.dir/flags.make
CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.o: ../src/Spiel.cpp
CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.o: CMakeFiles/WeinAchtWichtel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.o -MF CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.o.d -o CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.o -c /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Spiel.cpp

CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Spiel.cpp > CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.i

CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Spiel.cpp -o CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.s

CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.o: CMakeFiles/WeinAchtWichtel.dir/flags.make
CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.o: ../src/Spielstand.cpp
CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.o: CMakeFiles/WeinAchtWichtel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.o -MF CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.o.d -o CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.o -c /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Spielstand.cpp

CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Spielstand.cpp > CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.i

CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Spielstand.cpp -o CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.s

CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.o: CMakeFiles/WeinAchtWichtel.dir/flags.make
CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.o: ../src/Wichtel.cpp
CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.o: CMakeFiles/WeinAchtWichtel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.o -MF CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.o.d -o CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.o -c /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Wichtel.cpp

CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Wichtel.cpp > CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.i

CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Wichtel.cpp -o CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.s

CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.o: CMakeFiles/WeinAchtWichtel.dir/flags.make
CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.o: ../src/Spielfeld.cpp
CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.o: CMakeFiles/WeinAchtWichtel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.o -MF CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.o.d -o CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.o -c /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Spielfeld.cpp

CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Spielfeld.cpp > CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.i

CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/src/Spielfeld.cpp -o CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.s

# Object files for target WeinAchtWichtel
WeinAchtWichtel_OBJECTS = \
"CMakeFiles/WeinAchtWichtel.dir/main.cpp.o" \
"CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.o" \
"CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.o" \
"CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.o" \
"CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.o"

# External object files for target WeinAchtWichtel
WeinAchtWichtel_EXTERNAL_OBJECTS =

WeinAchtWichtel: CMakeFiles/WeinAchtWichtel.dir/main.cpp.o
WeinAchtWichtel: CMakeFiles/WeinAchtWichtel.dir/src/Spiel.cpp.o
WeinAchtWichtel: CMakeFiles/WeinAchtWichtel.dir/src/Spielstand.cpp.o
WeinAchtWichtel: CMakeFiles/WeinAchtWichtel.dir/src/Wichtel.cpp.o
WeinAchtWichtel: CMakeFiles/WeinAchtWichtel.dir/src/Spielfeld.cpp.o
WeinAchtWichtel: CMakeFiles/WeinAchtWichtel.dir/build.make
WeinAchtWichtel: CMakeFiles/WeinAchtWichtel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable WeinAchtWichtel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WeinAchtWichtel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WeinAchtWichtel.dir/build: WeinAchtWichtel
.PHONY : CMakeFiles/WeinAchtWichtel.dir/build

CMakeFiles/WeinAchtWichtel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WeinAchtWichtel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WeinAchtWichtel.dir/clean

CMakeFiles/WeinAchtWichtel.dir/depend:
	cd /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build /mnt/c/Users/mmgra/OneDrive/Studium_PDFs/SoftwareEng_II/programmentwurf_5393168/WeinAchtsWichtel/build/CMakeFiles/WeinAchtWichtel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WeinAchtWichtel.dir/depend

