//example of std::string::find method use
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    std::string exm_str("http://newsapi.sina.cn/?resource=video/location&videoId=ma158e815001008qqb&videoPlayUrl=http://ask.ivideo.sina.com.cn/v_play_ipad.php?vid=157725995&docID=ma158e815001008qqb&col=&videoCate=kandian&tags=newsapp_android&fromsinago=1&postt=news_video_recom_2&from=6068695012&videoPlayUrl=http://ask2.ivideo.chobar.cn/test11.mp4");
    
    std::vector<std::string> vec;
    do {
        std::string::size_type find_pos = exm_str.find("=http://");
        if (find_pos != std::string::npos) {
            std::cout <<" position : " << find_pos << std::endl;
            std::string front_str = exm_str.substr(0,find_pos+1);
            vec.push_back(front_str);
            
            exm_str = exm_str.substr(find_pos+1);
            //std::cout << " front_str = " << front_str.c_str() << std::endl;
            //std::cout << " after_str = " << after_str.c_str() << std::endl;
            //exm_str = after_str.substr(8);
            //std::cout << " exm_str = " << exm_str.c_str() << std::endl;
        } else {
            vec.push_back(exm_str);
            break;
        }
    } while (1);

    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout <<" : " << *iter << std::endl;
    }


}
