#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"
#include "graph.h"
#include<iostream>
#include<chrono>
TEST_CASE("File Test 1")
{
	Graph g;
	g.ALGO1("test1.txt","Pernik");
	std::vector<std::string> test;
	test.push_back("Pernik"); 
	test.push_back("Sofia");
	test.push_back("Burgas");
	test.push_back("Plovdiv");
	test.push_back("Pernik");
	CHECK(g.getPath() == test);
	Graph k;
	k.ALGO2("test1.txt","Pernik");
	CHECK(k.GetKruskal() == test);
	
}
TEST_CASE("File Test 2")
{
	Graph g;
	Graph k;
	g.ALGO1("test2.txt", "Paris");
	k.ALGO2("test2.txt", "Paris");
	std::vector<std::string> test;
	test.push_back("Paris");
	test.push_back("Lyon");
	test.push_back("Berlin");
	test.push_back("London");
	test.push_back("Rome");
	test.push_back("Paris");
	
	CHECK(g.getPath() == test);
	CHECK(k.GetKruskal() == test);

}
TEST_CASE("File Test 3") //DIFFERENCE BETWEEN TWO ALGORITHMS - WORKING FIRST ALGORITHM
{
	Graph g;
	Graph k;
	g.ALGO1("test3.txt","Ankara");
	k.ALGO2("test3.txt", "Ankara");
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
	std::vector<std::string> test2;
	test2.push_back("Ankara");
	test2.push_back("Wien");
	test2.push_back("Paris");
	test2.push_back("Moskva");
	test2.push_back("Teheran");
	test2.push_back("Pekin");
	test2.push_back("Kolorado");
	test2.push_back("Ankara");
	CHECK(k.GetKruskal() == test2);
}
TEST_CASE("File Test 4")
{
	Graph g;
	Graph k;
	g.ALGO1("test2.txt", "Rome");
	k.ALGO2("test2.txt", "Rome");
	std::vector<std::string> test;
	test.push_back("Rome");
	test.push_back("Paris");
	test.push_back("Lyon");
	test.push_back("Berlin");
	test.push_back("London");
	test.push_back("Rome");
	CHECK(g.getPath() == test);
	CHECK(k.GetKruskal() == test);
}
TEST_CASE("Other Start Test")
{
	Graph g;
	Graph k;
	g.ALGO1("test3.txt","Kolorado");
	k.ALGO2("test3.txt", "Kolorado");
	std::vector<std::string> test;
	test.push_back("Kolorado");
	test.push_back("Teheran");
	test.push_back("Moskva");
	test.push_back("Wien");
	test.push_back("Paris");
	test.push_back("Ankara");
	test.push_back("Pekin");
	test.push_back("Kolorado");
	CHECK(g.getPath() == test);
	std::vector<std::string> test2;
	test2.push_back("Kolorado");
	test2.push_back("Ankara");
	test2.push_back("Wien");
	test2.push_back("Paris");
	test2.push_back("Moskva");
	test2.push_back("Teheran");
	test2.push_back("Pekin");
	test2.push_back("Kolorado");
	CHECK(k.GetKruskal() == test2);
}
TEST_CASE("File Test 5")
{
	Graph g;
	Graph k;
	g.ALGO1("test4.txt","Plovdiv");
	k.ALGO2("test4.txt", "Plovdiv");
	std::vector<std::string> test;
	test.push_back("Plovdiv");
	test.push_back("Ankara");
	test.push_back("Moskva");
	test.push_back("Teheran");
	test.push_back("Wien");
	test.push_back("Paris");
	test.push_back("Pekin");
	test.push_back("Kolorado");
	test.push_back("Plovdiv");
	CHECK(g.getPath() == test);
	std::vector<std::string> test2;
	test2.push_back("Plovdiv");
	test2.push_back("Wien");
	test2.push_back("Moskva");
	test2.push_back("Teheran");
	test2.push_back("Paris");
	test2.push_back("Pekin");
	test2.push_back("Kolorado");
	test2.push_back("Ankara");
	test2.push_back("Plovdiv");
	CHECK(k.GetKruskal() == test2);
}
TEST_CASE("Other Start Test 2")
{
	Graph g;
	Graph k;
	g.ALGO1("test4.txt","Teheran");
	k.ALGO2("test4.txt", "Teheran");
	std::vector<std::string> test;
	test.push_back("Teheran");
	test.push_back("Moskva");
	test.push_back("Wien");
	test.push_back("Paris");
	test.push_back("Ankara");
	test.push_back("Plovdiv");
	test.push_back("Pekin");
	test.push_back("Kolorado");
	test.push_back("Teheran");
	CHECK(g.getPath() == test);
	std::vector<std::string> test2;
	test2.push_back("Teheran");
	test2.push_back("Paris");
	test2.push_back("Pekin");
	test2.push_back("Kolorado");
	test2.push_back("Ankara");
	test2.push_back("Plovdiv");
	test2.push_back("Wien");
	test2.push_back("Moskva");
	test2.push_back("Teheran");
	CHECK(k.GetKruskal() == test2);

}
TEST_CASE("Error Test")
{
	Graph g;
	Graph k;
	g.ALGO1("error.txt","Paris");
	k.ALGO2("error.txt", "Paris");
	std::vector<std::string> test;
	test.push_back("Paris");
	test.push_back("Lyon");
	test.push_back("Berlin");
	test.push_back("London");
	test.push_back("London");
	test.push_back("Paris");

	CHECK(g.getPath() != test);
	CHECK(k.GetKruskal() != test);

}
TEST_CASE("File Test 6")
{
	Graph g;
	Graph k;
	g.ALGO1("test5.txt", "B");
	k.ALGO2("test5.txt", "B");
	std::vector<std::string> test;
	test.push_back("B");
	test.push_back("A");
	test.push_back("E");
	test.push_back("F");
	test.push_back("C");
	test.push_back("D");
	test.push_back("G");
	test.push_back("J");
	test.push_back("H");
	test.push_back("I");
	test.push_back("B");
	CHECK(g.getPath() == test);
	std::vector<std::string> test2;
	test2.push_back("B");
	test2.push_back("C");
	test2.push_back("D");
	test2.push_back("H");
	test2.push_back("I");
	test2.push_back("G");
	test2.push_back("J");
	test2.push_back("A");
	test2.push_back("E");
	test2.push_back("F");
	test2.push_back("B");
	CHECK(k.GetKruskal() == test2);
}
TEST_CASE("File Test 8")
{
	Graph g;
	Graph k;
	g.ALGO1("test7.txt", "O");
	k.ALGO2("test7.txt", "O");
	std::vector<std::string> test;
	test.push_back("O");
	test.push_back("A");
	test.push_back("E");
	test.push_back("N");
	test.push_back("D");
	test.push_back("L");
	test.push_back("C");
	test.push_back("M");
	test.push_back("F");
	test.push_back("K");
	test.push_back("H");
	test.push_back("I");
	test.push_back("P");
	test.push_back("G");
	test.push_back("J");
	test.push_back("Q");
	test.push_back("B");
	test.push_back("O");
	CHECK(g.getPath() == test);
	std::vector<std::string> test2;
	test2.push_back("O");
	test2.push_back("P");
	test2.push_back("Q");
	test2.push_back("J");
	test2.push_back("G");
	test2.push_back("I");
	test2.push_back("A");
	test2.push_back("E");
	test2.push_back("H");
	test2.push_back("K");
	test2.push_back("C");
	test2.push_back("F");
	test2.push_back("M");
	test2.push_back("D");
	test2.push_back("N");
	test2.push_back("L");
	test2.push_back("B");
	test2.push_back("O");
	CHECK(k.GetKruskal() == test2);
}
TEST_CASE("File Test 7")
{
	Graph g;
	Graph k;
	g.ALGO1("test6.txt", "I");
	k.ALGO2("test6.txt", "I");
	std::vector<std::string> test;
	test.push_back("I");
	test.push_back("K");
	test.push_back("H");
	test.push_back("L");
	test.push_back("D");
	test.push_back("N");
	test.push_back("F");
	test.push_back("M");
	test.push_back("C");
	test.push_back("A");
	test.push_back("E");
	test.push_back("J");
	test.push_back("G");
	test.push_back("B");
	test.push_back("I");
	CHECK(g.getPath() == test);
	std::vector<std::string> test2;
	test2.push_back("I");
	test2.push_back("A");
	test2.push_back("E");
	test2.push_back("H");
	test2.push_back("K");
	test2.push_back("C");
	test2.push_back("F");
	test2.push_back("M");
	test2.push_back("D");
	test2.push_back("N");
	test2.push_back("L");
	test2.push_back("B");
	test2.push_back("J");
	test2.push_back("G");
	test2.push_back("I");
	CHECK(k.GetKruskal() == test2);
}

int main()
{
	doctest::Context().run();
	//Graph g;
	//g.ALGO2("test6.txt","I");
	return 0;
}


