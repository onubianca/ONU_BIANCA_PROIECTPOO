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

	CartiRomanesti operator=(const CartiRomanesti& a)
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

	void setTitluCarte(string titluCarte)
        {
		if (titluCarte.length() > 3)
			this->titluCarte = titluCarte;
	}

	string getTitluCarte()
	{
		return this->titluCarte;
	}

	void setNumeAutor(string numeAutor) 
        {
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

	void afisCartiRomanesti()
	{
		cout << "Cartea " << titluCarte << " scrisa de " << numeAutor << " publicata in anul " << anPublicatie << " are " << nrCapitole << " capitole, denumite astfel: ";
		if (nrCapitole > 0)
			for (int i = 0; i < nrCapitole; i++)
				cout << numeCapitole[i] << " ";
		else
			cout << " nu are capitole";
		cout << endl;
	}
};
string CartiRomanesti::limba = "romana";

class Bibliotecar
{
private:
	const int cnp;
	static int nrLegitimatie;
	string numeBibliotecar;
	int varsta;
	int nrLimbiStraine;
	string* limbiStraine;

public:
	Bibliotecar() :cnp(nrLegitimatie++)
	{
		this->varsta = 26;
		this->numeBibliotecar = "Ana";
		this->nrLimbiStraine = 0;
		this->limbiStraine = NULL;
	}

	Bibliotecar(string numeBibliotecar, int varsta, int nrLimbiStraine, string* limbiStraine) :cnp(nrLegitimatie++) 
	{
		this->numeBibliotecar = numeBibliotecar;
		this->varsta = varsta;
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
		this->nrLimbiStraine = 0;
		this->limbiStraine = NULL;
	}

	Bibliotecar(const Bibliotecar& b) :cnp(nrLegitimatie++)  //constructor copiere
	{
		this->numeBibliotecar = b.numeBibliotecar;
		this->varsta = b.varsta;
		this->nrLimbiStraine = b.nrLimbiStraine;
		this->limbiStraine = new string[b.nrLimbiStraine];
		for (int i = 0; i < b.nrLimbiStraine; i++)
		{
			this->limbiStraine[i] = b.limbiStraine[i];
		}
	}

	Bibliotecar operator=(const Bibliotecar& b)
	{
		if (this != &b)
		{
			this->numeBibliotecar = b.numeBibliotecar;
			this->varsta = b.varsta;
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
		Bibliotecar::nrLegitimatie=nrLegitimaie+1;
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

	void afisBibliotecar()
	{
		cout << "Bibliotecara " << numeBibliotecar << " are " << varsta << " de ani si cunoaste " << nrLimbiStraine << " limbi straine cum ar fi: ";
		if (nrLimbiStraine > 0)
			for (int i = 0; i < nrLimbiStraine; i++)
				cout << limbiStraine[i] << " ";
		else
			cout << " nu cunoste limbi straine.";
		cout << endl;
	}

	friend int getVarsta(Bibliotecar b);
};
 int Bibliotecar::nrLegitimatie = 100;

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

	Biblioteca operator=(const Biblioteca& c)
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

	void afisBiblioteca()
	{
		cout << "Biblioteca din orasul " << oras << " are o suprafata de " << suprafata << " metri patrati si  " << nrSaliLectura << " sali lectura numite dupa scriitori romani precum:  ";
		if (nrSaliLectura > 0)
			for (int i = 0; i < nrSaliLectura; i++)
				cout << numeSaliLectura[i] << " ";
		else
			cout << " nu are sali de lectura.";
		cout << endl;
		cout << "Biblioteca se afla pe planeta " << planeta << endl;
	}

	friend string getSirSaliLectura(const Biblioteca& c);
};
string Biblioteca::planeta = "Terra";

int getVarsta(Bibliotecar b)
{
	return b.varsta;
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

void main()
{
	CartiRomanesti a1;
	a1.afisCartiRomanesti();

	string* numeCapitole = new string[2];
	numeCapitole[0] = "Glasul Pamantului,";
	numeCapitole[1] = "Glasul Iubirii";

	CartiRomanesti a2("Ion", "Rebreanu", 1920, 2, numeCapitole) ;
	a2.afisCartiRomanesti();

	CartiRomanesti a3("Morometii", "Preda", 1955);
	a3.afisCartiRomanesti();

	cout << a3.getLimbaPublicatie() << endl;

	CartiRomanesti a4;
	a4 = a2;
	a4.afisCartiRomanesti();

	cout << a4.getLimbaPublicatie() << endl;

	a4.setTitluCarte("Morometii");
	cout << a4.getTitluCarte() << endl;

	a4.setNumeAutor("Preda");
	cout << a4.getNumeAutor() << endl;

	a4.setAnPublicatie(1955);
	cout << a4.getAnPublicatie() << endl;

	string* v1 = new string[2]{ "Partea I,", "Partea II" };  
	a4.setCapitole(2, v1);
	for (int j = 0; j < 2; j++)
		cout << a4.getNumeCapitole()[j] << endl;
	delete[]v1;

	a4.afisCartiRomanesti();

	Bibliotecar b1;
	b1.afisBibliotecar();

	cout << b1.getNrLegitimatie() << endl;

	string* limbiStraine = new string[3];
	limbiStraine[0] = "engleza,";
	limbiStraine[1] = "germana,";
	limbiStraine[2] = "franceza";

	Bibliotecar b2("Maria", 37, 3, limbiStraine);
	b2.afisBibliotecar();

	Bibliotecar b3("Anca", 29);
	b3.afisBibliotecar();

	Bibliotecar b4 = b3;
	b4.afisBibliotecar();

	b4.setNumeBibliotecar("Sara");
	cout << b4.getNumeBibliotecar() << endl;

	b4.setVarsta(47);
	cout << b4.getVarsta() << endl;

	string* v2 = new string[4]{ "engleza,", "franceza,", "germana,", "araba"};
	b4.setLimbiStraine(4, v2);
	for (int j = 0; j < 4; j++)
		cout << b4.getLimbiStraine()[j] << endl;
	delete[]v2;

	b4.afisBibliotecar();

	cout << getVarsta(b1)<< endl;

	Biblioteca c1;
	c1.afisBiblioteca();

	string* numeSaliLectura = new string[2];
	numeSaliLectura[0] = "Eminescu,";
	numeSaliLectura[1] = "Creanga";
	
	Biblioteca c2("Iasi", 1500, 2, numeSaliLectura);
	c2.afisBiblioteca();

	Biblioteca c3(2, numeSaliLectura);
	c3.afisBiblioteca();

	Biblioteca c4 = c1;
	c4.afisBiblioteca();

	c4.setOras("Timisoara");
	cout << c4.getOras() << endl;

	c4.setSuprafata(4500);
	cout << c4.getSuprafata() << endl;

	string* v3 = new string[3]{ "Eminescu,", "Creanga,", "Caragiale"};
	c4.setSaliLetura(3, v3);
	for (int j = 0; j < 3; j++)
		cout << c4.getSaliLetura()[j] << endl;
	delete[]v3;

	c4.afisBiblioteca();

	cout << getSirSaliLectura(c4) << endl;

	Biblioteca::setPlaneta("planeta Terra");
	
}
