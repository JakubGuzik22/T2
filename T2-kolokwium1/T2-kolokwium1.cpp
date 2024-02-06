#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>


using namespace std;

int main()
{
	//zadania 1 i 2
	setlocale(LC_ALL, "");
	cout << "WYBÓR OPERACJI: " << endl;
	cout << "a) Wype³nianie rosn¹co od 0,11 z krokiem co 0,01" << endl;
	cout << "b) Wype³nianie malej¹co od 1,98 z krokiem co 0,02" << endl;
	cout << "c) Wype³nianie losowe z przedzia³u obustronnie domkniêtego podanego przez u¿ytkownika w postacica³kowitych granic przedzia³u." << endl;
	char wybor;
	cin >> wybor;
	double T[12] = {};
	int proby = 2; // zale¿nie od interpretacji treœci
	double* wsk = &T[0];
	double* wsk2 = &T[0];
	srand(time(NULL));
	double srednia = 0;

	while (wybor != 'a' && wybor != 'b' && wybor != 'c')
	{
		cin >> wybor;
		proby--;
		if (proby == 0)
		{
			break;
		}
	}

	switch (wybor)
	{
	case 'a':
		for (int i = 0; i < 12; i++)
		{
			*wsk = 0.11 + 0.01 * double(i);
			srednia = srednia + *wsk;
			++wsk;
		}
		break;

	case 'b':
		for (int i = 0; i < 12; i++)
		{
			*wsk = 1.98 - 0.02 * double(i);
			srednia = srednia + *wsk;
			++wsk;
		}
		break;
	default:
	case 'c':
		double dolnagranica;
		double gornagranica;
		cout << "Podaj doln¹ granicê: ";  cin >> dolnagranica;
		cout << "Podaj górn¹ granicê: ";  cin >> gornagranica;
		while (gornagranica - dolnagranica < 1||dolnagranica>=gornagranica)
		{
			cout << "Podano b³êdne watroœci" << endl;
			cout << "Podaj doln¹ granicê: ";  cin >> dolnagranica;
			cout << "Podaj górn¹ granicê: ";  cin >> gornagranica;
		}
		for (int i = 0; i < 12; i++)
		{

			*wsk = (dolnagranica*1.00 + (static_cast<double>(rand()) / RAND_MAX * (gornagranica - dolnagranica))*1.00);
			srednia = srednia + *wsk;
			++wsk;
		}
		break;
	}

	for (int i = 0; i < 12; i++)
	{
		cout << fixed << setprecision(2) << T[i] << '\t';
	}
	cout << endl;
	srednia = srednia / 12.0;
	cout << "Œrednia wynosi: " << fixed << setprecision(2) << srednia << endl;
	cout << "Wyœwietlanie zadania 3: " << endl;
	//zadanie 3
	double minroznica = abs(static_cast<double>(*wsk2 - srednia));
	for (int i = 0; i < 12; i++ )
	{
		double roznica = abs(static_cast<double>(T[i]) - srednia);
		if (roznica < minroznica)
		{
			minroznica = roznica;
			wsk2 = &T[i];
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (&T[i] == wsk2)
		{
			cout << fixed << setprecision(2) << *wsk2 << '\t';
		}
		else
		{
			cout << fixed << setprecision(2) << "0" << '\t';
		}
	}
	/*jeœli istniej¹ dwie liczby jednakowo bliskie œredniej np (œrednia = 1,5 ; liczba a = 1,4 ; liczba b = 1,6) to zostanie wyœwietlona ta pierwsza (czyli liczba a)*/
}
