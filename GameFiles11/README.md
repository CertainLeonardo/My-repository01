# 3D Raylib Project

A lightweight 3D graphics application built using C++ and the raylib library. This project demonstrates basic 3D rendering, camera controls, and input handling.

## Features

* **3D Camera System:** First-person or third-person camera perspective.
* **Basic Shapes:** Rendering of cubes, spheres, and custom 3D primitives.
* **Input Handling:** Smooth keyboard and mouse controls for navigation.
* **Performance:** High frame rate rendering with minimal overhead.

## Prerequisites

Before building the project, ensure you have the following installed:

* A C++ compiler (GCC, Clang, or MSVC)
* CMake (version 3.10 or higher)
* [raylib](https://raylib.com) (version 4.5 or higher)

## Installation & Building

1. **Clone the repository:**
   ```bash
   git clone https://github.com
   cd your-repo-name
   ```

2. **Create a build directory:**
   ```bash
   mkdir build && cd build
   ```

3. **Configure and build the project:**
   ```bash
   cmake ..
   cmake --build .
   ```

4. **Run the executable:**
   ```bash
   ./my_raylib_project
   ```

## Controls

* **W/A/S/D:** Move the camera or character.
* **Mouse:** Look around (rotate camera).
* **Spacebar:** Jump / Move upward.
* **Escape:** Close the application.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
