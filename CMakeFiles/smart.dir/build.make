# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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

# Include any dependencies generated for this target.
include CMakeFiles/smart.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/smart.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/smart.dir/flags.make

CMakeFiles/smart.dir/src/main.c.o: CMakeFiles/smart.dir/flags.make
CMakeFiles/smart.dir/src/main.c.o: src/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linux/fsmart/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/smart.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/smart.dir/src/main.c.o   -c /home/linux/fsmart/src/main.c

CMakeFiles/smart.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/smart.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/linux/fsmart/src/main.c > CMakeFiles/smart.dir/src/main.c.i

CMakeFiles/smart.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/smart.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/linux/fsmart/src/main.c -o CMakeFiles/smart.dir/src/main.c.s

CMakeFiles/smart.dir/src/main.c.o.requires:
.PHONY : CMakeFiles/smart.dir/src/main.c.o.requires

CMakeFiles/smart.dir/src/main.c.o.provides: CMakeFiles/smart.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/smart.dir/build.make CMakeFiles/smart.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/smart.dir/src/main.c.o.provides

CMakeFiles/smart.dir/src/main.c.o.provides.build: CMakeFiles/smart.dir/src/main.c.o

CMakeFiles/smart.dir/src/fsocket.c.o: CMakeFiles/smart.dir/flags.make
CMakeFiles/smart.dir/src/fsocket.c.o: src/fsocket.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linux/fsmart/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/smart.dir/src/fsocket.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/smart.dir/src/fsocket.c.o   -c /home/linux/fsmart/src/fsocket.c

CMakeFiles/smart.dir/src/fsocket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/smart.dir/src/fsocket.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/linux/fsmart/src/fsocket.c > CMakeFiles/smart.dir/src/fsocket.c.i

CMakeFiles/smart.dir/src/fsocket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/smart.dir/src/fsocket.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/linux/fsmart/src/fsocket.c -o CMakeFiles/smart.dir/src/fsocket.c.s

CMakeFiles/smart.dir/src/fsocket.c.o.requires:
.PHONY : CMakeFiles/smart.dir/src/fsocket.c.o.requires

CMakeFiles/smart.dir/src/fsocket.c.o.provides: CMakeFiles/smart.dir/src/fsocket.c.o.requires
	$(MAKE) -f CMakeFiles/smart.dir/build.make CMakeFiles/smart.dir/src/fsocket.c.o.provides.build
.PHONY : CMakeFiles/smart.dir/src/fsocket.c.o.provides

CMakeFiles/smart.dir/src/fsocket.c.o.provides.build: CMakeFiles/smart.dir/src/fsocket.c.o

CMakeFiles/smart.dir/src/usart.c.o: CMakeFiles/smart.dir/flags.make
CMakeFiles/smart.dir/src/usart.c.o: src/usart.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linux/fsmart/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/smart.dir/src/usart.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/smart.dir/src/usart.c.o   -c /home/linux/fsmart/src/usart.c

CMakeFiles/smart.dir/src/usart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/smart.dir/src/usart.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/linux/fsmart/src/usart.c > CMakeFiles/smart.dir/src/usart.c.i

CMakeFiles/smart.dir/src/usart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/smart.dir/src/usart.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/linux/fsmart/src/usart.c -o CMakeFiles/smart.dir/src/usart.c.s

CMakeFiles/smart.dir/src/usart.c.o.requires:
.PHONY : CMakeFiles/smart.dir/src/usart.c.o.requires

CMakeFiles/smart.dir/src/usart.c.o.provides: CMakeFiles/smart.dir/src/usart.c.o.requires
	$(MAKE) -f CMakeFiles/smart.dir/build.make CMakeFiles/smart.dir/src/usart.c.o.provides.build
.PHONY : CMakeFiles/smart.dir/src/usart.c.o.provides

CMakeFiles/smart.dir/src/usart.c.o.provides.build: CMakeFiles/smart.dir/src/usart.c.o

CMakeFiles/smart.dir/src/readdata.c.o: CMakeFiles/smart.dir/flags.make
CMakeFiles/smart.dir/src/readdata.c.o: src/readdata.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linux/fsmart/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/smart.dir/src/readdata.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/smart.dir/src/readdata.c.o   -c /home/linux/fsmart/src/readdata.c

CMakeFiles/smart.dir/src/readdata.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/smart.dir/src/readdata.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/linux/fsmart/src/readdata.c > CMakeFiles/smart.dir/src/readdata.c.i

CMakeFiles/smart.dir/src/readdata.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/smart.dir/src/readdata.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/linux/fsmart/src/readdata.c -o CMakeFiles/smart.dir/src/readdata.c.s

CMakeFiles/smart.dir/src/readdata.c.o.requires:
.PHONY : CMakeFiles/smart.dir/src/readdata.c.o.requires

CMakeFiles/smart.dir/src/readdata.c.o.provides: CMakeFiles/smart.dir/src/readdata.c.o.requires
	$(MAKE) -f CMakeFiles/smart.dir/build.make CMakeFiles/smart.dir/src/readdata.c.o.provides.build
.PHONY : CMakeFiles/smart.dir/src/readdata.c.o.provides

CMakeFiles/smart.dir/src/readdata.c.o.provides.build: CMakeFiles/smart.dir/src/readdata.c.o

# Object files for target smart
smart_OBJECTS = \
"CMakeFiles/smart.dir/src/main.c.o" \
"CMakeFiles/smart.dir/src/fsocket.c.o" \
"CMakeFiles/smart.dir/src/usart.c.o" \
"CMakeFiles/smart.dir/src/readdata.c.o"

# External object files for target smart
smart_EXTERNAL_OBJECTS =

smart: CMakeFiles/smart.dir/src/main.c.o
smart: CMakeFiles/smart.dir/src/fsocket.c.o
smart: CMakeFiles/smart.dir/src/usart.c.o
smart: CMakeFiles/smart.dir/src/readdata.c.o
smart: CMakeFiles/smart.dir/build.make
smart: CMakeFiles/smart.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable smart"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/smart.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/smart.dir/build: smart
.PHONY : CMakeFiles/smart.dir/build

CMakeFiles/smart.dir/requires: CMakeFiles/smart.dir/src/main.c.o.requires
CMakeFiles/smart.dir/requires: CMakeFiles/smart.dir/src/fsocket.c.o.requires
CMakeFiles/smart.dir/requires: CMakeFiles/smart.dir/src/usart.c.o.requires
CMakeFiles/smart.dir/requires: CMakeFiles/smart.dir/src/readdata.c.o.requires
.PHONY : CMakeFiles/smart.dir/requires

CMakeFiles/smart.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/smart.dir/cmake_clean.cmake
.PHONY : CMakeFiles/smart.dir/clean

CMakeFiles/smart.dir/depend:
	cd /home/linux/fsmart && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linux/fsmart /home/linux/fsmart /home/linux/fsmart /home/linux/fsmart /home/linux/fsmart/CMakeFiles/smart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/smart.dir/depend

