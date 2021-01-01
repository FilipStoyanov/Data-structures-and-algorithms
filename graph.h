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
	unsigned int NVertex;                    // Nearest Neigbour
	std::vector<std::string>Path_Neighbor;

	std::vector<std::string>VertexList;
	unsigned int MinimalCost = 0;

	typedef std::pair<std::string, std::string>iPair;   //Greedy Algorithm MINIMAL SPANNING TREE
	typedef std::pair<std::string, int>KruskalPair;
	std::vector<std:: vector<std::string>>SpanningTree;
	std::vector<std::pair<unsigned int,iPair>>AllEdges;
	std::vector<std::string>Path_Kruskal;



public:
	Graph();
	~Graph();
	const std::unordered_map <std::string, std::list<std::pair<std::string, unsigned int>>>& getList();
	void SortedGraph();
	void addEdge(const std::string& , const std::string& , const unsigned int& );
	//void printAdjList();
	int GetNumEdge();
	int GetNumVertex();
	std::vector<std::string> getPath();
	std::vector<std::string> GetKruskal();
	void OutList();
	size_t RetPos(const std::string& );
	void Hamiltonian(const std::string& );
	void PrintPath();
	void ReadGraph(const std::string& );
	void GreedySort();
	int find(const std::string&);
	void Kruskal(const std::string&);
	void CreateSet();
	void PrintKruskal();
	void ALGO1(const std::string&, const std::string&);
	void ALGO2(const std::string&, const std::string&);
};


