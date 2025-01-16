#include<iostream>
#include<map>
#include<list>
using namespace std;
class Aliment {
	string nume;
	float pret;
public:
	Aliment()
	{
		this->nume = "Aliment";
		this->pret = 0;
	}
	Aliment(string nume, float pret)
	{
		this->nume = nume;
		this->pret = pret;
	}
	void afisareDescriere() {
		cout << nume << "=>" << pret << endl;
	}
};
int main()
{
	//containere map- 2 elemente- <key, value>
	//cheile vor fi sortate cresc si unice
	//si la containere SET- val vor fi unice si sortate cresc

	map<string, float> preturi;
	preturi.insert(pair<string, float>("Lapte", 23));
	preturi.insert(pair<string, float>("Paine", 7));
	preturi.insert(pair<string, float>("Oua", 16));
	preturi.insert(pair<string, float>("Lapte", 35));

	//indexez map ul preturi dupa cheie(inserez alt pret la lapte, pentru ca
	// linia de mai sus de insert nu va merge(o cheie odata ce o pui, nu o mai poti schimba, ramane prima cu pretul 23)

	preturi["Lapte"] = 67;

	//begin si end- metode(begin- ret adresa de inceput, end- adr de sf)
	//for-ul la map nu incepe cu 0, pentru ca elementele sunt imprastiate in memorie
	//iterator=pointerul cu care parcurgem elementele dintr-un map

	map<string, float>::iterator it;
	it = preturi.begin();
	int suma = 0;
	while (it != preturi.end())
	{
		suma = suma + it->second;
		//trecem la poz urmatoare
		it++;
	}
	cout << "Preturi totale: " << suma << endl;
	//afisare container map:
	it = preturi.begin();
	while (it != preturi.end())
	{
		cout << it->first << "->" << it->second << endl;
		//trecem la poz urmatoare
		it++;
	}
	//container list
	list < Aliment> alimente;
	//push back sau front - adaugi elemente
	//cu insert- poti adauga la mijoc
	alimente.push_back(Aliment());
	alimente.push_back(Aliment("lapte", 20));
	alimente.push_front(Aliment("paine", 10));
	alimente.push_front(Aliment("oua", 16));
	cout << endl << "Lista: " << endl;
	list<Aliment>::iterator iter = alimente.begin();
	while (iter != alimente.end())
	{
		iter->afisareDescriere();
		iter++;
	}

	return 0;
}