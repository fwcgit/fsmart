# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/linux/fsmart

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linux/fsmart

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/linux/fsmart/CMakeFiles /home/linux/fsmart/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/linux/fsmart/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named smart40

# Build rule for target.
smart40: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 smart40
.PHONY : smart40

# fast build rule for target.
smart40/fast:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/build
.PHONY : smart40/fast

src/fsocket.o: src/fsocket.c.o
.PHONY : src/fsocket.o

# target to build an object file
src/fsocket.c.o:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/fsocket.c.o
.PHONY : src/fsocket.c.o

src/fsocket.i: src/fsocket.c.i
.PHONY : src/fsocket.i

# target to preprocess a source file
src/fsocket.c.i:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/fsocket.c.i
.PHONY : src/fsocket.c.i

src/fsocket.s: src/fsocket.c.s
.PHONY : src/fsocket.s

# target to generate assembly for a file
src/fsocket.c.s:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/fsocket.c.s
.PHONY : src/fsocket.c.s

src/main.o: src/main.c.o
.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/main.c.s
.PHONY : src/main.c.s

src/readdata.o: src/readdata.c.o
.PHONY : src/readdata.o

# target to build an object file
src/readdata.c.o:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/readdata.c.o
.PHONY : src/readdata.c.o

src/readdata.i: src/readdata.c.i
.PHONY : src/readdata.i

# target to preprocess a source file
src/readdata.c.i:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/readdata.c.i
.PHONY : src/readdata.c.i

src/readdata.s: src/readdata.c.s
.PHONY : src/readdata.s

# target to generate assembly for a file
src/readdata.c.s:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/readdata.c.s
.PHONY : src/readdata.c.s

src/usart.o: src/usart.c.o
.PHONY : src/usart.o

# target to build an object file
src/usart.c.o:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/usart.c.o
.PHONY : src/usart.c.o

src/usart.i: src/usart.c.i
.PHONY : src/usart.i

# target to preprocess a source file
src/usart.c.i:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/usart.c.i
.PHONY : src/usart.c.i

src/usart.s: src/usart.c.s
.PHONY : src/usart.s

# target to generate assembly for a file
src/usart.c.s:
	$(MAKE) -f CMakeFiles/smart40.dir/build.make CMakeFiles/smart40.dir/src/usart.c.s
.PHONY : src/usart.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... smart40"
	@echo "... src/fsocket.o"
	@echo "... src/fsocket.i"
	@echo "... src/fsocket.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/readdata.o"
	@echo "... src/readdata.i"
	@echo "... src/readdata.s"
	@echo "... src/usart.o"
	@echo "... src/usart.i"
	@echo "... src/usart.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

