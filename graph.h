#pragma once
#ifndef _GRAPH_H
#define _GRAPH_H
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
	std::unordered_map < std::string, std::list<std::pair<std::string, unsigned int>>> getList();
	void SortedGraph();
	void addEdge(std::string x, std::string y, int weight);
	void printAdjList();
	int GetNumEdge();
	int GetNumVertex();
	void OutList();
	size_t RetPos(std::string str);
	void Hamiltonian(std::string startPoint);
	void PrintPath();
	void ReadGraph(std::string filename);

};


#endif