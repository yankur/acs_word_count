# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/kurlyana/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5233.103/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kurlyana/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5233.103/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kurlyana/UCU/SEM4/ACS/lab4_word_count

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab4_word_count.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab4_word_count.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab4_word_count.dir/flags.make

CMakeFiles/lab4_word_count.dir/read_file.cpp.o: CMakeFiles/lab4_word_count.dir/flags.make
CMakeFiles/lab4_word_count.dir/read_file.cpp.o: ../read_file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab4_word_count.dir/read_file.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4_word_count.dir/read_file.cpp.o -c /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/read_file.cpp

CMakeFiles/lab4_word_count.dir/read_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4_word_count.dir/read_file.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/read_file.cpp > CMakeFiles/lab4_word_count.dir/read_file.cpp.i

CMakeFiles/lab4_word_count.dir/read_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4_word_count.dir/read_file.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/read_file.cpp -o CMakeFiles/lab4_word_count.dir/read_file.cpp.s

CMakeFiles/lab4_word_count.dir/count_words.cpp.o: CMakeFiles/lab4_word_count.dir/flags.make
CMakeFiles/lab4_word_count.dir/count_words.cpp.o: ../count_words.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab4_word_count.dir/count_words.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4_word_count.dir/count_words.cpp.o -c /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/count_words.cpp

CMakeFiles/lab4_word_count.dir/count_words.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4_word_count.dir/count_words.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/count_words.cpp > CMakeFiles/lab4_word_count.dir/count_words.cpp.i

CMakeFiles/lab4_word_count.dir/count_words.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4_word_count.dir/count_words.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/count_words.cpp -o CMakeFiles/lab4_word_count.dir/count_words.cpp.s

CMakeFiles/lab4_word_count.dir/main.cpp.o: CMakeFiles/lab4_word_count.dir/flags.make
CMakeFiles/lab4_word_count.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab4_word_count.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4_word_count.dir/main.cpp.o -c /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/main.cpp

CMakeFiles/lab4_word_count.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4_word_count.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/main.cpp > CMakeFiles/lab4_word_count.dir/main.cpp.i

CMakeFiles/lab4_word_count.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4_word_count.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/main.cpp -o CMakeFiles/lab4_word_count.dir/main.cpp.s

CMakeFiles/lab4_word_count.dir/merge.cpp.o: CMakeFiles/lab4_word_count.dir/flags.make
CMakeFiles/lab4_word_count.dir/merge.cpp.o: ../merge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab4_word_count.dir/merge.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4_word_count.dir/merge.cpp.o -c /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/merge.cpp

CMakeFiles/lab4_word_count.dir/merge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4_word_count.dir/merge.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/merge.cpp > CMakeFiles/lab4_word_count.dir/merge.cpp.i

CMakeFiles/lab4_word_count.dir/merge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4_word_count.dir/merge.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/merge.cpp -o CMakeFiles/lab4_word_count.dir/merge.cpp.s

CMakeFiles/lab4_word_count.dir/read_config.cpp.o: CMakeFiles/lab4_word_count.dir/flags.make
CMakeFiles/lab4_word_count.dir/read_config.cpp.o: ../read_config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab4_word_count.dir/read_config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4_word_count.dir/read_config.cpp.o -c /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/read_config.cpp

CMakeFiles/lab4_word_count.dir/read_config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4_word_count.dir/read_config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/read_config.cpp > CMakeFiles/lab4_word_count.dir/read_config.cpp.i

CMakeFiles/lab4_word_count.dir/read_config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4_word_count.dir/read_config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/read_config.cpp -o CMakeFiles/lab4_word_count.dir/read_config.cpp.s

CMakeFiles/lab4_word_count.dir/write_result.cpp.o: CMakeFiles/lab4_word_count.dir/flags.make
CMakeFiles/lab4_word_count.dir/write_result.cpp.o: ../write_result.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lab4_word_count.dir/write_result.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4_word_count.dir/write_result.cpp.o -c /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/write_result.cpp

CMakeFiles/lab4_word_count.dir/write_result.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4_word_count.dir/write_result.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/write_result.cpp > CMakeFiles/lab4_word_count.dir/write_result.cpp.i

CMakeFiles/lab4_word_count.dir/write_result.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4_word_count.dir/write_result.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/write_result.cpp -o CMakeFiles/lab4_word_count.dir/write_result.cpp.s

CMakeFiles/lab4_word_count.dir/unpack.cpp.o: CMakeFiles/lab4_word_count.dir/flags.make
CMakeFiles/lab4_word_count.dir/unpack.cpp.o: ../unpack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lab4_word_count.dir/unpack.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4_word_count.dir/unpack.cpp.o -c /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/unpack.cpp

CMakeFiles/lab4_word_count.dir/unpack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4_word_count.dir/unpack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/unpack.cpp > CMakeFiles/lab4_word_count.dir/unpack.cpp.i

CMakeFiles/lab4_word_count.dir/unpack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4_word_count.dir/unpack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/unpack.cpp -o CMakeFiles/lab4_word_count.dir/unpack.cpp.s

# Object files for target lab4_word_count
lab4_word_count_OBJECTS = \
"CMakeFiles/lab4_word_count.dir/read_file.cpp.o" \
"CMakeFiles/lab4_word_count.dir/count_words.cpp.o" \
"CMakeFiles/lab4_word_count.dir/main.cpp.o" \
"CMakeFiles/lab4_word_count.dir/merge.cpp.o" \
"CMakeFiles/lab4_word_count.dir/read_config.cpp.o" \
"CMakeFiles/lab4_word_count.dir/write_result.cpp.o" \
"CMakeFiles/lab4_word_count.dir/unpack.cpp.o"

# External object files for target lab4_word_count
lab4_word_count_EXTERNAL_OBJECTS =

lab4_word_count: CMakeFiles/lab4_word_count.dir/read_file.cpp.o
lab4_word_count: CMakeFiles/lab4_word_count.dir/count_words.cpp.o
lab4_word_count: CMakeFiles/lab4_word_count.dir/main.cpp.o
lab4_word_count: CMakeFiles/lab4_word_count.dir/merge.cpp.o
lab4_word_count: CMakeFiles/lab4_word_count.dir/read_config.cpp.o
lab4_word_count: CMakeFiles/lab4_word_count.dir/write_result.cpp.o
lab4_word_count: CMakeFiles/lab4_word_count.dir/unpack.cpp.o
lab4_word_count: CMakeFiles/lab4_word_count.dir/build.make
lab4_word_count: /usr/local/lib/libboost_filesystem.so.1.72.0
lab4_word_count: /usr/local/lib/libboost_locale.so.1.72.0
lab4_word_count: /usr/local/lib/libboost_system.so.1.72.0
lab4_word_count: /usr/local/lib/libboost_chrono.so.1.72.0
lab4_word_count: /usr/local/lib/libboost_thread.so.1.72.0
lab4_word_count: CMakeFiles/lab4_word_count.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable lab4_word_count"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab4_word_count.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab4_word_count.dir/build: lab4_word_count

.PHONY : CMakeFiles/lab4_word_count.dir/build

CMakeFiles/lab4_word_count.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab4_word_count.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab4_word_count.dir/clean

CMakeFiles/lab4_word_count.dir/depend:
	cd /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kurlyana/UCU/SEM4/ACS/lab4_word_count /home/kurlyana/UCU/SEM4/ACS/lab4_word_count /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug /home/kurlyana/UCU/SEM4/ACS/lab4_word_count/cmake-build-debug/CMakeFiles/lab4_word_count.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab4_word_count.dir/depend
