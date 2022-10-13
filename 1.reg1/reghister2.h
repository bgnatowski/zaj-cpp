
/******************************************************************************
*
* Plik reghister2.h
*
* Autorzy:
*
******************************************************************************/

#ifndef REGHISTER2_H_INCLUDED
#define REGHISTER2_H_INCLUDED

//-----------------------------------------------------------------------------

class RegHister2 {

// Tutaj nalezy zadeklarowac skladowe (zmienne i metody) klasy RegHister2.
public:
	RegHister2(double l1, double h1, double l2, double h2);
	bool SetPar(double l1, double h1, double l2, double h2);
	double GetPar(char par);
	bool ParOk(void);
	int Run(double zad, double rzecz);

private:
	bool ok;
	double l, h, L, H;
	int y;
};

//-----------------------------------------------------------------------------

#endif		/* REGHISTER2_H_INCLUDED */
