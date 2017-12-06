add_library(alist ${CMAKE_CURRENT_SOURCE_DIR}/private/alist.c)
target_include_directories(alist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public)
target_include_directories(alist PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/private)
set_target_properties(alist PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

if(${UNIT_TESTS})
  target_link_libraries(alist cpputest)
  add_subdirectory(test)
endif()
