#include "Baza_de_date.h"
#include <iostream>
#include <bits/stdc++.h>

/*void Baza_de_date::addPers(bool b){
    if(b){
        incN();
        a[getN()]= new Persoana;
        std::string nme;
        int var;
        char s;
        std::cin>>nme;
        std::cin>>var;
        std::cin>>s;
        a[getN()]->setNume(nme);
        a[getN()]->setAn(var);
        a[getN()]->setSex(s);
    }
    else{
        ifstream f;
        f.open ("datein.txt");
        a[getN()]= new Persoana;
        std::string nme;
        int var;
        char s;
        std::in>>nme;
        std::in>>var;
        std::in>>s;
        a[getN()]->setNume(nme);
        a[getN()]->setAn(var);
        a[getN()]->setSex(s);
    }
}
*/
Baza_de_date::Baza_de_date( ){
    int i;
    for(i=1;i<=n;i++){
        a[i]=NULL;
    }
}

Baza_de_date::~Baza_de_date(){
    int i;
    for(i=1;i<=n;i++){
        delete a[i];
    }
}

Persoana* Baza_de_date :: getAdress(int n){
    return a[n];
}

void Baza_de_date :: addPers(){
    incN();
    a[getN()]= new Persoana;
    std::string nme;
    int var;
    char s;
    std::cin>>nme;
    std::cin>>var;
    std::cin>>s;
    a[getN()]->setNume(nme);
    a[getN()]->setAn(var);
    a[getN()]->setSex(s);

}


void Baza_de_date :: addPers(string nme, int var, char s){
    incN();
    a[getN()]= new Persoana;
    a[getN()]->setNume(nme);
    a[getN()]->setAn(var);
    a[getN()]->setSex(s);

}

void Baza_de_date :: addPers(int n){
    incN();
    a[getN()]=new Persoana;
    a[getN()]->setNume(getAdress(n)->getNume());
    a[getN()]->setAn(getAdress()->getAn());
    a[getN()]->setAn(getAdress()->getSex());
}

void Baza_de_date :: afisPers(){
    int i;
    for(i=1;i<=getN();i++){
        std::cout<<a[i]->getNume()<<" ";
        std::cout<<a[i]->getAn()<<" ";
        std::cout<<a[i]->getSex()<<"\n";

    }
    }

void Baza_de_date::rmvPer(std::string ncaut){
    int i,del=1,gasit=0;
    while(del){
    del=0;
    i=1;
    for(i;i<=n-1&&a[i]->getNume()!=ncaut;i++)
        i++;
    if(a[i]->getNume()!=ncaut)
        {}//cout<<"Numele nu a fost gasit";
    else{
        delete a[i];
        del=1,gasit=1;
        for(i;i<=n-1;i++)
            a[i]=a[i+1];
        decN();
    }

    }
    if(gasit==0)
        std::cout<<"numele nu a fost gasit";

}

void Baza_de_date::rmvPer(int acaut){
    int i,del=1,gasit=0;
    while(del){
    del=0;
    int i=1;
    for(i;i<=n-1&&a[i]->getAn()!=acaut;i++)
        i++;
    if(a[i]->getAn()!=acaut)
        {}//cout<<"Anul nu a fost gasit";
    else{
        delete a[i];
        del=1,gasit=1;
        for(i;i<=n-1;i++)
            a[i]=a[i+1];
        decN();
    }
    }
    if(gasit==0)
        std::cout<<"numele nu a fost gasit";
}

void Baza_de_date::rmvPer(char scaut){
    int i,del=1,gasit=0;
    while(del){
    del=0;
    for(i=1;i<=n-1&&a[i]->getSex()!=scaut;i++)
        i++;
    if(a[i]->getSex()!=scaut)
        {}//cout<<"Sexul nu a fost gasit";
    else{
        delete a[i];
        del=1,gasit=1;
        for(i;i<=n-1;i++)
            a[i]=a[i+1];
        decN();
    }
    }
    if(gasit==0)
        std::cout<<"numele nu a fost gasit";
}

void Baza_de_date::afisNumeOrd(){
    int i;
    Persoana *b[100];
    Persoana *aux;
    for(i=1;i<=n;i++){
        b[i]=getAdress(i);
    }
    int j;
    for(i=1;i<=n-1;i++)
        for(j=i+1;j<=n;j++)
            if(b[i]->getNume()>b[i+1]->getNume()){
                aux=b[i];
                b[i]=b[i+1];
                b[i+1]=aux;
            }
    for(i=1;i<=n;i++){
        std::cout<<i<<" ";
        std::cout<<b[i]->getNume()<<" ";
        std::cout<<b[i]->getAn()<<" ";
        std::cout<<b[i]->getSex()<<"\n";
    }
}

void Baza_de_date::afisVarsOrd(){
    int i;
    Persoana *b[100];
    Persoana *aux;
    for(i=1;i<=n;i++){
        b[i]=getAdress(i);
    }
    int j;
    for(i=1;i<=n-1;i++)
        for(j=1;j<=n;j++)
            if(b[i]->getAn()<b[i+1]->getAn()){
                ///de scris ca mai sus, numai intre aux--b[i]
                aux=b[i];
                b[i]=b[i+1];
                b[i+1]=aux;
            }
        for(i=1;i<=n;i++){
    std::cout<<i<<" ";
    std::cout<<b[i]->getNume()<<" ";
    std::cout<<b[i]->getAn()<<" ";
    std::cout<<b[i]->getSex()<<"\n";

}
}
