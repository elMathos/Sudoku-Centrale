#pragma once
#include "Grid.h"

class IVisitor
{
public:
	IVisitor();
	virtual ~IVisitor()=0;
	virtual bool Visit(Grid& ioGrid) const=0;
};

