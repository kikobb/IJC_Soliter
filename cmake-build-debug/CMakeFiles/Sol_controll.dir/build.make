# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/martin/clion-2017.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/martin/clion-2017.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/martin/CLionProjects/IJC_Soliter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/martin/CLionProjects/IJC_Soliter/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sol_controll.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sol_controll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sol_controll.dir/flags.make

CMakeFiles/Sol_controll.dir/Controller.cpp.o: CMakeFiles/Sol_controll.dir/flags.make
CMakeFiles/Sol_controll.dir/Controller.cpp.o: ../Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/CLionProjects/IJC_Soliter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sol_controll.dir/Controller.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sol_controll.dir/Controller.cpp.o -c /home/martin/CLionProjects/IJC_Soliter/Controller.cpp

CMakeFiles/Sol_controll.dir/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sol_controll.dir/Controller.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/CLionProjects/IJC_Soliter/Controller.cpp > CMakeFiles/Sol_controll.dir/Controller.cpp.i

CMakeFiles/Sol_controll.dir/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sol_controll.dir/Controller.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/CLionProjects/IJC_Soliter/Controller.cpp -o CMakeFiles/Sol_controll.dir/Controller.cpp.s

CMakeFiles/Sol_controll.dir/Controller.cpp.o.requires:

.PHONY : CMakeFiles/Sol_controll.dir/Controller.cpp.o.requires

CMakeFiles/Sol_controll.dir/Controller.cpp.o.provides: CMakeFiles/Sol_controll.dir/Controller.cpp.o.requires
	$(MAKE) -f CMakeFiles/Sol_controll.dir/build.make CMakeFiles/Sol_controll.dir/Controller.cpp.o.provides.build
.PHONY : CMakeFiles/Sol_controll.dir/Controller.cpp.o.provides

CMakeFiles/Sol_controll.dir/Controller.cpp.o.provides.build: CMakeFiles/Sol_controll.dir/Controller.cpp.o


CMakeFiles/Sol_controll.dir/main.cpp.o: CMakeFiles/Sol_controll.dir/flags.make
CMakeFiles/Sol_controll.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/CLionProjects/IJC_Soliter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Sol_controll.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sol_controll.dir/main.cpp.o -c /home/martin/CLionProjects/IJC_Soliter/main.cpp

CMakeFiles/Sol_controll.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sol_controll.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/CLionProjects/IJC_Soliter/main.cpp > CMakeFiles/Sol_controll.dir/main.cpp.i

CMakeFiles/Sol_controll.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sol_controll.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/CLionProjects/IJC_Soliter/main.cpp -o CMakeFiles/Sol_controll.dir/main.cpp.s

CMakeFiles/Sol_controll.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Sol_controll.dir/main.cpp.o.requires

CMakeFiles/Sol_controll.dir/main.cpp.o.provides: CMakeFiles/Sol_controll.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Sol_controll.dir/build.make CMakeFiles/Sol_controll.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Sol_controll.dir/main.cpp.o.provides

CMakeFiles/Sol_controll.dir/main.cpp.o.provides.build: CMakeFiles/Sol_controll.dir/main.cpp.o


# Object files for target Sol_controll
Sol_controll_OBJECTS = \
"CMakeFiles/Sol_controll.dir/Controller.cpp.o" \
"CMakeFiles/Sol_controll.dir/main.cpp.o"

# External object files for target Sol_controll
Sol_controll_EXTERNAL_OBJECTS =

Sol_controll: CMakeFiles/Sol_controll.dir/Controller.cpp.o
Sol_controll: CMakeFiles/Sol_controll.dir/main.cpp.o
Sol_controll: CMakeFiles/Sol_controll.dir/build.make
Sol_controll: CMakeFiles/Sol_controll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martin/CLionProjects/IJC_Soliter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Sol_controll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sol_controll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sol_controll.dir/build: Sol_controll

.PHONY : CMakeFiles/Sol_controll.dir/build

CMakeFiles/Sol_controll.dir/requires: CMakeFiles/Sol_controll.dir/Controller.cpp.o.requires
CMakeFiles/Sol_controll.dir/requires: CMakeFiles/Sol_controll.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Sol_controll.dir/requires

CMakeFiles/Sol_controll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sol_controll.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sol_controll.dir/clean

CMakeFiles/Sol_controll.dir/depend:
	cd /home/martin/CLionProjects/IJC_Soliter/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martin/CLionProjects/IJC_Soliter /home/martin/CLionProjects/IJC_Soliter /home/martin/CLionProjects/IJC_Soliter/cmake-build-debug /home/martin/CLionProjects/IJC_Soliter/cmake-build-debug /home/martin/CLionProjects/IJC_Soliter/cmake-build-debug/CMakeFiles/Sol_controll.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sol_controll.dir/depend

