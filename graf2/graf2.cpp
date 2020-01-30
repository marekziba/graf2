// graf2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdio>


#include "Solution.h"
#include "Population.h"
#include "GeneticAlgorithm.h"

void generate(int nVerts, float density, std::string path) {		// this one works fine
	// the std::array can only be fixed-size, therefore we're forced to use vector of vectors 
	std::vector<std::vector<int>> adjMX; adjMX.resize(nVerts);
	//	initializing the "array"

	std::ofstream outfile(path);

	outfile << nVerts << "\n";

	for (int i = 0; i < nVerts; i++) {
		adjMX[i].resize(nVerts);
	}
	//	filling with zeros
	for (int i = 0; i < nVerts; i++) {
		for (int j = 0; j < nVerts; j++) {
			adjMX[i][j] = 0;
		}
	}
	//	and now we're determining the amount of edges and generating them by randomly choosing two vertices
	int nEdges = round((nVerts * (nVerts - 1)) / 2 * density);
	int v1, v2;
	//std::srad(std::time(nullptr));
	for (int i = 0; i < nEdges; i++) {
		do {
			v1 = std::rand() % nVerts;
			v2 = std::rand() % nVerts;
		} while (v1 == v2 || adjMX[v1][v2] == 1 || adjMX[v2][v1] == 1);	// we need to check whether the edge is not a self-loop and hasn't been generated yet

		adjMX[v1][v2] = 1; adjMX[v2][v1] = 1;	// writing an edge to the matrix
		//std::cout << v1 << " --- " << v2 << "\n";
	}

	for (int i = 0; i < nVerts; i++) {
		for (int j = 0; j < nVerts; j++) {
			if (adjMX[i][j] == 1 && i < j) {
				outfile << i + 1 << " " << j + 1 << "\n";
			}
		}
	}

	outfile.close();
}

int main()
{
	std::string path = "C:/Users/Lenovo/Documents/OK/gc500.txt";
	std::srand(std::time(nullptr));
	//generate(496, 0.01, path);
	Graf g(path.c_str());
	g.print();
	std::cout << "\n\n";
	/*
	for (int i = 0; i < 10; i++) {
		Solution s(g, 3);
		std::cout << s << "\n";
	}
	*/

	/*
	Population p(g, 6, 4);
	std::cout << p;
	p.refresh();
	std::cout << "\nPopulation after refresh:\n" << p;
	*/
	int colors = 209;
	GeneticAlgorithm genalg(g, colors);
	//getch();
	genalg.printResults();
	while (genalg.run(20000)) {
		std::cout << "Found solution for " << colors << " colors\n";
		genalg = GeneticAlgorithm(g, --colors);
	}
	genalg.printResults();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
