#pragma once
#include "IVisitor.h"
class OnlyOneChoiceInRowVisitor :
	public IVisitor
{
public:
	OnlyOneChoiceInRowVisitor();
	~OnlyOneChoiceInRowVisitor();

	bool Visit(Grid& ioGrid) const;
};

