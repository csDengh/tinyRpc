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
CMAKE_SOURCE_DIR = /root/tiny_rpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/tiny_rpc/build

# Include any dependencies generated for this target.
include src/CMakeFiles/librpc.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/librpc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/librpc.dir/flags.make

src/CMakeFiles/librpc.dir/logger.cc.o: src/CMakeFiles/librpc.dir/flags.make
src/CMakeFiles/librpc.dir/logger.cc.o: ../src/logger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/tiny_rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/librpc.dir/logger.cc.o"
	cd /root/tiny_rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/librpc.dir/logger.cc.o -c /root/tiny_rpc/src/logger.cc

src/CMakeFiles/librpc.dir/logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/librpc.dir/logger.cc.i"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/tiny_rpc/src/logger.cc > CMakeFiles/librpc.dir/logger.cc.i

src/CMakeFiles/librpc.dir/logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/librpc.dir/logger.cc.s"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/tiny_rpc/src/logger.cc -o CMakeFiles/librpc.dir/logger.cc.s

src/CMakeFiles/librpc.dir/logger.cc.o.requires:

.PHONY : src/CMakeFiles/librpc.dir/logger.cc.o.requires

src/CMakeFiles/librpc.dir/logger.cc.o.provides: src/CMakeFiles/librpc.dir/logger.cc.o.requires
	$(MAKE) -f src/CMakeFiles/librpc.dir/build.make src/CMakeFiles/librpc.dir/logger.cc.o.provides.build
.PHONY : src/CMakeFiles/librpc.dir/logger.cc.o.provides

src/CMakeFiles/librpc.dir/logger.cc.o.provides.build: src/CMakeFiles/librpc.dir/logger.cc.o


src/CMakeFiles/librpc.dir/rpcApplication.cc.o: src/CMakeFiles/librpc.dir/flags.make
src/CMakeFiles/librpc.dir/rpcApplication.cc.o: ../src/rpcApplication.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/tiny_rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/librpc.dir/rpcApplication.cc.o"
	cd /root/tiny_rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/librpc.dir/rpcApplication.cc.o -c /root/tiny_rpc/src/rpcApplication.cc

src/CMakeFiles/librpc.dir/rpcApplication.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/librpc.dir/rpcApplication.cc.i"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/tiny_rpc/src/rpcApplication.cc > CMakeFiles/librpc.dir/rpcApplication.cc.i

src/CMakeFiles/librpc.dir/rpcApplication.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/librpc.dir/rpcApplication.cc.s"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/tiny_rpc/src/rpcApplication.cc -o CMakeFiles/librpc.dir/rpcApplication.cc.s

src/CMakeFiles/librpc.dir/rpcApplication.cc.o.requires:

.PHONY : src/CMakeFiles/librpc.dir/rpcApplication.cc.o.requires

src/CMakeFiles/librpc.dir/rpcApplication.cc.o.provides: src/CMakeFiles/librpc.dir/rpcApplication.cc.o.requires
	$(MAKE) -f src/CMakeFiles/librpc.dir/build.make src/CMakeFiles/librpc.dir/rpcApplication.cc.o.provides.build
.PHONY : src/CMakeFiles/librpc.dir/rpcApplication.cc.o.provides

src/CMakeFiles/librpc.dir/rpcApplication.cc.o.provides.build: src/CMakeFiles/librpc.dir/rpcApplication.cc.o


src/CMakeFiles/librpc.dir/rpcChannel.cc.o: src/CMakeFiles/librpc.dir/flags.make
src/CMakeFiles/librpc.dir/rpcChannel.cc.o: ../src/rpcChannel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/tiny_rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/librpc.dir/rpcChannel.cc.o"
	cd /root/tiny_rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/librpc.dir/rpcChannel.cc.o -c /root/tiny_rpc/src/rpcChannel.cc

