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
    
    friend istream& operator>>(istream& in, Telefon& t);
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
istream& operator>>(istream& in, Telefon& t) {
    cout << "Introduceti numarul de contacte: ";
    in >> t.nrContacte;
    t.contacte = new string[t.nrContacte];
    for (int i = 0; i < t.nrContacte; i++) {
        cout << "Contact " << i + 1 << ": ";
        in >> t.contacte[i];
    }
    cout << "Introduceti pretul: ";
    in >> t.pret;
    cout << "Introduceti sanatatea bateriei (%): ";
    in >> t.sanatateBaterie;
    return in;
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

    friend istream& operator>>(istream& in, Laptop& l);
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

istream& operator>>(istream& in, Laptop& l) {
    cout << "Introduceti numarul de programe: ";
    in >> l.numarPrograme;
    l.programe = new string[l.numarPrograme];
    for (int i = 0; i < l.numarPrograme; i++) {
        cout << "Program " << i + 1 << ": ";
        in >> l.programe[i];
    }
    cout << "Introduceti pretul: ";
    in >> l.pret;
    cout << "Introduceti producatorul: ";
    in >> l.producator;
    return in;
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
    
    ~Smartwatch() {
        if (this->cadrane != NULL) {
            delete[] cadrane;
        }
    }
    friend istream& operator>>(istream& in, Smartwatch& s);
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
istream& operator>>(istream& in, Smartwatch& s) {
    cout << "Introduceți numărul de cadrane: ";
    in >> s.numarCadrane;
    if (s.cadrane != NULL) {
        {
            delete[] s.cadrane;
        }
        s.cadrane = new char[50];
        cout << "Introduceți tipul cadranului: ";
        in >> s.cadrane;
        cout << "Introduceți producătorul: ";
        in >> s.producator;
        cout << "Introduceți dimensiunea (mm): ";
        in >> s.dimensiune;
        cout << "Este folosit (1 - Da, 0 - Nu): ";
        in >> s.folosit;
        return in;
    }
}

int Smartwatch::numarCeas = 0;

int Telefon::numarTelefoane = 0;

int Laptop::numarLaptop = 0;

int main() {

    // Vectori de obiecte
    int n1, n2, n3;
    cout << "Introduceți numărul de telefoane: ";
    cin >> n1;
    Telefon* telefoane = new Telefon[n1];
    for (int i = 0; i < n1; i++) {
        cout << "Telefon " << i + 1 << ":\n";
        cin >> telefoane[i];
    }
    cout << "Telefoanele introduse:\n";
    for (int i = 0; i < n1; i++) {
        cout << telefoane[i];
    }

    cout << "Introduceți numărul de laptopuri: ";
    cin >> n2;
    Laptop* laptopuri = new Laptop[n2];
    for (int i = 0; i < n2; i++) {
        cout << "Laptop " << i + 1 << ":\n";
        cin >> laptopuri[i];
    }
    cout << "Laptopurile introduse:\n";
    for (int i = 0; i < n2; i++) {
        cout << laptopuri[i];
    }

    cout << "Introduceți numărul de smartwatch-uri: ";
    cin >> n3;
    Smartwatch* ceasuri = new Smartwatch[n3];
    for (int i = 0; i < n3; i++) {
        cout << "Smartwatch " << i + 1 << ":\n";
        cin >> ceasuri[i];
    }
    cout << "Smartwatch-urile introduse:\n";
    for (int i = 0; i < n3; i++) {
        cout << ceasuri[i];
    }

    // Matrice de laptopuri
    int linii, col;
    cout << "Introduceți dimensiunile matricei de laptopuri (linii și coloane): ";
    cin >> linii >> col;
    Laptop** matriceLaptopuri = new Laptop * [linii];
    for (int i = 0; i < linii; i++) {
        matriceLaptopuri[i] = new Laptop[col];
    }

    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Laptop [" << i + 1 << "][" << j + 1 << "]:\n";
            cin >> matriceLaptopuri[i][j];
        }
    }

    cout << "Matricea de laptopuri:\n";
    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < col; j++) {
            cout << matriceLaptopuri[i][j];
        }
    }

  
    if (telefoane != NULL) {
        delete[] telefoane;
    }
    if (laptopuri != NULL) {
        delete[] laptopuri;
    }
    if (ceasuri != NULL) {
        delete[] ceasuri;
    }
    if (matriceLaptopuri != NULL) {
        for (int i = 0; i < linii; i++) {
            delete[] matriceLaptopuri[i];
        }
        delete[] matriceLaptopuri;
    }
    

}