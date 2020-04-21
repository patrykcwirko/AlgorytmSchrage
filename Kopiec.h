#pragma once

#include "Zadanie.h"

const int MAXINT = -2147483647;

struct qelement
{
	int prio;
	Zadanie data;
};

class Kopiec
{
	private:
		qelement* T;  // kopiec dynamiczny
		int n;         // liczba elementów

	public:
		Kopiec(int max_n);
		~Kopiec();
		bool empty();
		Zadanie  front();
		int  frontprio();
		void push(int prio, Zadanie v);
		void pop();
};

