cmake_minimum_required(VERSION 2.8.9)

project (cyclic-dependency)
add_executable(cyclic-dependency cyclic-dependency/cyclic_dependency.cpp)
add_executable(shared_pointer cyclic-dependency/shared_pointer.cpp)
add_executable(unique_pointer cyclic-dependency/unique_pointer.cpp)
add_executable(weak_pointer cyclic-dependency/weak_pointer.cpp)

project (operating-system)
add_executable(mutex operating-system/async.cpp)
add_executable( thread operating-system/thread.cpp )

find_package( Threads )
target_link_libraries( thread ${CMAKE_THREAD_LIBS_INIT} )
target_link_libraries( mutex ${CMAKE_THREAD_LIBS_INIT} )