# Component source configuration
#set (Soundex_SRC src/Soundex.cpp)

# Component include pathes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Component is compiled into a library
#add_library(toDoCore ${toDo_SRC})

# Configure used C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Unit test configuration for todo component
set(SoundexTest_SRC test/SoundexTest.cpp)
add_gmock_test(SoundexTest ${SoundexTest_SRC})
#target_link_libraries(ToDoTest toDoCore)
