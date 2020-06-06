#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::string str1 = "45";
    std::string str2 = "-3.14159";
    std::string str3 = "31337 with words"; //begynner med et tall ==> OK
    std::string str4 = "words and 2";// begkynner ikke med et tall ==> FEIL

    int myint1 = std::atoi(str1.c_str());  //OBS  ATOI kaster en "const char*" til en int
    int myint2 = std::stoi(str2);
    int myint3 = std::stoi(str3);

    // int myint4 = std::stoi(str4); // error: 'std::invalid_argument'

    std::cout << "std::atoi(\"" << str1 << "\".c_str()) is " << myint1 << '\n';
    std::cout << "std::stoi(\"" << str2 << "\") is " << myint2 << '\n';
    std::cout << "std::stoi(\"" << str3 << "\") is " << myint3 << '\n';
    //std::cout << "std::stoi(\"" << str4 << "\") is " << myint4 << '\n';



    std::string orbits ("686.97 365.24");
    std::size_t sz = orbits.size();     // alias of size_t

    float mars = std::stof (orbits,&sz);
    float earth = std::stof (orbits.substr(sz));
    cout << earth<< endl;
    std::cout << "One martian year takes " << (mars/earth) << " Earth years.\n";

}
