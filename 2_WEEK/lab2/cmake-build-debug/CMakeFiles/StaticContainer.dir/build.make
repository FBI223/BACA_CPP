# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\instalki\jetbrainz\toolbox_apps\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\instalki\jetbrainz\toolbox_apps\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StaticContainer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/StaticContainer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/StaticContainer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StaticContainer.dir/flags.make

CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.obj: CMakeFiles/StaticContainer.dir/flags.make
CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.obj: C:/Users/msztu/Desktop/UJ_LETNI_25/EAMPCPP/BACA_CPP/2_WEEK/lab2/Ex1_StaticContainer.cpp
CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.obj: CMakeFiles/StaticContainer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.obj"
	C:\instalki\jetbrainz\toolbox_apps\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.obj -MF CMakeFiles\StaticContainer.dir\Ex1_StaticContainer.cpp.obj.d -o CMakeFiles\StaticContainer.dir\Ex1_StaticContainer.cpp.obj -c C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\Ex1_StaticContainer.cpp

CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.i"
	C:\instalki\jetbrainz\toolbox_apps\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\Ex1_StaticContainer.cpp > CMakeFiles\StaticContainer.dir\Ex1_StaticContainer.cpp.i

CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.s"
	C:\instalki\jetbrainz\toolbox_apps\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\Ex1_StaticContainer.cpp -o CMakeFiles\StaticContainer.dir\Ex1_StaticContainer.cpp.s

# Object files for target StaticContainer
StaticContainer_OBJECTS = \
"CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.obj"

# External object files for target StaticContainer
StaticContainer_EXTERNAL_OBJECTS =

StaticContainer.exe: CMakeFiles/StaticContainer.dir/Ex1_StaticContainer.cpp.obj
StaticContainer.exe: CMakeFiles/StaticContainer.dir/build.make
StaticContainer.exe: CMakeFiles/StaticContainer.dir/linkLibs.rsp
StaticContainer.exe: CMakeFiles/StaticContainer.dir/objects1.rsp
StaticContainer.exe: CMakeFiles/StaticContainer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StaticContainer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StaticContainer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StaticContainer.dir/build: StaticContainer.exe
.PHONY : CMakeFiles/StaticContainer.dir/build

CMakeFiles/StaticContainer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StaticContainer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StaticContainer.dir/clean

CMakeFiles/StaticContainer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2 C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2 C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug\CMakeFiles\StaticContainer.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/StaticContainer.dir/depend

