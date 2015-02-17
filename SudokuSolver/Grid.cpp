#include "Grid.h"
#include <vector>
#include <string>
using namespace std;

Grid::Grid(vector<vector<string>>& values)
{
	_regions = vector<vector<Region>>(M);

	for (int i = 0; i < M; i++)
	{
		_regions[i] = vector<Region>(M);
		
		for (int j = 0; j < M; j++)
		{
			_regions[i][j] = Region(values[i][j]);
		}
	}
}

Grid::Grid(vector<vector<Region>>& regions)
{
	_regions = vector<vector<Region>>(M);

	for (int i = 0; i < M; i++)
	{
		_regions[i] = vector<Region>(M);

		for (int j = 0; j < M; j++)
		{
			_regions[i][j] = regions[i][j];
		}
	}
}


Grid::~Grid()
{
}


bool Grid::IsFull(){
	for (int i = 0; i < M; i++){
		for (int j = 0; j < M; j++){
			if (!_regions[i][j].IsFull()) {
				return false;
			}
		}
	}
	//If we get out of the loop, all the regions are full, the grid is full
	return true;
}