src/CMakeFiles/librpc.dir/rpcChannel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/librpc.dir/rpcChannel.cc.i"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/tiny_rpc/src/rpcChannel.cc > CMakeFiles/librpc.dir/rpcChannel.cc.i

src/CMakeFiles/librpc.dir/rpcChannel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/librpc.dir/rpcChannel.cc.s"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/tiny_rpc/src/rpcChannel.cc -o CMakeFiles/librpc.dir/rpcChannel.cc.s

src/CMakeFiles/librpc.dir/rpcChannel.cc.o.requires:

.PHONY : src/CMakeFiles/librpc.dir/rpcChannel.cc.o.requires

src/CMakeFiles/librpc.dir/rpcChannel.cc.o.provides: src/CMakeFiles/librpc.dir/rpcChannel.cc.o.requires
	$(MAKE) -f src/CMakeFiles/librpc.dir/build.make src/CMakeFiles/librpc.dir/rpcChannel.cc.o.provides.build
.PHONY : src/CMakeFiles/librpc.dir/rpcChannel.cc.o.provides

src/CMakeFiles/librpc.dir/rpcChannel.cc.o.provides.build: src/CMakeFiles/librpc.dir/rpcChannel.cc.o


src/CMakeFiles/librpc.dir/rpcConfig.cc.o: src/CMakeFiles/librpc.dir/flags.make
src/CMakeFiles/librpc.dir/rpcConfig.cc.o: ../src/rpcConfig.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/tiny_rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/librpc.dir/rpcConfig.cc.o"
	cd /root/tiny_rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/librpc.dir/rpcConfig.cc.o -c /root/tiny_rpc/src/rpcConfig.cc

src/CMakeFiles/librpc.dir/rpcConfig.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/librpc.dir/rpcConfig.cc.i"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/tiny_rpc/src/rpcConfig.cc > CMakeFiles/librpc.dir/rpcConfig.cc.i

src/CMakeFiles/librpc.dir/rpcConfig.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/librpc.dir/rpcConfig.cc.s"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/tiny_rpc/src/rpcConfig.cc -o CMakeFiles/librpc.dir/rpcConfig.cc.s

src/CMakeFiles/librpc.dir/rpcConfig.cc.o.requires:

.PHONY : src/CMakeFiles/librpc.dir/rpcConfig.cc.o.requires

src/CMakeFiles/librpc.dir/rpcConfig.cc.o.provides: src/CMakeFiles/librpc.dir/rpcConfig.cc.o.requires
	$(MAKE) -f src/CMakeFiles/librpc.dir/build.make src/CMakeFiles/librpc.dir/rpcConfig.cc.o.provides.build
.PHONY : src/CMakeFiles/librpc.dir/rpcConfig.cc.o.provides

src/CMakeFiles/librpc.dir/rpcConfig.cc.o.provides.build: src/CMakeFiles/librpc.dir/rpcConfig.cc.o


src/CMakeFiles/librpc.dir/rpcController.cc.o: src/CMakeFiles/librpc.dir/flags.make
src/CMakeFiles/librpc.dir/rpcController.cc.o: ../src/rpcController.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/tiny_rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/librpc.dir/rpcController.cc.o"
	cd /root/tiny_rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/librpc.dir/rpcController.cc.o -c /root/tiny_rpc/src/rpcController.cc

src/CMakeFiles/librpc.dir/rpcController.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/librpc.dir/rpcController.cc.i"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/tiny_rpc/src/rpcController.cc > CMakeFiles/librpc.dir/rpcController.cc.i

src/CMakeFiles/librpc.dir/rpcController.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/librpc.dir/rpcController.cc.s"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/tiny_rpc/src/rpcController.cc -o CMakeFiles/librpc.dir/rpcController.cc.s

src/CMakeFiles/librpc.dir/rpcController.cc.o.requires:

.PHONY : src/CMakeFiles/librpc.dir/rpcController.cc.o.requires

