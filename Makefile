# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/harrison/Programming/PhysicsEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/harrison/Programming/PhysicsEngine

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/harrison/Programming/PhysicsEngine/CMakeFiles /home/harrison/Programming/PhysicsEngine//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/harrison/Programming/PhysicsEngine/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named PhysicsEngine

# Build rule for target.
PhysicsEngine: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 PhysicsEngine
.PHONY : PhysicsEngine

# fast build rule for target.
PhysicsEngine/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/build
.PHONY : PhysicsEngine/fast

external/imgui/imgui.o: external/imgui/imgui.cpp.o

.PHONY : external/imgui/imgui.o

# target to build an object file
external/imgui/imgui.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui.cpp.o
.PHONY : external/imgui/imgui.cpp.o

external/imgui/imgui.i: external/imgui/imgui.cpp.i

.PHONY : external/imgui/imgui.i

# target to preprocess a source file
external/imgui/imgui.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui.cpp.i
.PHONY : external/imgui/imgui.cpp.i

external/imgui/imgui.s: external/imgui/imgui.cpp.s

.PHONY : external/imgui/imgui.s

# target to generate assembly for a file
external/imgui/imgui.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui.cpp.s
.PHONY : external/imgui/imgui.cpp.s

external/imgui/imgui_demo.o: external/imgui/imgui_demo.cpp.o

.PHONY : external/imgui/imgui_demo.o

# target to build an object file
external/imgui/imgui_demo.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_demo.cpp.o
.PHONY : external/imgui/imgui_demo.cpp.o

external/imgui/imgui_demo.i: external/imgui/imgui_demo.cpp.i

.PHONY : external/imgui/imgui_demo.i

# target to preprocess a source file
external/imgui/imgui_demo.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_demo.cpp.i
.PHONY : external/imgui/imgui_demo.cpp.i

external/imgui/imgui_demo.s: external/imgui/imgui_demo.cpp.s

.PHONY : external/imgui/imgui_demo.s

# target to generate assembly for a file
external/imgui/imgui_demo.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_demo.cpp.s
.PHONY : external/imgui/imgui_demo.cpp.s

external/imgui/imgui_draw.o: external/imgui/imgui_draw.cpp.o

.PHONY : external/imgui/imgui_draw.o

# target to build an object file
external/imgui/imgui_draw.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_draw.cpp.o
.PHONY : external/imgui/imgui_draw.cpp.o

external/imgui/imgui_draw.i: external/imgui/imgui_draw.cpp.i

.PHONY : external/imgui/imgui_draw.i

# target to preprocess a source file
external/imgui/imgui_draw.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_draw.cpp.i
.PHONY : external/imgui/imgui_draw.cpp.i

external/imgui/imgui_draw.s: external/imgui/imgui_draw.cpp.s

.PHONY : external/imgui/imgui_draw.s

# target to generate assembly for a file
external/imgui/imgui_draw.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_draw.cpp.s
.PHONY : external/imgui/imgui_draw.cpp.s

external/imgui/imgui_impl_glfw.o: external/imgui/imgui_impl_glfw.cpp.o

.PHONY : external/imgui/imgui_impl_glfw.o

# target to build an object file
external/imgui/imgui_impl_glfw.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_impl_glfw.cpp.o
.PHONY : external/imgui/imgui_impl_glfw.cpp.o

external/imgui/imgui_impl_glfw.i: external/imgui/imgui_impl_glfw.cpp.i

.PHONY : external/imgui/imgui_impl_glfw.i

# target to preprocess a source file
external/imgui/imgui_impl_glfw.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_impl_glfw.cpp.i
.PHONY : external/imgui/imgui_impl_glfw.cpp.i

external/imgui/imgui_impl_glfw.s: external/imgui/imgui_impl_glfw.cpp.s

.PHONY : external/imgui/imgui_impl_glfw.s

# target to generate assembly for a file
external/imgui/imgui_impl_glfw.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_impl_glfw.cpp.s
.PHONY : external/imgui/imgui_impl_glfw.cpp.s

external/imgui/imgui_impl_opengl3.o: external/imgui/imgui_impl_opengl3.cpp.o

.PHONY : external/imgui/imgui_impl_opengl3.o

