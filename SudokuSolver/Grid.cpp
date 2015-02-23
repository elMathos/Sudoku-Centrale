#include "Grid.h"
#include "IVisitor.h"
#include <vector>
#include <string>
using namespace std;

Grid::Grid(vector<string>& values)
{	
	//TODO Check that values is of length 9
	_rNW = Region(values[0]);
	_rN = Region(values[1]);
	//TODO do this 7 more times
}

Grid::Grid(vector<Region>& regions)
{
	//TODO check that 9 regions are given as input (length of vector)
	_rNW = regions[0];
	//TODO do this 9 times
}


Grid::~Grid()
{
}


bool Grid::IsFull(){
	//A grid is full iff its 9 regions are
	bool isFull = _rNW.IsFull() && _rN.IsFull() && _rNE.IsFull() && _rW.IsFull() && _rC.IsFull() && _rE.IsFull() && _rSW.IsFull() && _rS.IsFull() && _rSE.IsFull();
	return isFull;;
}

Region& Grid::Get_rNW()
{
	return _rNW;;
}

//TODO implement the other accessors Get_rN();

void Grid::Accept(const IVisitor& visitor)
{
	visitor.Visit(*this);
}