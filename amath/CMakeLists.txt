add_library(amath amath.c)
target_include_directories(amath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(amath PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")
add_subdirectory(test)
