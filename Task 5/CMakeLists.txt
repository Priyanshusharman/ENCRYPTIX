project(image_processing)

# Specify the path to the OpenCV installation
set(OpenCV_DIR "C:/opencv/build")

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} image_processing.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
