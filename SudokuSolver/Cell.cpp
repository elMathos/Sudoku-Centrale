#include "Cell.h"
#include <stdexcept>
using namespace std;

Cell::Cell()
{
	_value = -1;
}

int Cell::GetValue()
{
	return _value;
}

Cell::Cell(int value)
{
	if (value < 0 || value > 9)
	{
		throw invalid_argument("Incorrect input value for Cell.\n");
	}
	else
	{
		_value = value;
	}
	
}

Cell::Cell(char chr, string allowed){
	if (allowed.find(chr) != string::npos) {
		if (chr == '-'){
			_value = -1;
		}
		else{
			int i = chr - '0';
			_value = i;
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

//Bad practice
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
