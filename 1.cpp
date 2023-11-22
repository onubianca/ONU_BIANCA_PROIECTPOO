#include <iostream>
using namespace std;

class CartiRomanesti
{
private:
	const int idCarte;
	static string limba;
	string titluCarte;
	string numeAutor;
	int anPublicatie;
	int nrCapitole;
	string* numeCapitole;

public:
	CartiRomanesti() :idCarte(1)
	{
		this->titluCarte = "Ion";
		this->numeAutor = "Rebreanu";
		this->anPublicatie = 1920;
		this->nrCapitole = NULL;

	}

	CartiRomanesti(string titluCarte, string numeAutor, int anPublicatie, int nrCapitole, string* numeCapitole) :idCarte(5)
	{
		this->titluCarte = titluCarte;
		this->numeAutor = numeAutor;
		this->anPublicatie = anPublicatie;
		this->nrCapitole = nrCapitole;
		this->numeCapitole = new string[nrCapitole];
		for (int i = 0; i < nrCapitole; i++)
		{
			this->numeCapitole[i] = numeCapitole[i];
		}

	}

	CartiRomanesti(string titluCarte, string numeAutor, int anPublicatie) :idCarte(25)
	{

		this->titluCarte = titluCarte;
		this->numeAutor = numeAutor;
		this->anPublicatie = anPublicatie;
		this->nrCapitole = 0;
		this->numeCapitole = NULL;
	}

	CartiRomanesti(const CartiRomanesti& a) :idCarte(a.idCarte)  //constructor copiere
	{
		this->titluCarte = a.titluCarte;
		this->numeAutor = a.numeAutor;
		this->anPublicatie = a.anPublicatie;
		this->nrCapitole = a.nrCapitole;
		this->numeCapitole = new string[a.nrCapitole];
		for (int i = 0; i < a.nrCapitole; i++)
		{
			this->numeCapitole[i] = a.numeCapitole[i];
		}
	}

	CartiRomanesti operator=(const CartiRomanesti& a) //op=
	{
		if (this != &a)
		{
			this->titluCarte = a.titluCarte;
			this->numeAutor = a.numeAutor;
			this->anPublicatie = a.anPublicatie;
			this->nrCapitole = a.nrCapitole;
			if (this->numeCapitole != NULL)
				delete[]this->numeCapitole;
			this->numeCapitole = new string[a.nrCapitole];
			for (int i = 0; i < a.nrCapitole; i++)
			{
				this->numeCapitole[i] = a.numeCapitole[i];
			}
		}
		return *this;
	}

	~CartiRomanesti()
	{
		if (this->numeCapitole != NULL)
			delete[]this->numeCapitole;
	}

	int getIdCarte()
	{
		return this->idCarte;
	}

	static string getLimbaPublicatie()
	{
		return CartiRomanesti::limba;
	}

	static void setLimbaPublicatie(string limba)
	{
		CartiRomanesti::limba = limba;
	}

	void setTitluCarte(string titluCarte) {
		if (titluCarte.length() > 3)
			this->titluCarte = titluCarte;
	}

	string getTitluCarte()
	{
		return this->titluCarte;
	}

	void setNumeAutor(string numeAutor) {
		if (numeAutor.length() > 3)
			this->numeAutor = numeAutor;
	}

	string getNumeAutor()
	{
		return this->numeAutor;
	}

	void setAnPublicatie(int anPublicatie)
	{
		if (anPublicatie > 0)
			this->anPublicatie = anPublicatie;
	}

	int getAnPublicatie()
	{
		return this->anPublicatie;
	}

	void setCapitole(int nrCapitole, string* numeCapitole)
	{
		if (nrCapitole > 0)
		{
			this->nrCapitole = nrCapitole;
			if (this->numeCapitole != NULL)
				delete[]this->numeCapitole;
			this->numeCapitole = new string[nrCapitole];
			for (int i = 0; i < nrCapitole; i++)
				this->numeCapitole[i] = numeCapitole[i];
		}
	}

	string* getNumeCapitole()
	{
		return numeCapitole;
	}

