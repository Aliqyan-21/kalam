# Kalam Library

Kalam is a simple, easy-to-use C++ library designed for handling basic image operations such as loading, saving, and viewing images. It aims
to streamline the process of working with images by providing straightforward interfaces, allowing users to perform common tasks with minimal code and in easy way.

## Features

- Load images in common formats like PNG and JPEG/JPG.
- Save images to disk in different formats.
- Display images directly using the default system viewer without saving.
- Cross-platform compatibility with Windows, macOS, and Linux.
- Easy integration with other libraries for further image processing.

## Getting Started

### Requirements

- `cmake V(3.10 and above)`
- `gcc and g++ capable of running c++ 20`
- `boost library (only for windows)`

### Building and Installing

Kalam supports both dynamic and static linking. Follow the platform-specific instructions in the documentation to build and install the library.

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
