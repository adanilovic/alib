# include CppUTest headers
include_directories(/usr/include/CppUTest)

add_executable(RunAllTests_hashtable test_hashtable.cpp)
target_link_libraries(RunAllTests_hashtable cpputest hashtable)

set_target_properties(RunAllTests_hashtable PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

add_custom_command(TARGET RunAllTests_hashtable COMMAND ./RunAllTests_hashtable POST_BUILD)
