#include "Kopiec.h"
#include <iostream>

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

//Najmniejsze
void Kopiec::pushN(uint32_t prio, Zadanie z)
{
	uint32_t k, l;

	k = ilosc++;
	l = (k-1) / 2;

	while (k > 0 && T[l].prio > prio)
	{
		T[k] = T[l];
		k = l;
		l = (k - 1) / 2;
	}

	T[k].prio = prio;
	T[k].dane = z;
}

//Narwiêksze
void Kopiec::pushQ(uint32_t prio, Zadanie z)
{
	uint32_t k, l;

	k = ilosc++;
	l = (k - 1) / 2;

	//TODO: jest jedynie dla q, a powinno byæ te¿ dla r
	while (k > 0 && T[l].prio < prio)
	{
		T[k] = T[l];
		k = l;
		l = (k - 1) / 2;
	}

	T[k].prio = prio;
	T[k].dane = z;
}

void Kopiec::popQ()
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
			//TODO: jest jedynie dla q, a powinno byæ te¿ dla r
			if (l + 1 > ilosc && T[l + 1].prio < T[l].prio) l++;
			//TODO: jest jedynie dla q, a powinno byæ te¿ dla r
			if (p <= T[l].prio) break;
			T[k] = T[l];
			k = l;
			l = 2 * l + 1;
		}

		T[k].prio = p;
		T[k].dane = z;
	}
}

void Kopiec::popN()
{
	uint32_t k, l, p;
	Zadanie z;

	if (ilosc--)
	{
		p = T[ilosc].prio;
		z = T[ilosc].dane;
		std::cout << p << std::endl;

		k = 0;
		l = 1;

		while (l < ilosc)
		{
			if (l + 1 < ilosc && T[l + 1].prio < T[l].prio) l++;
			if (p <= T[l].prio) break;
			T[k] = T[l];
			k = l;
			l = 2 * l+1;
		}

		T[k].prio = p;
		T[k].dane = z;
	}
}

uint32_t Kopiec::size()
{
	return ilosc;
}

void Kopiec::printBT(std::string sp, std::string sn, int v)
{

	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	std::string s;

	if (v < ilosc)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << T[v].prio << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, 2 * v + 1);
	}
}

void Kopiec::swap(int id_1, int id_2)
{
	qelement temp = T[id_1];
	T[id_1] = T[id_2];
	T[id_2] = temp;
}
