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
include CMakeFiles/String.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/String.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/String.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/String.dir/flags.make

CMakeFiles/String.dir/Ex4_String.cpp.obj: CMakeFiles/String.dir/flags.make
CMakeFiles/String.dir/Ex4_String.cpp.obj: C:/Users/msztu/Desktop/UJ_LETNI_25/EAMPCPP/BACA_CPP/2_WEEK/lab2/Ex4_String.cpp
CMakeFiles/String.dir/Ex4_String.cpp.obj: CMakeFiles/String.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/String.dir/Ex4_String.cpp.obj"
	C:\instalki\jetbrainz\toolbox_apps\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/String.dir/Ex4_String.cpp.obj -MF CMakeFiles\String.dir\Ex4_String.cpp.obj.d -o CMakeFiles\String.dir\Ex4_String.cpp.obj -c C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\Ex4_String.cpp

CMakeFiles/String.dir/Ex4_String.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/String.dir/Ex4_String.cpp.i"
	C:\instalki\jetbrainz\toolbox_apps\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\Ex4_String.cpp > CMakeFiles\String.dir\Ex4_String.cpp.i

CMakeFiles/String.dir/Ex4_String.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/String.dir/Ex4_String.cpp.s"
	C:\instalki\jetbrainz\toolbox_apps\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\Ex4_String.cpp -o CMakeFiles\String.dir\Ex4_String.cpp.s

# Object files for target String
String_OBJECTS = \
"CMakeFiles/String.dir/Ex4_String.cpp.obj"

# External object files for target String
String_EXTERNAL_OBJECTS =

String.exe: CMakeFiles/String.dir/Ex4_String.cpp.obj
String.exe: CMakeFiles/String.dir/build.make
String.exe: CMakeFiles/String.dir/linkLibs.rsp
String.exe: CMakeFiles/String.dir/objects1.rsp
String.exe: CMakeFiles/String.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable String.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\String.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/String.dir/build: String.exe
.PHONY : CMakeFiles/String.dir/build

CMakeFiles/String.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\String.dir\cmake_clean.cmake
.PHONY : CMakeFiles/String.dir/clean

CMakeFiles/String.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2 C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2 C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug C:\Users\msztu\Desktop\UJ_LETNI_25\EAMPCPP\BACA_CPP\2_WEEK\lab2\cmake-build-debug\CMakeFiles\String.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/String.dir/depend

