#pragma once
class Cell
{
public:
	Cell();
	Cell(int);
	~Cell();
	bool IsEmpty();
	Cell& operator=(unsigned char iValue);
	operator unsigned char() const;
	bool operator==(unsigned char iValue) const;

private:
	bool _isEmpty;
	int _value;
};

