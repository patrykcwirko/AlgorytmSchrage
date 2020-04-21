// AlgorytmSchrage.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include "Schrage.h"
#include "Kopiec.h"
#include "Zadanie.h"

#define DATA_SET "data.002"

using namespace std;

void testKopca()
{
	Kopiec kopiec(5);
	kopiec.push(1, Zadanie{ 1,1,1,1 });
	kopiec.push(3, Zadanie{ 3,3,3,3 });
	kopiec.push(4, Zadanie{ 2,2,2,2 });
	kopiec.push(5, Zadanie{ 5,5,5,5 });
	kopiec.push(4, Zadanie{ 4,4,4,4 });
	cout << "Pusty: " << kopiec.empty() << endl;
	cout << "Ilość: " << kopiec.size() << endl;
	cout << "FrontPrio: " << kopiec.frontPrio() << endl;
	cout << "Front R: " << kopiec.front().r << endl;
	//Wydrukować
	kopiec.pop();
	cout << "Pusty: " << kopiec.empty() << endl;
	cout << "Ilość: " << kopiec.size() << endl;
	cout << "FrontPrio: " << kopiec.frontPrio() << endl;
	cout << "Front R: " << kopiec.front().r << endl;	
	kopiec.pop();
	cout << "Pusty: " << kopiec.empty() << endl;
	cout << "Ilość: " << kopiec.size() << endl;
	cout << "FrontPrio: " << kopiec.frontPrio() << endl;
	cout << "Front R: " << kopiec.front().r << endl;
	kopiec.pop();
	cout << "Pusty: " << kopiec.empty() << endl;
	cout << "Ilość: " << kopiec.size() << endl;
	cout << "FrontPrio: " << kopiec.frontPrio() << endl;
	cout << "Front R: " << kopiec.front().r << endl;

}

int main()
{
	testKopca();

	//uint32_t N;
	//fstream data("schr.data.txt");
	//string tmp;
	//Schrage algorytm;

	//pomija dupuki nie natrafi na np. data.002;
	//while (tmp != DATA_SET) data >> tmp;

	//zczytuje ilość zadań
	//data >> N;

	//Kopiec KolejnoscZadanN(N);
	//Kopiec KolejnoscZadanQ(N);

	//zczytuje parametry zadań
	//for (uint32_t i = 0; i < N; ++i)
	//{
	//    uint32_t r, p, q;
	//    data >> r >> p >> q;
	//    KolejnoscZadanN.push(r, Zadanie{ r,p,q,i });
	//}

	
	//algorytm.schrage();


	cout << "Zrobione\n";
}
