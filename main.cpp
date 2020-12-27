#include<iostream>
#include<unordered_map>
#include<memory>
#include<fstream>
#include<vector>
#include<list>
#include<string>
#include<cmath>
#include<iomanip>
#include"graph.h"


int main()
{
	Graph g;
	/*g.addEdge("Plovdiv", "Sofia", 20);
	g.addEdge("Sofia", "Burgas", 10);   //SOFIA, PLOVDIV, BURGAS, PERNIK
	g.addEdge("Pernik", "Sofia", 15);
	g.addEdge("Plovdiv", "Burgas", 25);
	g.addEdge("Pernik", "Plovdiv", 30);
	g.addEdge("Pernik", "Burgas", 30);*/
	
	//std::cout << g.GetNumEdge() << std::endl;
	g.ReadGraph("myfile.txt");
	//g.printAdjList();
	g.Hamiltonian("Sofia");
	g.PrintPath();
	//g.Hamiltonian("A");
	//g.PrintPath();

    //g.HAM("Sof"); 
	//g.PrintPath();//PROBLEM WITH MULTIPLE VARIATIONS IN THE VERTEX
	//g.OutList();
	//g.printAdjList();
	//g.PrintPath();
	return 0;
}