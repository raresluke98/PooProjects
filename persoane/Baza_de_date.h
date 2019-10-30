#ifndef BAZA_DE_DATE_H_INCLUDED
#define BAZA_DE_DATE_H_INCLUDED
#include <bits/stdc++.h>
#include "Persoana.h"

class Baza_de_date: public Persoana{
private:
    Persoana* a[100];
    int n=0;
public:
    Baza_de_date();
    ~Baza_de_date();
    void incN(){
        n++;
    }
    void decN(){
        n--;
    }
    int getN(){
        return n;
    };
    Persoana* getAdress(int n);
    void addPers();
    void afisPers();
    void rmvPer(std::string ncaut);
    void rmvPer(int acaut);
    void rmvPer(char scaut);
    void afisNumeOrd();
    void afisVarsOrd();
};


#endif // BAZA_DE_DATE_H_INCLUDED
