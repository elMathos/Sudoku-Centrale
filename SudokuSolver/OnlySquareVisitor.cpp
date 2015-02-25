#include "OnlySquareVisitor.h"


OnlySquareVisitor::OnlySquareVisitor()
{
}


OnlySquareVisitor::~OnlySquareVisitor()
{
}

bool OnlySquareVisitor::Visit(Grid& ioGrid) const
{
	bool visited = false;
	for (unsigned char i = 0; i < 9; i++)
	{
		NineHolder fullrow = ioGrid.GetRow(i);
		//todo check present values
		//if there are 2 absent, find their indices u and v
		//get  NineHolder on column u and v by ioGrid.GetColumn(u)
		//check for absentValue1 and absentValue2 in fullColu and fullColv
		//4 if (abs1 in fullColu, fullColv, same abs2): set value and visited == true
	}
	//TODO do the same for 9 columns :)
	return visited;
}
