# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\WolfNathanHW4.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\WolfNathanHW4.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\WolfNathanHW4.dir\flags.make

CMakeFiles\WolfNathanHW4.dir\main.cpp.obj: CMakeFiles\WolfNathanHW4.dir\flags.make
CMakeFiles\WolfNathanHW4.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WolfNathanHW4.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\WolfNathanHW4.dir\main.cpp.obj /FdCMakeFiles\WolfNathanHW4.dir\ /FS -c "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\main.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WolfNathanHW4.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\WolfNathanHW4.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\main.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WolfNathanHW4.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\WolfNathanHW4.dir\main.cpp.s /c "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\main.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\Knight.cpp.obj: CMakeFiles\WolfNathanHW4.dir\flags.make
CMakeFiles\WolfNathanHW4.dir\Knight.cpp.obj: ..\Knight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WolfNathanHW4.dir/Knight.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\WolfNathanHW4.dir\Knight.cpp.obj /FdCMakeFiles\WolfNathanHW4.dir\ /FS -c "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\Knight.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\Knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WolfNathanHW4.dir/Knight.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\WolfNathanHW4.dir\Knight.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\Knight.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\Knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WolfNathanHW4.dir/Knight.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\WolfNathanHW4.dir\Knight.cpp.s /c "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\Knight.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\Log.cpp.obj: CMakeFiles\WolfNathanHW4.dir\flags.make
CMakeFiles\WolfNathanHW4.dir\Log.cpp.obj: ..\Log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WolfNathanHW4.dir/Log.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\WolfNathanHW4.dir\Log.cpp.obj /FdCMakeFiles\WolfNathanHW4.dir\ /FS -c "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\Log.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\Log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WolfNathanHW4.dir/Log.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\WolfNathanHW4.dir\Log.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\Log.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\Log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WolfNathanHW4.dir/Log.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\WolfNathanHW4.dir\Log.cpp.s /c "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\Log.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\Rabbit.cpp.obj: CMakeFiles\WolfNathanHW4.dir\flags.make
CMakeFiles\WolfNathanHW4.dir\Rabbit.cpp.obj: ..\Rabbit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WolfNathanHW4.dir/Rabbit.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\WolfNathanHW4.dir\Rabbit.cpp.obj /FdCMakeFiles\WolfNathanHW4.dir\ /FS -c "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\Rabbit.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\Rabbit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WolfNathanHW4.dir/Rabbit.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\WolfNathanHW4.dir\Rabbit.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\Rabbit.cpp"
<<

CMakeFiles\WolfNathanHW4.dir\Rabbit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WolfNathanHW4.dir/Rabbit.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\WolfNathanHW4.dir\Rabbit.cpp.s /c "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\Rabbit.cpp"
<<

# Object files for target WolfNathanHW4
WolfNathanHW4_OBJECTS = \
"CMakeFiles\WolfNathanHW4.dir\main.cpp.obj" \
"CMakeFiles\WolfNathanHW4.dir\Knight.cpp.obj" \
"CMakeFiles\WolfNathanHW4.dir\Log.cpp.obj" \
"CMakeFiles\WolfNathanHW4.dir\Rabbit.cpp.obj"

# External object files for target WolfNathanHW4
WolfNathanHW4_EXTERNAL_OBJECTS =

WolfNathanHW4.exe: CMakeFiles\WolfNathanHW4.dir\main.cpp.obj
WolfNathanHW4.exe: CMakeFiles\WolfNathanHW4.dir\Knight.cpp.obj
WolfNathanHW4.exe: CMakeFiles\WolfNathanHW4.dir\Log.cpp.obj
WolfNathanHW4.exe: CMakeFiles\WolfNathanHW4.dir\Rabbit.cpp.obj
WolfNathanHW4.exe: CMakeFiles\WolfNathanHW4.dir\build.make
WolfNathanHW4.exe: CMakeFiles\WolfNathanHW4.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable WolfNathanHW4.exe"
	"C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\WolfNathanHW4.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\ENTERP~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\WolfNathanHW4.dir\objects1.rsp @<<
 /out:WolfNathanHW4.exe /implib:WolfNathanHW4.lib /pdb:"C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug\WolfNathanHW4.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\WolfNathanHW4.dir\build: WolfNathanHW4.exe

.PHONY : CMakeFiles\WolfNathanHW4.dir\build

CMakeFiles\WolfNathanHW4.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\WolfNathanHW4.dir\cmake_clean.cmake
.PHONY : CMakeFiles\WolfNathanHW4.dir\clean

CMakeFiles\WolfNathanHW4.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4" "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4" "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug" "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug" "C:\Users\Nwolf\Documents\SPRING 2020\OS\Homework\4\WolfNathanHW4\cmake-build-debug\CMakeFiles\WolfNathanHW4.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\WolfNathanHW4.dir\depend

