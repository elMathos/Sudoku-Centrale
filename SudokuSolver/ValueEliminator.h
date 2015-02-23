#pragma once
#include "RegionHolder.h"
#include <set>
using namespace std;

class ValueEliminator
{
public:
	ValueEliminator();
	~ValueEliminator();
	set<unsigned char> AvailableValue();
	void SetFlags(const RegionHolder& region);

private:
	bool _alreadySeen[9];
	void Flag(unsigned char iValue);
	
	//So good naming practices....
	int AvailableValues();

	//Note : added by us
};

