cmake_minimum_required(VERSION 3.0)

project(STcache)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)

enable_testing()

add_test(NAME test_sys_exe_path COMMAND test_sys_exe_path)
set_tests_properties(test_sys_exe_path
  PROPERTIES PASS_REGULAR_EXPRESSION "F:/shortcut/temporary-project/boost_process_tutorial/build/tests/test_sys_exe_path.exe")

add_test(NAME test_ini COMMAND test_ini)
set_tests_properties(test_ini
  PROPERTIES PASS_REGULAR_EXPRESSION "mimi")

add_test(NAME test_inja COMMAND test_inja WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests)
set_tests_properties(test_inja
  PROPERTIES PASS_REGULAR_EXPRESSION "hello, world!")
