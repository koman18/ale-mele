#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

enum tipProdus{
	Normal = 1, Vegetarian = 2, Vegan = 3
		
};

class Produs {
private:
	const int idProdus;
	const string codProdus;
	string nume;
	tipProdus tip;
	char* producator;
	float pret;
	int nrIngrediente;
	string* denumireIngrediente;
	float* gramajIngrediente;
	bool dePost;
	static int contor;
	static int TVA;//va fi procentul
public:
	//default
	Produs() :idProdus(contor++), codProdus("AAAA") {
		this->nume = "Necunoscut";
		this->tip = Normal;
		this->producator = new char[strlen("Anonim") + 1];
		strcpy(producator, "Anonim");
		this->pret = 0;
		this->nrIngrediente = 0;
		this->denumireIngrediente = nullptr;
		this->gramajIngrediente = nullptr;
		this->dePost = 0;
	}

	//constructor cu 3 parametrii
	Produs(int nrIngrediente, string* denumireIngrediente, float* gramajIngrediente) :idProdus(contor++), codProdus("AAAAAA") {
		this->nrIngrediente = nrIngrediente;
		this->denumireIngrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->denumireIngrediente[i] = denumireIngrediente[i];
		}
		this->gramajIngrediente = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->gramajIngrediente[i] = gramajIngrediente[i];
		}
	}
	

	//constructorul cu tot parametrii
	Produs(string codProdus, string nume, tipProdus tip, const char* producator, float pret, int nrIngrediente, string* denumireIngrediente, float* gramajIngrediente, bool dePost) :idProdus(contor++), codProdus(codProdus) {
		this->nume = nume;
		this->tip = tip;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);

		this->pret = pret;
		this->nrIngrediente = nrIngrediente;

		this->denumireIngrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->denumireIngrediente[i] = denumireIngrediente[i];
		}

		this->gramajIngrediente = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->gramajIngrediente[i] = gramajIngrediente[i];
		}

		this->dePost = dePost;
	}

	//getteri
	const int getIdProdus() {
		return this->idProdus;
	}

	const string getCodProdus() {
		return this->codProdus;
	}

	string getNume() {
		return this->nume;
	}

	/*tipProdus getTip() {
		return this->tip;
	}*/
	//se afiseasa urat

	string getTip() {
		switch (this->tip) {
		case 1:return "Normal"; break;
		case 2:return "Vegetarian"; break;
		case 3:return "Vegan"; break;
		default: return "Normal"; break;
		}
	}

	char* getProducator() {
		char* copie = new char[strlen(producator) + 1];
		strcpy(copie, producator);
		return copie;
	}

	float getPret() {
		return this->pret;
	}

	int getNrIngrediente() {
		return this->nrIngrediente;
	}

	string* getDenumireIngrediente() {
		return this->denumireIngrediente;
	}

	float* getGramajIngrediente() {
		return this->gramajIngrediente;
	}

	bool getDePost() {
		return this->dePost;
	}


	//setteri -  NU SE FAC PT CONST si Statistce - PT POINTER SE DEZALOCA SI DUPA SE ALOCA
	/*/void setNumeVariabila(tipvariabila NumeVariabila{
			this numeVariabila = numeVariabila;
	}*/
	
	void setNume(string nume) {
		this->nume = nume;
	}

	void setTipProdus(tipProdus tip) {
		this->tip = tip;

	}

	void setNumeProducator(const char* producator) {
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}

	void setPret(float pret) {
		this->pret = pret;
	}

	void setNrIngrediente(int nrIngrediente) {
		this->nrIngrediente = nrIngrediente;
	}

	void setDenumireIngrediente(int nrIngrediente, string* denumireIngrediente) {
		this->nrIngrediente = nrIngrediente;
		if (this->denumireIngrediente != nullptr) {
			delete[] this->denumireIngrediente;
		}
		this->denumireIngrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->denumireIngrediente[i] = denumireIngrediente[i];
		}
	}

	void setGramajIngrediente(int nrIngrediente, float* gramajIngrediente) {
		this->nrIngrediente = nrIngrediente;
		if (this->gramajIngrediente != nullptr) {
			delete[] this->gramajIngrediente;
		}
		this->gramajIngrediente = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->gramajIngrediente[i] = gramajIngrediente[i];
		}
	}
	//sau varianta mai OP
	void setIngrediente(int nrIngrediente, string* denumireIngrediente, float* gramajIngrediente) {
		this->nrIngrediente = nrIngrediente;
		if (this->denumireIngrediente != nullptr) {
			delete[] this->denumireIngrediente;
		}
		if (this->gramajIngrediente != nullptr) {
			delete[] this->gramajIngrediente;
		}
		this->nrIngrediente = nrIngrediente;

		this->denumireIngrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->denumireIngrediente[i] = denumireIngrediente[i];
		}

		this->gramajIngrediente = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->gramajIngrediente[i] = gramajIngrediente[i];
		}

	}


	void setDePost(bool dePost) {
		this->dePost = dePost;
	}

	//destructor = dezaloca memoria din atributele alocate dinamic - practic din *
	~Produs() {
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
		if (this->denumireIngrediente != nullptr) {
			delete[] this->denumireIngrediente;
		}
		if (this->gramajIngrediente != nullptr) {
			delete[] this->gramajIngrediente;
		}
	}
	
	//constructor de copiere;

	Produs(const Produs& p):idProdus(p.idProdus), codProdus(p.codProdus) {
		this->nume = p.nume;
		this->tip = p.tip;
		this->producator = new char[strlen(p.producator) + 1];
		strcpy(this->producator, p.producator);

		this->pret = p.pret;
		this->nrIngrediente = p.nrIngrediente;

		this->denumireIngrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->denumireIngrediente[i] =p.denumireIngrediente[i];
		}

		this->gramajIngrediente = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->gramajIngrediente[i] = p.gramajIngrediente[i];
		}

		this->dePost = p.dePost;

	}

	//operatorul egal(copiem intr-un obiect existent valorile din alt obiect)
	//este alcatuit din constructor si destructor +return *this
	Produs &operator=(const Produs& p) {
		if (this != &p) {
			if (this->producator != nullptr) {
				delete[] this->producator;
			}
			if (this->denumireIngrediente != nullptr) {
				delete[] this->denumireIngrediente;
			}
			if (this->gramajIngrediente != nullptr) {
				delete[] this->gramajIngrediente;
			}
			this->nume = p.nume;
			this->tip = p.tip;
			this->producator = new char[strlen(p.producator) + 1];
			strcpy(this->producator, p.producator);

			this->pret = p.pret;
			this->nrIngrediente = p.nrIngrediente;

			this->denumireIngrediente = new string[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->denumireIngrediente[i] = p.denumireIngrediente[i];
			}

			this->gramajIngrediente = new float[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->gramajIngrediente[i] = p.gramajIngrediente[i];
			}

			this->dePost = p.dePost;
			return *this;
		}
		
	}
	//metode
	float totalCantitate() {
		float suma = 0;
		for (int i = 0; i < this->nrIngrediente; i++) {
			suma += this->gramajIngrediente[i];
		}
		return suma;
	}
	float medieCantitate() {
		float suma = 0;
		for (int i = 0; i < this->nrIngrediente; i++) {
			suma += this->gramajIngrediente[i];
		}
		/*suma /= this->nrIngrediente;*/
		return suma/this->nrIngrediente;
	}

	float gramajMaxim() {
		float maxim = this->gramajIngrediente[0];
		for (int i = 1; i < this->nrIngrediente; i++) {
			if (maxim < this->gramajIngrediente[i]) {
				maxim = this->gramajIngrediente[i];
			}
		}
		return maxim;
	}

	string ingredientulGramajMaxim(){
		float maxim = this->gramajIngrediente[0];
		string gramajMaxim = this->denumireIngrediente[0];
		for (int i = 1; i < this->nrIngrediente; i++) {
			if (maxim < this->gramajIngrediente[i]) {
				maxim = gramajIngrediente[i];
				gramajMaxim = this->denumireIngrediente[i];
			}
		}
		return gramajMaxim;
	}

	float pretFaraTVA() {
		float PretFaraTVA = this->pret - float(TVA) / 100 * this->pret;
		/*float PretFaraTVA = this->pret - TVA / 100.0 * this->pret;*/
		//ambele variante sunt corecte!!!! trebuie sa modificam tva in float pt ca era int inainte
		return PretFaraTVA;
	}

	void adaugaIngrediente(string numeIngredient, float gramajIngredient) {
		Produs copie = *this;
		//practic in copie raman valorile vechi, inclusiv nr de ingrediente vechi, sa zicem el era 3 si devine 4
		delete[]this->denumireIngrediente;
		delete[]this->gramajIngrediente;
		this->nrIngrediente++;

		this->denumireIngrediente = new string[this->nrIngrediente];

		this->gramajIngrediente = new float[this->nrIngrediente];
		
		for (int i = 0; i < copie.nrIngrediente; i++) {
			this->denumireIngrediente[i] = copie.denumireIngrediente[i];
			this->gramajIngrediente[i] = copie.gramajIngrediente[i];
		}
		this->denumireIngrediente[this->nrIngrediente - 1] = numeIngredient;
		this->gramajIngrediente[this->nrIngrediente - 1] = gramajIngredient;
		//this->denumireIngrediente[copie.nrIngrediente] = numeIngredient;
		//this->gramajIngrediente[copie.nrIngrediente] = gramajIngredient;
		//e corect in ambele feluri;
	}

	static float totalPreturiProduse(int nrProduse, Produs* produse) {
		float totalPreturi = 0;
		for (int i = 0; i < nrProduse; i++) {
			totalPreturi += produse[i].getPret();
		}
		return totalPreturi;

	}


	//operatori
	//operator << (de afisare)
	friend ostream& operator<<(ostream& out, const Produs& p) {
		out << "Id: " << p.idProdus << endl;
		out << "Cod Produs: " << p.codProdus << endl;
		out << "Denumire produs: " << p.nume << endl;
		out << "Tip: ";
		if (p.tip == Normal) {
			out << "Normal" << endl;
		}
		else if (p.tip == Vegetarian) {
			out << "Vegetarian" << endl;
		}
		else if (p.tip == Vegan) {
			out << "Vegan" << endl;
		}
		out << "Producator: " << p.producator << endl;
		out << "Pret: " << p.pret << endl;
		out << "Numarul de ingrediente: " << p.nrIngrediente << endl;
		out << "Denumire ingrediente: ";
		for (int i = 0; i < p.nrIngrediente; i++) {
			out << p.denumireIngrediente[i] << " | ";
		}
		out << endl;
		out << "Gramaj per ingredient: ";
		for (int i = 0; i < p.nrIngrediente; i++) {
			out << p.gramajIngrediente[i] << " | ";
		}
		out << endl;
		if (p.dePost == 0) {
			out << "Produsul NU este de post." << endl;
		}
		else {
			out << "Produsul este de post." << endl;
		}
		return out;
	}
	//operator >>
	friend istream& operator>>(istream& in, Produs& p) {
		//pt string
		cout<<"Nume produs: ";
		in >> ws; //dac nu merge se pune asta;
		/*in >> p.nume;*///citeste pana la primul spatiu.
		getline(in, p.nume);
		//tip produs
		cout << "Tip produs(Folositi cifre => 1-Normal, 2-Vegetarian, 3-Vegan: ";
		int opt;
		in >> opt;
		switch (opt) {
		case 1:p.tip = Normal; break;
		case 2:p.tip = Vegetarian; break;
		case 3:p.tip = Vegan; break;
		default:p.tip = Normal; break;
		}
		//char*
		cout << "Producator: ";
		in >> ws; //dac nu merge se pune asta;
		delete[]p.producator;
		char aux[100];
		in.getline(aux, 99);
		p.producator = new char[strlen(aux) + 1];
		strcpy(p.producator, aux);

		cout << "Pret: ";
		in >> p.pret;

		cout << "Nr Ingrediente: ";
		in >> p.nrIngrediente;

		delete[]p.denumireIngrediente;
		delete[]p.gramajIngrediente;
		
		cout << "Lista ingrediente: ";
		p.denumireIngrediente = new string[p.nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++) {
			in>>p.denumireIngrediente[i];
		}

		cout << "Gramaj per ingredient: ";
		p.gramajIngrediente = new float[p.nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++) {
			in >> p.gramajIngrediente[i];
		}

		cout << "Este de post?(1-Da, 0-Nu): ";	
		in >> p.dePost;

		return in;
	}
	//PT SCRIEREA IN FISIERE TEXT SI CITIREA DIN FISIERE TEXT AVEM NEVOIE DE OFSTREAM, RESPECTIV IFSTREAM
	//OFSTREAM SI IFSTREAM SUNT LA FEL CA SI OSTREAM SI ISTREAM FARA TEXT, FARA ATRIBUTE CONSTANTE SAU STATICE
	//IAR LA OFSTREAM DAM ENDL DUPA FIECARE VALOARE CA SA NE FIE MAI USOR DE CITIT
	friend ofstream& operator<<(ofstream& out, const Produs& p) {
		out <<p.nume << endl;
		out << p.tip;
		
		out << p.producator << endl;
		out <<p.pret << endl;
		out <<p.nrIngrediente << endl;
		for (int i = 0; i < p.nrIngrediente; i++) {
			out << p.denumireIngrediente[i] <<endl;
		}

		for (int i = 0; i < p.nrIngrediente; i++) {
			out << p.gramajIngrediente[i] <<endl;
		}

		out << p.dePost;
		return out;
	}
	//operator >>
	friend ifstream& operator>>(ifstream& in, Produs& p) {
		in >> ws; //dac nu merge se pune asta;
		getline(in, p.nume);
		int opt;
		in >> opt;
		switch (opt) {
		case 1:p.tip = Normal; break;
		case 2:p.tip = Vegetarian; break;
		case 3:p.tip = Vegan; break;
		default:p.tip = Normal; break;
		}
		in >> ws; //dac nu merge se pune asta;
		delete[]p.producator;
		char aux[100];
		in.getline(aux, 99);
		p.producator = new char[strlen(aux) + 1];
		strcpy(p.producator, aux);
		in >> p.pret;
		in >> p.nrIngrediente;
		delete[]p.denumireIngrediente;
		delete[]p.gramajIngrediente;
		p.denumireIngrediente = new string[p.nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++) {
			in >> p.denumireIngrediente[i];
		}
		p.gramajIngrediente = new float[p.nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++) {
			in >> p.gramajIngrediente[i];
		}
		in >> p.dePost;
		return in;
	}









	//operator functie()
	float operator()() {
		return totalCantitate();

	}
	float operator()(float moneda) {
		return this->pret / moneda;

	}

	//operator cast - schimba tipul de date
	explicit operator string() {
		return this->producator; //asta e char devine string
	}
	
	//operator de indexare -- op[] - p2[3]
	string& operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < this->nrIngrediente) {
			return this->denumireIngrediente[pozitie];
		}
		else {
			/*throw "Nu exista!";*/
			
		}
	}

	
	//op ++
	//preincrementare
	Produs& operator++() {
		this->pret++;
		return *this;
	}
	//postincremenetare - unar
	Produs operator++(int) {
		Produs copie = *this;
		string ultimNumeIngredient = this->denumireIngrediente[this->nrIngrediente - 1];
		float gramaUltimIngredient = this->gramajIngrediente[this->nrIngrediente - 1];
		adaugaIngrediente(ultimNumeIngredient, gramaUltimIngredient);


		return copie;
	}

	//operator += - atribuire compusa
	Produs& operator +=(int valoare) { //pot sa aduni si float, tre sa scriu float in loc de int
		this->pret += valoare;
		return *this;
	}

	//operator + => are 3 forme:
	//1. obj + valoarea
	Produs operator+(float val) {
		Produs copie = *this;
		copie.pret += val;
		return copie;
	}
	//2. obj + obj
	Produs operator+(Produs p) {
		Produs copie = *this;
		delete[]copie.denumireIngrediente;
		delete[] copie.gramajIngrediente;
		copie.nrIngrediente += p.nrIngrediente;
		copie.denumireIngrediente = new string[copie.nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			copie.denumireIngrediente[i] = this->denumireIngrediente[i];
		}
		for (int i = this->nrIngrediente; i < copie.nrIngrediente; i++) {
			copie.denumireIngrediente[i] = p.denumireIngrediente[i - this->nrIngrediente];
		}
		copie.gramajIngrediente = new float[copie.nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			copie.gramajIngrediente[i] = this->gramajIngrediente[i];
		}
		for (int i = this->nrIngrediente; i < copie.nrIngrediente; i++) {
			copie.gramajIngrediente[i] = p.gramajIngrediente[i - this->nrIngrediente];
		}
		return copie;
	}

	friend Produs operator+(float val, Produs p) {
		Produs copie = p;
		copie.gramajIngrediente[0] += val;
		return copie;
	}

	//op >, <, >=, <=
	bool operator>(Produs p) {
		return this->pret > p.pret;
	}
	//op!
	bool operator!() {
		if (this->dePost == true) {
			this->dePost == false;
			return true;
		}
		else {
			this->dePost == true;
			return false;
		}
	}

	bool operator~() {
		return this->pret >= 30;
	}
};

