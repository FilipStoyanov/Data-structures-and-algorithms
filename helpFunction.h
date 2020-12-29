#pragma once
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<unordered_map>
bool sortbysec(const std::pair<std::string, unsigned int>& a,
	const std::pair<std::string, unsigned int>& b)
{
	return (a.second < b.second);
}
bool MapMember(const std::string& input, const std::unordered_map < std::string, std::list<std::pair<std::string, unsigned int>>> example)
{
	if (example.find(input) == example.end())
	{
		return false;
	}
	return true;
}
bool VisitedEdge(const std::string& current, const std::vector<std::string> saveInit)
{
	for (size_t i = 0; i < saveInit.size(); i++)
	{
		if (current == saveInit[i])
		{
			return true;
		}
	}
	return false;
}

