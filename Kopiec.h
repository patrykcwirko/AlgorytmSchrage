#pragma once

#include "Schrage.h"
#include "Zadanie.h"

class Kopiec
{

	public:
		Kopiec(int max_n);
		~Kopiec();
		void push(int prio, Zadanie v);
};

