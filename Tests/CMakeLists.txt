# 设置头文件目录
include_directories("${MetaNN_PROJECT}/"
                    "${CMAKE_CURRENT_SOURCE_DIR}/")

# 添加测试工程
add_subdirectory(DataOpTest)
add_subdirectory(LayerTest)
add_subdirectory(OtherTests)