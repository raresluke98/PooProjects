#include "Meniu.h"
#include <iostream>
#include <bits/stdc++.h>

void Meniu::meniuStart(){
    std::cout<<"Introduceti numarul optiunii dorite:\n";
    std::cout<<"1. Adaugare persoana\n";
    std::cout<<"2. Eliminare persoana dupa nume\n";
    std::cout<<"3. Eliminare persoana dupa varsta\n";
    std::cout<<"4. Eliminare persoana dupa sex\n";
    std::cout<<"5. Afisare persoane in ordine alfabetica \n";
    std::cout<<"6. Afisare persoane dupa varsta \n";
    std::cout<<"7. Inchidere";
    std::cout<<"\n";
}

void Meniu::citireOpt(){
    int a;
    std::cin>>a;
    setOpt(a);
}

void Meniu::apelareFunctie(){
    if(getOpt()==1){
        std::cout<<"Ai apelat functia 1\n";
        addPers();
        afisPers();
    }
    else if(getOpt()==2){
        std::cout<<"Ai apelat functia 2\n";
        std::string ntemp;
        std::cin>>ntemp;
        rmvPer(ntemp);
        afisPers();
    }
    else if(getOpt()==3){
        std::cout<<"Ai apelat functia 3\n";
        int vtemp;
        std::cin>>vtemp;
        rmvPer(vtemp);
        afisPers();
    }
    else if(getOpt()==4){
        std::cout<<"Ai apelat functia 4\n";
        char stemp;
        std::cin>>stemp;
        rmvPer(stemp);
        afisPers();
    }
    else if(getOpt()==5){
        std::cout<<"Ai apelat functia 5\n";
        afisNumeOrd();
        //afisPers();
    }
    else if(getOpt()==6){
        std::cout<<"Ai apelat functia 6\n";
        afisVarsOrd();
    }
    /*else if(getOpt()==7){
        cout<<"ai parasit programul\n";
    }*/
    else{
        std::cout<<"Optiune gresita\n";
    }
}

void Meniu::rulare(){
    meniuStart();
    citireOpt();
    while(getOpt()!=7){
        apelareFunctie();
        citireOpt();
    }
    if(getOpt()==7)
        std::cout<<"Ai parasit programul\n";
}
