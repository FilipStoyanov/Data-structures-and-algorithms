#pragma once
#include<iostream>
#include<unordered_map>
#include<fstream>
#include<vector>
#include<list>
#include<string>
#include<cmath>
#include<iomanip>
class Graph
{
private:
	std::unordered_map < std::string, std::list<std::pair<std::string, unsigned int>>>l;
	unsigned int NEdge;
	unsigned int NVertex;
	std::vector<std::string>VertexList;
	std::vector<std::string>path;
public:
	Graph();
	const std::unordered_map <std::string, std::list<std::pair<std::string, unsigned int>>>& getList();
	void SortedGraph();
	void addEdge(const std::string& , const std::string& , const unsigned int& );
	void printAdjList();
	int GetNumEdge();
	int GetNumVertex();
	std::vector<std::string> getPath();
	void OutList();
	size_t RetPos(const std::string& );
	void Hamiltonian(const std::string& );
	void PrintPath();
	void ReadGraph(const std::string& );

};


