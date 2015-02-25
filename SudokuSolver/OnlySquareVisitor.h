#pragma once
#include "IVisitor.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class ExportedByDll OnlySquareVisitor :
	public IVisitor
{
public:
	OnlySquareVisitor();
	~OnlySquareVisitor();
	bool Visit(Grid& ioGrid) const;
};