src/CMakeFiles/librpc.dir/rpcController.cc.o.provides: src/CMakeFiles/librpc.dir/rpcController.cc.o.requires
	$(MAKE) -f src/CMakeFiles/librpc.dir/build.make src/CMakeFiles/librpc.dir/rpcController.cc.o.provides.build
.PHONY : src/CMakeFiles/librpc.dir/rpcController.cc.o.provides

src/CMakeFiles/librpc.dir/rpcController.cc.o.provides.build: src/CMakeFiles/librpc.dir/rpcController.cc.o


src/CMakeFiles/librpc.dir/rpcProvider.cc.o: src/CMakeFiles/librpc.dir/flags.make
src/CMakeFiles/librpc.dir/rpcProvider.cc.o: ../src/rpcProvider.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/tiny_rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/librpc.dir/rpcProvider.cc.o"
	cd /root/tiny_rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/librpc.dir/rpcProvider.cc.o -c /root/tiny_rpc/src/rpcProvider.cc

src/CMakeFiles/librpc.dir/rpcProvider.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/librpc.dir/rpcProvider.cc.i"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/tiny_rpc/src/rpcProvider.cc > CMakeFiles/librpc.dir/rpcProvider.cc.i

src/CMakeFiles/librpc.dir/rpcProvider.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/librpc.dir/rpcProvider.cc.s"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/tiny_rpc/src/rpcProvider.cc -o CMakeFiles/librpc.dir/rpcProvider.cc.s

src/CMakeFiles/librpc.dir/rpcProvider.cc.o.requires:

.PHONY : src/CMakeFiles/librpc.dir/rpcProvider.cc.o.requires

src/CMakeFiles/librpc.dir/rpcProvider.cc.o.provides: src/CMakeFiles/librpc.dir/rpcProvider.cc.o.requires
	$(MAKE) -f src/CMakeFiles/librpc.dir/build.make src/CMakeFiles/librpc.dir/rpcProvider.cc.o.provides.build
.PHONY : src/CMakeFiles/librpc.dir/rpcProvider.cc.o.provides

src/CMakeFiles/librpc.dir/rpcProvider.cc.o.provides.build: src/CMakeFiles/librpc.dir/rpcProvider.cc.o


src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o: src/CMakeFiles/librpc.dir/flags.make
src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o: ../src/rpcheader.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/tiny_rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o"
	cd /root/tiny_rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/librpc.dir/rpcheader.pb.cc.o -c /root/tiny_rpc/src/rpcheader.pb.cc

src/CMakeFiles/librpc.dir/rpcheader.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/librpc.dir/rpcheader.pb.cc.i"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/tiny_rpc/src/rpcheader.pb.cc > CMakeFiles/librpc.dir/rpcheader.pb.cc.i

src/CMakeFiles/librpc.dir/rpcheader.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/librpc.dir/rpcheader.pb.cc.s"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/tiny_rpc/src/rpcheader.pb.cc -o CMakeFiles/librpc.dir/rpcheader.pb.cc.s

src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o.requires:

.PHONY : src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o.requires

src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o.provides: src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o.requires
	$(MAKE) -f src/CMakeFiles/librpc.dir/build.make src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o.provides.build
.PHONY : src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o.provides

src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o.provides.build: src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o


src/CMakeFiles/librpc.dir/zkClient.cc.o: src/CMakeFiles/librpc.dir/flags.make
src/CMakeFiles/librpc.dir/zkClient.cc.o: ../src/zkClient.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/tiny_rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/librpc.dir/zkClient.cc.o"
	cd /root/tiny_rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/librpc.dir/zkClient.cc.o -c /root/tiny_rpc/src/zkClient.cc

src/CMakeFiles/librpc.dir/zkClient.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/librpc.dir/zkClient.cc.i"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/tiny_rpc/src/zkClient.cc > CMakeFiles/librpc.dir/zkClient.cc.i

