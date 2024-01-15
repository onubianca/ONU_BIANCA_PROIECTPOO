#include <iostream>
#include<fstream>
using namespace std;

class ResursaCulturala //cls abstracta
{
public:
	virtual void afisare() = 0;
};

class Carti //cls abstracta
{
public:
	virtual void afisareCarti() = 0;
};

class CartiRomanesti: public Carti
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
	void afisareCarti()
	{
		cout << "Cartea " << this->titluCarte << " scrisa de " << this->numeAutor << " a fost publicata in anul " << this->anPublicatie << endl;
	}
	

	CartiRomanesti() :Carti(),  idCarte(1)
	{
		this->titluCarte = "Ion";
		this->numeAutor = "Rebreanu";
		this->anPublicatie = 1920;
		this->nrCapitole = 0;
		this->numeCapitole = NULL;

	}

	CartiRomanesti(string titluCarte, string numeAutor, int anPublicatie, int nrCapitole, string* numeCapitole) :Carti(), idCarte(5)
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

	CartiRomanesti(string titluCarte, string numeAutor, int anPublicatie) :Carti(), idCarte(25)
	{

		this->titluCarte = titluCarte;
		this->numeAutor = numeAutor;
		this->anPublicatie = anPublicatie;
		this->nrCapitole = 0;
		this->numeCapitole = NULL;
	}

	CartiRomanesti(const CartiRomanesti& a) :Carti(a), idCarte(a.idCarte)  //constructor copiere
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
			Carti::operator=(a);
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

	friend ofstream& operator<<(ofstream& iesireC, const CartiRomanesti& a);
	friend ifstream& operator>>(ifstream& intrareC, CartiRomanesti& a);
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

ofstream& operator<<(ofstream& iesireC, const CartiRomanesti& a)  //afisare in fis
{
	iesireC << a.titluCarte << endl;
	iesireC << a.numeAutor << endl;
	iesireC << a.anPublicatie << endl;
	iesireC << a.nrCapitole << endl;
	if (a.nrCapitole > 0)
		for (int i = 0; i < a.nrCapitole; i++)
			iesireC << a.numeCapitole[i] << " ";
	iesireC << endl;
	return iesireC;

}
ifstream& operator>>(ifstream& intrareC,CartiRomanesti& a)
{
	intrareC >> a.titluCarte;
	intrareC >> a.numeAutor;
	intrareC >> a.anPublicatie;
	intrareC >> a.nrCapitole;
	if (a.numeCapitole != NULL)
		delete[]a.numeCapitole;
	a.numeCapitole = new string[a.nrCapitole];
	for (int i = 0; i < a.nrCapitole; i++)
		intrareC >> a.numeCapitole[i];
	return intrareC;
}

class BenziDesenate: public Carti
{
private:
	char* titluBenzi;
	
public:
	void afisareCarti()
	{
		cout << this->titluBenzi << " este o banda desenata" << endl;
	}

	BenziDesenate() :Carti()
	{
		this->titluBenzi = new char[strlen("IronMan") + 1];
		strcpy_s(this->titluBenzi, strlen("IronMan") + 1, "IronMan");
	}
	BenziDesenate(const char* titluBenzi) :Carti()
	{
		this->titluBenzi = new char[strlen(titluBenzi) + 1];
		strcpy_s(this->titluBenzi, strlen(titluBenzi) + 1, titluBenzi);
	}
	BenziDesenate(const BenziDesenate& g):Carti()
	{
		this->titluBenzi = g.titluBenzi;
	}
	BenziDesenate operator=(const BenziDesenate& g) 
	{
		if (this != &g)
		{
			Carti::operator=(g);
			this->titluBenzi = g.titluBenzi;
		}
		return *this;
	}
	~BenziDesenate()
	{
		if (this->titluBenzi) delete[]this->titluBenzi;
	}
};


