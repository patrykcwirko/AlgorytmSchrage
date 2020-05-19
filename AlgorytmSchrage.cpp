// AlgorytmSchrage.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include "Schrage.h"
#include "Kopiec.h"
#include "Zadanie.h"
#include "KopiecOdw.h"

#define DATA_SET_000 "data.000:"

using namespace std;

void testKopca()
{
	Kopiec kopiec(5);
	kopiec.pushN(1, Zadanie{ 1,1,1,1 });
	kopiec.pushN(3, Zadanie{ 3,3,3,3 });
	kopiec.pushN(4, Zadanie{ 2,2,2,2 });
	kopiec.pushN(5, Zadanie{ 5,5,5,5 });
	kopiec.pushN(4, Zadanie{ 4,4,4,4 });
	cout << "Pusty: " << kopiec.empty() << endl;
	cout << "Ilość: " << kopiec.size() << endl;
	cout << "FrontPrio: " << kopiec.frontPrio() << endl;
	cout << "Front R: " << kopiec.front().r << endl;
	//Wydrukować
	kopiec.popN();
	cout << "Pusty: " << kopiec.empty() << endl;
	cout << "Ilość: " << kopiec.size() << endl;
	cout << "FrontPrio: " << kopiec.frontPrio() << endl;
	cout << "Front R: " << kopiec.front().r << endl;	
	kopiec.popN();
	cout << "Pusty: " << kopiec.empty() << endl;
	cout << "Ilość: " << kopiec.size() << endl;
	cout << "FrontPrio: " << kopiec.frontPrio() << endl;
	cout << "Front R: " << kopiec.front().r << endl;
	kopiec.popN();
	cout << "Pusty: " << kopiec.empty() << endl;
	cout << "Ilość: " << kopiec.size() << endl;
	cout << "FrontPrio: " << kopiec.frontPrio() << endl;
	cout << "Front R: " << kopiec.front().r << endl;

}

void wyswietl(Schrage) {

}

int main()
{
	//testKopca();

	uint32_t N;
	fstream data("schr.data.txt");
	string tmp;

	//pomija dupóki nie natrafi na np. data.000;
	while (tmp != DATA_SET_000) data >> tmp;

	//zczytuje ilość zadań
	data >> N;

	KopiecOdw kolejnoscZadanN(N);
	Kopiec kolejnoscZadanQ(N);

	Schrage schrage(N);
	Schrage schrageZPodzialem(N);

	//zczytuje parametry zadań
	for (uint32_t i = 0; i < N; ++i)
	{
	    uint32_t r, p, q;
	    data >> r >> p >> q;
	    kolejnoscZadanN.push(r, Zadanie{ r,p,q,i+1 });
	    //kolejnoscZadanQ.pushQ(r, Zadanie{ r,p,q,i });
	}

	cout << "  Obliczanie kolejnosci... \n";

	//schrage.permutuj(kolejnoscZadanN);
	//schrage.ptrintKolejnosc();
	//int cmtab = schrage.cmaxtab();
	//cout << "  Czas trwania Cmax: " << cmtab << endl;

	//cout << "  Obliczanie kolejnosci... \n";	
	//schrageZPodzialem.permutujZPodzialem(kolejnoscZadanQ);
	//schrageZPodzialem.ptrintKolejnosc();
	//cmtab = schrageZPodzialem.cmaxtab();
	//cout << "  Czas trwania Cmax: " << cmtab << endl;


	//algorytm.schrage(kolejnoscZadanN, kolejnoscZadanQ);


	cout << "Zrobione\n";
}
