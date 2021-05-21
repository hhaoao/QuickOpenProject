find_package(Boost 1.75 REQUIRED COMPONENTS
             filesystem program_options)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})

  add_library(config_file_parser_class STATIC ${CMAKE_CURRENT_SOURCE_DIR}/config_file_parser_class.cpp)
  target_include_directories(config_file_parser_class PUBLIC ${CMAKE_SOURCE_DIR}/include)

  add_library(path_function STATIC ${CMAKE_CURRENT_SOURCE_DIR}/path_function.cpp)
  target_include_directories(path_function PUBLIC ${CMAKE_SOURCE_DIR}/include)
  target_link_libraries(path_function Boost::filesystem)

  add_library(project_template STATIC ${CMAKE_CURRENT_SOURCE_DIR}/project_template.cpp)
  target_include_directories(project_template PUBLIC ${CMAKE_SOURCE_DIR}/include)

  # add_library(arg_parser STATIC ${CMAKE_CURRENT_SOURCE_DIR}/arg_parser.cpp)
  # target_include_directories(arg_parser PUBLIC ${CMAKE_SOURCE_DIR}/include)
  # target_link_libraries(arg_parser Boost::program_options)

  add_library(data STATIC ${CMAKE_CURRENT_SOURCE_DIR}/data.cpp)
  target_include_directories(data PUBLIC ${CMAKE_SOURCE_DIR}/include)
  target_link_libraries(data
    Boost::filesystem
    Boost::program_options
    path_function
    config_file_parser_class
  )


endif()
