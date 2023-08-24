cmake_minimum_required(VERSION 3.25)
project(libudsock VERSION 0.1.1)

set(CMAKE_CXX_STANDARD 17)

add_library(libudsock SHARED src/Client.cpp include/Client.hpp include/Data.hpp src/ClientException.cpp src/ClientException.hpp src/ServerException.cpp src/ServerException.hpp src/Server.cpp include/Server.hpp src/Connection.cpp include/Connection.hpp)
set_target_properties(libudsock PROPERTIES PREFIX "")
include_directories(include)

add_subdirectory(example)

set(target1 libudsock)

set(pc_req_public)

configure_file(libudsock.pc.in libudsock.pc @ONLY)

install(TARGETS libudsock)
install(FILES libudsock.pc DESTINATION lib/pkgconfig)