class Bibliotecar:public ResursaCulturala
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
	void afisare()
	{
		cout << this->numeBibliotecar << " este bibliotecar" << endl;
	}

	Bibliotecar() :ResursaCulturala(), cnp(nrLegitimatie++)
	{
		this->varsta = 26;
		this->numeBibliotecar = "Ana";
		this->nrLimbiStraine = 0;
		this->gen = 'f';
		this->limbiStraine = NULL;
	}

	Bibliotecar(string numeBibliotecar, int varsta, char gen, int nrLimbiStraine, string* limbiStraine) :ResursaCulturala(), cnp(nrLegitimatie++)
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

	Bibliotecar(string numeBibliotecar, int varsta) :ResursaCulturala(), cnp(nrLegitimatie)
	{
		nrLegitimatie++;
		this->varsta = varsta;
		this->numeBibliotecar = numeBibliotecar;
		this->gen = 'f';
		this->nrLimbiStraine = 0;
		this->limbiStraine = NULL;
	}

	Bibliotecar(const Bibliotecar& b) :ResursaCulturala(b), cnp(nrLegitimatie++)  //constructor copiere
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
			ResursaCulturala::operator=(b);
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

	void citireDinFisBinar(fstream& f) //met pt citire on fis bin
	{
		f.read((char*)&this->nrLimbiStraine, sizeof(int));
		if (this->limbiStraine)
			delete[] this->limbiStraine;
		this->limbiStraine = new string[this->nrLimbiStraine];
		for (int i = 0; i < this->nrLimbiStraine; i++) 
		{
			int l = 0;
			f.read((char*)&l, sizeof(int));
			char* limbaStraina = new char[l + 1];
			f.read((char*)limbaStraina, l);
			limbaStraina[l] = '\0';
			this->limbiStraine[i] = string(limbaStraina);
			delete[] limbaStraina;
		}
	}

	void scriereInFisBinar(fstream& g) //met pt scriere on fis bin
	{
		g.write((char*)&this->nrLimbiStraine, sizeof(int));
		for (int i = 0; i < this->nrLimbiStraine; i++) 
		{
			int l = this->limbiStraine[i].length();
			g.write((char*)&l, sizeof(int));
			g.write(this->limbiStraine[i].c_str(), l);
		}
	}

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

class Biblioteca: public ResursaCulturala
{
private:
	const int anInfiintare;
	static string planeta;
	string oras;
	float suprafata;
	int nrSaliLectura;
	string* numeSaliLectura;

public:
	void afisare()
	{
		cout << "In orasul " << this->oras << " exista biblioteca";
	}

	Biblioteca() :ResursaCulturala(), anInfiintare(1980)
	{
		this->suprafata = 5000;
		this->oras = "Bucuresti";
		this->nrSaliLectura = 0;
		this->numeSaliLectura = NULL;
	}

	Biblioteca(string oras, float suprafata, int nrSaliLectura, string* numeSaliLectura) :ResursaCulturala(), anInfiintare(1948)
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

	Biblioteca(int nrSaliLectura, string* numeSaliLectura) :ResursaCulturala(), anInfiintare(2005)
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


	Biblioteca(const Biblioteca& c) :ResursaCulturala(c), anInfiintare(c.anInfiintare)  //constructor copiere
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
			ResursaCulturala::operator=(c);
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

	void citireDinFisBinar(fstream& f)
	{
		f.read((char*)&this->nrSaliLectura, sizeof(int));
		if (this->numeSaliLectura)
			delete[] this->numeSaliLectura;
		this->numeSaliLectura = new string[this->nrSaliLectura];
		for (int i = 0; i < this->nrSaliLectura; i++)
		{
			int l = 0;
			f.read((char*)&l, sizeof(int));
			char* salaLectura = new char[l + 1];
			f.read((char*)salaLectura, l);
			salaLectura[l] = '\0';
			this->numeSaliLectura[i] = string(salaLectura);
			delete[] salaLectura;
		}
	}

