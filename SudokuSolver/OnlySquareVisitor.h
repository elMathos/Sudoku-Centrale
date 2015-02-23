#pragma once
#include "IVisitor.h"
class OnlySquareVisitor :
	public IVisitor
{
public:
	OnlySquareVisitor();
	~OnlySquareVisitor();
	bool Visit(Grid& ioGrid) const;
};

