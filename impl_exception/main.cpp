#include <iostream>

using namespace std;

class ex :public exception{

public:
    int num;
    ex(int n):num(n){

    }

    const char* what() const throw() {
        string er = to_string(num) +  "error error error...";

        char* c = new char[er.length()];
        copy(er.begin() , er.end() , c);
//        cout << s.data() << endl;
        return c;
    }
};

int main(int argc, char *argv[])
{

    try{
        throw ex(123);
    }catch(ex e){
        cout << e.what() << endl;
    }

    return 0;
}