src/CMakeFiles/librpc.dir/zkClient.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/librpc.dir/zkClient.cc.s"
	cd /root/tiny_rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/tiny_rpc/src/zkClient.cc -o CMakeFiles/librpc.dir/zkClient.cc.s

src/CMakeFiles/librpc.dir/zkClient.cc.o.requires:

.PHONY : src/CMakeFiles/librpc.dir/zkClient.cc.o.requires

src/CMakeFiles/librpc.dir/zkClient.cc.o.provides: src/CMakeFiles/librpc.dir/zkClient.cc.o.requires
	$(MAKE) -f src/CMakeFiles/librpc.dir/build.make src/CMakeFiles/librpc.dir/zkClient.cc.o.provides.build
.PHONY : src/CMakeFiles/librpc.dir/zkClient.cc.o.provides

src/CMakeFiles/librpc.dir/zkClient.cc.o.provides.build: src/CMakeFiles/librpc.dir/zkClient.cc.o


# Object files for target librpc
librpc_OBJECTS = \
"CMakeFiles/librpc.dir/logger.cc.o" \
"CMakeFiles/librpc.dir/rpcApplication.cc.o" \
"CMakeFiles/librpc.dir/rpcChannel.cc.o" \
"CMakeFiles/librpc.dir/rpcConfig.cc.o" \
"CMakeFiles/librpc.dir/rpcController.cc.o" \
"CMakeFiles/librpc.dir/rpcProvider.cc.o" \
"CMakeFiles/librpc.dir/rpcheader.pb.cc.o" \
"CMakeFiles/librpc.dir/zkClient.cc.o"

# External object files for target librpc
librpc_EXTERNAL_OBJECTS =

../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/logger.cc.o
../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/rpcApplication.cc.o
../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/rpcChannel.cc.o
../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/rpcConfig.cc.o
../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/rpcController.cc.o
../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/rpcProvider.cc.o
../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o
../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/zkClient.cc.o
../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/build.make
../lib/liblibrpc.a: src/CMakeFiles/librpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/tiny_rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library ../../lib/liblibrpc.a"
	cd /root/tiny_rpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/librpc.dir/cmake_clean_target.cmake
	cd /root/tiny_rpc/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/librpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/librpc.dir/build: ../lib/liblibrpc.a

.PHONY : src/CMakeFiles/librpc.dir/build

src/CMakeFiles/librpc.dir/requires: src/CMakeFiles/librpc.dir/logger.cc.o.requires
src/CMakeFiles/librpc.dir/requires: src/CMakeFiles/librpc.dir/rpcApplication.cc.o.requires
src/CMakeFiles/librpc.dir/requires: src/CMakeFiles/librpc.dir/rpcChannel.cc.o.requires
src/CMakeFiles/librpc.dir/requires: src/CMakeFiles/librpc.dir/rpcConfig.cc.o.requires
src/CMakeFiles/librpc.dir/requires: src/CMakeFiles/librpc.dir/rpcController.cc.o.requires
src/CMakeFiles/librpc.dir/requires: src/CMakeFiles/librpc.dir/rpcProvider.cc.o.requires
src/CMakeFiles/librpc.dir/requires: src/CMakeFiles/librpc.dir/rpcheader.pb.cc.o.requires
src/CMakeFiles/librpc.dir/requires: src/CMakeFiles/librpc.dir/zkClient.cc.o.requires

.PHONY : src/CMakeFiles/librpc.dir/requires

src/CMakeFiles/librpc.dir/clean:
	cd /root/tiny_rpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/librpc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/librpc.dir/clean

src/CMakeFiles/librpc.dir/depend:
	cd /root/tiny_rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/tiny_rpc /root/tiny_rpc/src /root/tiny_rpc/build /root/tiny_rpc/build/src /root/tiny_rpc/build/src/CMakeFiles/librpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/librpc.dir/depend
