file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/rein.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test_ini ${CMAKE_CURRENT_SOURCE_DIR}/read_ini.cpp)
target_link_libraries(test_ini config_file_parser_class path_function)

add_executable(test_sys_exe_path ${CMAKE_CURRENT_SOURCE_DIR}/get_exe_path.cpp)
target_link_libraries(test_sys_exe_path path_function)

add_executable(test_inja ${CMAKE_CURRENT_SOURCE_DIR}/inja_template.cpp)
target_include_directories(test_inja PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_inja project_template)

# add_executable(test_arg_parser ${CMAKE_CURRENT_SOURCE_DIR}/arg_parser.cpp)
# target_include_directories(test_arg_parser PUBLIC ${CMAKE_SOURCE_DIR}/include)
# target_link_libraries(test_arg_parser arg_parser)
