set(GMOCK_DIR "external/googletest"
    CACHE PATH "The path to the GoogleMock test framework.")
    
add_subdirectory(${GMOCK_DIR} ${CMAKE_BINARY_DIR}/googlemock)

set_property(TARGET gtest APPEND_STRING PROPERTY COMPILE_FLAGS " -w")

include_directories(SYSTEM ${GMOCK_DIR}/googlemock/include ${GMOCK_DIR}/googletest/include)

#
# add_gmock_test(<target> <sources>...)
#
# Adds a Google Mock based test executable, <target>, build from <sources> and
# adds the test so that CTest will run it. Both the executable and the test
# will be named <target>.
#
function(add_gmock_test target)
    add_executable(${target} ${ARGN})
    target_link_libraries(${target} gmock_main)
    
    add_test(${target} ${target})
    
    add_custom_command( TARGET ${target}
                        POST_BUILD
                        COMMAND ${target} --gtest_output=xml:./${target}_report.xml
                        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                        COMMENT "Running ${target}" VERBATIM)   
endfunction()