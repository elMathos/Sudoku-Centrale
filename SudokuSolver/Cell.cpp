#include "Cell.h"
#include <stdexcept>
using namespace std;

Cell::Cell()
{
	_value = -1;
}

int Cell::getValue()
{
	return _value;
}

Cell::Cell(int value)
{
	if (value < 1 || value > 9)
	{
		throw invalid_argument("Incorrect input value for Cell.\n");
	}
	else
	{
		_value = value;
	}
	
}

Cell::Cell(char chr, string allowed){
	// allowed is the string of authorized characters
	if (allowed.find(chr) != string::npos) // string.find(chr) returns npos if chr not found
	{
		if (chr == '-'){
			_value = -1;
		}
		else{
			int i = chr - '0';
			_value = i; // int i corresponds to the figure chr represents
		}
	}
	else{
		throw invalid_argument("Invalid input character to instanciate Cell.\n");
	}
}

bool Cell::IsEmpty() const
{
	return _value==-1;
}

Cell& Cell::operator=(unsigned char iValue)
{
	_value = iValue;
	return *this;
}

Cell::operator unsigned char() const
{
	return _value;
}

bool Cell::operator==(unsigned char iValue) const
{
	return (_value == iValue);
}

Cell::~Cell()
{
}