	void scriereInFisBinar(fstream& g)
	{
		g.write((char*)&this->nrSaliLectura, sizeof(int));
		for (int i = 0; i < this->nrSaliLectura; i++)
		{
			int l = this->numeSaliLectura[i].length();
			g.write((char*)&l, sizeof(int));
			g.write(this->numeSaliLectura[i].c_str(), l);
		}
	}

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

//faza 5

class Cititor
{
private:
	const int idCititor;
	int nrCartiImprumutate;
	CartiRomanesti* carte;

public:
	Cititor() :idCititor(0)
	{
		this->nrCartiImprumutate = 0;

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
	friend istream& operator>>(istream& intrareCititor, Cititor& d);

	friend ofstream& operator<<(ofstream& iesireCi, const Cititor& d);
	friend ifstream& operator>>(ifstream& intrareCi, Cititor& d);
};
ostream& operator<<(ostream& iesireCititor, const Cititor& d)
{
	iesireCititor << "Cititorul a imprumutat  " << d.nrCartiImprumutate << " carti cum ar fi: ";
	if (d.nrCartiImprumutate > 0)
		for (int i = 0; i < d.nrCartiImprumutate; i++)
			iesireCititor << d.carte[i] << " ";
	else
		iesireCititor << " nu a imprumutat carti";
	iesireCititor << endl;
	return iesireCititor;
}
istream& operator>>(istream& intrareCititor, Cititor& d)
{
	cout << " nr carti imprumutate: ";
	intrareCititor >> d.nrCartiImprumutate;
	if (d.carte != NULL)
		delete[]d.carte;
	d.carte = new CartiRomanesti[d.nrCartiImprumutate];
	for (int i = 0; i < d.nrCartiImprumutate; i++)
	{
		cout << " titlurile cartilor imprumutate: ";
		intrareCititor >> d.carte[i];
	}
	return intrareCititor;
}

ofstream& operator<<(ofstream& iesireCi, const Cititor& d)  //afisare in fis
{
	iesireCi << d.nrCartiImprumutate << endl;
	if (d.nrCartiImprumutate > 0)
		for (int i = 0; i < d.nrCartiImprumutate; i++)
			iesireCi << d.carte[i] << " ";
	iesireCi << endl;
	return iesireCi;

}
ifstream& operator>>(ifstream& intrareCi, Cititor& d)
{
	intrareCi >> d.nrCartiImprumutate;
	if (d.carte != NULL)
		delete[]d.carte;
	d.carte = new CartiRomanesti[d.nrCartiImprumutate];
	for (int i = 0; i < d.nrCartiImprumutate; i++)
		intrareCi >> d.carte[i];
	return intrareCi;
}


class Autor : public CartiRomanesti
{
private:
	char* numeAutor;
	int nrCartiPublicate;

public:
	Autor() : CartiRomanesti()
	{
		this->nrCartiPublicate = 5;
		this->numeAutor = new char[strlen("Sadoveanu") + 1];
		strcpy_s(this->numeAutor, strlen("Sadoveanu") + 1, "Sadoveanu");
	}
	Autor(int nrCartiPublicate, const char* numeAutor) : CartiRomanesti()
	{
		this->nrCartiPublicate = nrCartiPublicate;
		this->numeAutor = new char[strlen(numeAutor) + 1];
		strcpy_s(this->numeAutor, strlen(numeAutor) + 1, numeAutor);
	}
	Autor(const Autor& a) : CartiRomanesti(a)
	{
		this->nrCartiPublicate = a.nrCartiPublicate;
		this->numeAutor = new char[strlen(a.numeAutor) + 1];
		strcpy_s(this->numeAutor, strlen(a.numeAutor) + 1, a.numeAutor);
	}
	Autor operator=(const Autor& a)
	{
		if(this!=&a)
		{
			(CartiRomanesti)*this = (CartiRomanesti)a;
			this->nrCartiPublicate = a.nrCartiPublicate;
			if (this->numeAutor) delete[]this->numeAutor;
			this->numeAutor = new char[strlen(a.numeAutor) + 1];
			strcpy_s(this->numeAutor, strlen(a.numeAutor) + 1, a.numeAutor);
		}
		return *this;
	}
	~Autor()
	{
		if (this->numeAutor) delete[]this->numeAutor;
	}

