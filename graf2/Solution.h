#pragma once
#include "Graf.h"
#include <vector>
#include <algorithm>

class Solution
{
public:
	Solution();
	Solution(Graf &g, int ncolors);
	Solution(std::vector<int> solutionVector, Graf& g, int ncolors);

	int getFitness();
	int size();
	void mutate(Graf &g, int mode);

	friend std::ostream& operator << (std::ostream& out, Solution& s);
	bool operator < (Solution& s);
	int& operator[] (int n);
private:
	void calculateFitness(Graf& g);

	std::vector<int> _colors;
	int _ncolors;
	int _fitness;
};

