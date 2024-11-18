#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
using namespace std;

class Telefon {

    string* contacte;
    float pret;
    int sanatateBaterie;
    int nrContacte;
    static int numarTelefoane;
    const int id;
public:
    Telefon() :id(++numarTelefoane) {
        this->nrContacte = NULL;
        this->contacte = NULL;
        this->pret = 2000;
        this->sanatateBaterie = 95;
    }

    Telefon(int _nrContacte, float pret, int sanatateBaterie) :id(++numarTelefoane) {
        this->nrContacte = _nrContacte;
        this->contacte = new string[_nrContacte];
        for (int i = 0; i < _nrContacte; i++) {
            this->contacte[i] = "Popa Rebeca";
        }
        this->pret = pret;
        this->sanatateBaterie = sanatateBaterie;
    }

    Telefon(const Telefon& t) :id(++numarTelefoane) {
        this->nrContacte = t.nrContacte;
        this->contacte = new string[this->nrContacte];
        for (int i = 0; i < nrContacte; i++) {
            this->contacte[i] = t.contacte[i];
        }
        this->pret = t.pret;
        this->sanatateBaterie = t.sanatateBaterie;
    }

   /* void afisareTelefon() {
        cout << "Numar telefon: " << this->id << endl;
        if (contacte != NULL) {
            cout << "Contacte:" << endl;
            for (int i = 0; i < nrContacte; i++) {
                cout << this->contacte[i] << endl;
            }
        }
        else {
            cout << "Nu exista contacte" << endl;
        }
        cout << "Pret: " << this->pret << " lei" << endl;
        cout << "Sanatate baterie:" << this->sanatateBaterie << "%" << endl << endl;
    }*/

    ~Telefon() {
        if (this->contacte != NULL) {
            delete[]this->contacte;
        }
    }
    //Operator =
    Telefon operator=(const Telefon& t) {
        if (&t != this) {
            this->nrContacte = t.nrContacte;
            for (int i = 0; i < t.nrContacte; i++)
            {
                this->contacte[i] = t.contacte[i];
            }
            this->sanatateBaterie = t.sanatateBaterie;
            this->pret = t.pret;
        }
        return *this;
    }
    // Operator +(adauga contacte noi)
    Telefon operator+(int nrContacteNoi) {
        this->nrContacte += nrContacteNoi;
        return *this;
    }

    // Operator ++(creste sanatatea bateriei)
    Telefon& operator++() {
        this->sanatateBaterie += 1;
        return *this;
    }

    // Operator <(compara preturile a doua telefoane)
    bool operator<(const Telefon& t) const {
        return this->pret < t.pret;
    }

    friend ostream& operator<<(ostream& out, const Telefon& t);
};
ostream& operator<<(ostream& out, const Telefon& t) {
    out << "Telefon ID: " << t.id << endl;
    out << "Pret: " << t.pret << endl;
    out << "Sanatate baterie: " << t.sanatateBaterie << endl;
    out << "Numar contacte: " << t.nrContacte << endl;
    if (t.contacte) {
        out << "Contacte:";
        for (int i = 0; i < t.nrContacte; i++) {
            out << "- " << t.contacte[i] << endl;
        }
    }
    else {
        out << "Fara contacte" << endl;
    }
    return out;
}


class Laptop {
private:
    string* programe;
    int numarPrograme;
    float pret;
    string producator;
    static int numarLaptop;
    const int id;
public:
    Laptop() :id(++numarLaptop) {
        this->numarPrograme = NULL;
        this->programe = NULL;
        this->pret = 2000;
        this->producator = "Asus";
    }

    Laptop(int _numarPrograme, float pret, string producator) :id(++numarLaptop) {
        this->numarPrograme = _numarPrograme;
        this->programe = new string[_numarPrograme];
        for (int i = 0; i < _numarPrograme; i++) {
            this->programe[i] = "Slack";
        }
        this->pret = pret;
        this->producator = "Asus";
    }

    Laptop(const Laptop& l) :id(++numarLaptop) {
        this->numarPrograme = l.numarPrograme;
        this->programe = new string[numarPrograme];
        for (int i = 0; i < numarPrograme; i++) {
            this->programe[i] = l.programe[i];
        }
        this->pret = l.pret;
        this->producator = l.producator;
    }
    //Operatorul =
    Laptop operator=(const Laptop& l) {
        this->numarPrograme = l.numarPrograme;
        for (int i = 0; i < numarPrograme; i++) {
            this->programe[i] = l.programe[i];
        }
        this->pret = l.pret;
        this->producator = l.producator;
        return *this;
    }


    ~Laptop() {
        if (this->programe != NULL) {
            delete[] programe;
        }
    }

    // Operator +(adauga programe noi)
    Laptop operator+(int programeNoi) {
        this->numarPrograme += programeNoi;
        return *this;
    }

    // Operator --(scade nr de programe)
    Laptop& operator--() {
        if (this->numarPrograme > 0) this->numarPrograme -= 1;
        return *this;
    }

