#pragma once

#include "Zadanie.h"

const uint32_t MAXINT = 2147483647;

struct qelement
{
	uint32_t prio;
	Zadanie dane;
};

class Kopiec
{
	private:
		qelement* T;  // kopiec dynamiczny
		uint32_t ilosc;         // liczba elementów

	public:
		Kopiec(uint32_t max_n);
		~Kopiec();
		bool empty();
		Zadanie  front();
		uint32_t  frontPrio();
		void pushQ(uint32_t prio, Zadanie v);
		void pushN(uint32_t prio, Zadanie v);
		void popQ();
		void popN();
		uint32_t size();
};