int Produs::contor = 1;
int Produs::TVA = 19;
int main() {
	Produs p;
	cout << p.getIdProdus() << endl;
	cout << p.getCodProdus() << endl;
	cout << p.getNume() << endl;
	cout << p.getTip() << endl;
	cout << p.getProducator() << endl;
	cout << p.getPret() << endl;
	cout << p.getNrIngrediente() << endl;
	for (int i = 0; i < p.getNrIngrediente(); i++) {
		cout << p.getDenumireIngrediente()[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < p.getNrIngrediente(); i++) {
		cout << p.getGramajIngrediente()[i] << " ";
	}
	cout << p.getDePost() << endl;
	cout << endl << endl;



	string denumiri[] = {"Zahar","Apa","Pisat"};
	float gramaje[] = { 23.2, 11.6, 32.1 };
	/*Produs p1(3, denumiri, gramaje)*/
	/*cout << p1 << endl;*/



	//se poate sa nu ia pt ca e char * pt a nu mai scrie asta trebuie sa pun const char* 
	/*char* aux = new char[strlen("Jerrys") + 1];
	strcpy(aux, "Jerrys");*/
	Produs p2("ABC123", "Pizza Vegana", Vegan, "Jerrys", 29.99, 3, denumiri, gramaje, 1);
	p2.setNumeProducator("Dominos");
	string aux[3] = { "Faina","Apa","Oua" };
	float aux2[3] = { 123.2,323.4,3232.34 };
	//p2.setDenumireIngrediente(3, aux);
	//p2.setGramajIngrediente(3, aux2);
	/*p2.setNrIngrediente(5);*/
	p2.setIngrediente(5, new string[5]{ "Apa", "Faina", "Drojdie", "Sare", "Zahar" }, new float[5] {0.5, 100.50, 3.7, 1.6, 0.5});
	cout << p2.getIdProdus() << endl;
	cout << p2.getCodProdus() << endl;
	cout << p2.getNume() << endl;
	cout << p2.getTip() << endl;
	cout << p2.getProducator() << endl;
	cout << p2.getPret() << endl;
	cout << p2.getNrIngrediente() << endl;
	for (int i = 0; i < p2.getNrIngrediente(); i++) {
		cout << p2.getDenumireIngrediente()[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < p2.getNrIngrediente(); i++) {
		cout << p2.getGramajIngrediente()[i] << " ";
	}
	cout << endl;
	cout << p2.getDePost() << endl;
	cout << endl << endl;

	cout << "___________Constructorul de copiere__________" << endl;
	Produs p3 = p;
	//sau Produs p3(p)
	cout << p3.getIdProdus() << endl;
	cout << p3.getCodProdus() << endl;
	cout << p3.getNume() << endl;
	cout << p3.getTip() << endl;
	cout << p3.getProducator() << endl;
	cout << p3.getPret() << endl;
	cout << p3.getNrIngrediente() << endl;
	for (int i = 0; i < p3.getNrIngrediente(); i++) {
		cout << p3.getDenumireIngrediente()[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < p3.getNrIngrediente(); i++) {
		cout << p3.getGramajIngrediente()[i] << " ";
	}
	cout << endl;
	cout << p3.getDePost() << endl;
	cout << endl << endl;

	cout << "___________Operatorul = __________" << endl;
	p3 = p3;
	cout << p3.getIdProdus() << endl;
	cout << p3.getCodProdus() << endl;
	cout << p3.getNume() << endl;
	cout << p3.getTip() << endl;
	cout << p3.getProducator() << endl;
	cout << p3.getPret() << endl;
	cout << p3.getNrIngrediente() << endl;
	for (int i = 0; i < p3.getNrIngrediente(); i++) {
		cout << p3.getDenumireIngrediente()[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < p3.getNrIngrediente(); i++) {
		cout << p3.getGramajIngrediente()[i] << " ";
	}
	cout << endl;
	cout << p3.getDePost() << endl;
	cout << endl << endl;

	cout << "___________Metode__________" << endl;
	cout << p2.totalCantitate() << endl;
	cout << p2.medieCantitate() << endl;
	cout << p2.gramajMaxim() << endl;
	cout << p2.ingredientulGramajMaxim() << endl;
	cout << p2.pretFaraTVA() << endl;
	p2.adaugaIngrediente("Cimbru", 0.3);
	cout << p2.getNrIngrediente() << endl;
	for (int i = 0; i < p2.getNrIngrediente(); i++) {
		cout << p2.getDenumireIngrediente()[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < p2.getNrIngrediente(); i++) {
		cout << p2.getGramajIngrediente()[i] << " ";
	}
	cout << endl;
	cout << endl << endl;

	//mai fac un produs p4
	Produs p4("BCD234", "Pizza Carnivora", Normal, "Jerrys", 34.99, 3, denumiri, gramaje, 0);
	p3 = p4;

	cout << "___________Metode Statica__________" << endl;
	//pt un vector de produse alocat static, adica alocat normal
	Produs produse[3];
	produse[0] = p2;
	produse[1] = p3;
	produse[2] = p4;
	cout << p2.getPret() << endl;
	cout << p3.getPret() << endl;
	cout << p4.getPret() << endl;
	cout << Produs::totalPreturiProduse(3, produse);
	cout << endl << endl;

	//pt un vector de produse dinamic;
	int nrElementeVector = 2; //pot face si asa
	Produs* vectProduse = new Produs[nrElementeVector];
	vectProduse[0] = p2;
	vectProduse[1] = p3;
	cout << p2.getPret() << endl;
	cout << p3.getPret() << endl;
	cout << Produs::totalPreturiProduse(nrElementeVector, vectProduse);
	cout << endl << endl;


	cout << "___________Operatori__________" << endl;
	cout << "Operator <<" << endl;
	cout << p4 << endl;
	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "Operator >>" << endl;
	/*cout << p << endl;
	cin >> p;
	cout << endl << endl;
	cout << p << endl;
	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;*/
	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "Operator () / functie" << endl;
	/*cout << p4() << endl;
	cout << p4(4.8) << endl;*/
	//sau
	float totalGr = p4();
	cout << totalGr << endl;
	float euro = 4.8;
	float conversiePretInEuro = p4(euro);
	cout << conversiePretInEuro << endl;
	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "Operator cast" << endl;
	string numeProd = (string)p4;
	cout << numeProd << endl;
	cout << typeid(p4.getProducator()).name();
	cout << endl << "-------------------------------" << endl; 
	cout << endl << endl;

	cout << "Operator de indexare" << endl;
	cout << p4[1] << endl;
	//sa zicem ca vrem sa si modificam elementul
	p4[1] = "Apa Plata";
	cout << p4[1] << endl; //am modif si elementul de la pozitia respectiva
	//cout << p4[4] << endl;
	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "Operator ++ post si pre" << endl;
	cout << "PREINCREMENTARE" << endl;
	cout << p4 << endl;

	cout << ++p4 << endl;
	cout << "POSTINCREMENATRE" << endl;
	Produs p5 = p4++;
	cout << p5 << endl<< p4 << endl;
	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "Operator +=" << endl;
	p5 += 10;
	cout << p5 << endl;
	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "Operator + (obj + val)" << endl; //adaugi la un atribut din clasa o valoare.
	Produs p6 = p5 + 20;
	cout << p6 << endl << p5 << endl;


	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;


	cout << "Operator + (obj + obj)" << endl; //adaugi la un atribut dintr-o clasa, un atribut din alta clasa
	Produs p7 = p2 + p5;
	cout << p2 << endl;
	cout << p5 << endl;
	cout << p7 << endl;


	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "Operator +(val + obiect)" << endl;
	Produs p8 = 10 + p7;
	cout << p7 << endl;
	cout << p8 << endl;

	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "Operato >" << endl;
	cout << p2 << endl;
	cout << p4 << endl;
	if (p2 > p4) {
		cout << "p2 are pretul mai mare." << endl;
	}
	else {
		cout << "p4 are pretul mai mare." << endl;
	}

	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;


	cout << "Operator !" << endl;
	cout << !p8 << endl;
	cout << p8 << endl;
	cout << !p8 << endl;
	cout << p8 << endl;
	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "Operator ~" << endl;
	if (~p2) {
		cout << "Costa mai mult de 30 lei";
	}
	else {
		cout << "Costa mai putin de 30 lei";
	}
	cout << endl << "-------------------------------" << endl;
	cout << endl << endl;

	cout << "_______________CITIREA SI SCRIEREA IN FISIERE______________" << endl;
	ofstream file("produs.txt", ios::out);
	file << p8 << endl;
	file.close();
	cout << endl << "-------------------------------" << endl;

	return 0;
}