#ifndef CONFIG_FILE_PARSER_CLASS_HPP
#define CONFIG_FILE_PARSER_CLASS_HPP

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/foreach.hpp>

#include <fstream>
#include <string>
#include <iomanip>

#include "nlohmann/json.hpp"

// <boost/property_tree/json_parser.hpp> 有bug, 估计要1.76版才能修复.
// https://github.com/boostorg/property_tree/issues/51
using namespace boost::property_tree;
using namespace nlohmann;

struct ConfigFileParser
{
  boost::property_tree::ptree tree;
  void load(const std::string &filename);
  void save(const std::string &filename);
};

struct JsonFileParser
{
  nlohmann::json tree;
  void load(const std::string &filename);
  void save(const std::string &filename);
};


#endif