    // Operator ==(compara producatorii a 2 laptopuri)
    bool operator==(const Laptop& l) const {
        return this->producator == l.producator;
    }
    friend ostream& operator<<(ostream& out, const Laptop& l);
};
ostream& operator<<(ostream& out, const Laptop& l) {
    out << "Laptop ID: " << l.id << endl;
    out << "Producator: " << l.producator << endl;
    out << "Pret: " << l.pret << endl;
    out << "Numar programe: " << l.numarPrograme << endl;
    if (l.programe) {
        out << "Programe:";
        for (int i = 0; i < l.numarPrograme; i++) {
            out << "- " << l.programe[i] << endl;
        }
    }
    else {
        out << "Fara programe instalate" << endl;
    }
    return out;
}

class Smartwatch {
private:
    int numarCadrane;
    char* cadrane;
    string producator;
    float dimensiune;
    bool folosit;
    static int numarCeas;
    const int id;
public:
    Smartwatch() :id(++numarCeas) {
        this->cadrane = new char[strlen("Analog") + 1];
        for (int i = 0; i < numarCadrane; i++) {
            strcpy(this->cadrane, "Analog");
        }
        this->producator = "Samsung";
        this->dimensiune = 41.8;
        this->folosit = 0;
    }

    Smartwatch(int _numarCadrane, string producator, float dimenisune, bool folosit) :id(++numarCeas) {
        this->numarCadrane = _numarCadrane;
        this->cadrane = new char[strlen("Digital") + 1];
        for (int i = 0; i < numarCadrane; i++) {
            strcpy(this->cadrane, "Digital");
        }
        this->producator = producator;
        this->dimensiune = dimenisune;
        this->folosit = folosit;
    }

    Smartwatch(const Smartwatch& s) :id(++numarCeas) {
        this->numarCadrane = s.numarCadrane;
        this->cadrane = new char[strlen(s.cadrane) + 1];
        for (int i = 0; i < numarCadrane; i++) {
            strcpy(this->cadrane, s.cadrane);
        }
        this->producator = s.producator;
        this->dimensiune = s.dimensiune;
        this->folosit = s.folosit;
    }
    //operatorul = 
    Smartwatch operator=(const Smartwatch& s) {
        this->cadrane = s.cadrane;
        for (int i = 0; i < numarCadrane; i++) {
            strcpy(cadrane, s.cadrane);
        }
        this->producator = s.producator;
        this->dimensiune = s.dimensiune;
        this->folosit = s.folosit;
        return *this;
    }
    // Operator * (schimba dim cadranului)
    Smartwatch operator*(float factor) {
        this->dimensiune *= factor;
        return *this;
    }

    // Operator ! (verif daca smart ul e folosit sau nu)
    bool operator!() const {
        return !this->folosit;
    }

    // Operator > (compara dimensiunile a 2 smartwatchuri)
    bool operator>(const Smartwatch& s) const {
        return this->dimensiune > s.dimensiune;
    }
    

    ~Smartwatch() {
        if (this->cadrane != NULL) {
            delete[] cadrane;
        }
    }
    friend ostream& operator<<(ostream& out, const Smartwatch& s);
};
ostream& operator<<(ostream& out, const Smartwatch& s) {
    out << "Smartwatch ID: " << s.id << "\n";
    out << "Producator: " << s.producator << "\n";
    out << "Dimensiune: " << s.dimensiune << " mm\n";
    out << "Folosire: " << (s.folosit ? "Da" : "Nu") << "\n";
    out << "Numar cadrane: " << s.numarCadrane << "\n";
    if (s.cadrane) {
        out << "Cadrane: " << s.cadrane << "\n";
    }
    else {
        out << "Fara cadrane disponibile\n";
    }
    return out;
}

int Smartwatch::numarCeas = 0;

int Telefon::numarTelefoane = 0;

int Laptop::numarLaptop = 0;

int main() {

    Telefon t1(3, 5000, 90), t2(2, 3000, 80);
    cout << t1;
    t1 = t2;
    t1 = t1 + 2;
    ++t1;
    if (t1 < t2) {
        cout << "Telefonul 1 este mai ieftin.";
    }
    else {
        cout << "Telefonul 2 este mai ieftin."<< endl;
    }
    
    Laptop l1(3, 7000, "Dell"), l2(2, 6000, "HP");
    l1 = l2;
    cout << l1;
    l1 = l1 + 2;
    --l1;
    if (l1 == l2) {
        cout << "Laptopurile au acelasi producator." << endl;
    }
    else {
        cout << "Laptopurile au producatori diferiti." << endl;
    }
    
    Smartwatch s1(2, "Apple", 40.5, true), s2(3, "Samsung", 44.0, false);
    cout << s1;
    s1 = s2;
    s1 = s1 * 1.1;
    if (!s1) {
        cout << "Smartwatch-ul nu este folosit." << endl;
    }
    else {
        cout << "Smartwatch - ul este folosit." << endl;
    }
    
}