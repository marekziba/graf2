#ifndef graf_h
#define graf_h

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <ostream>

class Graf {
private:
	std::vector< std::list<int> > _vertexList;
	std::vector< std::vector<int> > _matrix;
	int _n;
	std::vector<int> colors;
	void initializeStructures();
public:
	Graf(std::vector< std::list<int> > vertexList);
	Graf(const char* path);
	void fromFile(const char* path);
	void colorize();
	void printColors();
	void addEdge(int v1, int v2);
	void print();
	int size();
	bool checkEdge(int, int);
	std::vector<int> getAdjacentVertices(int vertex);
};

#endif /*graf_cpp*/