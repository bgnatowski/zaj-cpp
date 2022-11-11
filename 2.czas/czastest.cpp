

/***************************************************************
*
* Plik czastest.cpp
* Program do testowania klasy Czas z �wiczenia JCC-C02
*
* Autor: Zbigniew Miko�
*
***************************************************************/

using namespace std;

#include	<iostream>
#include	"czas.h"

//======================================================

ostream & operator << ( ostream &s, const Czas &c )
{
	cout << (c.sign() ? "-" : " ");
	cout << '(' << c.h( ) << "h " << c.m( ) << "m " << c.s( ) << "s " << c.ms( ) << "ms" << ')';
	return s;
}


//======================================================

void PressAnyKey( void )
{
	char	buf[128];

	cout << "Nacisnij <Enter> ... ";
	cout.flush( );
	while( cin.rdbuf( )->in_avail( ) > 0 )
		cin.ignore( );
	cin.getline( buf, 128 );
	cout << endl;
}

//======================================================

int main( void )
{
	int			h1, m1, s1, ms1;
	long int	tLong;
	double		tDouble;
//	char 		c;

	Czas		tTmp, t01, t31;

//-------------------------------------------------------

	cout << "Test konstruktorow" << endl << endl;

	Czas	t0;
	cout << "t0( ) = " << t0 << endl << endl;

	cout << "Podaj czas w formacie h m s ms: ";
	cin >> h1 >> m1 >> s1 >> ms1;
	Czas	t1( h1, m1, s1, ms1 );
	cout << "t1( int, int, int, int ) = " << t1 << endl << endl;

	tTmp = t1;

	cout << "Podaj czas w formacie long int: ";
	cin >> tLong;
	Czas	t2( tLong );
	cout << "t2( long int ) = " << t2 << endl << endl;

	cout << "Podaj czas w formacie double: ";
	cin >> tDouble;
	Czas	t3( tDouble );
	cout << "t3( double ) = " << t3 << endl << endl;

	PressAnyKey( );

	cout << "Test operatora +=" << endl;
	cout << "INSTR. t0 = t1; t01 = t0 += t2;" << endl;
	t0 = t1;
	t01 = t0 += t2;
	cout << "t0  = " << t0 << endl;
	cout << "t01 = " << t01 << endl << endl;

	cout << "Test operatora -=" << endl;
	cout << "INSTR. t0 = t1; t01 = t0 -= t2;" << endl;
	t0 = t1;
	t01 = t0 -= t2;
	cout << "t0  = " << t0 << endl;
	cout << "t01 = " << t01 << endl << endl;

	cout << "Test operatora +" << endl;
	cout << "INSTR. t01 = t0 = t1 + t2;" << endl;
	t01 = t0 = t1 + t2;
	cout << "t0  = " << t0 << endl;
	cout << "t01 = " << t01 << endl << endl;

	cout << "Test operatora -" << endl;
	cout << "INSTR. t01 = t0 = t1 - t2;" << endl;
	t01 = t0 = t1 - t2;
	cout << "t0  = " << t0 << endl;
	cout << "t01 = " << t01 << endl << endl;

	PressAnyKey( );

	cout << "Test operatora = ( long int )" << endl;
	cout << "INSTR. t31 = t3 = tLong;" << endl;
	t31 = t3 = tLong;
	cout << "tLong = " << tLong << ",  t31 = " << t31 << ",  t3 = " << t3 << endl << endl;

	cout << "Test operatora = ( double )" << endl;
	cout << "INSTR. t31 = t3 = tDouble;" << endl;
	t31 = t3 = tDouble;
	cout << "tDouble = " << tDouble << ",  t31 = " << t31 << ",  t3 = " << t3 << endl << endl;

	cout << "Test operatorow konwersji typu (long int) i (double)" << endl;
	cout << "INSTR. tLong = t1; tDouble = t1;" << endl;
	tLong = t1;
	tDouble = t1;
	cout << "t1 = " << t1 << endl;
	cout << "t1 jako long int = " << tLong << endl;
	cout << "t1 jako double = " << tDouble << endl << endl;

	PressAnyKey( );

	cout << "Test prefiksowego operatora ++" << endl;
	t01 = t0 = 0L;
	t1 = tTmp;
	cout << "t0 = " << t0 << ", t01 = " << t01 << ", t1 = " << t1 << endl;
	cout << "INSTR. t01 = t0 = ++t1;" << endl;
	t01 = t0 = ++t1;
	cout << "t0  = " << t0 << ", t1 = " << t1 << endl;
	cout << "t01 = " << t01 << endl << endl;

	cout << "Test postfiksowego operatora ++" << endl;
	t01 = t0 = 0L;
	t1 = tTmp;
	cout << "t0 = " << t0 << ", t01 = " << t01 << ", t1 = " << t1 << endl;
	cout << "INSTR. t01 = t0 = t1++;" << endl;
	t01 = t0 = t1++;
	cout << "t0  = " << t0 << ", t1 = " << t1 << endl;
	cout << "t01 = " << t01 << endl << endl;

	cout << "Test prefiksowego operatora --" << endl;
	t01 = t0 = 0L;
	t1 = tTmp;
	cout << "t0 = " << t0 << ", t01 = " << t01 << ", t1 = " << t1 << endl;
	cout << "INSTR. t01 = t0 = --t1;" << endl;
	t01 = t0 = --t1;
	cout << "t0  = " << t0 << ", t1 = " << t1 << endl;
	cout << "t01 = " << t01 << endl << endl;

	cout << "Test postfiksowego operatora --" << endl;
	t01 = t0 = 0L;
	t1 = tTmp;
	cout << "t0 = " << t0 << ", t01 = " << t01 << ", t1 = " << t1 << endl;
	cout << "INSTR. t01 = t0 = t1--;" << endl;
	t01 = t0 = t1--;
	cout << "t0  = " << t0 << ", t1 = " << t1 << endl;
	cout << "t01 = " << t01 << endl << endl;

	PressAnyKey( );

	t1 = tTmp;
	cout << "Test operatorow ==, !=, <, <=, >, >=" << endl;
	cout << "t1 = " << t1 << ", t2 = " << t2 << endl;

	cout << "t1 == t1 " << ( t1 == t1 ) << "    t1 == t2 " << ( t1 == t2 ) << endl;
	cout << "t1 != t1 " << ( t1 != t1 ) << "    t1 != t2 " << ( t1 != t2 ) << endl;
	cout << "t1 <  t1 " << ( t1 < t1 )  << "    t1 <  t2 " << ( t1 < t2 )  << endl;
	cout << "t1 <= t1 " << ( t1 <= t1 ) << "    t1 <= t2 " << ( t1 <= t2 ) << endl;
	cout << "t1 >  t1 " << ( t1 > t1 )  << "    t1 >  t2 " << ( t1 > t2 )  << endl;
	cout << "t1 >= t1 " << ( t1 >= t1 ) << "    t1 >= t2 " << ( t1 >= t2 ) << endl;

	return 0;
}

//======================================================
