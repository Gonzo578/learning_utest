# Component source configuration
set (toDo_SRC src/ToDo.cc)

# Component include pathes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Component is compiled into a library
add_library(toDoCore ${toDo_SRC})

# Unit test configuration for todo component
set(ToDoTest_SRC test/ToDoTest.cc)
add_gmock_test(ToDoTest ${ToDoTest_SRC})
target_link_libraries(ToDoTest toDoCore)
