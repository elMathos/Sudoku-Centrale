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
	bool IsEmpty();
	Cell& operator=(unsigned char iValue);
	operator unsigned char() const;
	bool operator==(unsigned char iValue) const;
	int GetValue();

private:
	bool _isEmpty;
	int _value;
};

