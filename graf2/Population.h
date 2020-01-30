#pragma once
#include <vector>
#include <algorithm>
#include "Solution.h"

#define MUTATION_PROBABILTY 95

class Population
{
public:
	Population(Graf &g, int size, int ncolors);

	void refresh();
	int size();

	friend std::ostream& operator << (std::ostream& out, Population &p);
	Solution& operator [] (int n);
	friend Solution reproduce(Population p, Graf& g, int mode);
private:
	int _ncolors;
	Graf _g;
	std::vector<Solution> _solutions;
	void sort();
};

