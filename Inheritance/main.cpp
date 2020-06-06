#include <iostream>

using namespace std;

class Shape {
protected:
    int width, height;
public:
    Shape( int a, int b) {
        width = a;
        height = b;
        cout << "Parent class konst" <<endl;

    }
    virtual int area(){ //OBS må ha "virtual" med
        cout << "Parent class area :" <<endl;
        return 0;
    }
};
class Rectangle: public Shape{
public:
    Rectangle( int a, int b):Shape(a, b){
        //          Shape(a, b);  OBS feil
        cout << "Rectangle class konst" <<endl;


    }
    int area (){
        cout << "Rectangle class area :" <<endl;
        return (width * height);
    }
};
class Triangle: public Shape{
public:
    Triangle( int a, int b):Shape(a, b){
        cout << "Triangle class konst" <<endl;

    }
    int area () {
        cout << "Triangle class area :" <<endl;
        return (width * height / 2);
    }
};

int main(int argc, char *argv[])
{
    Shape* shape;
    Rectangle rec(10,5);
    Triangle tri(10,10);

    //setter pekeren shape til å peke på Rectangle
    shape = & rec;

    //regne ut "rec" sin areale
    cout << "The area "<< shape->area()<<endl;

    //setter pekeren shape til å peke på Tringle
    shape = & tri;

    // regn ut "tri" sin areale
    cout << "The area "<< shape->area()<<endl;

    /*  The arrow operator (->)

struct movies_t {
  string title;
  int year;
};

movies_t amovie;
movies_t * pmovie;

pmovie = &amovie;
pmovie->title   equivalent to (*pmovie).title

Here amovie is an object of structure type movies_t, and pmovie is a pointer to point to objects of structure type movies_t.
Therefore, the following code would also be valid:

The arrow operator (->) is a dereference operator that is used exclusively with pointers to objects that have members.
This operator serves to access the member of an object directly from its address

OBS
Both expressions, pmovie->title and (*pmovie).title are valid, and both access the member title of the data structure pointed by
a pointer called pmovie. It is definitely something different than:

*pmovie.title   which is rather equivalent to:   *(pmovie.title)

This would access the value pointed by a hypothetical pointer member called title of the structure object pmovie
(which is not the case, since title is not a pointer type). The following panel summarizes possible combinations of
the operators for pointers and for structure members:


            */
    return 0;
}
