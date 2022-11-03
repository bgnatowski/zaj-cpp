
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
	setAll(h, m, s, ms);
	normalise();
	if (h < 0)
		m_sign = true;
	m_sign = false;
}

Czas::Czas(long int x){
	if(x < 0 )
		m_sign = true;
	m_sign = false;
	czasFromLongInt(x);
	normalise();

}

Czas::Czas(double x){
	if(x < 0 )
		m_sign = true;
	m_sign = false;
	czasFromDouble(x);
	normalise();

}

Czas& Czas::operator+=(const Czas& x){
	HH+= x.h();
	MM+= x.m();
	SS+= x.s();
	sss+= x.ms();

	normalise();
	return *this;
}

Czas& Czas::operator-=(const Czas& x){
	HH-= x.h();
	MM-= x.m();
	SS-= x.s();
	sss-= x.ms();
	if(HH <= 0 && MM <= 0 && SS <= 0 && sss <= 0){
		HH = MM = SS = sss = 0;
		return *this;
	}
	normalise();
	return *this;
}

Czas& Czas::operator=(long int x) {
	czasFromLongInt(x);
	return *this;
}

Czas& Czas::operator=(double x) {
	czasFromDouble(x);
	return *this;
}

//todo
Czas::operator long int() const {
	return this->convertToLongInt();
}
//todo
Czas::operator double() const {
	return this->convertToDouble();
}

Czas Czas::operator ++ (void){
	SS++;
	normalise();
	return *this;
}

Czas Czas::operator -- (void){
	SS--;
	normalise();
	return *this;
}

Czas Czas::operator ++ (int a){
	Czas tmp;
	tmp = *this;
	SS++;
	normalise();
	return tmp;
}

Czas Czas::operator -- (int a){
	Czas tmp;
	tmp = *this;
	SS--;
	normalise();
	return tmp;
}
//-------------------------------------------------------------

// Tutaj nale¿y zdefiniowaæ zewnêtrzne funkcje operatorowe
// zwi¹zane z klas¹ Czas

//-------------------------------------------------------------

Czas operator + (const Czas x1, const Czas x2){
	Czas tmp = x1;
	return tmp+=x2;
}

Czas operator - (const Czas x1, const Czas x2){
	Czas tmp = x1;
	return tmp-=x2;
}

bool operator > (const Czas x1, const Czas x2){
	return ((x1.h() > x2.h())
	&& (x1.m() > x2.m())
	&& (x1.s() > x2.s())
	&& (x1.ms() > x2.ms()));
}

bool operator >= (const Czas x1, const Czas x2){
	return ((x1.h() >= x2.h())
		&& (x1.m() >= x2.m())
		&& (x1.s() >= x2.s())
		&& (x1.ms() >= x2.ms()));
}

bool operator < (const Czas x1, const Czas x2){
	return ((x1.h() < x2.h())
		&& (x1.m() < x2.m())
		&& (x1.s() < x2.s())
		&& (x1.ms() < x2.ms()));
}

bool operator <= (const Czas x1, const Czas x2){
	return ((x1.h() <= x2.h())
		&& (x1.m() <= x2.m())
		&& (x1.s() <= x2.s())
		&& (x1.ms() <= x2.ms()));
}

bool operator == (const Czas x1, const Czas x2){
	return ((x1.h() == x2.h())
		&& (x1.m() == x2.m())
		&& (x1.s() == x2.s())
		&& (x1.ms() == x2.ms()));
}

bool operator != (const Czas x1, const Czas x2){
	return ((x1.h() != x2.h())
		&& (x1.m() != x2.m())
		&& (x1.s() != x2.s())
		&& (x1.ms() != x2.ms()));
}

