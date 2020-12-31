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
#include"graph.h"
#include"helpFunction.h"


	Graph::Graph()
	{
		this->NEdge = 0;
		this->NVertex = 0;
	}
	Graph::~Graph()
	{
		l.clear();
		Path_Neighbor.clear();
		VertexList.clear();
		this->MinimalCost = 0;
		SpanningTree.clear();
		AllEdges.clear();
		Path_Kruskal.clear();
	}
	const std::unordered_map < std::string, std::list<std::pair<std::string, unsigned int>>>& Graph::getList()
	{
		return this->l;
	}

	void Graph::SortedGraph()
	{
		std::list<std::pair<std::string, unsigned int>>EdgeSort;
		std::list<std::pair<std::string, unsigned int>>::iterator itEdge;
		std::list<std::pair<std::string, unsigned int>>::iterator NextIt;
		std::unordered_map < std::string, std::list<std::pair<std::string, unsigned int>>>::iterator mapIt;
		mapIt = l.begin();
		while (mapIt != l.end())
		{
			EdgeSort = (*mapIt).second;
			itEdge = EdgeSort.begin();
			NextIt = std::next(EdgeSort.begin(), 1);
			(*mapIt).second.sort(sortbysec);
			mapIt++;
		}
		EdgeSort.clear();

	}
	std::vector<std::string>  Graph:: getPath ()
	{
		return this->Path_Neighbor;
	} 
	std::vector<std::string>  Graph:: GetKruskal()
	{
		return this->Path_Kruskal;
	}
	void Graph::addEdge(const std::string& x, const std::string& y, const unsigned int& weight)
	{
		AllEdges.push_back({ weight, {x,y} });

		if (MapMember(x, this->getList()) == false || (MapMember(y, this->getList()) == false))
		{
			if (MapMember(x, this->getList()) == false)
			{
				this->NVertex++;
				VertexList.push_back(x);
				
			}
			if (MapMember(y, this->getList()) == false)
			{

				this->NVertex++;
				VertexList.push_back(y);
				
			}
		}
		l[y].push_back(std::make_pair(x, weight));
		l[x].push_back(std::make_pair(y, weight));
		this->NEdge++;
	}
	/*void Graph::printAdjList()
	{

		for (auto p : l)
		{
			std::string city = p.first;
			std::list<std::pair<std::string, unsigned int>>nbrs = p.second;
			std::cout << city << "->";
			for (auto i : nbrs)
			{
				std::string dest = i.first;
				int dist = i.second;
				std::cout << dest << " " << dist << ",";
			}
			std::cout << std::endl;
		}

	}*/
	int Graph::GetNumEdge()
	{
		return this->NEdge;
	}
	int Graph::GetNumVertex()
	{
		return this->NVertex;
	}
	void Graph::OutList()
	{
		for (size_t i = 0; i < NVertex; i++)
		{
			std::cout << VertexList[i] << std::endl;
		}
	}
	size_t Graph::RetPos(const std::string& str)
	{

		for (size_t i = 0; i < VertexList.size(); i++)
		{
			if (VertexList[i] == str)
			{
				return i;
			}
		}
	}

	void Graph::Hamiltonian(const std::string& startPoint)
	{
		if (Path_Neighbor.size() == this->GetNumVertex())
		{
			Path_Neighbor.push_back(Path_Neighbor[0]);
		}
		for (auto p : l)
		{
			std::list<std::pair<std::string, unsigned int>>edg;
			if (p.first == startPoint)
			{
				if (Path_Neighbor.size() == 0)
				{
					Path_Neighbor.push_back(p.first);
				}
				edg = p.second;
				std::list<std::pair<std::string, unsigned int>>::iterator k;
				k = edg.begin();
				while (k != edg.end())
				{
					if (VisitedEdge((*k).first, Path_Neighbor) == false || (*k).first == startPoint)
					{
						Path_Neighbor.push_back((*k).first);
						Hamiltonian((*k).first);
					}
					else
					{
						k++;
					}

				}
			}
		}
	}
	void Graph::PrintPath()
	{
		std::cout << "THIS IS THE PATH ACCORDING TO NEAREST NEIGHBOUR'S METHOD:" << std::endl;
		for (size_t i = 0; i < Path_Neighbor.size(); i++)
		{
			std::cout << Path_Neighbor[i];
			if (i < Path_Neighbor.size() - 1)
			{
				std::cout << "->";
			}
		}
		std::cout << std::endl;
	}
	void Graph::ReadGraph(const std::string& filename)
	{
		std::ifstream in(filename);
		std::string line;
		std::string x;
		std::string y;
		char* w = new char[10];
		int number = 0;
		while (in >> x >> y >> w)
		{
			number = std::atoi(w);
			addEdge(x, y, number);
		}
		in.close();
	

	}

	void Graph::GreedySort()
	{
		std::vector<std::pair<unsigned int, iPair>>::iterator it;
		std::vector<std::pair<unsigned int, iPair>>::iterator itNext;
		it = AllEdges.begin();
		while (it != AllEdges.end())
		{
			for (itNext = it + 1; itNext != AllEdges.end(); itNext++)
			{
				if ((*itNext).first < (*it).first)
				{
					std::swap((*it), (*itNext));
				}
			}
			it++;
		}

	}
	void Graph::CreateSet()
	{
		KruskalPair current;
		std::vector<KruskalPair>help;
		for (size_t i = 0; i < this->GetNumVertex(); i++)
		{
			current.first = VertexList[i];
			current.second = 0;
			help.push_back(current);
			SpanningTree.push_back(help);
			help.clear();
		}
	}
	int Graph::find(const std::string& s)
	{
		for (size_t i = 0; i < SpanningTree.size(); i++)
		{ 
			for (size_t j = 0; j < SpanningTree[i].size(); j++)
			{
				if (SpanningTree[i][j].first == s)
				{
					return i;
				}
			}
		}
		return -1;

	}
	void Graph::Kruskal(const std::string& StartCity)
	{
		std::vector<std::pair<unsigned int, iPair>> ::iterator KruskalIt;
		std::vector<std::pair<unsigned int, iPair>> ::iterator KruskalItNext;
		int index1;
		int index2;
		std::vector < KruskalPair > ex;
		for (KruskalIt = AllEdges.begin(); KruskalIt != AllEdges.end(); KruskalIt++)
		{

			index1 = find(((*KruskalIt).second).first);
			index2 = find(((*KruskalIt).second).second);
			if (index1 != index2)
			{
					ex = SpanningTree[index2];
					for (size_t k = 0; k < SpanningTree[index2].size(); k++)
					{
						SpanningTree[index2][k].first = "";
					}
					for (size_t i = 0; i < ex.size(); i++)
					{
						SpanningTree[index1].push_back(ex[i]);
						MinimalCost += (*KruskalIt).first;  //PROBLEM WITH LENGTH OF THE PATH
					} 
			}
		}
		for (size_t i = 0; i < SpanningTree.size(); i++)
		{
			if (SpanningTree[i].size() == this->GetNumVertex())
			{
				for (size_t j = 0; j < SpanningTree[i].size(); j++)
				{
					if (SpanningTree[i][j].first == StartCity)
					{
						for (size_t counter1 = j; counter1 < SpanningTree[i].size(); counter1++)
						{
							Path_Kruskal.push_back(SpanningTree[i][counter1].first);
						}
						for (size_t counter2 = 0; counter2 < j; counter2++)
						{
							Path_Kruskal.push_back(SpanningTree[i][counter2].first);
						}
						Path_Kruskal.push_back(StartCity);
					}
				}
			}

		}
	}
    void Graph::PrintKruskal()
	{	
		std::cout << "THIS IS CURCUIT ACCORDING MINIMAL SPANNING TREE'S METHOD!" << std::endl;
		for (size_t i = 0; i < Path_Kruskal.size(); i++)
		{
			std::cout << Path_Kruskal[i] << "->";
		}
		std::cout << Path_Kruskal[0] << std::endl;
		//std::cout << "Length:" << MinimalCost << std::endl; // PROBLEM WITH CALCULATING THE PATH'S LENGTH
	}
	void Graph::ALGO1(const std::string& filename,const std::string& StartCity)
	{
		ReadGraph(filename);
		SortedGraph();
		Hamiltonian(StartCity);
		PrintPath();
	}
	void Graph::ALGO2(const std::string& filename, const std::string& StartCity)
	{
		ReadGraph(filename);
		GreedySort();
		CreateSet();
		Kruskal(StartCity);
		PrintKruskal();
	}
#endif