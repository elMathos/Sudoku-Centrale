#include "OnlySquareVisitor.h"


OnlySquareVisitor::OnlySquareVisitor()
{
}


OnlySquareVisitor::~OnlySquareVisitor()
{
}

bool OnlySquareVisitor::Visit(Grid& ioGrid) const
{
	//foreach regionHolder in grid
	//	set<unsigned char> valuesAvailable = regionHolder.FlagValues;
	//	if (valuesAvailable.count==2)
	//	{
	//		unsigned char v1 = valuesAvailable.First();
	//		unsigned char v2 = valuesAvailable.Second();

	//		var v1_i = //rowIndex of v1 in the region
	//		var v1_j = //columnIndex of v1 in the region

	//		var v2_i = //rowIndex of v1 in the region
	//		var v2_j = //columnIndex of v1 in the region

	//		//TODO : faire ca 4 fois.
	//		//chercher les available values sur la RowHolder indice v1_i. si ne contient pas v1, alors la Cell(i,j) vaut v2. Si ca ne contient pas v2, alors la Cell(i,j) vaut v1

	//	}
}
