#pragma once
#include "IVisitor.h"

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

class ExportedByDll OnlyOneChoiceGlobalVisitor :
	public IVisitor
{
public:
	OnlyOneChoiceGlobalVisitor();
	~OnlyOneChoiceGlobalVisitor();

	bool Visit(Grid& ioGrid) const;
};

