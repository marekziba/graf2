#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(Graf& g, int ncolors) :
	_g(g), _ncolors(ncolors), _p(g,50,ncolors) {}

int GeneticAlgorithm::run(int termCondition) {
	int nIter = 0;
	while (_p[0].getFitness() > 0 and nIter < termCondition) {
		nIter++;
		//std::cout << nIter <<"  " <<_p[0].getFitness() << "\n";
		_p.refresh();
	}
	if (_p[0].getFitness() == 0) return 1;
	else return 0;
}

void GeneticAlgorithm::printResults() {
	for (int i = 0; i < _p.size(); i++) {
		std::cout << _p[i];
	}
}