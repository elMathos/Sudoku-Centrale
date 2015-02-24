#pragma once
#include "RegionHolder.h"
#include <set>
using namespace std;

class ValueEliminator
{
public:
	ValueEliminator();
	~ValueEliminator();
	set<unsigned char> availableValue();
	void setFlags(const RegionHolder& region);
	void setFlags(TripleHolder& tripleHolder);

private:
	bool _alreadySeen[9];
	void flag(unsigned char iValue);
	int availableValues();

	//Note : added by us
};

