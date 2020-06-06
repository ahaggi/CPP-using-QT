#include <iostream>
#include <string>
#include<bitset>

using namespace std;


void lesFlerVerdier (){
    string navn;
    int alder;

    cout << "legg merke til hvordan cin fongerer" << endl;

    cout << "Tast inn navn og alder" << endl;
    cin >> navn >> alder; // itilfellet inndate er (int og etterpå string) ==> navn=int "OK", men alder=0

    cout << "navn er:" << navn << "alder er:" << alder << endl;

}

void defaultParameters(int x, float y = 0.1){
    cout << "Note that parameters without default values must precede all the parameters with defaults; you can't skip arbitrary parameters in the middle of a function call \n\n";
    cout << "x verdi er " << x << ", y verdi er float som er "<< y << "\n";

}

void gjoerOm(int tall){
    std::bitset<8> b(tall);  //OBS int"des" to bin
    std::cout << b.to_string() << '\n'
    << b.to_string('O') << '\n'
    << b.to_string('_', 'W') << '\n';
}

/** OBS Må deklarere funksjonen før main*/
void conv();
void skrivPrefixPostfix();
void skrivUt();


int find_ch(){
    string s = "123.456";
    cout << "Denne retunerer posisjonen til et char i strengen '" << s << "', tast inn et char" << endl;
    string f;
    cin >> f;


    int found = s.find(f);

    cout << found << endl;
    return found;
}
/**         main            */

int main(int argc, char *argv[])
{
    string nylinje = "\n\n\n*******************************************\n";

    cout  << nylinje << "valg en funksjon-kall \n 1.LesFlerVerdier \n 2.Conv. \n 3.SkrivPrefixPostfix \n 4.SkrivUt  \n 5.DefaultParameters \n 6.gjør om til bin \n 7.Finn et char \n Annet. avslutt while-løkke" << endl;
    int tall;

    while (cin >> tall) {

    switch (tall) {
    case 1:
        lesFlerVerdier ();
        break;
    case 2:
        conv();
        break;
    case 3:
        skrivPrefixPostfix();
        break;
    case 4:
        skrivUt();
        break;
    case 5:
        int a;
        cout << "Tast inn en int tall \n";
        cin >> a;
        defaultParameters(a);
        break;
    case 6:{  // OBS {} for å deklarere "a" lokalt, uten parantes vil "a" blir definert i hele "switch"
        int a;
        cout << "Tast inn en int tall \n";
        cin >> a;
        gjoerOm(a);
        break;
        }
    case 7:
        find_ch();
        break;

    default:
        return 0;
        break;
    }
    cout  << nylinje << "valg en funksjon-kall \n 1.LesFlerVerdier \n 2.Conv. \n 3.SkrivPrefixPostfix \n 4.SkrivUt  \n 5.DefaultParameters \n 6.gjør om til bin \n 7.Finn et char \n Annet. avslutt while-løkke" << endl;
}

}

/*
int x1 = 27; ==> int x2(27);
auto x3={27} ==> auto x3{27}

int x = 0x2a;//hex  2a(hex) =42(des)

*/

void conv(){
    const double cmToInc = 2.45; //finale
    int lengde = 1;
    cout << "legg merke til at hvis vi taster inn en bokstav eller 0, vil while-løkke avsluttes" << endl;
    cout << "og hvis du taster '1  2  3  4  a  5',vil while løkke lese fra 1 til 4 og avsluttes etterpå." << endl;

    while(lengde != 0){
        cout << "Tast inn tallet i inch \n";
        cin >> lengde;
        cout << lengde << " inch. = " << lengde*cmToInc << " cm.\n";
    }
}

void skrivPrefixPostfix(){

    int n1 = 1;
    int n2 = ++n1;    // n2 = 2 n1 = 2
    int n3 = ++ ++n1; // n3 = 4 n1 = 4
    int n4 = n1++;    // n4 = 4 n1 = 5  OBS
//  int n5 = n1++ ++;
//  int n6 = n1 + ++n1;
    cout << "n1 = " << n1 << " \n"
         << "n2 = " << n2 << " \n"
         << "n3 = " << n3 << " \n"
         << "n4 = " << n4 << " \n";

/*
 *



    string res;
      res = "n1 = " + n1 + ' \n'
         + 'n2 = ' + n2 + '\n'
         + 'n3 = ' + n3 + '\n'
         + 'n4 = ' + n4 + '\n';
    return res;
*/
}

void skrivUt(){
    cout << "legg merke til 'for-løkkes init. variabel' , tast x for å avslutte for-løkke" << endl;
    for (string s; cin>>s && s != "x"; )
        cout << s << "\n";
}


