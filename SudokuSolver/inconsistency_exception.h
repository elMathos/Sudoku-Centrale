#pragma once
#include <exception>

#ifdef SUDOKUSOLVER_EXPORTS
#define ExportedByDll __declspec(dllexport)
#else
#define ExportedByDll __declspec(dllimport)
#endif
using namespace std;

class ExportedByDll inconsistency_exception :
	public exception
{
public:
	inconsistency_exception();
	~inconsistency_exception();
	virtual const char* what() const throw()
	{
		return "Grid reached an inconsistency state";
	}
};

