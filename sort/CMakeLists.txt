add_library(mergesort mergesort.c)
target_include_directories(mergesort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mergesort amath)
set_target_properties(mergesort PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

if(${UNIT_TESTS})
  target_link_libraries(mergesort cpputest)
  add_subdirectory(test)
endif()
