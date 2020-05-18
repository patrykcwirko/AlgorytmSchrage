#pragma once

#include "Zadanie.h"
#include <string>

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

		void swap(int id_1, int id_2);

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
		void printBT(std::string sp, std::string sn, int v);

		void insert(Zadanie t);
		void ShiftUp(int id);
		Zadanie extractMax();
		void ShiftDown(int id);
};

