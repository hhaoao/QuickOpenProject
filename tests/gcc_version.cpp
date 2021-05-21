#include <boost/process/system.hpp>
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
  // std::cout << "输出示例" << std::endl;
  // std::cin >> v1;
  std::cout << std::system("gcc --version") << std::endl;
  return 0;
}



