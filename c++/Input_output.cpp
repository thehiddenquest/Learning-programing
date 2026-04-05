#include <iostream>

int main(){
    std::string name;
    std::cout<<"Enter your name: ";
    std::cin>>name; // stop reading after white space
    std::cout<<"Hello "<<name;
    return 0;
}
