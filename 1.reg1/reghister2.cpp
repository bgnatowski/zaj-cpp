
/******************************************************************************
*
* Plik reghister2.cpp
*
* Autorzy:
*
******************************************************************************/

#include "reghister2.h"

//-----------------------------------------------------------------------------
// Tutaj nalezy zdefinowac konstruktor klasy RegHister2
RegHister2::RegHister2(double l1, double h1, double l2, double h2){
	l = h = L = H = 0.0;
	y = 0;
	SetPar(l1, h1, l2, h2);

}

//-----------------------------------------
// Tutaj nalezy zdefinowac metode SetPar klasy RegHister2
bool RegHister2::SetPar(double l1, double h1, double l2, double h2){
	if (l1 > 0)
		l = l1;
	if (h1 > 0 && h1 >= l1)
		h = h1;
	if (l2 > 0 && l2 >= h1)
		L = l2;
	if (h2 > 0 && h2 >= l2)
		H = h2;

	ok = (H >= L) && (L >= h) && (h >= l) && (l > 0);
	return ok;
}
//-----------------------------------------
// Tutaj nalezy zdefinowac metode GetPar klasy RegHister2
double RegHister2::GetPar(char par){
	switch(par) {
		case 'l': return l;
		case 'h': return h;
		case 'L': return L;
		case 'H': return H;
		default: return -1.0;
	}
}

//-----------------------------------------
// Tutaj nalezy zdefinowac metode ParOk klasy RegHister2
bool RegHister2::ParOk(void){
	return ok;
}
//-----------------------------------------
// Tutaj nalezy zdefinowac metode Run klasy RegHister2
int RegHister2::Run(double zad, double rzecz){
	if(!ok) {
		y = 0;
		return 0;
	}

	double err = zad - rzecz;
	if (err > 0){
		if (err < l)
			y = 0;
		else if (err >= l && err < h)
			y = 1;
		else if (err >= h && err < L)
			y = 1;
		else if (err >= L)
			y = 2;
	} else if ( err < 0){
		if (err > -l)
			y = 0;
		else if (err <= -l && err > -h)
			y = -1;
		else if (err <= -h && err > -L)
			y = -1;
		else if (err <= -L)
			y = -2;
	}

	return y;
}

//-----------------------------------------
//-----------------------------------------------------------------------------
