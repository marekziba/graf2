#include "Solution.h"

Solution::Solution() {
	_fitness = 0;
}

Solution::Solution(Graf &g, int ncolors): _ncolors(ncolors) {
	_colors.resize(g.size());
	_fitness = 0;
	std::generate(_colors.begin(), _colors.end(), std::rand );
	for (int i = 0; i < _colors.size(); i++) {
		_colors[i] = _colors[i] % ncolors;
	}
	calculateFitness(g);
}

Solution::Solution(std::vector<int> solutionVector, Graf &g, int ncolors): 
	_colors(solutionVector), _ncolors(ncolors) 
{
	_fitness = 0;
	calculateFitness(g);
}

std::ostream& operator << (std::ostream& stream, Solution& s) {
	stream << "[";
	for (int i = 0; i < s._colors.size(); i++) {
		if (i == s._colors.size() - 1) {
			stream << s._colors[i] << "]";
		}
		else {
			stream << s._colors[i] << ", ";
		}
	}
	//out << stream.str();
	stream << "\t" << s.getFitness() <<"\n";
	return stream;
}

bool Solution::operator<(Solution& s) {
	return this->_fitness < s._fitness;
}

int& Solution::operator[] (int n) {
	return _colors[n];
}

int Solution::getFitness() {
	return _fitness;
}

int Solution::size() {
	return _colors.size();
}

void Solution::mutate(Graf &g, int mode) {
	//std::cout << "Let's mutate some shit!\n";
	std::vector<int> adjacentVertices, validColors, colorVector; // , validColors_copy;
	bool violated;
	validColors.resize(_ncolors);
	int color, idx;
	if (mode == 0) {
		for (int i = 0; i < _colors.size(); i++) {
			adjacentVertices = g.getAdjacentVertices(i);
			violated = false;
			colorVector.clear();
			std::fill(validColors.begin(), validColors.end(), 0);
			for (int j : adjacentVertices) {
				validColors[_colors[j]] = -1;
				if (_colors[i] == _colors[j] && i < j) {
					violated = true;
				}
			}
			for (int i = 0; i < validColors.size(); i++) {
				if (validColors[i] != -1) {
					colorVector.push_back(i);
				}
			}
			if (violated) {
				if (colorVector.size() > 0) {
					color = colorVector[std::rand() % colorVector.size()];
				}
				else {
					color = std::rand() % _ncolors;
				}
				_colors[i] = color;
			}
		}
	}
	else {
		for (int i = 0; i < _colors.size(); i++) {
			adjacentVertices = g.getAdjacentVertices(i);
			violated = false;
			colorVector.clear();
			std::fill(validColors.begin(), validColors.end(), 0);
			for (int j : adjacentVertices) {
				validColors[_colors[j]] = -1;
				if (_colors[i] == _colors[j] && i < j) {
					_colors[i] = std::rand() % _ncolors;
				}
			}
		}
	}
	this->calculateFitness(g);
}

void Solution::calculateFitness(Graf& g) {
	_fitness = 0;
	for (int i = 0; i < _colors.size(); i++) {
		for (int j = i + 1; j < _colors.size(); j++) {
			if (_colors[i] == _colors[j] && g.checkEdge(i, j)) {
				this->_fitness++;
				//std::cout << "invEdge\n";
			}
		}
	}
}