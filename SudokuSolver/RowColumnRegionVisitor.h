#pragma once
#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "IVisitor.h"

class ExportedByDll RowColumnRegionVisitor :
	public IVisitor
{
public:
	RowColumnRegionVisitor();
	~RowColumnRegionVisitor();
	bool Visit(Grid& ioGrid) const;

};

