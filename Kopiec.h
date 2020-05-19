#pragma once

#include "Zadanie.h"
#include <string>

class Kopiec
{
	private:
		qelement* T;  // kopiec dynamiczny
		uint32_t ilosc;         // liczba element�w

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
		Zadanie getElement(uint32_t id);
		void ShiftDown(uint32_t id);
		void ShiftUp(uint32_t id);
		void Make();
		void push(uint32_t prio, Zadanie v);
		void pop();
		void HeapSort();
};

