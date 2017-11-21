# Component source configuration
set (printer_SRC src/printer.cc)

# Component include pathes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Component is compiled into a library
add_library(printerCore ${printer_SRC})

# Unit test configuration for todo component
set(printerTest_SRC test/printerTest.cc)
add_gmock_test(printerTest ${printerTest_SRC})
target_link_libraries(printerTest printerCore)
