#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"
#include "graph.h"
#include<iostream>

TEST_CASE("File Test 1")
{
	Graph g;
	g.ReadGraph("test1.txt");
    g.Hamiltonian("Pernik");
	std::vector<std::string> test;
	test.push_back("Pernik");
	test.push_back("Sofia");
	test.push_back("Burgas");
	test.push_back("Plovdiv");
	test.push_back("Pernik");
	CHECK(g.getPath() == test);
	
}
TEST_CASE("File Test 2")
{
	Graph g;
	g.ReadGraph("test2.txt");
	g.Hamiltonian("Paris");
	std::vector<std::string> test;
	test.push_back("Paris");
	test.push_back("Lyon");
	test.push_back("Berlin");
	test.push_back("London");
	test.push_back("Rome");
	test.push_back("Paris");
	
	CHECK(g.getPath() == test);

}
TEST_CASE("File Test 3")
{
	Graph g;
	g.ReadGraph("test3.txt");
	g.Hamiltonian("Ankara");
	std::vector<std::string> test;
	test.push_back("Ankara");
	test.push_back("Moskva");
	test.push_back("Teheran");
	test.push_back("Wien");
	test.push_back("Paris");
	test.push_back("Pekin");
	test.push_back("Kolorado");
	test.push_back("Ankara");
	CHECK(g.getPath() == test);

}
TEST_CASE("File Test 4")
{
	Graph g;
	g.ReadGraph("test2.txt");
	g.Hamiltonian("Rome");
	std::vector<std::string> test;
	test.push_back("Rome");
	test.push_back("Paris");
	test.push_back("Lyon");
	test.push_back("Berlin");
	test.push_back("London");
	test.push_back("Rome");

	CHECK(g.getPath() == test);

}
TEST_CASE("Other Start Test")
{
	Graph g;
	g.ReadGraph("test3.txt");
	g.Hamiltonian("Kolorado");
	std::vector<std::string> test;
	test.push_back("Kolorado");
	test.push_back("Wien");
	test.push_back("Paris");
	test.push_back("Ankara");
	test.push_back("Moskva");
	test.push_back("Teheran");
	test.push_back("Pekin");
	test.push_back("Kolorado");
	CHECK(g.getPath() == test);

}
TEST_CASE("File Test 5")
{
	Graph g;
	g.ReadGraph("test4.txt");
	g.Hamiltonian("Plovdiv");
	std::vector<std::string> test;
	test.push_back("Plovdiv");
	test.push_back("Moskva");
	test.push_back("Teheran");
	test.push_back("Wien");
	test.push_back("Paris");
	test.push_back("Ankara");
	test.push_back("Kolorado");
	test.push_back("Pekin");
	test.push_back("Plovdiv");
	CHECK(g.getPath() == test);

}
TEST_CASE("Other Start Test 2")
{
	Graph g;
	g.ReadGraph("test4.txt");
	g.Hamiltonian("Teheran");
	std::vector<std::string> test;
	test.push_back("Teheran");
	test.push_back("Moskva");
	test.push_back("Wien");
	test.push_back("Paris");
	test.push_back("Ankara");
	test.push_back("Kolorado");
	test.push_back("Plovdiv");
	test.push_back("Pekin");
	test.push_back("Teheran");
	CHECK(g.getPath() == test);

}
TEST_CASE("Error Test")
{
	Graph g;
	g.ReadGraph("error.txt");
	g.Hamiltonian("Paris");
	std::vector<std::string> test;
	test.push_back("Paris");
	test.push_back("Lyon");
	test.push_back("Berlin");
	test.push_back("London");
	test.push_back("London");
	test.push_back("Paris");

	CHECK(g.getPath() != test);
}

int main()
{
	/*Graph k;
	k.ReadGraph("test4.txt");
	k.Hamiltonian("Teheran");
	k.PrintPath();*/

	doctest::Context().run();


	


	return 0;
}


