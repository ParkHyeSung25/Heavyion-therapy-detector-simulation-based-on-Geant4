# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3

# Utility rule file for G__rootIO.

# Include any custom commands dependencies for this target.
include rootIO/CMakeFiles/G__rootIO.dir/compiler_depend.make

# Include the progress variables for this target.
include rootIO/CMakeFiles/G__rootIO.dir/progress.make

rootIO/CMakeFiles/G__rootIO: rootIO/G__rootIO.cxx
rootIO/CMakeFiles/G__rootIO: rootIO/librootIO_rdict.pcm
rootIO/CMakeFiles/G__rootIO: rootIO/librootIO.rootmap

rootIO/G__rootIO.cxx: rootIO/include/LinkDef.h
rootIO/G__rootIO.cxx: rootIO/include/Interface.h
rootIO/G__rootIO.cxx: rootIO/include/RootInterface.h
rootIO/G__rootIO.cxx: rootIO/include/Interface.h
rootIO/G__rootIO.cxx: rootIO/include/RootInterface.h
rootIO/G__rootIO.cxx: rootIO/include/LinkDef.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating G__rootIO.cxx, librootIO_rdict.pcm, librootIO.rootmap"
	cd /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO && /opt/homebrew/Cellar/cmake/3.26.1/bin/cmake -E env LD_LIBRARY_PATH=/opt/homebrew/Cellar/root/6.26.06_2/lib/root: /opt/homebrew/bin/rootcling -v2 -f G__rootIO.cxx -s /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/librootIO.dylib -rml librootIO.dylib -rmf /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/librootIO.rootmap -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk/usr/include/c++/v1 -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0/include -compilerI/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk/usr/include -compilerI/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/include -I/opt/homebrew/Cellar/root/6.26.06_2/include/root -I/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/include/Interface.h /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/include/RootInterface.h /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/include/LinkDef.h

rootIO/librootIO_rdict.pcm: rootIO/G__rootIO.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate rootIO/librootIO_rdict.pcm

rootIO/librootIO.rootmap: rootIO/G__rootIO.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate rootIO/librootIO.rootmap

G__rootIO: rootIO/CMakeFiles/G__rootIO
G__rootIO: rootIO/G__rootIO.cxx
G__rootIO: rootIO/librootIO.rootmap
G__rootIO: rootIO/librootIO_rdict.pcm
G__rootIO: rootIO/CMakeFiles/G__rootIO.dir/build.make
.PHONY : G__rootIO

# Rule to build all files generated by this target.
rootIO/CMakeFiles/G__rootIO.dir/build: G__rootIO
.PHONY : rootIO/CMakeFiles/G__rootIO.dir/build

rootIO/CMakeFiles/G__rootIO.dir/clean:
	cd /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO && $(CMAKE_COMMAND) -P CMakeFiles/G__rootIO.dir/cmake_clean.cmake
.PHONY : rootIO/CMakeFiles/G__rootIO.dir/clean

rootIO/CMakeFiles/G__rootIO.dir/depend:
	cd /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3 /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3 /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/CMakeFiles/G__rootIO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rootIO/CMakeFiles/G__rootIO.dir/depend

