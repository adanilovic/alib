# include CppUTest headers
include_directories(/usr/include/CppUTest)

add_executable(RunAllTests_stack test_stack.cpp)
target_link_libraries(RunAllTests_stack cpputest astack)

set_target_properties(RunAllTests_stack PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

add_custom_command(TARGET RunAllTests_stack COMMAND ./RunAllTests_stack POST_BUILD)
