
/***************************************************************
*
* Plik czas.h
*
* Autorzy: Konrad Jurczyk, Bartosz Gnatowski
*
***************************************************************/

#ifndef CZAS_H_INCLUDED
#define CZAS_H_INCLUDED

//--------------------------------------------------------------
#include <cmath>

//--------------------------------------------------------------

class Czas
{
public:

// Tutaj nale�y zadeklarowa� publiczne sk�adowe klasy Czas
	Czas(void); // 1
	Czas(int h, int m, int s, int ms); // 2
	Czas(long int x); // 3
	Czas(double x); // 4

	// Gettery // 5
	int h(void) const { return HH; }
	int m(void) const { return MM; }
	int s(void) const { return SS; }
	int ms(void) const { return sss; }
	bool sign(void) const { return m_sign; }

	Czas & operator += (const Czas &x);
	Czas & operator -= (const Czas &x);
	Czas & operator = (long int x);
	Czas & operator = (double x);
	operator long int() const;
	operator double() const;

	Czas operator ++ (void); // prefix
	Czas operator ++ (int);  // postfix
	Czas operator -- (void);
	Czas operator -- (int);

private:
// Tutaj nale�y zadeklarowa� prywatne sk�adowe klasy Czas
	bool m_sign;
	int HH, MM, SS, sss;

	void normalise(void){
		sss += SS * 1000;
		sss += MM * 60 * 1000;
		sss += HH * 60 * 60 * 1000;

		HH = abs(sss / (60*60*1000));
		MM = abs(((sss / (60*1000))) % 60);
		SS = abs((sss / 1000) % 60);
		sss = abs(sss % 1000);
	}

	void setAll(int h, int m, int s, int ms){
		HH = h;
		MM = m;
		SS = s;
		sss = ms;
	}

	void timeFromLongInt(long int x){
		sss = x % 1000;
		x /= 1000;
		SS = x % 100;
		x /= 100;
		MM = x % 100;
		x /= 100;
		HH = x % 100;

		if(x < 0 ) m_sign = true;
		else m_sign = false;
	}

	void timeFromDouble(double x) {
		HH = MM = SS = sss = 0;
		sss = x * 1000;

		if(x < 0 ) m_sign = true;
		else m_sign = false;
	}

	long int convertToLongInt() const {
		long int x = 0;
		x += HH * 10000000;
		x += MM * 100000;
		x += SS * 1000;
		x += sss;

		if(sign())
			return -x;
		return x;
	}

	double convertToDouble() const {
		double x = 0;
		x += HH * 60 * 60;
		x += MM * 60;
		x += SS;
		x += sss * 0.001;

		if(sign())
			return -x;
		return x;
	}

};

//--------------------------------------------------------------

// Tutaj nale�y zadeklarowa� zewn�trzne funkcje operatorowe
// zwi�zane z klas� Czas

Czas operator + (const Czas x1, const Czas x2);
Czas operator - (const Czas x1, const Czas x2);
bool operator > (const Czas x1, const Czas x2);
bool operator >= (const Czas x1, const Czas x2);
bool operator < (const Czas x1, const Czas x2);
bool operator <= (const Czas x1, const Czas x2);
bool operator == (const Czas x1, const Czas x2);
bool operator != (const Czas x1, const Czas x2);


//--------------------------------------------------------------

#endif		/* CZAS_H_INCLUDED */
