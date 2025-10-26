# 设置工程名
set (CURRENT_PROJECT_NAME OtherTests)

# 设置头文件目录
include_directories("${MetaNN_PROJECT}/"
                    "${CMAKE_CURRENT_SOURCE_DIR}/")

# 查找指定目录下的所有头文件
file(GLOB_RECURSE headerfile
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    )
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${headerfile})

# 查找指定目录下的所有源文件
file(GLOB_RECURSE sourceFile
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    )

# 设置依赖项
# link_directories("${PROJECT_BINARY_DIR}")
# link_libraries(MetaNN)

# 项目添加文件
add_executable(OtherTests
              ${headerfile}
              ${sourceFile}
)