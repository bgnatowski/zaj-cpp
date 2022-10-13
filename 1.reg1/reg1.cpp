
/******************************************************************************
*
* Plik reg1.cpp
*
* Autor: Zbigniew Mikos
*
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <curses.h>

#include <time.h>

#include "reghister2.h"
#include "naped.h"

//-----------------------------------------------------------------------------

#define		CMD_NONE	' '
#define		CMD_POZ		'P'
#define		CMD_L1		'l'
#define		CMD_H1		'h'
#define		CMD_L2		'L'
#define		CMD_H2		'H'
#define		CMD_V_SLOW	'S'
#define		CMD_V_FAST	'F'
#define		CMD_QUIT	'Q'

//-----------------------------------------------------------------------------

struct CtrlData_s 
{
	char	cmd;
	double	data;
};

CtrlData_s	CtrlData;

WINDOW		*InputWin, *OutputWin;

//-----------------------------------------------------------------------------

enum	{ PAIR_NORMAL = 1, PAIR_RK, PAIR_MAX };

int 	ncInit( void );
void	ncClose( void );

//-----------------------------------------------------------------------------

int	ncInit( void )
{
	initscr( );

	noecho( );
	cbreak( );
	nonl( );
	intrflush( stdscr, FALSE );
	keypad( stdscr, TRUE );
	nodelay( stdscr, TRUE );
	raw( );
	scrollok( stdscr, FALSE );

	start_color( );
	if( COLOR_PAIRS >= PAIR_MAX )
	{
		init_pair( PAIR_NORMAL, COLOR_WHITE, COLOR_BLACK );
		init_pair( PAIR_RK, COLOR_RED, COLOR_BLACK );
	}

	curs_set( 0 );
	bkgdset( 0 | COLOR_PAIR( PAIR_NORMAL ) );
	clear( );
	refresh( );

	return 0;
}

//-----------------------------------------------------------------------------

void ncClose( void )
{
	nl( );
	clear( );
	refresh( );
	endwin( );
}

//-----------------------------------------------------------------------------

void Input( void )
{
	char	*prompt = " [liczba]-pozycja, [l|h|L|H]-par.reg., [s|f]-par.napedu, [Q|X]-koniec: ";
	int		promptLen;
	int		xMax, yMax;

	char	c;
	static char	buf[32] = "";
	static char bufIdx = 0;
	
	promptLen = strlen( prompt );
	xMax = getmaxx( InputWin );
	yMax = getmaxy( InputWin );

	noecho( );
	nodelay( InputWin, TRUE );
	
	mvwprintw( InputWin, 2, ( xMax - promptLen ) / 2, "%s", prompt );

	c = wgetch( InputWin );

	wmove( InputWin, 2, ( xMax + promptLen ) / 2 + 1 );

	if( c != ERR && c != '\x0D' )
	{
		buf[bufIdx++] = c;
		buf[bufIdx] = '\0';
		wprintw( InputWin, "%s", buf );
	}
	
	if( c == '\x0D' )
	{
		wclrtoeol( InputWin );

		switch( buf[0] )
		{
		case '0' :					// cyfra, + lub -
		case '1' :
		case '2' :
		case '3' :
		case '4' :
		case '5' :
		case '6' :
		case '7' :
		case '8' :
		case '9' :
		case '-' :
		case '+' :
			CtrlData.data = strtod( buf, NULL );
			CtrlData.cmd = CMD_POZ;
			break;
		
		case 'l' :
			CtrlData.data = strtod( &buf[1], NULL );
			CtrlData.cmd = CMD_L1;
			break;

		case 'h' :
			CtrlData.data = strtod( &buf[1], NULL );
			CtrlData.cmd = CMD_H1;
			break;

		case 'L' :
			CtrlData.data = strtod( &buf[1], NULL );
			CtrlData.cmd = CMD_L2;
			break;

		case 'H' :
			CtrlData.data = strtod( &buf[1], NULL );
			CtrlData.cmd = CMD_H2;
			break;

		case 's' :
		case 'S' :
			CtrlData.data = strtod( &buf[1], NULL );
			CtrlData.cmd = CMD_V_SLOW;
			break;

		case 'f' :
		case 'F' :
			CtrlData.data = strtod( &buf[1], NULL );
			CtrlData.cmd = CMD_V_FAST;
			break;

		case 'q' :
		case 'Q' :
		case 'x' :
		case 'X' :
			CtrlData.cmd = CMD_QUIT;
			break;

		default :
			break;

		}
		bufIdx = 0;
		buf[0] = '\0';
	}

}

//-----------------------------------------------------------------------------

int	Draw( int y, int n, char c, int attr )
{
	char		bar[256];
	int			i;

	for( i = 0; i < n; i++ ) bar[i] = c;
	bar[i] = '\0';

	wmove( OutputWin, y, 0 );
	wclrtoeol( OutputWin );
	wattron( OutputWin, attr );
	mvwprintw( OutputWin, y, 0, "%s", bar );
	mvwprintw( OutputWin, y + 2, 0, "%-5d", n );
	wattroff( OutputWin, attr );

	wrefresh( OutputWin );

	return n;
}

//-----------------------------------------------------------------------------

int	main( void )
{
	double	poz, pozZad;
	int		vSel;

	bool	quit = false;

	RegHister2	reg( 0.2, 2.0, 5.0, 8.0 );
	Naped		naped( 0.1, 0.5 );

	struct timespec		period;

//-----------------------------------------

	ncInit( );

	InputWin = newwin( 5, getmaxx( stdscr ), getmaxy( stdscr ) - 5, 0 );
	OutputWin = newwin( getmaxy( stdscr ) - 5, getmaxx( stdscr ), 0, 0 );

	period.tv_sec = 0;
	period.tv_nsec = 250000000;

	CtrlData.cmd = CMD_NONE;
	pozZad = 0.0;


//-----------------------------------------

	do
	{
		nanosleep( &period, 0 );

		Input( );
		
		switch( CtrlData.cmd )
		{
		case CMD_POZ :
			pozZad = CtrlData.data;
			break;
		case CMD_L1 :
			reg.SetPar( CtrlData.data, -1.0, -1.0, -1.0 );
			break;
		case CMD_H1 :
			reg.SetPar( -1.0, CtrlData.data, -1.0, -1.0 );
			break;
		case CMD_L2 :
			reg.SetPar( -1.0, -1.0, CtrlData.data, -1.0 );
			break;
		case CMD_H2 :
			reg.SetPar( -1.0, -1.0, -1.0, CtrlData.data );
			break;
		case CMD_V_SLOW :
			naped.SetPar( CtrlData.data, -1.0 );
			break;
		case CMD_V_FAST :
			naped.SetPar( -1.0, CtrlData.data );
			break;
		case CMD_QUIT :
			quit = true;
			break;
		}
		CtrlData.cmd = CMD_NONE;

		vSel = reg.Run( pozZad, poz );
		poz = naped.Run( vSel );

		Draw( 10, (int)( pozZad + 0.5 ), '#', COLOR_PAIR( PAIR_NORMAL ) | A_BOLD );
		Draw( 14, (int)( poz + 0.5 ), '#', COLOR_PAIR( PAIR_RK ) | A_BOLD );

		mvwprintw( OutputWin, 2, 0, "pozZad=%5.1lf, poz=%5.1lf,  VSel=%3d",
			pozZad, poz, vSel );

		mvwprintw( OutputWin, 4, 0, 
			"Regulator: %-4s l=%4.1lf, h=%4.1lf, L=%4.1lf, H=%4.1lf",
			reg.ParOk( ) ? "OK" : "BLAD",
			reg.GetPar( 'l' ), 
			reg.GetPar( 'h' ), 
			reg.GetPar( 'L' ), 
			reg.GetPar( 'H' ) );

		mvwprintw( OutputWin, 5, 0, 
			"Naped:     %-4s Vslow=%4.1lf, Vfast=%4.1lf",
			naped.ParOk( ) ? "OK" : "BLAD",
			naped.GetPar( 's' ), 
			naped.GetPar( 'f' ) );

	}
	while( !quit );

//-----------------------------------------

	delwin( InputWin );
	delwin( OutputWin );
	
	ncClose( );

	return 0;
}

//-----------------------------------------------------------------------------


