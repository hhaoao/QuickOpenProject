#include "data.hpp"

void set_current_path(char *argv[])
{
  boost::filesystem::path exe_path = get_executable_path(argv);
  boost::filesystem::path exe_dir = exe_path.remove_filename();
  boost::filesystem::current_path(exe_dir);
};

void set_current_path(boost::filesystem::path &p)
{
  boost::filesystem::current_path(p);
};

boost::filesystem::path get_template_path(boost::filesystem::path templates_dir_path, std::string specified_template_name)
{
  boost::filesystem::path specified_template_path;
  for (boost::filesystem::directory_entry &x : directory_iterator(templates_dir_path)) {
    auto current_template_name = x.path().filename();
    if (current_template_name == specified_template_name) {
      specified_template_path = x.path();
      break;
    };
  };

  return specified_template_path;
};

void ConfigOptionData::set_config_options_data(char *argv[])
{
  auto cwd = boost::filesystem::current_path();
  set_current_path(argv);
  exe_dir_path = boost::filesystem::current_path();
  ConfigFileParser reinIni;
  reinIni.load("./qop.ini");

  templates_dir_path = reinIni.tree.get<std::string>("qop.templates_dir_path");

  boost::optional<std::string> editor = reinIni.tree.get_optional<std::string>("qop.editor");
  
  if (!editor)
  {
    editor_path = "start.bat";
  } else {
    editor_path = *editor;
  };

  run_env = reinIni.tree.get<std::string>("qop.run_env");
  set_current_path(cwd);
};

void UserData::set_user_data(const po::variables_map &vm)
{
  template_name = vm["template"].as<std::string>();
  target_path = vm["target-path"].as<std::string>();
  command_string = vm["run"].as<std::string>();
};

void ShareData::set_ShareData(ConfigOptionData qop_ini, UserData qop_arg){
  boost::filesystem::path p(qop_ini.templates_dir_path);
  templates_dir_path = boost::filesystem::canonical(p);
  source_path = get_template_path(templates_dir_path, qop_arg.template_name);
  target_path = boost::filesystem::canonical(boost::filesystem::path(qop_arg.target_path));
  txt_editor_path = boost::filesystem::canonical(boost::filesystem::path(qop_ini.editor_path), qop_ini.exe_dir_path);

};
