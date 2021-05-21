#include "path_function.hpp"


boost::filesystem::path get_executable_path(char *argv[])
{
  std::string argv_exe(argv[0]);
  boost::filesystem::path exe_path = boost::filesystem::system_complete(argv_exe);
  return exe_path;
};
