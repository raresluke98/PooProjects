#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED
#include <bits/stdc++.h>

class Persoana{
private:
    std::string nume;
    int an;
    char sex;
public:
    void setNume(std::string a){
        nume =a;
    }
    void setAn(int b){
        an=b;
    }
    void setSex(char c){
        sex=c;
    }
    /*void setValue(string a, int b, char c){
    nume=a;
    an=b;
    sex=c;
    }
    */
    std::string getNume(){
        return nume;
    }
    int getAn(){
        return an;
    }
    char getSex(){
        return sex;
    }
};


#endif // PERSOANA_H_INCLUDED
