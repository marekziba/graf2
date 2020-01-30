#pragma once
#include "Graf.h"
#include "Population.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(Graf& g, int ncolors);
	int run(int nIter);
	void printResults();
private:
	Graf _g;
	Population _p;
	int _ncolors;
};

