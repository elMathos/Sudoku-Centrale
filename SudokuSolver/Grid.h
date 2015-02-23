#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "Region.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;


class ExportedByDll Grid
{
public:
	//TODO fix the constructor when prof specifies input format of grids.
	Grid(vector<string>& values);
	//TODO understand this
	Grid(vector<Region>& regions);
	~Grid();
	bool IsFull();
	Region& Get_rNW();
	void Accept(const IVisitor& visitor);

private:
	Region _rNW;
	Region _rN;
	Region _rNE;
	Region _rW;
	Region _rC;
	Region _rE;
	Region _rSW;
	Region _rS;
	Region _rSE;
	const int M = 3;
};

