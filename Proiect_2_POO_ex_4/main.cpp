#include <iostream>

using namespace std;

class Nod{
protected:
    string info;
    Nod* next;
public:
    Nod() {};//constructor de initializare
    Nod(string s, Nod* n): info(s), next(n) {};//constructor parametrizat
    Nod(const Nod &ob);//copy constructor
    virtual ~Nod()=0;
    Nod& operator=(const Nod &ob);

    friend ostream &operator << (ostream &out, const Nod &ob){
        return ob.print(out);
    }
    virtual ostream& print (ostream &out) const{
        out<<"baza\n";
        out<<info;
        return out;
    };
    //friend istream &operator >> (istream &in, Nod &ob);
    friend istream &operator >> (istream &in, Nod &ob){
        return ob.read(in);
    };
    virtual istream& read (istream &in){
        cout<<"BAZA Introduceti string\n";
        in>>info;
        return in;
    }
    void afisInfo(){ cout<<info<<"\n";}
    void setInfo(string i){ info=i;}
    string getInfo(){ return info;}
    void setNext(Nod* n){ next = n;}
    Nod* getNext(){ return next;}
};

Nod::~Nod(){
    cout<<"destructor baza\n";
    delete &info;
    delete &next;
}

Nod::Nod(const Nod &ob){
    info = ob.info;
    next = ob.next;
}

Nod& Nod::operator=(const Nod& ob){
    if(this==&ob)
        return *this;
    info = ob.info;
    next = ob.next;
    return *this;
}

/*
istream & operator >> (istream &in, Nod &ob){
    cout<<"Introduceti string: ";
    in>> ob.info;
    return in;
}*/

class Nod_dublu: public Nod{
protected:
    Nod* ante;
public:
    Nod_dublu(): Nod() {};
    Nod_dublu(string s, Nod* n, Nod* a): Nod(s,n), ante(a) {};
    Nod_dublu(const Nod_dublu &ob);
    virtual ~Nod_dublu() {cout<<"destructor dervi1\n"; delete &ante;};
    Nod_dublu& operator= (const Nod_dublu &ob);
    virtual ostream& print(ostream& out)const {
        out<<"derivata1\n";
        out<<info<<"\n";
        return out;
    }
    virtual istream& read(istream& in){
        cout<<"DERIVATA introduceti string\n";
        in>>info;
        return in;
    }
    void setAnte(Nod* a){ ante = a;}
    Nod* getAnte(){ return ante; }
    //void showInfo(){cout<<info;}
};

Nod_dublu::Nod_dublu(const Nod_dublu &ob): Nod(ob){
    ante=ob.ante;
}

Nod_dublu& Nod_dublu::operator=(const Nod_dublu& ob){
    if(this != &ob){
        (Nod&)(*this) = ob;
        ante=ob.ante;
    }
    return *this;
}

class Nod_prioritate:public Nod_dublu{
protected:
    int prio;
public:
    Nod_prioritate(): Nod_dublu() {};
    Nod_prioritate(string s, Nod* n, Nod* a, int p): Nod_dublu(s,n,a), prio(p) {};
    Nod_prioritate(const Nod_prioritate &ob);
    ~Nod_prioritate(){ cout<<"destructor deriv2\n"; delete &prio;};
    Nod_prioritate& operator=(const Nod_prioritate &ob);
    virtual ostream& print(ostream& out)const{
        out<<"derivata 2\n";
        out<<info<<" "<<prio<<"\n";
        return out;
    }
    virtual istream& read (istream& in){
        cout<<"DERIVATA2 Introduceti string:\n";
        in>>info;
        cout<<"Introduceti prioritate\n";
        in>>prio;
        return in;
    }
    void setPrio(int p){ prio=p;}
    int getPrio(){return prio;}

};

Nod_prioritate::Nod_prioritate(const Nod_prioritate& ob): Nod_dublu(ob){
    prio=ob.prio;
}

Nod_prioritate& Nod_prioritate:: operator= (const Nod_prioritate& ob){
    if(this != &ob){
        (Nod_dublu&) (*this) = ob;
        prio = ob.prio;
    }
    return *this;
}

