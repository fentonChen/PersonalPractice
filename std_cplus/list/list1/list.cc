//list.cc
#include <list>
#include <iostream>

int main() {
    std::list<int> lst1;
    for (int i=0; i<10; i++) {
      lst1.push_back(i);
    }
    for (std::list<int>::reverse_iterator it = lst1.rbegin(); 
         it != lst1.rend(); ++it) {
      std::cout <<" " << *it << std::endl;
    }
}
