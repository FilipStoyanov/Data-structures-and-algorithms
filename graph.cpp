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
		return this->path;
	}
	void Graph::addEdge(const std::string& x, const std::string& y, const unsigned int& weight)
	{
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
	void Graph::printAdjList()
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

	}
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
		if (path.size() == this->GetNumVertex())
		{
			path.push_back(path[0]);
		}
		for (auto p : l)
		{
			std::list<std::pair<std::string, unsigned int>>edg;
			if (p.first == startPoint)
			{
				if (path.size() == 0)
				{
					path.push_back(p.first);
				}
				edg = p.second;
				std::list<std::pair<std::string, unsigned int>>::iterator k;
				k = edg.begin();
				while (k != edg.end())
				{
					if (VisitedEdge((*k).first, path) == false || (*k).first == startPoint)
					{
						path.push_back((*k).first);
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
		std::cout << "This is the shortest path for the travelling salesman:" << std::endl;
		for (size_t i = 0; i < path.size(); i++)
		{
			std::cout << path[i];
			if (i < path.size() - 1)
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
		SortedGraph();
		in.close();
	

	}


#endif