#pragma once
#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "IVisitor.h"

class ExportedByDll TwoOutOfThreeColumnVisitor :
	public IVisitor
{
public:
	TwoOutOfThreeColumnVisitor();
	~TwoOutOfThreeColumnVisitor();
	bool Visit(Grid& ioGrid) const;
};

