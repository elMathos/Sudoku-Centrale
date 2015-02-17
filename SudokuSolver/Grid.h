#pragma once
#include "Region.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;


class Grid
{
public:
	Grid(vector<vector<string>>& values);
	Grid(vector<vector<Region>>& regions);
	~Grid();
private:
	vector<vector<Region>> _regions;
	const int M = 3;
};

