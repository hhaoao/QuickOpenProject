# CMake generated Testfile for 
# Source directory: F:/shortcut/temporary-project/boost_process_tutorial
# Build directory: F:/shortcut/temporary-project/boost_process_tutorial/debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_sys_exe_path "F:/shortcut/temporary-project/boost_process_tutorial/debug/tests/test_sys_exe_path.exe")
set_tests_properties(test_sys_exe_path PROPERTIES  PASS_REGULAR_EXPRESSION "F:/shortcut/temporary-project/boost_process_tutorial/build/tests/test_sys_exe_path.exe" _BACKTRACE_TRIPLES "F:/shortcut/temporary-project/boost_process_tutorial/CMakeLists.txt;12;add_test;F:/shortcut/temporary-project/boost_process_tutorial/CMakeLists.txt;0;")
add_test(test_ini "F:/shortcut/temporary-project/boost_process_tutorial/debug/tests/test_ini.exe")
set_tests_properties(test_ini PROPERTIES  PASS_REGULAR_EXPRESSION "mimi" _BACKTRACE_TRIPLES "F:/shortcut/temporary-project/boost_process_tutorial/CMakeLists.txt;16;add_test;F:/shortcut/temporary-project/boost_process_tutorial/CMakeLists.txt;0;")
add_test(test_inja "F:/shortcut/temporary-project/boost_process_tutorial/debug/tests/test_inja.exe")
set_tests_properties(test_inja PROPERTIES  PASS_REGULAR_EXPRESSION "hello, world!" WORKING_DIRECTORY "F:/shortcut/temporary-project/boost_process_tutorial/debug/tests" _BACKTRACE_TRIPLES "F:/shortcut/temporary-project/boost_process_tutorial/CMakeLists.txt;20;add_test;F:/shortcut/temporary-project/boost_process_tutorial/CMakeLists.txt;0;")
subdirs("lib")
subdirs("src")
subdirs("tests")
