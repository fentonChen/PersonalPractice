//regex example of findout multi domain area from one URL and intert to a list 
#include <regex>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    std::string exm_url ("http://newsapi.sina.cn/?resource=video/location&videoId=ma158e815001008qqb&videoPlayUrl=http://ask.ivideo.sina.com.cn/v_play_ipad.php?vid=157725995&docID=ma158e815001008qqb&col=&videoCate=kandian&tags=newsapp_android&fromsinago=1&postt=news_video_recom_2&from=6068695012");

    regex reg1("\\b:\/\/([^:\/]*)");
    std::smatch m;
    std::vector<std::string> vec_str;

    while (std::regex_search (exm_url, m, reg1)) {
        for (auto x:m) 
            std::cout << x << " ";

        vec_str.push_back(m[1]);
        std::cout << std::endl;
        exm_url = m.suffix().str();
    }

    std::cout <<"####################################" << std::endl;
    for (auto iter = vec_str.begin(); iter != vec_str.end(); iter++) {
        std::cout << *iter << std::endl;
    }
}