	char* getNumeAutor()
	{
		return this->numeAutor;
	}
	void setNumeAutor(char* numeAutor)
	{
		if (this->numeAutor) delete[]this->numeAutor;
		this->numeAutor = new char[strlen(numeAutor) + 1];
		strcpy_s(this->numeAutor, strlen(numeAutor) + 1, numeAutor);
	}
	int getNrCartiPublicate()
	{
		return this->nrCartiPublicate;
	}
	void setNrCartiPublicate(int nr)
	{
		this->nrCartiPublicate = nr;
	}

	friend ostream& operator<<(ostream& out, const Autor& a);
	friend istream& operator>>(istream& intrareAutor, Autor& a);
};
ostream& operator<<(ostream& iesireAutor, const Autor& a)
{
	iesireAutor << (CartiRomanesti)a;
	iesireAutor << a.nrCartiPublicate;
	iesireAutor << a.numeAutor;
	return iesireAutor;
}
istream& operator>>(istream& intrareAutor, Autor& a)
{
	intrareAutor >> (CartiRomanesti&)a;
	if (a.numeAutor) delete[]a.numeAutor;
	char aux[50];
	cout << endl;
	cout << " numele autorului este: ";
	intrareAutor >> aux;
	a.numeAutor = new char[strlen(aux) + 1];
	strcpy_s(a.numeAutor, strlen(aux) + 1, aux);
	cout << endl;
	cout << " numarul de carti publicate de autor sunt: ";
	cout << endl;
	intrareAutor >> a.nrCartiPublicate;
	return intrareAutor;
}

class PermisBiblioteca : public Cititor
{
private:
	char* serie;
	int valabilitate;

public:
	PermisBiblioteca() :Cititor()
	{
		this->valabilitate=2;
		this->serie = new char[strlen("dgvdg") + 1];
		strcpy_s(this->serie, strlen("dgvdg") + 1, "dgvdg");
	}
	PermisBiblioteca(int valabilitate, const char* serie) :Cititor()
	{
		this->valabilitate=valabilitate;
		this->serie = new char[strlen(serie) + 1];
		strcpy_s(this->serie, strlen(serie) + 1, serie);
	}
	PermisBiblioteca(const PermisBiblioteca& p) :Cititor()
	{
		this->valabilitate = p.valabilitate;
		this->serie = new char[strlen(p.serie) + 1];
		strcpy_s(this->serie, strlen(p.serie) + 1, p.serie);
	}
	PermisBiblioteca operator=(const PermisBiblioteca& p)
	{
		if (this != &p)
		{
			(Cititor)*this = (Cititor)p;
			this->valabilitate = p.valabilitate;
			if (this->serie) delete[]this->serie;
			this->serie = new char[strlen(p.serie) + 1];
			strcpy_s(this->serie, strlen(p.serie) + 1, p.serie);
		}
		return *this;
	}
	~PermisBiblioteca()
	{
		if (this->serie) delete[]this->serie;
	}
	char* getSerie()
	{
		return this->serie;
	}
	void setSerir(char* serie)
	{
		if (this->serie) delete[]this->serie;
		this->serie = new char[strlen(serie) + 1];
		strcpy_s(this->serie, strlen(serie) + 1, serie);
	}
	int getValabilitate()
	{
		return this->valabilitate;
	}
	void setValabilitate(int val)
	{
		this->valabilitate = val;
	}
	
