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
CMAKE_SOURCE_DIR = "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lez_12042021.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lez_12042021.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lez_12042021.dir/flags.make

CMakeFiles/lez_12042021.dir/main.cpp.o: CMakeFiles/lez_12042021.dir/flags.make
CMakeFiles/lez_12042021.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lez_12042021.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lez_12042021.dir/main.cpp.o -c "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/main.cpp"

CMakeFiles/lez_12042021.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lez_12042021.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/main.cpp" > CMakeFiles/lez_12042021.dir/main.cpp.i

CMakeFiles/lez_12042021.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lez_12042021.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/main.cpp" -o CMakeFiles/lez_12042021.dir/main.cpp.s

# Object files for target lez_12042021
lez_12042021_OBJECTS = \
"CMakeFiles/lez_12042021.dir/main.cpp.o"

# External object files for target lez_12042021
lez_12042021_EXTERNAL_OBJECTS =

lez_12042021: CMakeFiles/lez_12042021.dir/main.cpp.o
lez_12042021: CMakeFiles/lez_12042021.dir/build.make
lez_12042021: CMakeFiles/lez_12042021.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lez_12042021"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lez_12042021.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lez_12042021.dir/build: lez_12042021

.PHONY : CMakeFiles/lez_12042021.dir/build

CMakeFiles/lez_12042021.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lez_12042021.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lez_12042021.dir/clean

CMakeFiles/lez_12042021.dir/depend:
	cd "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/cmake-build-debug" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/cmake-build-debug" "/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lez_12042021/cmake-build-debug/CMakeFiles/lez_12042021.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lez_12042021.dir/depend

