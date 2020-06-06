#include"epost.h"

ePost::ePost(QString t, QString sb, QString bdy){
    to = t;
    subj = sb;
    body = bdy;
}


QString ePost::tostring(){
       return to + subj + body;
}

ePost::~ePost(){
    cout << "epost blir slettet" << endl;
}
