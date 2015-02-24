#pragma once
#include "IVisitor.h"

class OnlyOneChoiceInColumnVisitor:
	public IVisitor
{
public:
	OnlyOneChoiceInColumnVisitor();
	~OnlyOneChoiceInColumnVisitor();

	bool Visit(Grid& ioGrid) const;
};