	bool operator==(const CartiRomanesti& a) //op==
	{
		return this->titluCarte == a.titluCarte;
	}

	CartiRomanesti* operator->()  //op->
	{
		this->anPublicatie = 2000;
		return this;
	}

	string& operator[](int k)  //op[]
	{
		if (k >= 0 && k < nrCapitole)
			return numeCapitole[k];
	}

	/*void afisCartiRomanesti()
	{
		cout << "Cartea " << titluCarte << " scrisa de " << numeAutor << " publicata in anul " << anPublicatie << " are " << nrCapitole << " capitole, denumite astfel: ";
		if (nrCapitole > 0)
			for (int i = 0; i < nrCapitole; i++)
				cout << numeCapitole[i] << " ";
		else
			cout << " nu are capitole";
		cout << endl;
	}*/
	friend ostream& operator<<(ostream& iesireCarti, const CartiRomanesti& a);
	friend istream& operator>>(istream& intrareCarti, CartiRomanesti& a);
	friend class Cititor;
};
string CartiRomanesti::limba = "romana";
ostream& operator<<(ostream& iesireCarti, const CartiRomanesti& a)
{
	iesireCarti << "Cartea " << a.titluCarte << " scrisa de " << a.numeAutor << " publicata in anul " << a.anPublicatie << " are " << a.nrCapitole << " capitole, denumite astfel: ";
	if (a.nrCapitole > 0)
		for (int i = 0; i < a.nrCapitole; i++)
			iesireCarti << a.numeCapitole[i] << " ";
	else
		iesireCarti << " nu are capitole";
	iesireCarti << endl;
	return iesireCarti;
}

istream& operator>>(istream& intrareCarti, CartiRomanesti& a)
{
	cout << "Titlul cartii: ";
	intrareCarti >> a.titluCarte;
	cout << "Numele autorului: ";
	intrareCarti >> a.numeAutor;
	cout << "Anul publicarii: ";
	intrareCarti >> a.anPublicatie;
	cout << "Numarul capitolelor: ";
	intrareCarti >> a.nrCapitole;
	cout << "Nume capitolelor: ";
	/*if (a.numeCapitole != NULL)
		delete[]a.numeCapitole;*/
	a.numeCapitole = new string[a.nrCapitole];
	for (int i = 0; i < a.nrCapitole; i++)
		intrareCarti >> a.numeCapitole[i];
	return intrareCarti;
}
class Bibliotecar
{
private:
	const int cnp;
	static int nrLegitimatie;
	string numeBibliotecar;
	int varsta;
	char gen;
	int nrLimbiStraine;
	string* limbiStraine;

public:
	Bibliotecar() :cnp(nrLegitimatie++)
	{
		this->varsta = 26;
		this->numeBibliotecar = "Ana";
		this->nrLimbiStraine = 0;
		this->gen = 'f';
		this->limbiStraine = NULL;
	}

	Bibliotecar(string numeBibliotecar, int varsta, char gen, int nrLimbiStraine, string* limbiStraine) :cnp(nrLegitimatie++)
	{
		this->numeBibliotecar = numeBibliotecar;
		this->varsta = varsta;
		this->gen = gen;
		this->nrLimbiStraine = nrLimbiStraine;
		this->limbiStraine = new string[nrLimbiStraine];
		for (int i = 0; i < nrLimbiStraine; i++)
		{
			this->limbiStraine[i] = limbiStraine[i];
		}
	}

	Bibliotecar(string numeBibliotecar, int varsta) :cnp(nrLegitimatie)
	{
		nrLegitimatie++;
		this->varsta = varsta;
		this->numeBibliotecar = numeBibliotecar;
		this->gen = 'f';
		this->nrLimbiStraine = 0;
		this->limbiStraine = NULL;
	}

	Bibliotecar(const Bibliotecar& b) :cnp(nrLegitimatie++)  //constructor copiere
	{
		this->numeBibliotecar = b.numeBibliotecar;
		this->varsta = b.varsta;
		this->gen = b.gen;
		this->nrLimbiStraine = b.nrLimbiStraine;
		this->limbiStraine = new string[b.nrLimbiStraine];
		for (int i = 0; i < b.nrLimbiStraine; i++)
		{
			this->limbiStraine[i] = b.limbiStraine[i];
		}
	}

