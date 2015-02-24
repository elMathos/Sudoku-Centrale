#pragma once
#include "IVisitor.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class ExportedByDll OnlyOneChoiceInRowVisitor :
	public IVisitor
{
public:
	OnlyOneChoiceInRowVisitor();
	~OnlyOneChoiceInRowVisitor();

	bool Visit(Grid& ioGrid) const;
};