# target to build an object file
external/imgui/imgui_impl_opengl3.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_impl_opengl3.cpp.o
.PHONY : external/imgui/imgui_impl_opengl3.cpp.o

external/imgui/imgui_impl_opengl3.i: external/imgui/imgui_impl_opengl3.cpp.i

.PHONY : external/imgui/imgui_impl_opengl3.i

# target to preprocess a source file
external/imgui/imgui_impl_opengl3.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_impl_opengl3.cpp.i
.PHONY : external/imgui/imgui_impl_opengl3.cpp.i

external/imgui/imgui_impl_opengl3.s: external/imgui/imgui_impl_opengl3.cpp.s

.PHONY : external/imgui/imgui_impl_opengl3.s

# target to generate assembly for a file
external/imgui/imgui_impl_opengl3.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_impl_opengl3.cpp.s
.PHONY : external/imgui/imgui_impl_opengl3.cpp.s

external/imgui/imgui_widgets.o: external/imgui/imgui_widgets.cpp.o

.PHONY : external/imgui/imgui_widgets.o

# target to build an object file
external/imgui/imgui_widgets.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_widgets.cpp.o
.PHONY : external/imgui/imgui_widgets.cpp.o

external/imgui/imgui_widgets.i: external/imgui/imgui_widgets.cpp.i

.PHONY : external/imgui/imgui_widgets.i

# target to preprocess a source file
external/imgui/imgui_widgets.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_widgets.cpp.i
.PHONY : external/imgui/imgui_widgets.cpp.i

external/imgui/imgui_widgets.s: external/imgui/imgui_widgets.cpp.s

.PHONY : external/imgui/imgui_widgets.s

# target to generate assembly for a file
external/imgui/imgui_widgets.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/imgui/imgui_widgets.cpp.s
.PHONY : external/imgui/imgui_widgets.cpp.s

external/implot/implot.o: external/implot/implot.cpp.o

.PHONY : external/implot/implot.o

# target to build an object file
external/implot/implot.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/implot/implot.cpp.o
.PHONY : external/implot/implot.cpp.o

external/implot/implot.i: external/implot/implot.cpp.i

.PHONY : external/implot/implot.i

# target to preprocess a source file
external/implot/implot.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/implot/implot.cpp.i
.PHONY : external/implot/implot.cpp.i

external/implot/implot.s: external/implot/implot.cpp.s

.PHONY : external/implot/implot.s

# target to generate assembly for a file
external/implot/implot.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/implot/implot.cpp.s
.PHONY : external/implot/implot.cpp.s

external/implot/implot_demo.o: external/implot/implot_demo.cpp.o

.PHONY : external/implot/implot_demo.o

# target to build an object file
external/implot/implot_demo.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/implot/implot_demo.cpp.o
.PHONY : external/implot/implot_demo.cpp.o

external/implot/implot_demo.i: external/implot/implot_demo.cpp.i

.PHONY : external/implot/implot_demo.i

# target to preprocess a source file
external/implot/implot_demo.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/implot/implot_demo.cpp.i
.PHONY : external/implot/implot_demo.cpp.i

external/implot/implot_demo.s: external/implot/implot_demo.cpp.s

.PHONY : external/implot/implot_demo.s

# target to generate assembly for a file
external/implot/implot_demo.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/implot/implot_demo.cpp.s
.PHONY : external/implot/implot_demo.cpp.s

external/implot/implot_items.o: external/implot/implot_items.cpp.o

.PHONY : external/implot/implot_items.o

# target to build an object file
external/implot/implot_items.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/implot/implot_items.cpp.o
.PHONY : external/implot/implot_items.cpp.o

external/implot/implot_items.i: external/implot/implot_items.cpp.i

.PHONY : external/implot/implot_items.i

# target to preprocess a source file
external/implot/implot_items.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/implot/implot_items.cpp.i
.PHONY : external/implot/implot_items.cpp.i

external/implot/implot_items.s: external/implot/implot_items.cpp.s

.PHONY : external/implot/implot_items.s

# target to generate assembly for a file
external/implot/implot_items.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/external/implot/implot_items.cpp.s
.PHONY : external/implot/implot_items.cpp.s

src/Camera.o: src/Camera.cpp.o

.PHONY : src/Camera.o

