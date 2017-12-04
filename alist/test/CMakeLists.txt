# include CppUTest headers
include_directories(/usr/include/CppUTest)

# add cpputest library
add_library(cpputest STATIC IMPORTED)
set_property(TARGET cpputest PROPERTY
             IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libCppUTest.a)

add_executable(RunAllTests_alist test_alist.cpp)
target_link_libraries(RunAllTests_alist cpputest alist)

set_target_properties(RunAllTests_alist PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

#add_custom_command(TARGET RunAllTests_alist COMMAND ./RunAllTests_alist POST_BUILD)
