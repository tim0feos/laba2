#include <iostream>
#include "calkmake.h"

int main(int argc, char** argv){
    std::string str;
    if(argv[1] != NULL) str = argv[1];
    else str = "none";
    std::cout<<calk(str)<<std::endl;
    return 0;
}