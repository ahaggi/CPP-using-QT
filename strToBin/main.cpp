#include <iostream>
 #include <bitset>
using namespace std;


int skiv (unsigned int a, unsigned int b=0){
   return a<<b;

}

int main(int argc, char *argv[])
{


    bitset<8>c (skiv(1,5));
    cout << c << endl;




    bitset<8> bin = 3;
    cout   << bin.flip() << "\n";

    string str = bin.to_string(); //to binary
    cout << str << "\n";


    string str2 = (bitset<8>("01011101")).to_string();
    string res="";
    for (int var = str2.length()-1; var >=0; --var) {
        res.push_back(str2.at(var));
    }


    cout << res << "\n";

    int decimal = (bitset<8>(str)).to_ulong();
    cout << decimal << "\n";

    return 0;
}
