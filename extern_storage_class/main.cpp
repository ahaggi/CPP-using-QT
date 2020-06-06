#include <iostream>
#include "extern_var_util.cpp" // including the contents of a user defined file

using namespace std;


extern int count; // declaration of variable 'count' ,,, variable inne i annen fil

   int main(int argc, char *argv[])
{
       cout << "count : " << count << endl;
       count = 1;
       cout << "count : " << count << endl;
       incrementCount();
       incrementCount();
       incrementCount();
       incrementCount();
       cout << "count : " << count << endl;
       return 0;
}
