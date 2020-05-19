#pragma once
#include "Zadanie.h"
#include <string>

const uint32_t MAXINT = 2147483647;

struct qelement
{
	uint32_t prio;
	Zadanie dane;
};

class KopiecOdw
{
private:
	qelement* T;  // kopiec dynamiczny
	uint32_t ilosc;         // liczba elementów

	void swap(int id_1, int id_2);

public:
	KopiecOdw(uint32_t max_n);
	~KopiecOdw();
	bool empty();
	uint32_t size();
	void printBT(std::string sp, std::string sn, int v);
	void ShiftDown(uint32_t id);
	void ShiftUp(uint32_t id);
	void Make();
	void push(uint32_t prio, Zadanie v);
	void pop();
	void HeapSort();
};

