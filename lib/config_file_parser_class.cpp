#include "config_file_parser_class.hpp"

void ConfigFileParser::load(const std::string &filename)
{
  boost::property_tree::read_ini(filename, tree);
};

void ConfigFileParser::save(const std::string &filename)
{
  boost::property_tree::write_ini(filename, tree);
};

void JsonFileParser::load(const std::string &filename)
{
  std::ifstream i(filename);
  i >> tree;
};

void JsonFileParser::save(const std::string &filename)
{
  std::ofstream o(filename);
  o << std::setw(4) << tree << std::endl;
};
