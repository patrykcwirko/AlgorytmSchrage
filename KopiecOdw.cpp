#include "KopiecOdw.h"
#include <iostream>

KopiecOdw::KopiecOdw(uint32_t max_n)
{
	//tworzenie pamiêci dla elementów kopca
	T = new qelement[max_n + 1];
	T[0].dane.r = -1;
	T[0].dane.p = -1;
	T[0].dane.q = -1;
	T[0].dane.o = -1;
	T[0].prio = -1;
	// kopiec jest pusty
	ilosc = 0;
}

KopiecOdw::~KopiecOdw()
{
	delete[] T;
}

bool KopiecOdw::empty()
{
	//czy kolejka jest pusta
	return !ilosc;
}

uint32_t KopiecOdw::size()
{
	return ilosc;
}

Zadanie KopiecOdw::front()
{
	return ilosc ? T[1].dane : Zadanie{ MAXINT, MAXINT, MAXINT, MAXINT };
}

uint32_t KopiecOdw::frontPrio()
{
	return ilosc ? T[1].prio : MAXINT;
}

void KopiecOdw::printBT(std::string sp, std::string sn, int v)
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

		std::cout << s << sn << T[v+1].prio << "-" << T[v+1].dane.o << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, 2 * v + 1);
	}
}

void KopiecOdw::ShiftDown(uint32_t id)
{
	uint32_t next = 2 * id;
	while (next <= ilosc)
	{
		if ((next < ilosc) && (T[next].prio > T[next + 1].prio))
			next++;
		if (T[id].prio > T[next].prio)
		{
			swap(id, next);
			id = next;
			next *= 2;
		}
		else
		{
			next = ilosc +1;
		}
	}
	//printBT("","",0);
}

void KopiecOdw::ShiftUp(uint32_t id)
{
	int next = id / 2;
	while ((id > 1) && (T[next].prio > T[id].prio))
	{
		swap(id, next);
		id = next;
		next /= 2;
	}
}

void KopiecOdw::Make()
{
	for (uint32_t count = ilosc / 2; count > 0; count--)
	{
		ShiftDown(1);
	}
}

void KopiecOdw::push(uint32_t prio, Zadanie v)
{
	T[++ilosc] = qelement{ prio, v };
	ShiftUp(ilosc);
}

void KopiecOdw::pop()
{
	swap(1, ilosc--);
	ShiftDown(1);
}

void KopiecOdw::HeapSort()
{
	Make();
	while (ilosc > 0)
	{
		pop();
	}
}

void KopiecOdw::swap(int id_1, int id_2)
{
	qelement temp = T[id_1];
	T[id_1] = T[id_2];
	T[id_2] = temp;
}
