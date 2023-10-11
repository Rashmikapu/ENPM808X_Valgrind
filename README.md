# Valgrind Exercise
This program builds a project to implement and explore Valgrind tool for memory leakage and other applications.<br>

What happens when the executable is linked statically?  Does Valgrind still detect those same bugs?
Why or why not? <br>
It may still detect issues related to memory management, such as memory leaks and invalid memory accesses.
but may not provide as detailed information about the runtime behavior and may not be able to track memory operations in the same way it does with dynamically linked executables. <br>
Explanation: <br>
Valgrind is primarily designed to analyze dynamically linked executables. It works by intercepting memory-related system calls and tracking memory operations of the running program. It can do this effectively with dynamically linked executables. When an executable is linked statically, it means that all the necessary libraries and dependencies are bundled directly into the executable, and the program runs independently of external shared libraries. 
Valgrind output for static linked executable in our case includes many references to internal library functions, such as _IO_cleanup and _IO_file_sync, which are part of the standard I/O library in C/C++. These internal library functions might be using uninitialized values, and we typically wouldn't have control over them in our code. When a program is linked statically, some of the library functions may behave differently, and Valgrind might not provide as detailed information about them as it does with dynamically linked programs.




## Standard install via command-line
```bash
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program without valgrind :
  ./build/app/shell-app
# Run valgrind on shell-app :
  valgrind --leak-check=full ./build/app/shell-app
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

