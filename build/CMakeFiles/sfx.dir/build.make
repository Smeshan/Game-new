# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/smeshan/workspace/SFX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/smeshan/workspace/SFX/build

# Include any dependencies generated for this target.
include CMakeFiles/sfx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sfx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfx.dir/flags.make

CMakeFiles/sfx.dir/src/main.cpp.o: CMakeFiles/sfx.dir/flags.make
CMakeFiles/sfx.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smeshan/workspace/SFX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfx.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfx.dir/src/main.cpp.o -c /home/smeshan/workspace/SFX/src/main.cpp

CMakeFiles/sfx.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfx.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/smeshan/workspace/SFX/src/main.cpp > CMakeFiles/sfx.dir/src/main.cpp.i

CMakeFiles/sfx.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfx.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/smeshan/workspace/SFX/src/main.cpp -o CMakeFiles/sfx.dir/src/main.cpp.s

CMakeFiles/sfx.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/sfx.dir/src/main.cpp.o.requires

CMakeFiles/sfx.dir/src/main.cpp.o.provides: CMakeFiles/sfx.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sfx.dir/build.make CMakeFiles/sfx.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/sfx.dir/src/main.cpp.o.provides

CMakeFiles/sfx.dir/src/main.cpp.o.provides.build: CMakeFiles/sfx.dir/src/main.cpp.o


CMakeFiles/sfx.dir/src/game/Game.cpp.o: CMakeFiles/sfx.dir/flags.make
CMakeFiles/sfx.dir/src/game/Game.cpp.o: ../src/game/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smeshan/workspace/SFX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sfx.dir/src/game/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfx.dir/src/game/Game.cpp.o -c /home/smeshan/workspace/SFX/src/game/Game.cpp

CMakeFiles/sfx.dir/src/game/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfx.dir/src/game/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/smeshan/workspace/SFX/src/game/Game.cpp > CMakeFiles/sfx.dir/src/game/Game.cpp.i

CMakeFiles/sfx.dir/src/game/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfx.dir/src/game/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/smeshan/workspace/SFX/src/game/Game.cpp -o CMakeFiles/sfx.dir/src/game/Game.cpp.s

CMakeFiles/sfx.dir/src/game/Game.cpp.o.requires:

.PHONY : CMakeFiles/sfx.dir/src/game/Game.cpp.o.requires

CMakeFiles/sfx.dir/src/game/Game.cpp.o.provides: CMakeFiles/sfx.dir/src/game/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/sfx.dir/build.make CMakeFiles/sfx.dir/src/game/Game.cpp.o.provides.build
.PHONY : CMakeFiles/sfx.dir/src/game/Game.cpp.o.provides

CMakeFiles/sfx.dir/src/game/Game.cpp.o.provides.build: CMakeFiles/sfx.dir/src/game/Game.cpp.o


CMakeFiles/sfx.dir/src/engine/Engine.cpp.o: CMakeFiles/sfx.dir/flags.make
CMakeFiles/sfx.dir/src/engine/Engine.cpp.o: ../src/engine/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smeshan/workspace/SFX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sfx.dir/src/engine/Engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfx.dir/src/engine/Engine.cpp.o -c /home/smeshan/workspace/SFX/src/engine/Engine.cpp

CMakeFiles/sfx.dir/src/engine/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfx.dir/src/engine/Engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/smeshan/workspace/SFX/src/engine/Engine.cpp > CMakeFiles/sfx.dir/src/engine/Engine.cpp.i

CMakeFiles/sfx.dir/src/engine/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfx.dir/src/engine/Engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/smeshan/workspace/SFX/src/engine/Engine.cpp -o CMakeFiles/sfx.dir/src/engine/Engine.cpp.s

CMakeFiles/sfx.dir/src/engine/Engine.cpp.o.requires:

.PHONY : CMakeFiles/sfx.dir/src/engine/Engine.cpp.o.requires

CMakeFiles/sfx.dir/src/engine/Engine.cpp.o.provides: CMakeFiles/sfx.dir/src/engine/Engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/sfx.dir/build.make CMakeFiles/sfx.dir/src/engine/Engine.cpp.o.provides.build
.PHONY : CMakeFiles/sfx.dir/src/engine/Engine.cpp.o.provides

CMakeFiles/sfx.dir/src/engine/Engine.cpp.o.provides.build: CMakeFiles/sfx.dir/src/engine/Engine.cpp.o


CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o: CMakeFiles/sfx.dir/flags.make
CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o: ../src/engine/EngineConfigLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smeshan/workspace/SFX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o -c /home/smeshan/workspace/SFX/src/engine/EngineConfigLoader.cpp

CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/smeshan/workspace/SFX/src/engine/EngineConfigLoader.cpp > CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.i

CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/smeshan/workspace/SFX/src/engine/EngineConfigLoader.cpp -o CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.s

CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o.requires:

.PHONY : CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o.requires

CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o.provides: CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o.requires
	$(MAKE) -f CMakeFiles/sfx.dir/build.make CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o.provides.build
.PHONY : CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o.provides

CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o.provides.build: CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o


# Object files for target sfx
sfx_OBJECTS = \
"CMakeFiles/sfx.dir/src/main.cpp.o" \
"CMakeFiles/sfx.dir/src/game/Game.cpp.o" \
"CMakeFiles/sfx.dir/src/engine/Engine.cpp.o" \
"CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o"

# External object files for target sfx
sfx_EXTERNAL_OBJECTS =

sfx: CMakeFiles/sfx.dir/src/main.cpp.o
sfx: CMakeFiles/sfx.dir/src/game/Game.cpp.o
sfx: CMakeFiles/sfx.dir/src/engine/Engine.cpp.o
sfx: CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o
sfx: CMakeFiles/sfx.dir/build.make
sfx: manager_utils/libmanager_utils.a
sfx: sdl_utils/libsdl_utils.a
sfx: utils/libutils.a
sfx: /usr/lib/x86_64-linux-gnu/libSDL2main.a
sfx: /usr/lib/x86_64-linux-gnu/libSDL2.so
sfx: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
sfx: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
sfx: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
sfx: CMakeFiles/sfx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/smeshan/workspace/SFX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sfx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfx.dir/build: sfx

.PHONY : CMakeFiles/sfx.dir/build

CMakeFiles/sfx.dir/requires: CMakeFiles/sfx.dir/src/main.cpp.o.requires
CMakeFiles/sfx.dir/requires: CMakeFiles/sfx.dir/src/game/Game.cpp.o.requires
CMakeFiles/sfx.dir/requires: CMakeFiles/sfx.dir/src/engine/Engine.cpp.o.requires
CMakeFiles/sfx.dir/requires: CMakeFiles/sfx.dir/src/engine/EngineConfigLoader.cpp.o.requires

.PHONY : CMakeFiles/sfx.dir/requires

CMakeFiles/sfx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfx.dir/clean

CMakeFiles/sfx.dir/depend:
	cd /home/smeshan/workspace/SFX/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/smeshan/workspace/SFX /home/smeshan/workspace/SFX /home/smeshan/workspace/SFX/build /home/smeshan/workspace/SFX/build /home/smeshan/workspace/SFX/build/CMakeFiles/sfx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfx.dir/depend
