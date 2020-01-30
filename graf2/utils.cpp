#include "utils.h"

Solution reproduce(Population p, Graf &g, int mode) {
	Solution parent1, parent2;
	//std::cout << "Reproduction...\n";
	if (mode == 0) {
		int p1 = std::rand() % p.size(), p2 = std::rand() % p.size();
		/*
		do {
			p2 = std::rand() % p.size();
			//std::cout << "while1\n";
		} while (p1 == p2);
		*/
		//std::cout << "p1 = " << p1 << ", p2 = " << p2 << "\n";
		//std::cout << "tempParent1 = " << p[p1] << "\n";
		//std::cout << "tempParent2 = " << p[p2] << "\n";
		int sel;
		if (p1 < p2) {
			sel = p1;
		}
		else {
			sel = p2;
		}
		parent1 = p[sel];
		//std::cout << "Selected parent1 = " << parent1 << "\n";
		p1 = std::rand() % p.size();
		p2 = std::rand() % p.size();
		/*
		do
		{
			p1 = std::rand() % p.size();
			//std::cout << "while2\n";
		} while (p1 == sel);
		do {
			p2 = std::rand() % p.size();
			//std::cout << "while3\n";
		} while (p1 == p2 or p2 == sel);
		*/
		//std::cout << "p1 = " << p1 << ", p2 = " << p2 << "\n";
		//std::cout << "tempParent1 = " << p[p1] << "\n";
		//std::cout << "tempParent2 = " << p[p2] << "\n";
		if (p1 < p2) {
			sel = p1;
		}
		else {
			sel = p2;
		}
		parent2 = p[sel];
		//std::cout << "Selected parent2 = " << parent2 << "\n";
	}
	else if (mode == 1) {
		parent1 = p[0]; parent2 = p[1];
	}

	int breakPoint = std::rand() % parent1.size();
	std::vector<int> childSolutionVector;
	childSolutionVector.resize(parent1.size());
	for (int i = 0; i < parent1.size(); i++) {
		if (i <= breakPoint) {
			childSolutionVector[i] = parent1[i];
		}
		else {
			childSolutionVector[i] = parent2[i];
		}
	}

	Solution child = Solution(childSolutionVector,g, p._ncolors);
	//std::cout << "child = " << child << "\n";
	return child;
}