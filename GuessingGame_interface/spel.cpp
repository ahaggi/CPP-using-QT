#include<spel.h>


    spel::spel(){
        srand(time(NULL));

    }
    spel::~spel(){

    }


    int spel::get_antall_forsoek(){
        return antall_forsoek;
    }
    void spel::oek_antall_forsoek(){
        ++antall_forsoek;
    }
    void spel::nullstill_antall_forsoek(){
        ++antall_forsoek=0;
    }

    int spel::get_rett(){
        return rett;
    }

    int spel::get_ny_rett(){

        rett = rand() % 10;
        cout << rett << endl;
        return rett;
    }
