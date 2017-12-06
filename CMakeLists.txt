PROJECT(alib)
cmake_minimum_required(VERSION 3.5)

if(${UNIT_TESTS})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include /usr/include/CppUTest/MemoryLeakDetectorMallocMacros.h")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include /usr/include/CppUTest/MemoryLeakDetectorMallocMacros.h")
endif()

add_subdirectory(amath)
add_subdirectory(alist)
add_subdirectory(sort)
add_subdirectory(stack)
add_subdirectory(hashtable)
