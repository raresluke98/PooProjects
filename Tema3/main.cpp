

#include <iostream>
#include <vector>
using namespace std;

//clasa de baza examen
class Examen{
private:
    int static idCurent;
    int idExamen;
    string denumireExamen;
    int notaScrisExamen;
    int notaOralPartial;
    int extraPuncteFinal;

public:
    Examen();
    Examen(string d,int id);
    virtual ~Examen(){};
    Examen& operator= (const Examen &examen);
    friend istream & operator >> (istream &in, Examen &e );
    void setIdExamen(int i){ idExamen=i; };
    int getIdExamen()const {return idExamen;};
    void setDenumireExamen(string d) { denumireExamen=d;};
    string getDenumireExamen()const {return denumireExamen;};
    void setNotaScrisExamen(int n) { notaScrisExamen=n;}
    int getNotaScrisExamen()const { return notaScrisExamen;};
    virtual void print1(){ cout<<"Denumire examen baza:"<<denumireExamen<<"\n";};
};


Examen::Examen(){ idExamen++;};

Examen::Examen(string d, int id){
    idExamen=id;
    denumireExamen=d;
};

Examen& Examen::operator=(const Examen& ex){
    if(this==&ex)
        return *this;
    denumireExamen=ex.denumireExamen;
    notaScrisExamen=ex.notaScrisExamen;
    return *this;
}

class Notare : public Examen{
private:

public:
    Notare(){};
    Notare(const Examen &e);
    ~Notare(){};

};

Notare::Notare(const Examen &e){
    setIdExamen(e.getIdExamen());
    setDenumireExamen(e.getDenumireExamen());
}

class Elev:public Notare{
private:
    int numarMatricol;
    string nume;
    vector<Notare*> nota;
public:
    Elev(){};
    Elev(string n, int m);
    ~Elev(){};
    int getNumarMatricol()const{ return numarMatricol; };
    string getNume()const{ return nume; };
    void adaugareNote();

};

Elev::Elev(string n, int m){
    numarMatricol=m;
    nume=n;
}



template <class T>
class CatalogIndividual{
private:
    static int numarMatricol;
    int numarExamene

};



class Meniu: public Examen, public Elev, public Notare{
private:
    int opt=0;
    vector<Examen*> ex;
    vector<Elev *> el;
public:
    void optiuniMeniu();
    void rulare();
};

void Meniu::optiuniMeniu(){
    cout<<"1.Adaugare materii\n";
    cout<<"2.Adaugare elev&note\n";
    cout<<"3.Update map\n";
    cout<<"4.CatalogIndividual\n";
    cout<<"5.Afisare materii\n";
}

void Meniu::rulare(){
    optiuniMeniu();
    cin>>opt;
    int id=0;
    int matricol=100;
    while(opt!=0){
        if(opt==1){
            cout<<"Introduceti numele materiei:\n";
            string temp;
            cin>>temp;
            id++;
            ex.insert(ex.end(), new Examen(temp,id));
            delete &temp;
        }
        else if(opt ==2){
            cout<<"Introduceti numele elevului:\n";
            string temp;
            cin>>temp;
            matricol++;
            el.insert(el.end(), new Elev(temp,matricol));
            delete &temp;
            //el
            for(int i=0; i<ex.size();i++){
                cout<<"Introduceti nota la materia"<<ex[i]->getDenumireExamen()<<"\n";
                Notare* temp;
                //el[el.end()-1]->Notare(ex[i]);
            }
        }
        else if (opt== 3){
            for(int i=0;i<el.size();i++){
                cout<<el[i]->getNumarMatricol()<<" "<<el[i]->getNume()<<"\n";
            }
        }
        else if(opt==5){
            for(int i=0;i<ex.size();i++){
                cout<<ex[i]->getIdExamen()<<". "<< ex[i]->getDenumireExamen()<<"\n";
            }
        }
        optiuniMeniu();
        cin>>opt;
    }
    cout<<"Ati inchis aplicatia.\n";
}

//unordered_map<idExamen, vector<Elev>>;

int main()
{
    Meniu m;
    m.rulare();
    return 0;
}
