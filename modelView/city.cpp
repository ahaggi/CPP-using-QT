#include<city.h>

city::city(string nm, int pop, double ar){
    name = nm;
    population = pop;
    area = ar;
    cout << "name: "<< name << " pop: "<< population << " area: " << area << endl;
}
