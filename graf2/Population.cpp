#include "Population.h"
#include "utils.h"

Population::Population(Graf &g, int size, int ncolors): _ncolors(ncolors), _g(g) {
	_solutions.resize(size);
	for (int i = 0; i < _solutions.size(); i++) {
		_solutions[i] = Solution(g, _ncolors);
	}
	this->sort();
}

void Population::refresh() {
	//std::cout << "Refreshing population...\nSorting...\n";
	this->sort();
	int breakPoint = (int) _solutions.size() / 2;
	int counter;
	//std::cout << "Removing worse performing half of the population...\n";
	//std::cout << "Initial population size " << _solutions.size() << ", breakpoint set to " << breakPoint << "\n";
	for (int i = breakPoint; i < _solutions.size(); i++) {
		//std::cout << "Replacing " << _solutions[i];
		_solutions[i] = Solution(_g, _ncolors);
		//std::cout << " with " << _solutions[i] << "\n";
	}
	this->sort();
	int mode;
	if (_solutions[0].getFitness() >= 4) {
		mode = 0;
	}
	else {
		mode = 1;
	}
	mode = 0;
	for (int i = breakPoint; i < _solutions.size(); i++) {
		//_solutions[i] = reproduce(*this, _g, mode);
		Solution child = reproduce(*this, _g, mode);
		if (std::rand() % 100 <= MUTATION_PROBABILTY) {
			child.mutate(_g, mode);
		}
		_solutions[i] = child;
	}
	this->sort();
}

int Population::size() {
	return _solutions.size();
}

void Population::sort() {
	std::sort(_solutions.begin(), _solutions.end());
}


std::ostream& operator << (std::ostream& stream, Population& p) {
	for (Solution s : p._solutions) {
		stream << s <<"\n";
	}
	return stream;
}

Solution & Population::operator[] (int n) {
	return _solutions[n];
}