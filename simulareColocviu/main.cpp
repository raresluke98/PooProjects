#include <iostream>
#include <vector>
using namespace std;

class Candidat{
private:
    string nume;
    int medieBacalaureat;
public:
    Candidat(){};
    Candidat(string n, int m);
    virtual ~Candidat(){};
    string getNume(){return nume;};
    int getMedieBacalaureat(){return medieBacalaureat;};
    virtual void afisare();
};

Candidat::Candidat(string n, int m){
    nume=n;
    medieBacalaureat=m;
}

void Candidat::afisare(){
    cout<<"Numele candidatului:"<<getNume()<<"\n";
    cout<<"Media bacalaureat:"<<getMedieBacalaureat()<<"\n";
}

class CandidatID: public Candidat{
private:
    int notaMatematica;
public:
    CandidatID(){};
    CandidatID(string n, int m, int mate);
    int getNotaMatematica(){return notaMatematica;};
    virtual  void afisare();
    virtual ~CandidatID(){};
};

CandidatID::CandidatID(string n, int m, int mate):Candidat(n,m){
    notaMatematica=mate;
}

void CandidatID::afisare(){
    cout<<"Numele candidatului:"<<getNume()<<"\n";
    cout<<"Media bacalaureat:"<<getMedieBacalaureat()<<"\n";
    cout<<"Nota matematica:"<<getNotaMatematica()<<"\n";
}

class CandidatADoua: public Candidat{
private:
    int notaAbsolvire;
public:
    CandidatADoua(){};
    CandidatADoua(string n, int m, int absolv);
    int getNotaAbsolvire (){return notaAbsolvire;};
    void afisare();
    ~CandidatADoua(){};
};

CandidatADoua::CandidatADoua(string n, int m, int absolv): Candidat(n,m){
    notaAbsolvire=absolv;
}

void CandidatADoua::afisare(){
    cout<<"Numele candidatului:"<<getNume()<<"\n";
    cout<<"Media bacalaureat:"<<getMedieBacalaureat()<<"\n";
    cout<<"Nota absolvire:"<<getNotaAbsolvire()<<"\n";
}

class CandidatADouaID: public CandidatID{
private:
    int notaAbsolvire;
public:
    CandidatADouaID(){};
    CandidatADouaID(string n, int m,int mate, int absolv);
    int getNotaAbsolvire(){ return notaAbsolvire;};
    void afisare();
    ~CandidatADouaID(){};
};

CandidatADouaID::CandidatADouaID(string n, int m, int mate, int absolv): CandidatID(n,m,mate){
    notaAbsolvire=absolv;
}

void CandidatADouaID::afisare(){
    cout<<"Numele candidatului:"<<getNume()<<"\n";
    cout<<"Media bacalaureat:"<<getMedieBacalaureat()<<"\n";
    cout<<"Nota Matematica:"<<getNotaMatematica()<<"\n";
    cout<<"Nota absolvire:"<<getNotaAbsolvire()<<"\n";
}


class Dosar:public Candidat{
private:
    int numarInregistrare;//trb incrementat

public:
    Dosar(){};
    ~Dosar(){};
};


class Meniu{
private:
    int opt;
    vector<Candidat*> ca;
    vector<Dosar*> ds;
    int numarDosar=0;
public:
    void afisareMeniu();
    void rulareMeniu();
};

void Meniu::afisareMeniu(){
    cout<<"Introduceti optiunea dorita:\n";
    cout<<"1.Adaugati candidat\n";
    cout<<"2.Afisati candidatii\n";
    cout<<"3.Dosare\n";
}

void Meniu::rulareMeniu(){
    afisareMeniu();
    cin>>opt;
    while(opt!=0){
        if(opt==1){
            cout<<"Introduceti numele:";
            string numeTemp;
            cin>>numeTemp;
            cout<<"Introduceti media la Bacalaureat";
            int medieBacTemp;
            cin>>medieBacTemp;
            cout<<"Introduceti programul de studii";
            cout<<"1.IF, 2.ID";
            int programTemp;
            cin>>programTemp;
            cout<<"Este prima sau a doua facultate? (1 sau 2)";
            int primaTemp;
            cin>>primaTemp;
            if(primaTemp==1){
                if(programTemp==1){
                    ca.insert(ca.end(),new Candidat(numeTemp,medieBacTemp));
                }
                else if(programTemp==2){
                    cout<<"Introduceti nota matematica";
                    int notaMateTemp;
                    cin>>notaMateTemp;
                    ca.insert(ca.end(),new CandidatID(numeTemp,medieBacTemp,notaMateTemp));
                    delete &notaMateTemp;
                }
            } else if(primaTemp==2){
                if (programTemp==1){
                    cout<<"Introduceti medie absolvire";
                    int medieAbsolvireTemp;
                    cin>>medieAbsolvireTemp;
                    ca.insert(ca.end(),new CandidatADoua(numeTemp,medieBacTemp,medieAbsolvireTemp));
                    delete &medieAbsolvireTemp;
                } else if (programTemp==2){
                    cout<<"Introduceti nota matematica";
                    int notaMateTemp;
                    cin>>notaMateTemp;
                    cout<<"Introduceti medie absolvire";
                    int medieAbsolvireTemp;
                    cin>>medieAbsolvireTemp;
                    ca.insert(ca.end(),new CandidatADouaID(numeTemp,medieBacTemp,notaMateTemp,medieAbsolvireTemp));
                    delete &notaMateTemp;
                    delete &medieAbsolvireTemp;
                }
            }
            delete &programTemp;
            delete &primaTemp;
            delete &numeTemp;
            delete &medieBacTemp;
        }
        else if(opt == 2){
            for(int i=0; i<ca.size();i++)
                ca[i]->afisare();
        }
        afisareMeniu();
        cin>>opt;
    }
}

int main()
{
    Meniu m;
    m.rulareMeniu();
    return 0;
}
