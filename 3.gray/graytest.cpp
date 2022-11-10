
/***************************************************************
*
* Plik graytest.cpp
*
* Autorzy: Zbigniew Mikos
*
***************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "int2bintext.h"
#include "gray.h"

using namespace std;

//-------------------------------------------------------------

int main()
{
	string binTxt, grayTxt;

	unsigned long int	nBin0, nBin1, nGray;
	int		n, nMax;

	cout << "Liczba_poczatkowa Ilosc: ";
	cin >> nBin0 >> nMax;

	for( n = 0; n < nMax; n++ )
	{
		Int2BinText( binTxt, nBin0 );
		nGray = Bin2Gray( nBin0 );
		Int2BinText( grayTxt, nGray );
		nBin1 = Gray2Bin( nGray );

		cout << setw(10) << nBin0 << "d = " << binTxt << "b = " << grayTxt << "g = " << nBin1 << "d" << endl;

		nBin0++;
	}

    return 0;
}

//-------------------------------------------------------------
