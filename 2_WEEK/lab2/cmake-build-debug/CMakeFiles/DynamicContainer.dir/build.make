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
include CMakeFiles/DynamicContainer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DynamicContainer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DynamicContainer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DynamicContainer.dir/flags.make

CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.obj: CMakeFiles/DynamicContainer.dir/flags.make
CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.obj: C:/Users/msztu/Desktop/UJ_LETNI_25/EAMPCPP/BACA_CPP/2_WEEK/lab2/Ex3_DynamicContainer.cpp
CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.obj: CMakeFiles/DynamicContainer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.obj"
	C:\instalki\jetbrainz\toolbox_apps\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.obj -MF CMakeFiles\DynamicContainer.dir\Ex3_DynamicContainer.cpp.obj.d -o CMakeFiles\DynamicContainer.dir\Ex3_DynamicContainer.cpp.obj -c C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\Ex3_DynamicContainer.cpp

CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.i"
	C:\instalki\jetbrainz\toolbox_apps\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\Ex3_DynamicContainer.cpp > CMakeFiles\DynamicContainer.dir\Ex3_DynamicContainer.cpp.i

CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.s"
	C:\instalki\jetbrainz\toolbox_apps\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\Ex3_DynamicContainer.cpp -o CMakeFiles\DynamicContainer.dir\Ex3_DynamicContainer.cpp.s

# Object files for target DynamicContainer
DynamicContainer_OBJECTS = \
"CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.obj"

# External object files for target DynamicContainer
DynamicContainer_EXTERNAL_OBJECTS =

DynamicContainer.exe: CMakeFiles/DynamicContainer.dir/Ex3_DynamicContainer.cpp.obj
DynamicContainer.exe: CMakeFiles/DynamicContainer.dir/build.make
DynamicContainer.exe: CMakeFiles/DynamicContainer.dir/linkLibs.rsp
DynamicContainer.exe: CMakeFiles/DynamicContainer.dir/objects1.rsp
DynamicContainer.exe: CMakeFiles/DynamicContainer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DynamicContainer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DynamicContainer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DynamicContainer.dir/build: DynamicContainer.exe
.PHONY : CMakeFiles/DynamicContainer.dir/build

CMakeFiles/DynamicContainer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DynamicContainer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DynamicContainer.dir/clean

CMakeFiles/DynamicContainer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2 C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2 C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug\CMakeFiles\DynamicContainer.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DynamicContainer.dir/depend

