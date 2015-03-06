#include "OnlyOneChoiceGlobalVisitor.h"
#include "OnlyOneChoiceInRowVisitor.h"
#include "OnlyOneChoiceInColumnVisitor.h"
#include "OnlyOneChoiceInRegionVisitor.h"


OnlyOneChoiceGlobalVisitor::OnlyOneChoiceGlobalVisitor()
{
}


OnlyOneChoiceGlobalVisitor::~OnlyOneChoiceGlobalVisitor()
{
}

bool OnlyOneChoiceGlobalVisitor::Visit(Grid& ioGrid) const
{
	OnlyOneChoiceInRowVisitor rowVisitor;
	OnlyOneChoiceInColumnVisitor colVisitor;
	OnlyOneChoiceInRegionVisitor regVisitor;
	bool rowSuccess = rowVisitor.Visit(ioGrid);
	bool colSuccess = colVisitor.Visit(ioGrid);
	bool regSuccess = regVisitor.Visit(ioGrid);
	bool success = rowSuccess || colSuccess || regSuccess;

	return success;
}