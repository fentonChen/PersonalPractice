// example of char array
#include <stdio.h>
#include <array>
#include <iostream>
#include <string>
#include <stdlib.h>


void func(std::array<std::string, 2> &array) {
    char * exa = "woshishui";
    char * exa2  = "nishishui";

    array[0] = exa;
    array[1] = exa2;
}

int main() {
    std::array<std::string, 2> array;
    func(array);
    for (int i=0; i<2; i++) {
        std::cout <<" " << array[i] << std::endl;
    }
    return 0;

}
