add_library(hashtable hashtable.c)
target_include_directories(hashtable PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(hashtable PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

if(${UNIT_TESTS})
  target_link_libraries(hashtable cpputest)
  add_subdirectory(test)
endif()
