# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.3.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.3.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lukesamora/dev/cc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lukesamora/dev/cc/build

# Include any dependencies generated for this target.
include CMakeFiles/TCC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TCC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TCC.dir/flags.make

CMakeFiles/TCC.dir/src/main.cpp.o: CMakeFiles/TCC.dir/flags.make
CMakeFiles/TCC.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lukesamora/dev/cc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TCC.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TCC.dir/src/main.cpp.o -c /Users/lukesamora/dev/cc/src/main.cpp

CMakeFiles/TCC.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCC.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/lukesamora/dev/cc/src/main.cpp > CMakeFiles/TCC.dir/src/main.cpp.i

CMakeFiles/TCC.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCC.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/lukesamora/dev/cc/src/main.cpp -o CMakeFiles/TCC.dir/src/main.cpp.s

CMakeFiles/TCC.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/TCC.dir/src/main.cpp.o.requires

CMakeFiles/TCC.dir/src/main.cpp.o.provides: CMakeFiles/TCC.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TCC.dir/build.make CMakeFiles/TCC.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/TCC.dir/src/main.cpp.o.provides

CMakeFiles/TCC.dir/src/main.cpp.o.provides.build: CMakeFiles/TCC.dir/src/main.cpp.o


CMakeFiles/TCC.dir/src/Preprocessor.cpp.o: CMakeFiles/TCC.dir/flags.make
CMakeFiles/TCC.dir/src/Preprocessor.cpp.o: ../src/Preprocessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lukesamora/dev/cc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TCC.dir/src/Preprocessor.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TCC.dir/src/Preprocessor.cpp.o -c /Users/lukesamora/dev/cc/src/Preprocessor.cpp

CMakeFiles/TCC.dir/src/Preprocessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCC.dir/src/Preprocessor.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/lukesamora/dev/cc/src/Preprocessor.cpp > CMakeFiles/TCC.dir/src/Preprocessor.cpp.i

CMakeFiles/TCC.dir/src/Preprocessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCC.dir/src/Preprocessor.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/lukesamora/dev/cc/src/Preprocessor.cpp -o CMakeFiles/TCC.dir/src/Preprocessor.cpp.s

CMakeFiles/TCC.dir/src/Preprocessor.cpp.o.requires:

.PHONY : CMakeFiles/TCC.dir/src/Preprocessor.cpp.o.requires

CMakeFiles/TCC.dir/src/Preprocessor.cpp.o.provides: CMakeFiles/TCC.dir/src/Preprocessor.cpp.o.requires
	$(MAKE) -f CMakeFiles/TCC.dir/build.make CMakeFiles/TCC.dir/src/Preprocessor.cpp.o.provides.build
.PHONY : CMakeFiles/TCC.dir/src/Preprocessor.cpp.o.provides

CMakeFiles/TCC.dir/src/Preprocessor.cpp.o.provides.build: CMakeFiles/TCC.dir/src/Preprocessor.cpp.o


# Object files for target TCC
TCC_OBJECTS = \
"CMakeFiles/TCC.dir/src/main.cpp.o" \
"CMakeFiles/TCC.dir/src/Preprocessor.cpp.o"

# External object files for target TCC
TCC_EXTERNAL_OBJECTS =

TCC: CMakeFiles/TCC.dir/src/main.cpp.o
TCC: CMakeFiles/TCC.dir/src/Preprocessor.cpp.o
TCC: CMakeFiles/TCC.dir/build.make
TCC: CMakeFiles/TCC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lukesamora/dev/cc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TCC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TCC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TCC.dir/build: TCC

.PHONY : CMakeFiles/TCC.dir/build

CMakeFiles/TCC.dir/requires: CMakeFiles/TCC.dir/src/main.cpp.o.requires
CMakeFiles/TCC.dir/requires: CMakeFiles/TCC.dir/src/Preprocessor.cpp.o.requires

.PHONY : CMakeFiles/TCC.dir/requires

CMakeFiles/TCC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TCC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TCC.dir/clean

CMakeFiles/TCC.dir/depend:
	cd /Users/lukesamora/dev/cc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lukesamora/dev/cc /Users/lukesamora/dev/cc /Users/lukesamora/dev/cc/build /Users/lukesamora/dev/cc/build /Users/lukesamora/dev/cc/build/CMakeFiles/TCC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TCC.dir/depend

