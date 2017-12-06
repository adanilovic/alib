add_library(stack stack.c)
target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(stack cpputest)
set_target_properties(stack PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

if(${UNIT_TESTS})
  target_link_libraries(stack cpputest)
endif()

add_subdirectory(test)
