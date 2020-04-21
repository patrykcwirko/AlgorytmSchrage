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
		void push(uint32_t prio, Zadanie v);
		void pop();
		uint32_t size();
};

