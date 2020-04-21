#include "Kopiec.h"

Kopiec::Kopiec(uint32_t max_n)
{
	//tworzenie pamiêci dla elementów kopca
	T = new qelement[max_n];
	// kopiec jest pusty
	ilosc = 0;                  
}

Kopiec::~Kopiec()
{
	delete[] T;
}

bool Kopiec::empty()
{
	//czy kolejka jest pusta
	return !ilosc;
}

Zadanie Kopiec::front()
{
	return ilosc ? T[0].dane : Zadanie{ MAXINT, MAXINT, MAXINT, MAXINT };
}

uint32_t Kopiec::frontPrio()
{
	return ilosc ? T[0].prio : MAXINT;
}

void Kopiec::push(uint32_t prio, Zadanie z)
{
	uint32_t k, l;

	k = ilosc++;
	l = (k - 1) / 2;

	while (k > 0 && T[l].prio < prio)
	{
		T[k] = T[l];
		k = l;
		l = (k - 1) / 2;
	}

	T[k].prio = prio;
	T[k].dane = z;
}

void Kopiec::pop()
{
	uint32_t k, l, p;
	Zadanie z;

	if (ilosc--)
	{
		p = T[ilosc].prio;
		z = T[ilosc].dane;

		k = 0;
		l = 1;

		while (l < ilosc)
		{
			if (l + 1 < ilosc && T[l + 1].prio > T[l].prio) l++;
			if (p >= T[l].prio) break;
			T[k] = T[l];
			k = l;
			l = 2 * l + 1;
		}

		T[k].prio = p;
		T[k].dane = z;
	}
}

uint32_t Kopiec::size()
{
	return ilosc;
}
