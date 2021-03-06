project (${PROJECT})

# 指定头文件路径
include_directories("${PROJECT_SOURCE_DIR}/../tools")
include_directories("${PROJECT_SOURCE_DIR}/route")
# 指定库文件路径
link_directories("${PROJECT_BINARY_DIR}/../tools")

#C++11 support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(ROUTE_HEAD
    route/Route.h
    route/Request.h
    route/Cookie.h
    route/Params.h
    )

set(ROUTE_SRC
    route/Route.cpp
    route/Request.cpp
    route/Cookie.cpp
    route/Params.cpp
    )

set(APPS_HEAD
    apps/CIndex.h
    apps/CLogin.h
    apps/CArticle.h
    main.h
    )

set(APPS_SRC
    apps/CIndex.cpp
    apps/CLogin.cpp
    apps/CArticle.cpp
    main.cpp
    )

# 生成的可执行文件的路径
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_INSTALL_PREFIX})

# 将所有源程序编译为可执行文件
add_executable(${PROJECT}
        ${ROUTE_HEAD}
        ${ROUTE_SRC}
        ${APPS_HEAD}
        ${APPS_SRC})

target_link_libraries(${PROJECT}
        Tool
        pthread
        fcgi)


# 安装程序到${CMAKE_INSTALL_PREFIX}/bin目录
install(TARGETS ${PROJECT} RUNTIME DESTINATION bin)

# 设定安装的可执行文件所需的库文件路径，如果没有该项设置，会出错：cannot open shared object file: No such file or directory
set_property(TARGET ${PROJECT}  PROPERTY INSTALL_RPATH_USE_LINK_PATH TRUE)
