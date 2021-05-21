#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;


int main(int argc, char *argv[])
{
  // std::cout << "输出示例" << std::endl;
  // std::cin >> v1;
  std::string dir_path = "./123";
  boost::filesystem::recursive_directory_iterator dir_p (dir_path);
  for (auto& x : dir_p) {
    std::cout << x.path() << std::endl;
  }
  return 0;
}