	Bibliotecar operator=(const Bibliotecar& b)  //op=
	{
		if (this != &b)
		{
			this->numeBibliotecar = b.numeBibliotecar;
			this->varsta = b.varsta;
			this->gen = b.gen;
			this->nrLimbiStraine = b.nrLimbiStraine;
			if (this->limbiStraine != NULL)
				delete[]this->limbiStraine;
			this->limbiStraine = new string[b.nrLimbiStraine];
			for (int i = 0; i < b.nrLimbiStraine; i++)
			{
				this->limbiStraine[i] = b.limbiStraine[i];
			}
		}
		return *this;
	}

	~Bibliotecar()
	{
		if (this->limbiStraine != NULL)
			delete[]this->limbiStraine;
	}

	int getCnp()
	{
		return this->cnp;
	}

	static void setNrLegitimatie(int nrLegitimaie)
	{
		Bibliotecar::nrLegitimatie = nrLegitimaie + 1;
	}

	static int getNrLegitimatie()
	{
		return Bibliotecar::nrLegitimatie;
	}

	void setNumeBibliotecar(string numeBibliotecar)
	{
		if (numeBibliotecar.length() > 3)
			this->numeBibliotecar = numeBibliotecar;
	}

	string getNumeBibliotecar()
	{
		return this->numeBibliotecar;
	}

	void setVarsta(int varsta)
	{
		if (varsta > 0)
			this->varsta = varsta;
	}

	int getVarsta()
	{
		return this->varsta;
	}

	void setGen(char gen)
	{
		this->gen = gen;
	}

	int getGen()
	{
		return this->gen;
	}

	void setLimbiStraine(int nrLimbiStraine, string* limbiStraine)
	{
		if (nrLimbiStraine > 0)
		{
			this->nrLimbiStraine = nrLimbiStraine;
			if (this->limbiStraine != NULL)
				delete[]this->limbiStraine;
			this->limbiStraine = new string[nrLimbiStraine];
			for (int i = 0; i < nrLimbiStraine; i++)
				this->limbiStraine[i] = limbiStraine[i];
		}
	}

	string* getLimbiStraine()
	{
		return limbiStraine;
	}

	Bibliotecar operator++(int)  //op++
	{
		Bibliotecar aux = *this;
		this->varsta++;
		return aux;
	}

	Bibliotecar operator!()  //op!
	{
		Bibliotecar aux = *this;
		aux.gen = !aux.gen;
		return aux;
	}

	/*void afisBibliotecar()
	{
		cout << "Bibliotecara " << numeBibliotecar << " are " << varsta << " de ani si cunoaste " << nrLimbiStraine << " limbi straine cum ar fi: ";
		if (nrLimbiStraine > 0)
			for (int i = 0; i < nrLimbiStraine; i++)
				cout << limbiStraine[i] << " ";
		else
			cout << " nu cunoste limbi straine.";
		cout << endl;
	}*/

	friend void verifVarstaB(Bibliotecar b);
	friend ostream& operator<<(ostream& iesireBibliotecar, Bibliotecar& b);
	friend istream& operator>>(istream& intrareBibliotecar, Bibliotecar& b);
};
int Bibliotecar::nrLegitimatie = 100;

ostream& operator<<(ostream& iesireBibliotecar, Bibliotecar& b)
{
	iesireBibliotecar << "Bibliotecara " << b.numeBibliotecar << " are " << b.varsta << " de ani si cunoaste " << b.nrLimbiStraine << " limbi straine cum ar fi: ";
	if (b.nrLimbiStraine > 0)
		for (int i = 0; i < b.nrLimbiStraine; i++)
			iesireBibliotecar << b.limbiStraine[i] << " ";
	else
		iesireBibliotecar << " nu cunoste limbi straine.";
	iesireBibliotecar << endl;
	return iesireBibliotecar;
}

