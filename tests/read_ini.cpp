#include <iostream>
#include "path_function.hpp"
#include "config_file_parser_class.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  // std::cout << "输出示例" << std::endl;
  // std::cin >> v1;
  boost::filesystem::path exe_path = get_executable_path(argv);
  boost::filesystem::path exe_dir = exe_path.remove_filename();
  boost::filesystem::path ini_path = exe_dir / "rein.ini";
  ConfigFileParser reinIni;
  /* std::string file_name = "./rein.ini"; */
  reinIni.load(ini_path.generic_string());
  std::string string_name = reinIni.tree.get<std::string>("filename.{{name}}");
  std::cout << string_name << std::endl;
  return 0;
}



