﻿// AlgorytmSchrage.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include "Schrage.h"
#include "Kopiec.h"
#include "Zadanie.h"

#define DATA_SET "data.002"

using namespace std;

int main()
{
    uint32_t N;
    fstream data("schr.data.txt");
    string tmp;
    Schrage algorytm;

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

    algorytm.schrage();


    cout << "Zrobione\n";
}
