#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>          // std::vector
#include <functional>    // std::greater
 
class packetCompare {
  public:
    bool operator() (int a, int b) {
      if (a > b)
        return true;
      else 
        return false;
    }
};

int main ()
{
	int myints[]= {10,60,50,50,20};
 
	std::priority_queue<int> intPQueue1 (myints, myints+5);
	std::priority_queue<int, std::vector<int>, std::greater<int> >
		intPQueue2 (myints,myints+5);
	std::priority_queue<int, std::vector<int>, packetCompare >
		intPQueue3 (myints,myints+5);
 
	std::cout << "less than: " << std::endl;
	while( !intPQueue1.empty() ){
		int pvalue = intPQueue1.top();
		std::cout << pvalue << " ";
		intPQueue1.pop(); 
	}
	std::cout << std::endl;
 
	std::cout << "bigger than: " << std::endl;
	while( !intPQueue2.empty() ){
		int pvalue = intPQueue2.top();
		std::cout << pvalue << " ";
		intPQueue2.pop(); 
	}
	std::cout << std::endl;

  std::cout << "self implement compare method, bigger than: " << std::endl;
  while( !intPQueue3.empty() ) {
    int pvalue = intPQueue3.top();
    std::cout << pvalue << " ";
    intPQueue3.pop();
  }
  std::cout << std::endl;
 
	return 0;
}

