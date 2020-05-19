#pragma once

#include <cstdint>
#include <queue>
#include <vector>
#include "Kopiec.h"
#include "Zadanie.h"
#include "KopiecOdw.h"



struct PorownajN
{
    bool operator()(Zadanie& a, Zadanie& b)
    {
        return a.r > b.r;
    }
};

struct PorownajG
{
    bool operator()(Zadanie& a, Zadanie& b)
    {
        return a.q < b.q;
    }
};

class Schrage
{
    private:
        uint32_t rozmiar;
        Zadanie* tab;
        uint32_t max(uint32_t cmax, uint32_t propozycja);

    public:
        Schrage(uint32_t n);
        ~Schrage();
        uint32_t permutuj(Zadanie* tabZad);
        uint32_t permutujZPodzialem(Zadanie* tabZad);
        uint32_t cmaxtab();
        void ptrintKolejnosc();
};

