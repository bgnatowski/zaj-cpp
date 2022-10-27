
/***************************************************************
*
* Plik czas.cpp
*
* Autorzy:
*
***************************************************************/

#include <cmath>

#include "czas.h"

//-------------------------------------------------------------

// Tutaj nale¿y zdefiniowaæ metody klasy Czas

Czas::Czas(void){
	HH = MM = SS = sss = 0;
}

Czas::Czas(int h, int m, int s, int ms){
	normalise(h, m, s, ms);
	setAll(h, m, s, ms);
	if (h < 0)
		sign = true;
	sign = false;
}

Czas::Czas(long int x){
	if(x < 0 )
		sign = true;
	sign = false;

	int ms = x % 1000;
	x /= 1000;
	int s = x % 100;
	x /= 100;
	int m = x % 100;
	x /= 100;
	int h = x % 100;

	normalise(h, m, s, ms);
	setAll(h, m, s, ms);
}

Czas::Czas(double x){
	if(x < 0 )
		sign = true;
	sign = false;

	int h, m, s, ms = 0;
	ms = x * 1000;
	normalise(h, m, s, ms);
	setAll(h, m, s, ms);
}

Czas::operator+=(const Czas& x){

}
//-------------------------------------------------------------

// Tutaj nale¿y zdefiniowaæ zewnêtrzne funkcje operatorowe
// zwi¹zane z klas¹ Czas

//-------------------------------------------------------------

