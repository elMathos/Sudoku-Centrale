#pragma once
#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "IVisitor.h"

class ExportedByDll TwoOutOfThreeRowVisitor: public IVisitor
{
public:
	TwoOutOfThreeRowVisitor();
	~TwoOutOfThreeRowVisitor();
	bool Visit(Grid& ioGrid) const;
};

