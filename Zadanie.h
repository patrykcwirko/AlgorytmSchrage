#pragma once
#include <cstdint>

const uint32_t MAXINT = 2147483647;

struct Zadanie
{
    uint32_t r;
    uint32_t p;
    uint32_t q;
    uint32_t o; //numer zadania
};

struct qelement
{
    uint32_t prio;
    Zadanie dane;
};