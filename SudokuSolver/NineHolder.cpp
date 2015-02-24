#include "NineHolder.h"


//TODO test NineHolder when inputed 123 456 789
NineHolder::NineHolder(TripleHolder& t1, TripleHolder& t2, TripleHolder& t3) : _cell1(t1.Cell1()), _cell2(t1.Cell2()),
_cell3(t1.Cell3()), _cell4(t2.Cell1()), _cell5(t2.Cell2()),
_cell6(t2.Cell3()), _cell7(t3.Cell1()), _cell8(t3.Cell2()),
_cell9(t3.Cell3())
{
}


NineHolder::~NineHolder()
{
}

Cell& NineHolder::GetCell(unsigned char i)
{
	//Careful there is an offset between i and celli+1
	if (i == 0) return _cell1;
	if (i == 1) return _cell2;
	if (i == 2) return _cell3;
	if (i == 3) return _cell4;
	if (i == 4) return _cell5;
	if (i == 5) return _cell6;
	if (i == 6) return _cell7;
	if (i == 7) return _cell8;
	if (i == 8) return _cell9;
	//TODO else trhow execption

}
