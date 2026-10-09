#include <iostream>
using namespace std;

struct Ghiozdan
{
	float lungime;
	int nrBuzunare;
	bool laptop;
	char* producator;
};

Ghiozdan citireGhiozdan()
{
	char numeProducator[10];
	Ghiozdan g;
	cout << "Lungime= ";
	cin >> g.lungime;
	cout << "Buzunare= ";
	cin >> g.nrBuzunare;
	cout << "Pt laptop? :(0/1): ";
	cin >> g.laptop;
	cout << "Producator= ";
	cin >> numeProducator;
	g.producator = new char[strlen(numeProducator) + 1];
	strcpy_s(g.producator, strlen(numeProducator) + 1, numeProducator);
	return g;
}

void modificareLungime(Ghiozdan* g, float lungimeNoua)
{
	(*g).lungime = lungimeNoua;
}

int calculeazaNrBuzunareTotal(Ghiozdan* ghiozdane, int nrGhiozdane)
{
	int suma = 0;
	for (int i = 0; i < nrGhiozdane; i++)
	{
		suma += ghiozdane[i].nrBuzunare;
	}
}

void afisareGhiozdan(Ghiozdan g)
{
	cout << endl << "Lungime: " << g.lungime << endl;
	cout << "Buzunare: " << g.nrBuzunare << endl;
	cout << "Laptop: " << g.laptop << endl;
	cout << "Producator: " << g.producator << endl << endl;
}

void main()
{
	/*Ghiozdan g = citireGhiozdan();
	afisareGhiozdan(g);
	modificareLungime(&g, 12);
	afisareGhiozdan(g);*/

	int nrGhiozdane = 3;
	Ghiozdan* ghiozdane;
	ghiozdane = new Ghiozdan[3];
	for (int i = 0; i < nrGhiozdane; i++)
	{
		ghiozdane[i] = citireGhiozdan();
	}

	for (int i = 0; i < nrGhiozdane; i++)
	{
		afisareGhiozdan(ghiozdane[i]);
	}

	cout << "Nr total de buzunare: " << calculeazaNrBuzunareTotal(ghiozdane, nrGhiozdane);
}