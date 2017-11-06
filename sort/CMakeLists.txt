add_library(mergesort mergesort.c)
target_include_directories(mergesort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(mergesort PROPERTIES COMPILE_FLAGS "-ggdb")
add_subdirectory(test)
