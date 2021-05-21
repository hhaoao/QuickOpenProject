#include "data.hpp"
#include "all.hpp"

int main(int argc, char *argv[])
{
  boost::filesystem::path current_path_cmd = boost::filesystem::current_path();

  po::options_description desc("quick open project.");
  po::options_description_easy_init option_next = desc.add_options();
  option_next("help", "show help.")
    ("template", po::value<std::string>(),
      "needed template.")
    ("target-path", po::value<std::string>()->default_value("."),
      "generate target's path, default: current path.")
    ("run", po::value<std::string>()->default_value(""), "run custom commands, e.g: qopenproject --run \"touch example.txt\"")
  ;

  po::positional_options_description position_desc;
  position_desc.add("target-path", -1);

  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv).
            options(desc).positional(position_desc).run(), vm);
  po::notify(vm);


  if (vm.count("help")) {
    std::cout << desc << std::endl;
  };


  if (vm.count("template")) {
    ConfigOptionData qop_ini;
    qop_ini.set_config_options_data(argv);

    UserData qop_arg;
    qop_arg.set_user_data(vm);
    
    ShareData qop_final;
    qop_final.set_ShareData(qop_ini, qop_arg);
    
    bool is_exists_source_path = boost::filesystem::exists(qop_final.source_path);
    bool is_exists_target_path = boost::filesystem::exists(qop_final.target_path);
    boost::filesystem::path qop_json_source = qop_final.source_path / "qop.json";
    boost::filesystem::path qop_json = qop_final.target_path / "qop.json";
    bool is_exists_qop_json = boost::filesystem::exists(qop_json_source);
    if ( is_exists_qop_json && is_exists_target_path) {
      boost::filesystem::copy_options over_write_or_recursive =
        boost::filesystem::copy_options::overwrite_existing | boost::filesystem::copy_options::recursive;
      boost::filesystem::copy(qop_json_source, qop_final.target_path, over_write_or_recursive);
      JsonFileParser reinJson;
      reinJson.load(qop_json.generic_string());
      reinJson.tree["this_template_path"] = qop_final.source_path.generic_string();
      reinJson.save(qop_json.generic_string());
      
    /*   boost::filesystem::copy_options over_write_or_recursive = */
    /*     boost::filesystem::copy_options::overwrite_existing | boost::filesystem::copy_options::recursive; */
    /*   boost::filesystem::copy(qop_final.source_path, qop_final.target_path, over_write_or_recursive); */
    };
    
    bool is_exists_txt_editor_path = boost::filesystem::exists(qop_final.txt_editor_path);
    if ( is_exists_qop_json && is_exists_txt_editor_path) {
      bp::system(qop_final.txt_editor_path, qop_json);
    };

    // 模板路径 对比.
    // 复制模板到当前路径, 弹出记事本修改.
  };

  if (vm.count("target-path")) {
    if (!vm.count("template") && !vm.count("help") && !vm.count("run")) {
      boost::filesystem::path target_path = boost::filesystem::path(vm["target-path"].as<std::string>());
      boost::filesystem::path config_json =
        boost::filesystem::canonical(target_path) / "qop.json";
      std::string config_json_string = config_json.generic_string();
      if (!config_json_string.empty()) {
        TemplateParser template_parser;
        std::vector<boost::filesystem::path> dir_and_files_path;
        JsonFileParser reinJson;
        reinJson.load(config_json_string);
        std::string this_template_path_string = reinJson.tree["this_template_path"];
        boost::filesystem::path this_template_path(this_template_path_string);
        for (directory_entry& x : recursive_directory_iterator(this_template_path)) {
          std::string x_path = x.path().generic_string();
          boost::filesystem::path x_path_name = x.path().filename();
          std::string x_path_name_string = x_path_name.generic_string();
          if ("qop.json" != x_path_name_string) {
            if (boost::filesystem::is_regular_file(x.path())) {
              boost::filesystem::path relative_templates_dir_path = boost::filesystem::relative(x.path(), this_template_path);

              boost::filesystem::path out_path = boost::filesystem::absolute(relative_templates_dir_path, target_path);
              boost::filesystem::path out_path_dir = out_path.lexically_normal().parent_path();
              boost::filesystem::create_directories(out_path_dir);
              boost::filesystem::copy_options over_write_or_recursive =
                boost::filesystem::copy_options::overwrite_existing | boost::filesystem::copy_options::recursive;
              boost::filesystem::copy(x.path(), out_path, over_write_or_recursive);


              /* auto out_file = /x_path_name; */
              template_parser.write_with_json_file(x_path, config_json_string, out_path.generic_string());
            } else {
              dir_and_files_path.push_back(x.path());
            }; 
          };
          
        };

        for (boost::filesystem::path y : dir_and_files_path) {
          boost::filesystem::path relative_templates_dir_path = boost::filesystem::relative(y, this_template_path);
          boost::filesystem::path out_dir_path = boost::filesystem::absolute(relative_templates_dir_path, target_path);
          std::string out_dir_path_string = out_dir_path.generic_string();
          std::string new_path = template_parser.read_with_json_string(out_dir_path_string, config_json_string);
          boost::filesystem::create_directories(new_path);
        };
        std::cout << "done." << std::endl;
      };
    };
  };

  if (vm.count("run")) {

    auto env = boost::this_process::environment();
    bp::environment env_ = env;

    ConfigOptionData qop_ini;
    qop_ini.set_config_options_data(argv);
    env_["PATH"] += {qop_ini.run_env};

    std::string run_string = vm["run"].as<std::string>();
    bp::system(run_string, env_);

  }
  
  return 0;
}


