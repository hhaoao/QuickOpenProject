#include "project_template.hpp"

std::string TemplateParser::read_with_json_file(std::string template_path, std::string json_path)
{
  std::string result = env.render_file_with_json_file(template_path, json_path);
  return result;
};

void TemplateParser::write_with_json_file(std::string template_path, std::string json_path, std::string target_path)
{
  env.write_with_json_file(template_path, json_path, target_path);
};

std::string TemplateParser::read_with_json_string(std::string template_string, std::string json_path)
{
  std::ifstream i(json_path);
  i >> data;
  std::string result = env.render(template_string, data);
  return result;
};
