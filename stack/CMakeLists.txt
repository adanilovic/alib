add_library(astack ${CMAKE_CURRENT_SOURCE_DIR}/private/astack.c)
target_include_directories(astack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public)
target_include_directories(astack PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/private)
target_link_libraries(astack PRIVATE alist)
set_target_properties(astack PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

if(${UNIT_TESTS})
  target_link_libraries(astack PRIVATE cpputest)
  add_subdirectory(test)
endif()
