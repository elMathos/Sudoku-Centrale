#pragma once
#include "IVisitor.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class ExportedByDll OnlyOneChoiceInRegionVisitor :
	public IVisitor
{
public:
	OnlyOneChoiceInRegionVisitor();
	~OnlyOneChoiceInRegionVisitor();

	bool Visit(Grid& ioGrid) const;
};

