#include "Schrage.h"
#include <iostream>

using namespace std;

uint32_t Schrage::max(uint32_t cmax, uint32_t propozycja)
{
    return (cmax <= propozycja) ? propozycja : cmax;
}

Schrage::Schrage(uint32_t n)
{
    tab = new Zadanie[n];
    rozmiar = n;
}

Schrage::~Schrage()
{
    delete[] tab;
}

uint32_t Schrage::permutuj(Zadanie* tabZad)
{
    uint32_t t = 0, k = 0, cmax = 0;
    priority_queue<Zadanie, vector<Zadanie>, PorownajG> kolejnoscZadanQ;
    priority_queue<Zadanie, vector<Zadanie>, PorownajN> kolejnoscZadanN;
    Zadanie z;

    for (int i = 0; i < rozmiar; i++)
    {
        kolejnoscZadanN.push(tabZad[i]);
    }

    while (!kolejnoscZadanN.empty() || !kolejnoscZadanQ.empty()) {
        while ((!kolejnoscZadanN.empty()) && (kolejnoscZadanN.top().r <= t)) {

            z = kolejnoscZadanN.top();
            kolejnoscZadanN.pop();
            kolejnoscZadanQ.push( z);
        }
        if (kolejnoscZadanQ.empty()) {
            t = kolejnoscZadanN.top().r;
        }
        else {
            z = kolejnoscZadanQ.top();
            kolejnoscZadanQ.pop();
            tab[k] = z;
            k++;
            t = t + z.p;
            cmax = max(cmax, t + z.q);
        }
    }
    return cmax;
}

uint32_t Schrage::permutujZPodzialem(Kopiec& kolejnoscZadanN)
{
    uint32_t t = 0, k = 0, cmax = 0;
    Kopiec kolejnoscZadanQ(kolejnoscZadanN.size());
    Zadanie z;
    while (!kolejnoscZadanN.empty() || !kolejnoscZadanQ.empty()) {
        while ((!kolejnoscZadanN.empty()) && (kolejnoscZadanN.front().r <= t)) {
            z = kolejnoscZadanN.front();
            kolejnoscZadanN.popN();
            kolejnoscZadanQ.pushQ(z.r, z);
        }
        if (kolejnoscZadanQ.empty()) {
            t = kolejnoscZadanN.front().r;
        }
        else {
            z = kolejnoscZadanQ.front();
            kolejnoscZadanQ.popQ();
            tab[k] = z;
            k++;
            t = t + z.p;
            cmax = max(cmax, t + z.q);
        }
    }
    return cmax;
}

uint32_t Schrage::cmaxtab()
{
    uint32_t i, t = 0, u = 0;
    for (i = 0; i < rozmiar; i++) {
        t = max(t, tab[i].r) + tab[i].p;
        u = max(u, t + tab[i].q);
    }
    return u;
}

void Schrage::ptrintKolejnosc()
{
    for (int i = 0; i < rozmiar; i++ )
    {
        std::cout << tab[i].o << " ";
    }
    std::cout << std::endl;
}

//cmax = 0
// for(o=0,b=1; o<N; o++, b*=2)
//  if(b&k)
//      cmax += p[o]
//
// for(o=0,b=1; o<N; o++, b*=2)
//  if(b&k)
// kara dla operacji o w chwili cmax max(cmax - D[o],0)*w[o]
// k=01011
// 