#ifndef PROJECT_TEMPLATE_HPP
#define PROJECT_TEMPLATE_HPP


#include <string>
#include "pantor/inja.hpp"

using namespace inja;

struct TemplateParser
{
  json data;
  Environment env;
  std::string read_with_json_file(std::string, std::string);
  std::string read_with_json_string(std::string, std::string);
  void write_with_json_file(std::string, std::string, std::string);
};

#endif
