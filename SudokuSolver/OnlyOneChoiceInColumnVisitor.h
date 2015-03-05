#pragma once
#include "IVisitor.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class ExportedByDll OnlyOneChoiceInColumnVisitor :
	public IVisitor
{
public:
	OnlyOneChoiceInColumnVisitor();
	~OnlyOneChoiceInColumnVisitor();

	bool Visit(Grid& ioGrid) const;
};
