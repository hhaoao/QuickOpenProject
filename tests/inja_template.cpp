#include <iostream>
#include "project_template.hpp"

using namespace std;


int main(int argc, char *argv[])
{
  // std::cout << "输出示例" << std::endl;
  // std::cin >> v1;
  std::string template_path = "assets/template.txt";
  std::string json_path = "assets/data.json";
  std::string target_path = "assets/target.txt";

  TemplateParser Tparser;
  Tparser.write_with_json_file(template_path, json_path, target_path);
  std::string result = Tparser.read_with_json_file(template_path, json_path);
  std::cout << result << std::endl;
  return 0;
}



