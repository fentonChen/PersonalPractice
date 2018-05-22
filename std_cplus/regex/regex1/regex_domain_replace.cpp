//regex example of findout domain area and replace it to an IP address
//in case of regex_replace error, the rebuild_str will be same with exm_url
#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main() {
  //char *exm_url = "http://wssource.pull.inke.cn/1526438291626693.flv";
  char *exm_url = "tcp://wssource.pull.inke.cn:80";
  regex reg1("\\b(:\/\/)([^:\/]*)\\b"); // matches words begining by "://"
  std::string replace_str = "://115.24.180.256";
  std::string rebuild_str = std::regex_replace (exm_url, reg1, replace_str.c_str());
  std::cout <<"rebuild_str = " << rebuild_str.c_str() << std::endl;
}
