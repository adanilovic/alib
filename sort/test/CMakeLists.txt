# include CppUTest headers
include_directories(/usr/include/CppUTest)

# add cpputest library
add_library(cpputest STATIC IMPORTED)
set_property(TARGET cpputest PROPERTY
             IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libCppUTest.a)

add_executable(RunAllTests_sort test_mergesort.cpp)
target_link_libraries(RunAllTests_sort cpputest mergesort)

set_target_properties(RunAllTests_sort PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

add_custom_command(TARGET RunAllTests_sort COMMAND ./RunAllTests_sort POST_BUILD)
