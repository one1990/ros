# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/kaanh/Desktop/cmake-3.12.3-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/kaanh/Desktop/cmake-3.12.3-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/catkin_ws/build

# Include any dependencies generated for this target.
include controller/CMakeFiles/fake_Client2.dir/depend.make

# Include the progress variables for this target.
include controller/CMakeFiles/fake_Client2.dir/progress.make

# Include the compile flags for this target's objects.
include controller/CMakeFiles/fake_Client2.dir/flags.make

controller/CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.o: controller/CMakeFiles/fake_Client2.dir/flags.make
controller/CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.o: /root/catkin_ws/src/controller/src/fake_client2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object controller/CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.o"
	cd /root/catkin_ws/build/controller && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.o -c /root/catkin_ws/src/controller/src/fake_client2.cpp

controller/CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.i"
	cd /root/catkin_ws/build/controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/catkin_ws/src/controller/src/fake_client2.cpp > CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.i

controller/CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.s"
	cd /root/catkin_ws/build/controller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/catkin_ws/src/controller/src/fake_client2.cpp -o CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.s

# Object files for target fake_Client2
fake_Client2_OBJECTS = \
"CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.o"

# External object files for target fake_Client2
fake_Client2_EXTERNAL_OBJECTS =

/root/catkin_ws/devel/lib/controller/fake_Client2: controller/CMakeFiles/fake_Client2.dir/src/fake_client2.cpp.o
/root/catkin_ws/devel/lib/controller/fake_Client2: controller/CMakeFiles/fake_Client2.dir/build.make
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/libtf.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/libtf2_ros.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/libactionlib.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/libmessage_filters.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/libroscpp.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/libxmlrpcpp.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/libtf2.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/libroscpp_serialization.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/librosconsole.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/librostime.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /opt/ros/kinetic/lib/libcpp_common.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libboost_system.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libpthread.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/aris/aris-1.5.0/lib/release/libaris_robot.a
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/aris/aris-1.5.0/lib/release/libaris_server.a
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/aris/aris-1.5.0/lib/release/libaris_plan.a
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/aris/aris-1.5.0/lib/release/libaris_dynamic.a
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/aris/aris-1.5.0/lib/release/libaris_control.a
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/aris/aris-1.5.0/lib/release/libaris_sensor.a
/root/catkin_ws/devel/lib/controller/fake_Client2: /usr/aris/aris-1.5.0/lib/release/libaris_core.a
/root/catkin_ws/devel/lib/controller/fake_Client2: controller/CMakeFiles/fake_Client2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /root/catkin_ws/devel/lib/controller/fake_Client2"
	cd /root/catkin_ws/build/controller && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fake_Client2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
controller/CMakeFiles/fake_Client2.dir/build: /root/catkin_ws/devel/lib/controller/fake_Client2

.PHONY : controller/CMakeFiles/fake_Client2.dir/build

controller/CMakeFiles/fake_Client2.dir/clean:
	cd /root/catkin_ws/build/controller && $(CMAKE_COMMAND) -P CMakeFiles/fake_Client2.dir/cmake_clean.cmake
.PHONY : controller/CMakeFiles/fake_Client2.dir/clean

controller/CMakeFiles/fake_Client2.dir/depend:
	cd /root/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/catkin_ws/src /root/catkin_ws/src/controller /root/catkin_ws/build /root/catkin_ws/build/controller /root/catkin_ws/build/controller/CMakeFiles/fake_Client2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : controller/CMakeFiles/fake_Client2.dir/depend
