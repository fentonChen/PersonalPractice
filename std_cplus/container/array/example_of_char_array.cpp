// example of char array
#include <stdio.h>
#include <array>
#include <iostream>
#include <string>
#include <stdlib.h>


void func(std::string *array) {
    char exa[51] = {"aawoshishui"};
    char exa2[51]  = {"aanishishui"};

    array[0] = exa;
    array[1] = exa2;
}

int main() {
    std::string array[2];
    func(array);
    for (int i=0; i<2; i++) {
        std::cout <<" " << array[i] << std::endl;
    }
    return 0;

}
