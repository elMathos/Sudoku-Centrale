#pragma once

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif


class ExportedByDll Cell
{
public:
	Cell();
	Cell(int);
	~Cell();
	bool IsEmpty() const;
	Cell& operator=(unsigned char iValue);
	operator unsigned char() const;
	bool operator==(unsigned char iValue) const;

private:
	int _value;
};

