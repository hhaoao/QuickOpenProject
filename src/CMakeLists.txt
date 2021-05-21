file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/qop.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/start.bat DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(qopenproject ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(qopenproject PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(
  qopenproject
  $<$<BOOL:${WIN32}>:ws2_32>
  path_function
  config_file_parser_class 
  data
  project_template

)

