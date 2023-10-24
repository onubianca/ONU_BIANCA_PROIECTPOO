#include <iostream>
using namespace std;

class CartiRomanesti 
{
public:
	const int idCarte;
	static string limba;
	string titluCarte;
	string numeAutor;
	int anPublicatie;
	int nrCapitole;
	string* numeCapitole;
	

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

	~CartiRomanesti()
	{
		if (this->numeCapitole != NULL)
			delete[]this->numeCapitole;
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

	string getLimbaPublicatie()
	{
		return limba;
	}
};
string CartiRomanesti::limba = "romana";

class Bibliotecar
{
public:
	const int cnp;
	static int nrLegitimatie;
	string numeBibliotecar;
	int varsta;
	int nrLimbiStraine;
	string* limbiStraine;

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

	~Bibliotecar()
	{
		if (this->limbiStraine != NULL)
			delete[]this->limbiStraine;
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

	static int getNrLegitimatie()
	{
		return nrLegitimatie++;
	}

};
 int Bibliotecar::nrLegitimatie = 1;

class Biblioteca
{
public:
	const int anInfiintare;
	static string planeta;
	string oras;
	float suprafata;
	int nrSaliLectura;
	string* numeSaliLectura;

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

	~Biblioteca()
	{
		if (this->numeSaliLectura != NULL)
			delete[]this->numeSaliLectura;
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

	static void setPlaneta(string planeta) 
	{
		Biblioteca::planeta = planeta;
	}
};
string Biblioteca::planeta = "Terra";

void main()
{
	CartiRomanesti a1;
	a1.afisCartiRomanesti();

	string* numeCapitole = new string[2];
	numeCapitole[0] = "Glasul Pamantului";
	numeCapitole[1] = "Glasul Iubirii";

	CartiRomanesti a2("Ion", "Rebreanu", 1920, 2, numeCapitole) ;
	a2.afisCartiRomanesti();

	CartiRomanesti a3("Morometii", "Preda", 1955);
	a3.afisCartiRomanesti();

	cout << a3.getLimbaPublicatie() << endl;

	Bibliotecar b1;
	b1.afisBibliotecar();

	string* limbiStraine = new string[3];
	limbiStraine[0] = "engleza";
	limbiStraine[1] = "germana";
	limbiStraine[2] = "franceza";

	Bibliotecar b2("Maria", 37, 3, limbiStraine);
	b2.afisBibliotecar();

	Bibliotecar b3("Anca", 29);
	b3.afisBibliotecar();

	cout << b2.getNrLegitimatie() << endl;

	Biblioteca c1;
	c1.afisBiblioteca();

	string* numeSaliLectura = new string[2];
	numeSaliLectura[0] = "Eminescu";
	numeSaliLectura[1] = "Creanga";
	
	Biblioteca c2("Iasi", 1500, 2, numeSaliLectura);
	c2.afisBiblioteca();

	Biblioteca c3(2, numeSaliLectura);
	c3.afisBiblioteca();

	Biblioteca::setPlaneta("planeta Terra");
	
}