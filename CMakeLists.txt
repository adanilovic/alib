PROJECT(alib)
cmake_minimum_required(VERSION 3.5)

if(${BUILD_TYPE})
  set(CMAKE_BUILD_TYPE ${BUILD_TYPE})
else()
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(${UNIT_TESTS})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include /usr/include/CppUTest/MemoryLeakDetectorMallocMacros.h")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include /usr/include/CppUTest/MemoryLeakDetectorMallocMacros.h")

  # add cpputest library
  add_library(cpputest STATIC IMPORTED)
  set_property(TARGET cpputest PROPERTY
              IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libCppUTest.a)
endif()

add_subdirectory(amath)
add_subdirectory(alist)
add_subdirectory(sort)
add_subdirectory(stack)
add_subdirectory(hashtable)
