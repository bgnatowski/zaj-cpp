
/******************************************************************************
*
* Plik naped.cpp
*
* Autorzy:
*
******************************************************************************/

#include "naped.h"

//-----------------------------------------------------------------------------
// Tutaj nalezy zdefinowac konstruktor klasy Naped
Naped::Naped(double av1,  double av2){
	v1 = v2 = poz = 0.0;
	SetPar(av1, av2);

}

//-----------------------------------------
// Tutaj nalezy zdefinowac metode SetPar klasy Naped
bool Naped::SetPar(double av1, double av2){
	if (av1 >= 0.0)
		v1 = av1;
	if (av2 >= 0.0)
		v2 = av2;
	ok = (v1 > 0.0) && (v2 >= v1);

	return ok;
}
//-----------------------------------------
// Tutaj nalezy zdefinowac metode GetPar klasy Naped
double Naped::GetPar(char c){
	switch(c){
	case 'f':
	case 'F':
		return v2;
	case 's':
	case 'S':
		return v1;
	default:
		return -1.0;
	}
}

//-----------------------------------------
// Tutaj nalezy zdefinowac metode ParOk klasy Naped
bool Naped::ParOk(void){
	return ok;
}

//-----------------------------------------
// Tutaj nalezy zdefinowac metode Run klasy Naped
double Naped::Run(int vsel){
	if(ok){
		switch(vsel){
			case -2:
				poz -= v2;
				break;
			case -1:
				poz -= v1;
				break;
			case 1:
				poz += v1;
				break;
			case 2:
				poz += v2;
				break;
		}
	}
	return poz;
}

//-----------------------------------------
//----------------------------------------------------------------------------

