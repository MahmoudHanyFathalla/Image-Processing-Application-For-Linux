# Qt & OpenCV-Based Image Processing Application

## Overview
This project is a **Qt-based GUI application** that utilizes **OpenCV** to load, display, and manipulate images. The application provides functionalities for image navigation, zooming, and interaction through mouse and keyboard events. It integrates **perspective transformations** and **image comparison metrics (IOA & IOU)** for advanced processing.

![Snake Game](imG.PNG)

## Features
- **Qt GUI Interface**: Intuitive graphical interface for user interaction.
- **Image Navigation**: Browse through images using a horizontal slider.
- **Zoom & Interaction**: Click to zoom on specific points, manipulate images using mouse and keyboard.
- **Perspective Transformation**: Apply transformations to images and compare them.
- **IOA & IOU Calculation**: Computes Intersection over Area (IOA) and Intersection over Union (IOU) between images.
- **Localization Support**: Supports multiple languages using Qt Linguist (`.ts` files).

## Prerequisites
Ensure you have the following dependencies installed:

### Required Software:
- **Qt 5.15 or later** (with Qt Widgets module)
- **OpenCV 4.5 or later**
- **CMake 3.10 or later**
- **A C++17 compatible compiler** (GCC, Clang, MSVC)

### Installation Instructions:
#### Install Qt
```sh
sudo apt update
sudo apt install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
```

#### Install OpenCV
```sh
sudo apt install libopencv-dev
```

## Compilation and Execution

### Build the Project
```sh
mkdir build && cd build
cmake ..
make
```

### Run the Application
```sh
./untitled
```

## Code Structure
```
├── CMakeLists.txt           # CMake build configuration
├── main.cpp                 # Application entry point
├── mainwindow.cpp           # Main window logic
├── mainwindow.h             # Main window header file
├── mainwindow.ui            # UI file for Qt Designer
├── playground.cpp           # Playground dialog logic
├── playground.h             # Playground dialog header file
├── playground.ui            # Playground UI
├── predtoreal.cpp           # Perspective transformation logic
├── predtoreal.h             # Perspective transformation header file
├── predtoreal.ui            # Perspective transformation UI
├── real.cpp                 # Image processing logic
├── real.h                   # Image processing header file
├── real.ui                  # Image processing UI
├── realtopred.cpp           # Reverse transformation logic
├── realtopred.h             # Reverse transformation header file
├── realtopred.ui            # Reverse transformation UI
├── img.qrc                  # Resource file for images
├── untitled_en_GB.ts        # Translation file
```

## Functionality

### **Main Window (mainwindow.cpp, mainwindow.h, mainwindow.ui)**
- **Image Loading**: Loads and displays images using OpenCV.
- **Event Handling**: Captures mouse and keyboard events for interaction.
- **Slider & Buttons**: Allows image navigation, zooming, and transformations.

### **Playground Dialog (playground.cpp, playground.h, playground.ui)**
- **Image Display**: Displays an image inside a separate window.
- **Image Updates**: Updates and processes the displayed image.

### **Perspective Transformation (predtoreal.cpp, realtopred.cpp)**
- **Apply Perspective Transformation**: Uses OpenCV to transform images.
- **IOA & IOU Calculation**:
  - Computes **Intersection over Area (IOA)**.
  - Computes **Intersection over Union (IOU)**.

### **Image Processing & Transformation**
- **OpenCV Integration**: Uses OpenCV for image processing (grayscale, thresholding, resizing).
- **Folder Selection**: Loads images from a specified directory.
- **Point Extraction**: Reads transformation points from a text file.
- **Real-Time Updates**: Applies transformations and updates images dynamically.

## REST API Endpoints (Future Enhancements)

The project can be extended to include a RESTful API for remote image processing using Pistache.

## Possible Enhancements
- **Database Integration**: Store and retrieve image data.
- **WebSocket Support**: Enable real-time image processing feedback.
- **Authentication System**: Secure the application with user authentication.
- **Cross-Platform Deployment**: Package the application for Windows, Linux, and macOS.

## Author
**Mahmoud Hany** - Computer Engineering Student & AI Enthusiast

## License
This project is licensed under the MIT License.

