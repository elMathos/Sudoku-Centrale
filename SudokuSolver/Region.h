#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "Cell.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class ExportedByDll Region
{
public:
	Region(string);
	Region();
	~Region();
	Region& operator=(const Region& r);
	bool IsFull();
	Cell& GetCell(unsigned char i, unsigned char j);


private:
	Cell _cNW;
	Cell _cN;
	Cell _cNE;
	Cell _cW;
	Cell _cC;
	Cell _cE;
	Cell _cSW;
	Cell _cS;
	Cell _cSE;
};

