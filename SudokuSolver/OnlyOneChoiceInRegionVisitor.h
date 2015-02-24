#pragma once
#include "IVisitor.h"

class OnlyOneChoiceInRegionVisitor:
	public IVisitor
{
public:
	OnlyOneChoiceInRegionVisitor();
	~OnlyOneChoiceInRegionVisitor();

	bool Visit(Grid& ioGrid) const;
};

