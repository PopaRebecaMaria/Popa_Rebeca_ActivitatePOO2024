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

    void afisareTelefon() {
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
    }

    ~Telefon() {
        if (this->contacte != NULL) {
            delete[]this->contacte;
        }
    }

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

    float getPret() const { 
        return this->pret; 
    }
    void setPret(float pretNou) { 
        this->pret = pretNou; 
    }

    int getSanatateBaterie() const { 
        return this->sanatateBaterie; 
    }
    void setSanatateBaterie(int sanatate) { 
        this->sanatateBaterie = sanatate; 
    }

    

    friend void verificaSanatateBaterie(const Telefon& t);
    friend void schimbPretTelefon(Telefon& t, float pretNou);

    static void getNumarTelefoane() {
        cout << "Numar total telefoane: " << numarTelefoane << endl;
    };

};
void verificaSanatateBaterie(const Telefon& t) {
    if (t.sanatateBaterie < 50) {
        cout << "Telefonul cu ID-ul " << t.id << " are o baterie slaba (sub 50%)." << endl;
    }
    else {
        cout << "Telefonul cu ID-ul " << t.id << " are o baterie buna." << endl;
    }
}

void schimbPretTelefon(Telefon& t, float pretNou) {
    t.pret = pretNou;
    cout << "Pretul telefonului a fost actualizat la " << pretNou << " lei." << endl;
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

    Laptop operator=(const Laptop& l) {
        this->numarPrograme = l.numarPrograme;
        for (int i = 0; i < numarPrograme; i++) {
            this->programe[i] = l.programe[i];
        }
        this->pret = l.pret;
        this->producator = l.producator;
        return *this;
    }

    void afisareLaptop() {
        cout << "Numar laptop: " << this->numarLaptop << endl;
        cout << "Producator: " << this->producator << endl;
        cout << "Pret: " << this->pret << endl;
        if (numarPrograme != 0) {
            cout << "Programe: " << endl;
            for (int i = 0; i < numarPrograme; i++) {
                cout << this->programe[i] << endl;
            }
            cout << endl;
        }
        else {
            cout << "Nu exista programe." << endl << endl;
        }
    }

    ~Laptop() {
        if (this->programe != NULL) {
            delete[] programe;
        }
    }

    static void getNumarLaptopuri() {
        cout << "Numar total laptopuri: " << numarLaptop << endl << endl;
    }

    float getPret() const { 
        return this->pret; 
    }
    void setPret(float pretNou) { 
        this->pret = pretNou; 
    }

    string getProducator() const { 
        return this->producator; 
    }
    void setProducator(string producatorNou) { 
        this->producator = producatorNou; 
    }

    int getNumarPrograme() const {
        return this->numarPrograme; 
    }
    void setNumarPrograme(int numar) {
        this->numarPrograme = numar;
    }

    friend void adaugaProgram(Laptop& l, string programNou);
    friend void verificaPrograme(const Laptop& l);
};
void adaugaProgram(Laptop& l, string programNou) {
    string* programeNoi = new string[l.numarPrograme + 1];
    for (int i = 0; i < l.numarPrograme; i++) {
        programeNoi[i] = l.programe[i];
    }
    programeNoi[l.numarPrograme] = programNou;
    if (l.programe != NULL) {
        delete[] l.programe;
    }
    l.programe = programeNoi;
    l.numarPrograme++;
    cout << "Programul " << programNou << " a fost ad?ugat cu succes!" << endl;
}

void verificaPrograme(const Laptop& l) {
    if (l.numarPrograme == 0) {
        cout << "Laptopul nu are programe instalate." << endl;
    }
    else {
        cout << "Laptopul are " << l.numarPrograme << " programe instalate." << endl;
    }
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

    void afisareSmartwatch() {
        cout << "Numar smartwatch: " << numarCeas << endl;
        cout << "Producator: " << producator << endl;
        cout << "Dimensiune: " << dimensiune << endl;
        if (cadrane != NULL) {
            cout << "Cadrane: " << endl;
            for (int i = 0; i < numarCadrane; i++) {
                cout << this->cadrane << endl;
            }
        }
        else {
            cout << "Nu are cadrane salvate." << endl;
        }
        cout << "Folosit: ";
        if (folosit) {
            cout << "da" << endl << endl;
        }
        else {
            cout << "nu" << endl << endl;
        }
    }

    ~Smartwatch() {
        if (this->cadrane != NULL) {
            delete[] cadrane;
        }
    }

    static void getNumarSmartwatchuri() {
        cout << "Numar total smartwatchuri: " << numarCeas << endl << endl;
    }

    int getNumarCadrane() const {
        return this->numarCadrane; 
    }
    void setNumarCadrane(int numar) { 
        this->numarCadrane = numar; 
    }

    const char* getCadrane() const { 
        return this->cadrane; 
    }
    void setCadrane(const char* tipCadran) {
        if (this->cadrane != nullptr) {
            delete[] this->cadrane;
        }
        this->cadrane = new char[strlen(tipCadran) + 1];
        strcpy(this->cadrane, tipCadran);
    }

    string getProducator() const { 
        return this->producator; 
    }
    void setProducator(string producatorNou) { 
        this->producator = producatorNou; 
    }

    float getDimensiune() const {
        return this->dimensiune; 
    }
    void setDimensiune(float dimensiuneNoua) { 
        this->dimensiune = dimensiuneNoua; 
    }

    bool isFolosit() const { 
        return this->folosit; 
    }
    void setFolosit(bool status) { 
        this->folosit = status; 
    }

    friend void schimbaCadran(Smartwatch& s, const char* tipCadranNou);
    friend void verificaFolosire(const Smartwatch& s);
};
void schimbaCadran(Smartwatch& s, const char* tipCadranNou) {
    s.setCadrane(tipCadranNou);
    cout << "Cadranul smartwatch-ului a fost schimbat în " << tipCadranNou << "!" << endl;
}

void verificaFolosire(const Smartwatch& s) {
    cout << "Smartwatch-ul este " << (s.folosit ? "folosit" : "nefolosit") << "." << endl;
}

int Smartwatch::numarCeas = 0;

int Telefon::numarTelefoane = 0;

int Laptop::numarLaptop = 0;

int main() {

    Telefon telefon1;
    telefon1.afisareTelefon();

    Telefon telefon2(3, 3500, 85);
    telefon2.afisareTelefon();

    verificaSanatateBaterie(telefon2);
    schimbPretTelefon(telefon2, 3000);
    telefon2.afisareTelefon();

    Telefon::getNumarTelefoane();

    int nr;
    Telefon::getNumarTelefoane();

   

    Laptop laptop1;
    laptop1.afisareLaptop();

    Laptop laptop2(3, 4500.50, "Dell");
    laptop2.afisareLaptop();

    adaugaProgram(laptop2, "Microsoft Office");
    laptop2.afisareLaptop();

    verificaPrograme(laptop2);

    Laptop::getNumarLaptopuri();

 
    Smartwatch s1;
    s1.afisareSmartwatch();

    Smartwatch s2(2, "Apple", 45.5, true);
    s2.afisareSmartwatch();

    schimbaCadran(s2, "Analog");
    s2.afisareSmartwatch();

    verificaFolosire(s2);

    Smartwatch s3(s2);
    s3.afisareSmartwatch();


    Smartwatch::getNumarSmartwatchuri();
}