#include "Schrage.h"

uint32_t Schrage::schrage(Kopiec kolejnoscZadanN, Kopiec kolejnoscZadanQ)
{
    uint32_t N = 0;
    Zadanie e = Zadanie{ 0,0,0,0 };

    uint32_t t = 0, k = 0, cMax = 0;


    while (kolejnoscZadanQ.empty() || kolejnoscZadanN.empty()) {
        //wyszukiwanie zadañ o najkrutszym czasie dostêpu
        while ((!kolejnoscZadanN.empty() ) && (kolejnoscZadanN.front().r <= t))
        {
            e = kolejnoscZadanN.front();
            kolejnoscZadanN.pop();
            kolejnoscZadanQ.push(e.q, e);
        }
        if (kolejnoscZadanQ.empty())
        {
            t = kolejnoscZadanN.front().r;
        }
    }


    return cMax;
}
