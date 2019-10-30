#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED
#include <bits/stdc++.h>
#include "Baza_de_date.h"
class Meniu: public Baza_de_date{
private:
    int opt;
public:
    void setOpt(int op){
        opt=op;
    };
    int getOpt(){
        return opt;
    };
    void meniuStart();
    void citireOpt();
    void apelareFunctie();
    void rulare();

};

#endif // MENIU_H_INCLUDED