# target to build an object file
src/Camera.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Camera.cpp.o
.PHONY : src/Camera.cpp.o

src/Camera.i: src/Camera.cpp.i

.PHONY : src/Camera.i

# target to preprocess a source file
src/Camera.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Camera.cpp.i
.PHONY : src/Camera.cpp.i

src/Camera.s: src/Camera.cpp.s

.PHONY : src/Camera.s

# target to generate assembly for a file
src/Camera.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Camera.cpp.s
.PHONY : src/Camera.cpp.s

src/Engine.o: src/Engine.cpp.o

.PHONY : src/Engine.o

# target to build an object file
src/Engine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Engine.cpp.o
.PHONY : src/Engine.cpp.o

src/Engine.i: src/Engine.cpp.i

.PHONY : src/Engine.i

# target to preprocess a source file
src/Engine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Engine.cpp.i
.PHONY : src/Engine.cpp.i

src/Engine.s: src/Engine.cpp.s

.PHONY : src/Engine.s

# target to generate assembly for a file
src/Engine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Engine.cpp.s
.PHONY : src/Engine.cpp.s

src/Entity.o: src/Entity.cpp.o

.PHONY : src/Entity.o

# target to build an object file
src/Entity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Entity.cpp.o
.PHONY : src/Entity.cpp.o

src/Entity.i: src/Entity.cpp.i

.PHONY : src/Entity.i

# target to preprocess a source file
src/Entity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Entity.cpp.i
.PHONY : src/Entity.cpp.i

src/Entity.s: src/Entity.cpp.s

.PHONY : src/Entity.s

# target to generate assembly for a file
src/Entity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Entity.cpp.s
.PHONY : src/Entity.cpp.s

src/Light.o: src/Light.cpp.o

.PHONY : src/Light.o

# target to build an object file
src/Light.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Light.cpp.o
.PHONY : src/Light.cpp.o

src/Light.i: src/Light.cpp.i

.PHONY : src/Light.i

# target to preprocess a source file
src/Light.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Light.cpp.i
.PHONY : src/Light.cpp.i

src/Light.s: src/Light.cpp.s

.PHONY : src/Light.s

# target to generate assembly for a file
src/Light.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Light.cpp.s
.PHONY : src/Light.cpp.s

src/Renderer/Mesh.o: src/Renderer/Mesh.cpp.o

.PHONY : src/Renderer/Mesh.o

# target to build an object file
src/Renderer/Mesh.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Renderer/Mesh.cpp.o
.PHONY : src/Renderer/Mesh.cpp.o

src/Renderer/Mesh.i: src/Renderer/Mesh.cpp.i

.PHONY : src/Renderer/Mesh.i

# target to preprocess a source file
src/Renderer/Mesh.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Renderer/Mesh.cpp.i
.PHONY : src/Renderer/Mesh.cpp.i

src/Renderer/Mesh.s: src/Renderer/Mesh.cpp.s

.PHONY : src/Renderer/Mesh.s

# target to generate assembly for a file
src/Renderer/Mesh.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Renderer/Mesh.cpp.s
.PHONY : src/Renderer/Mesh.cpp.s

src/Renderer/Renderer.o: src/Renderer/Renderer.cpp.o

.PHONY : src/Renderer/Renderer.o

# target to build an object file
src/Renderer/Renderer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Renderer/Renderer.cpp.o
.PHONY : src/Renderer/Renderer.cpp.o

src/Renderer/Renderer.i: src/Renderer/Renderer.cpp.i

.PHONY : src/Renderer/Renderer.i

# target to preprocess a source file
src/Renderer/Renderer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Renderer/Renderer.cpp.i
.PHONY : src/Renderer/Renderer.cpp.i

src/Renderer/Renderer.s: src/Renderer/Renderer.cpp.s

.PHONY : src/Renderer/Renderer.s

# target to generate assembly for a file
src/Renderer/Renderer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Renderer/Renderer.cpp.s
.PHONY : src/Renderer/Renderer.cpp.s

src/Shader.o: src/Shader.cpp.o

.PHONY : src/Shader.o

# target to build an object file
src/Shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Shader.cpp.o
.PHONY : src/Shader.cpp.o

src/Shader.i: src/Shader.cpp.i

