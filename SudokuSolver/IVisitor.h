#pragma once
#include "Grid.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class ExportedByDll IVisitor
{
public:
	IVisitor();
	virtual ~IVisitor()=0;
	virtual bool Visit(Grid& ioGrid) const=0;
};

