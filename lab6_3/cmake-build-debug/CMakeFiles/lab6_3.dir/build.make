# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab6_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6_3.dir/flags.make

CMakeFiles/lab6_3.dir/main.cpp.o: CMakeFiles/lab6_3.dir/flags.make
CMakeFiles/lab6_3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab6_3.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab6_3.dir/main.cpp.o -c "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/main.cpp"

CMakeFiles/lab6_3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6_3.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/main.cpp" > CMakeFiles/lab6_3.dir/main.cpp.i

CMakeFiles/lab6_3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6_3.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/main.cpp" -o CMakeFiles/lab6_3.dir/main.cpp.s

CMakeFiles/lab6_3.dir/ThreadPool.cpp.o: CMakeFiles/lab6_3.dir/flags.make
CMakeFiles/lab6_3.dir/ThreadPool.cpp.o: ../ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab6_3.dir/ThreadPool.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab6_3.dir/ThreadPool.cpp.o -c "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/ThreadPool.cpp"

CMakeFiles/lab6_3.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6_3.dir/ThreadPool.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/ThreadPool.cpp" > CMakeFiles/lab6_3.dir/ThreadPool.cpp.i

CMakeFiles/lab6_3.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6_3.dir/ThreadPool.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/ThreadPool.cpp" -o CMakeFiles/lab6_3.dir/ThreadPool.cpp.s

# Object files for target lab6_3
lab6_3_OBJECTS = \
"CMakeFiles/lab6_3.dir/main.cpp.o" \
"CMakeFiles/lab6_3.dir/ThreadPool.cpp.o"

# External object files for target lab6_3
lab6_3_EXTERNAL_OBJECTS =

lab6_3: CMakeFiles/lab6_3.dir/main.cpp.o
lab6_3: CMakeFiles/lab6_3.dir/ThreadPool.cpp.o
lab6_3: CMakeFiles/lab6_3.dir/build.make
lab6_3: CMakeFiles/lab6_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab6_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab6_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6_3.dir/build: lab6_3

.PHONY : CMakeFiles/lab6_3.dir/build

CMakeFiles/lab6_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab6_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab6_3.dir/clean

CMakeFiles/lab6_3.dir/depend:
	cd "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/cmake-build-debug" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/cmake-build-debug" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab6_3/cmake-build-debug/CMakeFiles/lab6_3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab6_3.dir/depend
