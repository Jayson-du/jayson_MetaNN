/*
  这是一个空函数, 用CMake构建工程时, 要生成库文件或者可执行文件,
  cmake必须知道链接语言类型(头文件库本身不需要编译, 因为它们只包含模板、
  内联函数或宏定义，直接包含在用户的代码中即可使用), 如果希望生成一个库文件
  就必须让CMake知道使用什么语言进行链接, 所以定义一个void.cc文件,
  让CMake文件可以正常构建;
  避免CMake报:
    CMake Error: Cannot determine link language for target "MetaNN"
 */