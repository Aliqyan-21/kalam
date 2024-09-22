# Kalam Library

Kalam is a simple, easy-to-use C++ library designed for handling basic image operations such as loading, saving, and viewing images. It aims
to streamline the process of working with images by providing straightforward interfaces, allowing users to perform common tasks with minimal code and in easy way.

## Why I Created Kalam

As a developer exploring the depths of C++, I often found that many existing libraries for image handling were either too complex or required heavy dependencies, making them difficult to integrate, especially for beginners.

`Kalam` was born out of the need for a lightweight, minimalistic library that simplifies basic image operations without overwhelming the user.

## Why The Name - Kalam

The name "Kalam" has a special significance—it means "pen" in several languages, symbolizing creativity, expression, and the act of making ideas tangible. Just as a pen is a simple yet powerful tool that brings thoughts to life on paper, this library serves as a tool that simplifies and enables image handling in C++. Naming it `Kalam` reflects the library’s aim: to be a creative, intuitive tool that empowers developers to handle images effortlessly.

## Features

- Load images in common formats like PNG and JPEG/JPG.
- Save images to disk in different formats.
- Display images directly using the default system viewer without saving.
- Cross-platform compatibility with Windows, macOS, and Linux.
- Easy integration with other libraries for further image processing.

## Documentaton pdf

[docs](doc/kalam_documentation.pdf)

## Getting Started

### Requirements

- `cmake V(3.10 and above)`
- `gcc and g++ capable of running c++ 20`
- `boost library (only for windows)`

### Building and Installing

Kalam supports both dynamic and static linking.

#### Linux/macOS Installation Instructions:

1. Clone the Repository and Navigate:

```bash
git clone git@github.com:Aliqyan-21/kalam.h.git
cd kalam
```

2. Build and Install:

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
sudo cmake --install .
```

#### Windows Installation Instructions:

1. Clone the Repository and Navigate:

```bash
git clone git@github.com:Aliqyan-21/kalam.h.git
cd kalam
```

2. Build and Install:

```bash
mkdir build && cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
cmake --install . --config Release
```

## Usage

### Loading an Image

```cpp
#include "image.h"
kalam::Image img;
if (img.load("path/to/image.png")) {
    // Image loaded successfully
}
```

### Saving an Image

```cpp
img.save("path/to/save/image.png");
```

### Showing/Displaying an Image

```cpp
img.show();
```

### Compiling and Running

```bash
g++ main.cpp -o main -lkalam

./main
```

## Technical Details

- **Image Class:** Handles image data, providing load, save, and show functionalities.

- **Load and Save Modules:** Implement loading and saving functions using the stb_image library.

- **Show Function:** Displays images using the default system image viewer without requiring a save.

## Contributing

Feedback, ideas, and contributions will be appreciated that can help improve Kalam and inspire others. If you build something exciting with Kalam, consider sharing it with the community!

## License

Kalam is an open-source project available under the MIT license. You are free to use, modify, and distribute the library as per the terms of the license.