istream& operator>>(istream& intrareBibliotecar, Bibliotecar& b)
{
	cout << "Numele: ";
	intrareBibliotecar >> b.numeBibliotecar;
	cout << "Varsta: ";
	intrareBibliotecar >> b.varsta;
	cout << "Nr limbilor straine: ";
	intrareBibliotecar >> b.nrLimbiStraine;
	cout << "limbile Straine: ";
	/*if (b.limbiStraine != NULL)
		delete[]b.limbiStraine;*/
	b.limbiStraine = new string[b.nrLimbiStraine];
	for (int i = 0; i < b.nrLimbiStraine; i++)
		intrareBibliotecar >> b.limbiStraine[i];
	return intrareBibliotecar;
}
void verifVarstaB(Bibliotecar b)
{
	if (b.varsta > 20) cout << "da";
	else cout << "nu" << endl;
}

class Biblioteca
{
private:
	const int anInfiintare;
	static string planeta;
	string oras;
	float suprafata;
	int nrSaliLectura;
	string* numeSaliLectura;

public:
	Biblioteca() :anInfiintare(1980)
	{
		this->suprafata = 5000;
		this->oras = "Bucuresti";
		this->nrSaliLectura = 0;
		this->numeSaliLectura = NULL;
	}

	Biblioteca(string oras, float suprafata, int nrSaliLectura, string* numeSaliLectura) :anInfiintare(1948)
	{
		this->oras = oras;
		this->suprafata = suprafata;
		this->nrSaliLectura = nrSaliLectura;
		this->numeSaliLectura = new string[nrSaliLectura];
		for (int i = 0; i < nrSaliLectura; i++)
		{
			this->numeSaliLectura[i] = numeSaliLectura[i];
		}
	}

	Biblioteca(int nrSaliLectura, string* numeSaliLectura) :anInfiintare(2005)
	{
		this->oras = "Iasi";
		this->suprafata = 1500;
		this->nrSaliLectura = nrSaliLectura;
		this->numeSaliLectura = new string[nrSaliLectura];
		for (int i = 0; i < nrSaliLectura; i++)
		{
			this->numeSaliLectura[i] = numeSaliLectura[i];
		}
	}


	Biblioteca(const Biblioteca& c) :anInfiintare(c.anInfiintare)  //constructor copiere
	{
		this->oras = c.oras;
		this->suprafata = c.suprafata;
		this->nrSaliLectura = c.nrSaliLectura;
		this->numeSaliLectura = new string[c.nrSaliLectura];
		for (int i = 0; i < c.nrSaliLectura; i++)
		{
			this->numeSaliLectura[i] = c.numeSaliLectura[i];
		}
	}

	Biblioteca operator=(const Biblioteca& c)  //op=
	{
		if (this != &c)
		{
			this->oras = c.oras;
			this->suprafata = c.suprafata;
			this->nrSaliLectura = c.nrSaliLectura;
			if (this->numeSaliLectura != NULL)
				delete[]this->numeSaliLectura;
			this->numeSaliLectura = new string[c.nrSaliLectura];
			for (int i = 0; i < c.nrSaliLectura; i++)
			{
				this->numeSaliLectura[i] = c.numeSaliLectura[i];
			}
		}
		return *this;
	}

	~Biblioteca()
	{
		if (this->numeSaliLectura != NULL)
			delete[]this->numeSaliLectura;
	}

	int getAnInfiintare()
	{
		return this->anInfiintare;
	}

	static void setPlaneta(string planeta)
	{
		Biblioteca::planeta = planeta;
	}

	static string getPlaneta()
	{
		return Biblioteca::planeta;
	}

	void setOras(string oras) {
		if (oras.length() > 3)
			this->oras = oras;
	}

	string getOras()
	{
		return this->oras;
	}

	void setSuprafata(int suprafata)
	{
		if (suprafata > 0)
			this->suprafata = suprafata;
	}

	int getSuprafata()
	{
		return this->suprafata;
	}

	void setSaliLetura(int nrSaliLectura, string* numeSaliLectura)
	{
		if (nrSaliLectura > 0)
		{
			this->nrSaliLectura = nrSaliLectura;
			if (this->numeSaliLectura != NULL)
				delete[]this->numeSaliLectura;
			this->numeSaliLectura = new string[nrSaliLectura];
			for (int i = 0; i < nrSaliLectura; i++)
				this->numeSaliLectura[i] = numeSaliLectura[i];
		}
	}

