add_library(stack stack.c)
target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(stack PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")
add_subdirectory(test)
