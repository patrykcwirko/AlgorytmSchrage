#include "Schrage.h"

uint32_t Schrage::max(uint32_t cmax, uint32_t propozycja)
{
    return uint32_t();
}

Schrage::Schrage(uint32_t n)
{
    tab = new Zadanie[n];
}

Schrage::~Schrage()
{
    delete[] tab;
}

uint32_t Schrage::permutuj(Kopiec kolejnoscZadanN)
{
    uint32_t t = 0, k = 0, cmax = 0;
    Kopiec kolejnoscZadanQ(kolejnoscZadanN.size() );
    Zadanie z;
    while (!kolejnoscZadanN.empty() || !kolejnoscZadanQ.empty()) {
        while ((!kolejnoscZadanN.empty()) && (kolejnoscZadanN.front().r <= t)) {
            z = kolejnoscZadanN.front();
            kolejnoscZadanN.pop();
            kolejnoscZadanQ.push(z.q, z);
        }
        if (kolejnoscZadanQ.empty()) {
            t = kolejnoscZadanN.front().r;
        }
        else {
            z = kolejnoscZadanQ.front();
            kolejnoscZadanQ.pop();
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
    return uint32_t();
}
