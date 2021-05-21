#ifndef DATA_HPP
#define DATA_HPP

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include "path_function.hpp"
#include "config_file_parser_class.hpp"
#include "project_template.hpp"

namespace po = boost::program_options;


struct ConfigOptionData
{
  boost::filesystem::path exe_dir_path;
  std::string templates_dir_path;
  std::string editor_path;
  std::string run_env;
  void set_config_options_data(char *[]);
};

struct UserData
{
  std::string template_name;
  std::string target_path;
  std::string command_string;
  void set_user_data(const po::variables_map &);
};

struct ShareData
{
  boost::filesystem::path templates_dir_path;
  boost::filesystem::path source_path;
  boost::filesystem::path target_path;
  boost::filesystem::path txt_editor_path;
  void set_ShareData(ConfigOptionData, UserData);

};

void set_current_path(char *[]);
void set_current_path(boost::filesystem::path &p);
boost::filesystem::path get_template_path(boost::filesystem::path, std::string);

#endif
