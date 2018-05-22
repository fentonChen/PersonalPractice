//regex example of findout domain area from an URL address
#include <regex>
#include <iostream>
using namespace std;

void out (bool b) {
  cout << (b ? "found" : "not found") << endl;  
}

int main() {
    //char *exm_url = "http://wssource.pull.inke.cn/live/1526438291626693.flv?ikDnsOp=1&ikHost=tx&ikOp=1&codecInfo=8192&ikLog=0&dpSrcG=26&ikDebug=1&ikMinBuf=3800&ikMaxBuf=4800&ikSlowRate=1.0&ikFastRate=1.2";
    char *exm_url = "http://wssource.pull.inke.cn/1526438291626693.flv";
    //char *exm_url = "tcp://wssource.pull.inke.cn:80";
    //char *exm_url = "tcp://wssource.pull.inke.cn";

    std::cmatch m;
    //regex reg1("[^:]*:\/\/([^:\/]*)[:\/].*");
    regex reg1("[^:]*:\/\/([^:\/]*).*");
    bool found = std::regex_search(exm_url, m, reg1);
    out(found);
    if (found) {
        cout <<"m[0] = " << m[0] << endl;
        cout <<"m[1] = " << m[1] << endl;
    }
}
