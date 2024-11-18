#include<iostream>
#include<string.h>
using namespace std;
class Bloc {
private:
	string Strada;
	int NrScari;
	int NrApartamente;
	int NrEtaje;
	bool Lift;
public:
	//constr fara parm
	Bloc() {
		this->Strada = "";
		this->NrScari = 0;
		this->NrApartamente = 0;
		this->NrEtaje = 0;
		this->Lift = 0;
	}
	//constr cu param
	Bloc(string Strada, int NrScari, int NrApartamente, int NrEtaje, bool Lift) {
		this->Strada = Strada;
		this->NrScari = NrScari;
		this->NrApartamente = NrApartamente;
		this->NrEtaje = NrEtaje;
		this->Lift = Lift;
	}
	//fctie citire
	void citire() {
		cout << "Introduceti datele blocului: " << endl;
		cout << "Nume strada: ";
		cin >> this->Strada;
		cout << "Numar Scari: ";
		cin >> this->NrScari;
		cout << "Nr. Apartamente: ";
		cin >> this->NrApartamente;
		cout << "Nr. Etaje: ";
		cin >> this->NrEtaje;
		cout << "Are lift? (1-Da, 0-Nu): ";
		cin >> this->Lift;
	}
	//afisare in prop:
	void afisare() const {
		cout << "Blocul de pe strada " << this->Strada
			<< " cu " << this->NrScari << " scari, "
			<< this->NrApartamente << " apartamente, "
			<< "are " << this->NrEtaje << " etaje si "
			<< (this->Lift ? "are" : "nu are") << " lift." << endl;
	}
};
int main() {
	int nrBlocuri = 10;
	Bloc* vector = new Bloc[nrBlocuri];
	for (int i = 0; i < nrBlocuri; i++) {
		vector[i].citire();
	}

	for (int i = 0; i < nrBlocuri; i++) {
		vector[i].afisare();
	}
	//dezalocare
	delete[] vector;
}