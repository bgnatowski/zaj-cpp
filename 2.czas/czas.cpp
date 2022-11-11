
/***************************************************************
*
* Plik czas.cpp
*
* Autorzy: Konrad Jurczyk, Bartosz Gnatowski
*
***************************************************************/

#include <cmath>

#include "czas.h"

//-------------------------------------------------------------

// Tutaj nale�y zdefiniowa� metody klasy Czas

Czas::Czas(void){
	HH = MM = SS = sss = 0;
    m_sign = false;
}

Czas::Czas(int h, int m, int s, int ms){
    if (h < 0) m_sign = true;
    else m_sign = false;

	setAll(h, m, s, ms);
	normalise();
}

Czas::Czas(long int x){
	if(x < 0 ) m_sign = true;
    else m_sign = false;
    timeFromLongInt(x);
	normalise();
}

Czas::Czas(double x){
	if(x < 0 ) m_sign = true;
	else m_sign = false;
    timeFromDouble(x);
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
    timeFromLongInt(x);
    normalise();
	return *this;
}

Czas& Czas::operator=(double x) {
    timeFromDouble(x);
    normalise();
	return *this;
}

Czas::operator long int() const {
	return convertToLongInt();
}

Czas::operator double() const {
	return convertToDouble();
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

// Tutaj nale�y zdefiniowa� zewn�trzne funkcje operatorowe
// zwi�zane z klas� Czas

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
	return ( (x1.h() > x2.h()) && (x1.m() > x2.m()) && (x1.s() > x2.s()) && (x1.ms() > x2.ms()) );
}

bool operator >= (const Czas x1, const Czas x2){
	return ( (x1.h() >= x2.h()) && (x1.m() >= x2.m()) && (x1.s() >= x2.s()) && (x1.ms() >= x2.ms()) );
}

bool operator < (const Czas x1, const Czas x2){
	return ( (x1.h() < x2.h()) && (x1.m() < x2.m()) && (x1.s() < x2.s()) && (x1.ms() < x2.ms()) );
}

bool operator <= (const Czas x1, const Czas x2){
	return ( (x1.h() <= x2.h()) && (x1.m() <= x2.m()) && (x1.s() <= x2.s()) && (x1.ms() <= x2.ms()) );
}

bool operator == (const Czas x1, const Czas x2){
	return ( (x1.h() == x2.h()) && (x1.m() == x2.m()) && (x1.s() == x2.s()) && (x1.ms() == x2.ms()) );
}

bool operator != (const Czas x1, const Czas x2){
	return ( (x1.h() != x2.h()) && (x1.m() != x2.m()) && (x1.s() != x2.s()) && (x1.ms() != x2.ms()) );
}