	string* getSaliLetura()
	{
		return numeSaliLectura;
	}

	string& operator[](int k)  //op[]
	{
		if (k >= 0 && k < nrSaliLectura)
			return numeSaliLectura[k];
	}

	bool operator>(Biblioteca c)  //op>
	{
		return this->suprafata > c.suprafata;
	}

	/*void afisBiblioteca()
	{
		cout << "Biblioteca din orasul " << oras << " are o suprafata de " << suprafata << " metri patrati si  " << nrSaliLectura << " sali lectura numite dupa scriitori romani precum:  ";
		if (nrSaliLectura > 0)
			for (int i = 0; i < nrSaliLectura; i++)
				cout << numeSaliLectura[i] << " ";
		else
			cout << " nu are sali de lectura.";
		cout << endl;
		cout << "Biblioteca se afla pe planeta " << planeta << endl;
	}*/

	friend string getSirSaliLectura(const Biblioteca& c);
	friend ostream& operator<<(ostream& iesireBiblioteca, Biblioteca& c);
	friend istream& operator>>(istream& intrareBiblioteca, Biblioteca& c);
};
string Biblioteca::planeta = "Terra";

ostream& operator<<(ostream& iesireBiblioteca, Biblioteca& c)
{
	iesireBiblioteca << "Biblioteca din orasul " << c.oras << " are o suprafata de " << c.suprafata << " metri patrati si  " << c.nrSaliLectura << " sali lectura numite dupa scriitori romani precum:  ";
	if (c.nrSaliLectura > 0)
		for (int i = 0; i < c.nrSaliLectura; i++)
			iesireBiblioteca << c.numeSaliLectura[i] << " ";
	else
		iesireBiblioteca << " nu are sali de lectura.";
	iesireBiblioteca << endl;
	return iesireBiblioteca;
}
istream& operator>>(istream& intrareBiblioteca, Biblioteca& c)
{
	cout << "Oras: ";
	intrareBiblioteca >> c.oras;
	cout << "Suprafata: ";
	intrareBiblioteca >> c.suprafata;
	cout << "Nr sali lectura: ";
	intrareBiblioteca >> c.nrSaliLectura;
	cout << "Nume sali lectura: ";
	/*if (c.numeSaliLectura != NULL)
		delete[]c.numeSaliLectura;*/
	c.numeSaliLectura = new string[c.nrSaliLectura];
	for (int i = 0; i < c.nrSaliLectura; i++)
		intrareBiblioteca >> c.numeSaliLectura[i];
	return intrareBiblioteca;
}

string getSirSaliLectura(const Biblioteca& c)
{
	string aux;
	for (int i = 0; i < c.nrSaliLectura; i++)
	{
		aux += c.numeSaliLectura[i];
	}
	return aux;
}

class Cititor
{
private:
	const int idCititor;
	int nrCartiImprumutate;
	CartiRomanesti* carte;

public:
	Cititor() :idCititor(0)
	{
		this->nrCartiImprumutate = 1;
		
	}
	Cititor(int idCititor, int nrCartiImprumutate, CartiRomanesti* carte) :idCititor(idCititor)
	{
		this->nrCartiImprumutate = nrCartiImprumutate;
		this->carte = new CartiRomanesti[this->nrCartiImprumutate];
		for (int i = 0; i < this->nrCartiImprumutate; i++)
		{
			this->carte[i] = carte[i];
		}
	}
	Cititor(const Cititor& d) : idCititor(d.idCititor)
	{
		this->nrCartiImprumutate = d.nrCartiImprumutate;
		this->carte = new CartiRomanesti[nrCartiImprumutate];
		for (int i = 0; i < this->nrCartiImprumutate; i++)
		{
			this->carte[i] = d.carte[i];
		}
	}
	Cititor operator=(const Cititor& d) 
	{
		if (this != &d)
		{
			this->nrCartiImprumutate = d.nrCartiImprumutate;
			if (this->carte != NULL)
				delete[] carte;
			this->carte = new CartiRomanesti[nrCartiImprumutate];
			for (int i = 0; i < this->nrCartiImprumutate; i++)
			{
				this->carte[i] = d.carte[i];
			}
		}
		return *this;
	}

