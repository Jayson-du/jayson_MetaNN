# 设置头文件目录
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/")

# 通过CMake内置的file函数将.h文件与.cpp文件分离,
# ${CMAKE_CURRENT_SOURCE_DIR}为当前目录
# 递归查找当前项目include下的所有.h文件
file(GLOB_RECURSE HeaderFile
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HeaderFile})

# 设置静态库输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# 库项目添加文件
add_library(MetaNN STATIC
            ${HeaderFile}
            void.cc)