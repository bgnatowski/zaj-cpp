
/***************************************************************
*
* Plik czas.h
*
* Autorzy:
*
***************************************************************/

#ifndef CZAS_H_INCLUDED
#define CZAS_H_INCLUDED

//--------------------------------------------------------------

using namespace std;

//--------------------------------------------------------------

class Czas
{
public:

// Tutaj nale¿y zadeklarowaæ publiczne sk³adowe klasy Czas
	Czas(void); // 1
	Czas(int h, int m, int s, int ms); // 2
	Czas(long int x); // 3
	Czas(double x); // 4

	// Gettery // 5
	int h(void) const { return HH; }
	int m(void) const { return MM; }
	int s(void) const { return SS; }
	int ms(void) const { return sss; }
	bool sign(void) const{ return sign; }
	//
	Czas & operator += (const Czas &x); // 6
	Czas & operator -= (const Czas &x); // 7
	Czas & operator == (long int x); // 8
	Czas & operator == (double x); // 9
	operator long int() const; // 10
	operator long double() const; // 11
	// 12
	Czas operator ++ (void);
	Czas operator ++ (int);
	Czas operator -- (void);
	Czas operator -- (int);

private:
// Tutaj nale¿y zadeklarowaæ prywatne sk³adowe klasy Czas
	int HH, MM, SS, sss;
	bool sign;

	private void normaliseMs(int &s, int &ms){
		if (ms > 999){
			int howManyTimes = ms % 1000;
			ms = ms - howManyTimes * 1000;
			s += howManyTimes;
		}
	}

	private void normaliseMs(int &m, int &s){
		if (s > 59){
			int howManyTimes = ms % 60;
			s = s - howManyTimes * 60;
			m += howManyTimes;
		}
	}

	private void normaliseM(int &h, int &ms){
		if (m > 59){
			int howManyTimes = m % 60;
			m = m - howManyTimes * 60;
			h += howManyTimes;
		}
	}

	private void setAll(int h, int m, int s, int ms){
		HH = h;
		MM = m;
		SS = s;
		sss = ms;
	};
};

//--------------------------------------------------------------

// Tutaj nale¿y zadeklarowaæ zewnêtrzne funkcje operatorowe
// zwi¹zane z klas¹ Czas

Czas operator + (const Czas x1, const Czas x2);
Czas operator - (const Czas x1, const Czas x2);
bool operator > (const Czas x1, const Czas x2);
bool operator => (const Czas x1, const Czas x2);
bool operator < (const Czas x1, const Czas x2);
bool operator <= (const Czas x1, const Czas x2);
bool operator == (const Czas x1, const Czas x2);
bool operator != (const Czas x1, const Czas x2);


//--------------------------------------------------------------

#endif		/* CZAS_H_INCLUDED */
