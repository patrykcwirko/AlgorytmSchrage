#pragma once

#include <cstdint>
#include "Kopiec.h"
#include "Zadanie.h"


class Schrage
{
    private:
        uint32_t rozmiar;
        Zadanie* tab;
        uint32_t max(uint32_t cmax, uint32_t propozycja);

    public:
        Schrage(uint32_t n);
        ~Schrage();
        uint32_t permutuj(Kopiec &kolejnoscZadanN);
        uint32_t permutujZPodzialem(Kopiec &kolejnoscZadanN);
        uint32_t cmaxtab();
        void ptrintKolejnosc();
};