class Coada_prioritati:public Nod_prioritate{
private:
    Nod* inc;
    Nod* ult;
public:
    Coada_prioritati();
    Coada_prioritati(Nod* i=NULL, Nod* u=NULL): inc(i), ult(u) {};
    Coada_prioritati(const Coada_prioritati& ob);
    ~Coada_prioritati(){delete inc; delete ult;};
    Coada_prioritati& operator=(const Coada_prioritati &ob);
    void insertNod(string s, int p);
    string top();
    string pop();
    void empty1();
    void Meniu();

};

Coada_prioritati::Coada_prioritati(const Coada_prioritati& ob){
    inc=ob.inc;
    ult=ob.ult;
}

Coada_prioritati& Coada_prioritati:: operator= (const Coada_prioritati& ob){
    if(this != &ob){
        inc=ob.inc;
        ult=ob.ult;
    }
    return *this;
}

void Coada_prioritati::insertNod(string s, int p){
    if(inc == NULL){
        inc = new Nod_prioritate(s,inc,inc,p);
        ult = inc;
    }
    else{
        Nod* temp = inc;
        Nod* ant;
        Nod* temp1;
        while(p< dynamic_cast<Nod_prioritate*>(temp)->getPrio() && temp != NULL){
            ant=temp;
            temp=temp->getNext();
        }
        if(temp==inc){//daca inserez pe prima poz
            cout<<"inserez...";
            temp1 = new Nod_prioritate(s,NULL,NULL,p);
            cout<<"am creat nod";
            inc=temp1;
            cout<<"am inserat";
        } else if(ant==inc){//daca inserez intre 1 si 2
            temp1 = new Nod_prioritate(s,NULL,ant,p);
            ant->setNext(temp1);
        }else if(temp->getNext()!=NULL){//daca inserez intre 2 - 3......n-1 - n
            temp1 = new Nod_prioritate(s,temp,ant,p);
            ant->setNext(temp1);
            dynamic_cast<Nod_dublu*>(temp)->setAnte(temp1);
        } else {//daca inserez dupa ultimul element
            temp1 = new Nod_prioritate(s,NULL,ant,p);
            ant->setNext(temp1);
        }
        //delete temp;
        //delete ant;
        //delete temp1;
        //Nod* temp = new Nod_prioritate()
    }
}

string Coada_prioritati::top(){
    return inc->getInfo();
}

string Coada_prioritati::pop(){
    string temps = inc->getInfo();
    Nod* tempp=inc;
    cout<<"am copiat valorile\n";
    inc = inc->getNext();
    dynamic_cast<Nod_dublu*>(inc)->setAnte(NULL);
    cout<<"am modificat pointerii\n";
    delete []tempp;
    return temps;
    //delete &temps;

}

void Coada_prioritati::empty1(){
    Nod* temp=inc->getNext();
    Nod* ant=inc;
    while(temp!=NULL){
        delete []ant;
        ant = temp;
        temp=temp->getNext();
    }
    delete []ant;
    delete inc;
    delete ult;
}

void Coada_prioritati::Meniu(){
    cout<<"Alegeti optiunea: 1. inserare, 2.top, 3.pop, 4.empty, 5.iesire\n";
    int opt;
    cin>>opt;
    while(opt!=5){
        if(opt<1||opt>5){
            cout<<"Optiune gresita";
        } else if (opt==1){
            string stemp;
            int ptemp;
            cin>>stemp;
            cin>>ptemp;
            insertNod(stemp,ptemp);
            delete &stemp;
            delete &ptemp;
        } else if (opt == 2){
            cout<<"top: "<<top();
        } else if (opt == 3) {
            cout<<"pop: "<<pop();
        } else if (opt == 4) {
            cout<<"Empty!";
            empty1();
        }
        cin>>opt;
    }
    delete &opt;
}



int main()
{
    Coada_prioritati cp(NULL,NULL);
    cp.Meniu();

}
