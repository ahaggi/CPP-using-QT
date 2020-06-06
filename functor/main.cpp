#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class bok{
public:
    string titel;
    int nr;
    string forfatter;

    bok(string t,int n, string f){
        titel = t;
        nr = n;
        forfatter = f;
    }

    bool operator==(bok *b2) const {
            return (*b2).nr == nr;
    }

};


class compareToTitle{
 public:
    bool operator()(bok b1, bok b2){   return b1.titel < b2.titel;   }
};

class compareToNr{
public:
   bool operator()(bok b1, bok b2){   return b1.nr < b2.nr;   }
};

class compareToForfatter{
public:
    bool operator()(bok b1, bok b2){   return b1.forfatter < b2.forfatter;   }
};



int main(int argc, char *argv[])
{

    vector<bok> v;

    for (int i = 0; i < 10; ++i) {
        string f = "forfatter"+ to_string(i%2);
        string t("titel"+to_string(10-i));
        v.push_back(bok(t, i , f));
    }
    compareToForfatter cf;
    sort(v.begin(), v.end(), [](bok b1, bok b2){   return b1.forfatter < b2.forfatter;   });
    for (vector<bok>::iterator it =v.begin() ; it!=v.end() ; ++it ) {

//        if(it!=v.end() && (*it).titel== "titel5")
//            v.erase(it);
        cout << "title " << (*it).titel << ", Nr " << (*it).nr << ", forfatter " << (*it).forfatter << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;

    vector<bok>::iterator ttt = find_if(v.begin(), v.end(), [](bok b){ return b.titel == "titel5";});
    if (ttt != v.end()) {
        cout << "title" << (*ttt).titel << ", Nr " << (*ttt).nr << ", forfatter " << (*ttt).forfatter << endl;
    }
    /** ***************************************************************************/
    bok b("qwqwqwqw",11,"foraaaaaaafatter1");
    v.push_back(b);
    v.push_back(b);
    v.push_back(b);
    bok *bb=&b;  //obs
    vector<bok>::iterator it;
    it = find(v.begin(), v.end(), bb);
 //    it = find(v.begin(), v.end(), b); her må args i "==" overloading inn i bok klasse (bok *b2) byttes med (bok b2) eller (bok &b2)
    v.erase(it);
    /** ***************************************************************************/

    compareToNr cn;
    sort(v.begin(), v.end(), cn);
    for (vector<bok>::iterator it =v.begin() ; it!=v.end() ; ++it ) {
        cout << "title " << (*it).titel << ", Nr " << (*it).nr << ", forfatter " << (*it).forfatter << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;

    compareToTitle ct;
    sort(v.begin(), v.end(), ct);
    for (vector<bok>::iterator it =v.begin() ; it!=v.end() ; ++it ) {
        cout << "title " << (*it).titel << ", Nr " << (*it).nr << ", forfatter " << (*it).forfatter << endl;
    }


    return 0;
}
