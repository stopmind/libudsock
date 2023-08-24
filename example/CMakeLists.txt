add_executable(example-server serverMain.cpp)
add_executable(example-client clientMain.cpp)

target_link_libraries(example-server libudsock)
target_link_libraries(example-client libudsock)