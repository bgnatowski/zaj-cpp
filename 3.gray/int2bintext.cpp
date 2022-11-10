
/***************************************************************
*
* Plik int2bintext.cpp
*
* Autorzy: Bartosz Gnatowski, Konrad Jurczyk
*
***************************************************************/

#include <string>
#include "int2bintext.h"

//-------------------------------------------------------------

// Funkcja do uzupe³nienia.
// Zamienia liczbê ca³kowit¹ n na postaæ tekstow¹ w formacie binarnym (dwójkowym)

void Int2BinText( string &s, unsigned long int n )
{
	s.clear();
	int i = (8*sizeof(unsigned long int)-1);
	unsigned long int maska = 1UL << i;

	for(i; i >= 0; i--){
		bool wynik = n&maska;

		if(wynik)
			s+='1';
		else
			s+='0';
		maska >>= 1;
	}

}

//-------------------------------------------------------------
