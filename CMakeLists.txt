cmake_minimum_required(VERSION 3.16)
project(VehicleRentalSystem VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt6 package
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Source files
set(SOURCES
    main.cpp
    Vehicle.cpp
    Car.cpp
    Bike.cpp
    RentalManager.cpp
    MainWindow.cpp
)

# Header files
set(HEADERS
    Vehicle.h
    Car.h
    Bike.h
    RentalManager.h
    MainWindow.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link Qt6 libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
