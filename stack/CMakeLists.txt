add_library(astack astack.c)
target_include_directories(astack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(astack cpputest)
set_target_properties(astack PROPERTIES COMPILE_FLAGS "-ggdb -Wall -Wextra -Werror")

if(${UNIT_TESTS})
  target_link_libraries(astack cpputest)
  add_subdirectory(test)
endif()