	~Cititor()
	{
		if (this->carte != NULL)
			delete[]this->carte;
	}
	int getIdCititor()
	{
		return this->idCititor;
	}
	void setCarte(int nrCartiImprumutate, CartiRomanesti* carte)
	{
		if (nrCartiImprumutate > 0)
		{
			this->nrCartiImprumutate = nrCartiImprumutate;
			if (this->carte != NULL)
				delete[]this->carte;
			this->carte = new CartiRomanesti[nrCartiImprumutate];
			for (int i = 0; i < nrCartiImprumutate; i++)
				this->carte[i] = carte[i];
		}
	}

	CartiRomanesti* getCarte()
	{
		return carte;
	}
	bool operator!=(const Cititor& d)
	{
		return this->nrCartiImprumutate != d.nrCartiImprumutate;
	}
	friend ostream& operator<<(ostream& iesireCititor, const Cititor& d);
};
ostream& operator<<(ostream& iesireCititor, const Cititor& d)
{
	iesireCititor << "Cititorul a imprumutat  " << d.nrCartiImprumutate << " carti cum ar fi: " ;
	if (d.nrCartiImprumutate > 0)
		for (int i = 0; i < d.nrCartiImprumutate; i++)
			iesireCititor << d.carte[i] << " ";
	else
		iesireCititor << " nu a imprumutat carti";
	iesireCititor << endl;
	return iesireCititor;
}
void main()
{

	//CartiRomanesti
	CartiRomanesti a1;
	/*a1.afisCartiRomanesti();*/
	cout << a1;

	string* numeCapitole = new string[2]{ "Glasul Pamantului,", "Glasul Iubirii" };
	CartiRomanesti a2("Ion", "Rebreanu", 1920, 2, numeCapitole);
	/*a2.afisCartiRomanesti();*/
	cout << a2;

	CartiRomanesti a3("Morometii", "Preda", 1955);
	/*a3.afisCartiRomanesti();*/
	cout << a3;

	cout << a3.getLimbaPublicatie() << endl;

	CartiRomanesti a4;
	a4 = a2;
	a4.setTitluCarte("Morometii");
	a4.setNumeAutor("Preda");
	a4.setAnPublicatie(1955);
	cout << "Cartea " << a4.getTitluCarte() << " scrisa de " << a4.getNumeAutor() << " publicata in anul " << a4.getAnPublicatie() << " are doua capitole cu numele:  ";
	string* v1 = new string[2]{ "Partea I,", "Partea II" };
	a4.setCapitole(2, v1);
	for (int j = 0; j < 2; j++)
		cout << a4.getNumeCapitole()[j];
	delete[]v1;
	cout << endl;

	CartiRomanesti a5;
	a5.setAnPublicatie(2001);
	cout << a5.getAnPublicatie() << endl;
	cout << a5->getAnPublicatie() << endl;

	cin >> a1 >> a2;
	if (a1 == a2)
		cout << "Aceiasi carte";
	else
		cout << "Carti diferite";
	cout << endl;

	int nrCarti;
	cout << "Introduceti numarul de carti: ";
	cin >> nrCarti;
	CartiRomanesti* carti = new CartiRomanesti[nrCarti];
	for (int i = 0; i < nrCarti; i++) {
		cout << i + 1 << endl;
		cin >> carti[i];
	}
	for (int i = 0; i < nrCarti; i++) {
		cout << carti[i];
	}
	delete[] carti;

	int nrLinii, nrColoane;
	cout << "Introduceti numarul de linii: ";
	cin >> nrLinii;
	cout << "Introduceti numarul de coloane: ";
	cin >> nrColoane;

	CartiRomanesti** carte = new CartiRomanesti * [nrLinii];
	for (int i = 0; i < nrLinii; i++) {
		carte[i] = new CartiRomanesti[nrColoane];
	}
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane; j++) {
			cout << i + 1 << " " << j + 1 << endl;
			cin >> carte[i][j];
		}
	}
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane; j++) {
			cout << carte[i][j];
		}
	}

	//Bibliotecar
	Bibliotecar b1;
	/*b1.afisBibliotecar();*/
	cout << b1;

	cout << b1.getNrLegitimatie() << endl;

	string* limbiStraine = new string[3]{ "engleza","franceza","germana" };
	Bibliotecar b2("Maria", 17, 'f', 3, limbiStraine);
	//b2.afisBibliotecar();
	cout << b2;

	Bibliotecar b3("Anca", 29);
	//b3.afisBibliotecar();
	b3++;
	cout << b3;

	Bibliotecar b4 = b3;
	b4.setNumeBibliotecar("Sara");
	b4.setVarsta(47);
	b4.setGen('f');
	cout << "Bibliotecara " << b4.getNumeBibliotecar() << " are " << b4.getVarsta() << " de ani si cunoaste patru limbi straine cum ar fi: ";
	string* v2 = new string[4]{ "engleza,", "franceza,", "germana,", "araba" };
	b4.setLimbiStraine(4, v2);
	for (int j = 0; j < 4; j++)
		cout << b4.getLimbiStraine()[j];
	delete[]v2;
	cout << endl;

	Bibliotecar b5;
	cin >> b5;
	cout << b5;
	verifVarstaB(b5);

	cout << endl;
	if (!b4.getGen())
		cout << "da";
	else
		cout << "nu";
	cout << endl;

	int numarBibliotecari;
	cout << "Introduceti numarul de bibliotecari: ";
	cin >> numarBibliotecari;
	Bibliotecar* bibliotecar = new Bibliotecar[numarBibliotecari];
	for (int i = 0; i < numarBibliotecari; i++) {
		cin >> bibliotecar[i];
	}
	for (int i = 0; i < numarBibliotecari; i++) {
		cout << bibliotecar[i];
	}
	delete[] bibliotecar;

	//Biblioteca
	Biblioteca c1;
	/*c1.afisBiblioteca();*/
	cin >> c1;
	cout << c1;

	string* numeSaliLectura = new string[2]{ "Eminescu,", "Creanga" };
	Biblioteca c2("Iasi", 1500, 2, numeSaliLectura);
	/*c2.afisBiblioteca();*/
	cout << c2;

	Biblioteca c3(2, numeSaliLectura);
	/*c3.afisBiblioteca();*/
	cout << c3;

	Biblioteca c4 = c1;
	c4.setOras("Timisoara");
	c4.setSuprafata(4500);
	cout << "Biblioteca din orasul " << c4.getOras() << " are o suprafata de " << c4.getSuprafata() << " metri patrati si trei sali de lectura numite dupa scriitori romani precum:  ";
	string* v3 = new string[3]{ "Eminescu,", "Creanga,", "Caragiale" };
	c4.setSaliLetura(3, v3);
	for (int j = 0; j < 3; j++)
		cout << c4.getSaliLetura()[j];
	delete[]v3;
	cout << endl;
	cout << c4[2] << endl;

	if (c2 > c4)
		cout << "c2 e mai mare";
	else
		cout << "c4 e mai mare";
	cout << endl;

	cout << getSirSaliLectura(c4) << endl;

	int numarBiblioteci;
	cout << "Introduceti numarul de biblioteci: ";
	cin >> numarBiblioteci;
	Biblioteca* biblioteca = new Biblioteca[numarBiblioteci];
	for (int i = 0; i < numarBiblioteci; i++) {
		cin >> biblioteca[i];
	}
	for (int i = 0; i < numarBiblioteci; i++) {
		cout << biblioteca[i];
	}
	delete[] biblioteca;

	Biblioteca::setPlaneta("planeta Terra");

    CartiRomanesti carte1, carte2;
    CartiRomanesti* vector = new CartiRomanesti[2]{ carte1, carte2 };
	Cititor d1;
	cout << d1 << endl;
	Cititor d2 = d1;
	cout << d2 << endl;
	Cititor d3(1, 2, vector);
	cout << d3;
}