     friend ostream& operator<<(ostream& iesirPermis, const PermisBiblioteca& p);
	 friend istream& operator>>(istream& intrarePermis, PermisBiblioteca& p);
};
ostream& operator<<(ostream& iesirPermis, const PermisBiblioteca& p)
{
	iesirPermis << (Cititor)p;
	iesirPermis << p.valabilitate;
	iesirPermis << p.serie;
	return iesirPermis;
}
istream& operator>>(istream& intrarePermis, PermisBiblioteca& p)
{
	intrarePermis >> (Cititor&)p;
	if (p.serie) delete[]p.serie;
	char aux[50];
	cout << endl;
	cout << " seria de pe permis: ";
	intrarePermis >> aux;
	p.serie = new char[strlen(aux) + 1];
	strcpy_s(p.serie, strlen(aux) + 1, aux);
	cout << endl;
	cout << " valabilitatea permisului: ";
	cout << endl;
	intrarePermis >> p.valabilitate;
	return intrarePermis;
}

class Colectie
{
private:
	int nr;
	Carti** carti;
public:
	Colectie()
	{
		this->nr = 10;
		this->carti = new Carti * [10];
		for (int i = 0; i < 10; i++)
			this->carti[i] = new CartiRomanesti();
	}
	Carti*& operator[](int i)
	{
		if (i >= 0 && i < this->nr)
			return this->carti[i];
	}
};

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

	CartiRomanesti a6, a7;
	cin >> a6;
	ofstream afisare("carte.txt", ios::out);
	afisare << a6;
	afisare.close();
	ifstream citire("carte.txt", ios::in);
	citire >> a7;
	cout << a7;
	citire.close();

	Cititor d4(1, 2, vector), d5;
	ofstream afisareC("cititor.txt", ios::out);
	afisare << d4;
	afisare.close();
	ifstream citireC("cititor.txt", ios::in);
	citire >> d5;
	cout << d5;
	citire.close();

	Bibliotecar b6, b7;
	cin >> b6;
	fstream g("bibliotecar.bin", ios::out | ios::binary);
	b6.scriereInFisBinar(g);
	g.close();

	fstream f("bibliotecar.bin", ios::in | ios::binary);
	b7.citireDinFisBinar(f);
	f.close();
	cout << b7;

	Biblioteca c6, c7;
	cin >> c6;
	fstream gB("biblioteca.bin", ios::out | ios::binary);
	c6.scriereInFisBinar(g);
	g.close();

	fstream fB("biblioteca.bin", ios::in | ios::binary);
	c7.citireDinFisBinar(f);
	f.close();
	cout << c7;

	Autor e1;
	Autor e2(5, "blaga");
	Autor e3 = e1;
	Autor e4;
	cin >> e4;
	cout << e4;
	cout << endl;
	PermisBiblioteca f1;
	PermisBiblioteca f2(6, "yyxygs");
	PermisBiblioteca f3 = f1;
	PermisBiblioteca f4;
	cin >> f4;
	cout << f4;

    //faza 8
	cout << endl;
CartiRomanesti a10("Ion", "Rebreanu", 1920);
a10.afisareCarti();

Carti* x;
x = new BenziDesenate();
x->afisareCarti();

cout << endl;

Colectie y;
y[0] = new CartiRomanesti("Baltagul", "Sadoveanu", 1930);
y[1] = new CartiRomanesti("Ion", "Rebreanu", 1920);
y[2] = new  BenziDesenate();
y[3] = new BenziDesenate("Thor");
y[4] = new CartiRomanesti("Morometii", "Preda", 1955);
y[5] = new CartiRomanesti("Soimii", "Sadoveanu", 1904);
y[6] = new CartiRomanesti("Rascoala", "Rebreanu", 1933);
y[7] = new BenziDesenate("Black Phanter");
y[8] = new BenziDesenate("Captain America");
y[9] = new BenziDesenate("Avengers");
for (int i = 0; i < 10; i++)
	y[i]->afisareCarti();
}

