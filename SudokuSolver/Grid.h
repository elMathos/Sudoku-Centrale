#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class IVisitor;

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
	Grid(vector<Region>& regions);
	~Grid();
	bool IsFull();
	Region& Get_rNW();
	Region& Get_rN();
	Region& Get_rNE();
	Region& Get_rW();
	Region& Get_rC();
	Region& Get_rE();
	Region& Get_rSW();
	Region& Get_rS();
	Region& Get_rSE();
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
};

