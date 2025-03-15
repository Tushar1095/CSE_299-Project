cmake_minimum_required(VERSION 3.16)

project(student_portal_management VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Add the executable
add_executable(student_portal_management
    main.cpp
    loginwindow.cpp loginwindow.h
    dashboard.cpp dashboard.h
    student_info.cpp student_info.h
    cgpa_calculator.cpp cgpa_calculator.h
    course_management.cpp course_management.h
    payment_parking.cpp payment_parking.h
)

# Link Qt6 libraries
target_link_libraries(student_portal_management PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

# Enable automatic MOC and UI processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