.PHONY : src/Shader.i

# target to preprocess a source file
src/Shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Shader.cpp.i
.PHONY : src/Shader.cpp.i

src/Shader.s: src/Shader.cpp.s

.PHONY : src/Shader.s

# target to generate assembly for a file
src/Shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Shader.cpp.s
.PHONY : src/Shader.cpp.s

src/Texture.o: src/Texture.cpp.o

.PHONY : src/Texture.o

# target to build an object file
src/Texture.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Texture.cpp.o
.PHONY : src/Texture.cpp.o

src/Texture.i: src/Texture.cpp.i

.PHONY : src/Texture.i

# target to preprocess a source file
src/Texture.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Texture.cpp.i
.PHONY : src/Texture.cpp.i

src/Texture.s: src/Texture.cpp.s

.PHONY : src/Texture.s

# target to generate assembly for a file
src/Texture.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Texture.cpp.s
.PHONY : src/Texture.cpp.s

src/Timer.o: src/Timer.cpp.o

.PHONY : src/Timer.o

# target to build an object file
src/Timer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Timer.cpp.o
.PHONY : src/Timer.cpp.o

src/Timer.i: src/Timer.cpp.i

.PHONY : src/Timer.i

# target to preprocess a source file
src/Timer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Timer.cpp.i
.PHONY : src/Timer.cpp.i

src/Timer.s: src/Timer.cpp.s

.PHONY : src/Timer.s

# target to generate assembly for a file
src/Timer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/Timer.cpp.s
.PHONY : src/Timer.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PhysicsEngine.dir/build.make CMakeFiles/PhysicsEngine.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... PhysicsEngine"
	@echo "... external/imgui/imgui.o"
	@echo "... external/imgui/imgui.i"
	@echo "... external/imgui/imgui.s"
	@echo "... external/imgui/imgui_demo.o"
	@echo "... external/imgui/imgui_demo.i"
	@echo "... external/imgui/imgui_demo.s"
	@echo "... external/imgui/imgui_draw.o"
	@echo "... external/imgui/imgui_draw.i"
	@echo "... external/imgui/imgui_draw.s"
	@echo "... external/imgui/imgui_impl_glfw.o"
	@echo "... external/imgui/imgui_impl_glfw.i"
	@echo "... external/imgui/imgui_impl_glfw.s"
	@echo "... external/imgui/imgui_impl_opengl3.o"
	@echo "... external/imgui/imgui_impl_opengl3.i"
	@echo "... external/imgui/imgui_impl_opengl3.s"
	@echo "... external/imgui/imgui_widgets.o"
	@echo "... external/imgui/imgui_widgets.i"
	@echo "... external/imgui/imgui_widgets.s"
	@echo "... external/implot/implot.o"
	@echo "... external/implot/implot.i"
	@echo "... external/implot/implot.s"
	@echo "... external/implot/implot_demo.o"
	@echo "... external/implot/implot_demo.i"
	@echo "... external/implot/implot_demo.s"
	@echo "... external/implot/implot_items.o"
	@echo "... external/implot/implot_items.i"
	@echo "... external/implot/implot_items.s"
	@echo "... src/Camera.o"
	@echo "... src/Camera.i"
	@echo "... src/Camera.s"
	@echo "... src/Engine.o"
	@echo "... src/Engine.i"
	@echo "... src/Engine.s"
	@echo "... src/Entity.o"
	@echo "... src/Entity.i"
	@echo "... src/Entity.s"
	@echo "... src/Light.o"
	@echo "... src/Light.i"
	@echo "... src/Light.s"
	@echo "... src/Renderer/Mesh.o"
	@echo "... src/Renderer/Mesh.i"
	@echo "... src/Renderer/Mesh.s"
	@echo "... src/Renderer/Renderer.o"
	@echo "... src/Renderer/Renderer.i"
	@echo "... src/Renderer/Renderer.s"
	@echo "... src/Shader.o"
	@echo "... src/Shader.i"
	@echo "... src/Shader.s"
	@echo "... src/Texture.o"
	@echo "... src/Texture.i"
	@echo "... src/Texture.s"
	@echo "... src/Timer.o"
	@echo "... src/Timer.i"
	@echo "... src/Timer.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

