#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif

#include <string>

class ExportedByDll Cell
{
public:
	Cell();
	Cell(int);
	Cell(char, std::string);
	~Cell();
	bool IsEmpty() const;
	Cell& operator=(unsigned char iValue);
	operator unsigned char() const;
	bool operator==(unsigned char iValue) const;
	int GetValue();

private:
	int _value;
};

