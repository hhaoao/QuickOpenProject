#include <iostream>
#include "path_function.hpp"
using namespace std;


int main(int argc, char *argv[])
{
  // std::cout << "输出示例" << std::endl;
  // std::cin >> v1;
  boost::filesystem::path exe_path = get_executable_path(argv);
  std::cout << exe_path.generic_string() << std::endl;
  return 0;
}


