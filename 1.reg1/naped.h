
/******************************************************************************
*
* Plik naped.h
*
* Autorzy:
*
******************************************************************************/

#ifndef NAPED_H_INCLUDED
#define NAPED_H_INCLUDED

//-----------------------------------------------------------------------------

class Naped {

// Tutaj nalezy zadeklarowac skladowe (zmienne i metody) klasy Naped.
public:
	Naped(double av1, double av2);
	bool SetPar(double av1, double av2);
	double GetPar(char c);
	bool ParOk(void);
	double Run(int vsel);

private:
	double v1, v2;
	bool ok;
	double poz;
};

//-----------------------------------------------------------------------------

#endif		/* NAPED_H_INCLUDED */
