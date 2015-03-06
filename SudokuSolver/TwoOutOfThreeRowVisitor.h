#pragma once
#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include "IVisitor.h"
#include <set>

using namespace std;

class ExportedByDll TwoOutOfThreeRowVisitor: public IVisitor
{
public:
	TwoOutOfThreeRowVisitor();
	~TwoOutOfThreeRowVisitor();
	bool Visit(Grid& ioGrid) const;
};

