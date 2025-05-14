#构建命令
macro(my_add_target name)

    # 收集普通源文件
    file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
            src/*.cpp
            src/*.h
            include/*.h
            *.rc
            *.manifest
    )

    # 添加可执行文件
    add_executable(${name} ${srcs})

    # 定义自定义模块文件集
    file(GLOB_RECURSE MODULE_FILES CONFIGURE_DEPENDS src/*.ixx)
    target_sources(${name}
            PUBLIC
            FILE_SET modules TYPE CXX_MODULES FILES
            ${MODULE_FILES}
    )

    # 添加标准库模块
    get_filename_component(STD_IXX_DIR "${STD_IXX_PATH}" DIRECTORY)
    target_sources(${name}
            PUBLIC
            FILE_SET std_modules TYPE CXX_MODULES
            BASE_DIRS "${STD_IXX_DIR}"
            FILES "${STD_IXX_PATH}"
    )

    # 确保模块目录被包含
    target_include_directories(${name} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/inluce")

endmacro()