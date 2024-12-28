cmake_minimum_required(VERSION 3.10)
project(rtmp-stream)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SUPPRESS_REGENERATION true)

# Add the source file for the executable
add_executable(rtmp-stream ${PROJECT_SOURCE_DIR}/src/rtmp-stream.cpp)

# Include directories for OpenCV
include_directories(F:/opencv/mingw_build/install/include)

# Include directories for FFmpeg
include_directories(F:/ffmpeg-master-latest-win64-gpl-shared/include)

# Link libraries for OpenCV
target_link_libraries(rtmp-stream
        F:/opencv/mingw_build/install/x64/mingw/lib/libopencv_core460.dll.a
        F:/opencv/mingw_build/install/x64/mingw/lib/libopencv_videoio460.dll.a
        F:/opencv/mingw_build/install/x64/mingw/lib/libopencv_imgproc460.dll.a
)

# Link with the FFmpeg import libraries (e.g., libavcodec.dll.a, libavformat.dll.a)
target_link_libraries(rtmp-stream
        F:/ffmpeg-master-latest-win64-gpl-shared/lib/libavcodec.dll.a
        F:/ffmpeg-master-latest-win64-gpl-shared/lib/libavdevice.dll.a
        F:/ffmpeg-master-latest-win64-gpl-shared/lib/libavfilter.dll.a
        F:/ffmpeg-master-latest-win64-gpl-shared/lib/libavformat.dll.a
        F:/ffmpeg-master-latest-win64-gpl-shared/lib/libavutil.dll.a
        F:/ffmpeg-master-latest-win64-gpl-shared/lib/libpostproc.dll.a
        F:/ffmpeg-master-latest-win64-gpl-shared/lib/libswresample.dll.a
        F:/ffmpeg-master-latest-win64-gpl-shared/lib/libswscale.dll.a
)

# Collect all include directories and libraries
target_include_directories(rtmp-stream PUBLIC  ${PROJECT_SOURCE_DIR}/include)
