/*
* this is hackjob that translates the ANSI escape sequences used by larn
* to Curses API calls
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <curses.h>
#include "includes/ansiterm.h"


/********************************************
*              CURSES BACK-END             *
********************************************/

static int llgetch (void);

void
ansiterm_init (void)
{
	initscr();
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);
	start_color();
	use_default_colors();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	curs_set(0);
	refresh();

#if defined WINDOWS_VS
  PDC_save_key_modifiers (1);
#endif
}

void
ansiterm_clean_up (void)
{
  nocbreak ();
  nl ();
  echo ();
  endwin ();
}

/*
* get char
*/
int
ansiterm_getch (void)
{
  return llgetch ();
}

void 
ansiterm_flush_input(void)
{
  flushinp();
}

void 
ansiterm_show_cursor(int visible)
{
  curs_set(visible);
}

/*
* get char (with echo)
*/
int
ansiterm_getche (void)
{
  int key;
  echo ();
  key = llgetch();
  noecho ();
  return key;
}
/* wgetch() is the modern way. -Gibbon */
static int
llgetch (void)
{
  int key;
  key = wgetch(stdscr);
#if defined(PDC_KEY_MODIFIER_SHIFT)
  int shift = PDC_get_key_modifiers () & PDC_KEY_MODIFIER_SHIFT;
#else
  int shift = 0;
#endif

#ifdef PDC_KEY_MODIFIER_SHIFT
  if (shift)
    {
      switch (key)
	{
	case '1':
	  return 'B';
	case '2':
	  return 'J';
	case '3':
	  return 'N';
	case '4':
	  return 'H';
	case '5':
	  return '.';
	case '6':
	  return 'L';
	case '7':
	  return 'Y';
	case '8':
	  return 'K';
	case '9':
	  return 'U';
	}
    }
#endif
  switch (key)
    {
    case KEY_UP:
      return shift?'K':'k';
    case KEY_DOWN:
      return shift?'J':'j';
    case KEY_LEFT:
      return shift?'H':'h';
    case KEY_RIGHT:
      return shift?'L':'l';
#if defined PDC_KEY_MODIFIER_SHIFT
    case KEY_A2:
      return shift?'K':'k';
    case KEY_B1:
      return shift?'H':'h';
    case KEY_B3:
      return shift?'L':'l';
    case KEY_C2:
      return shift?'J':'j';
    case PADENTER:
      return 13;
#endif
    case KEY_A1:
      return shift?'Y':'y';
    case KEY_A3:
      return shift?'U':'u';
    case KEY_C1:
      return shift?'B':'b';
    case KEY_C3:
      return shift?'N':'n';
    case KEY_B2:
      return '.';
    case KEY_ENTER:
      return 13;
    default:
      return key;
    }
}

void
ansiterm_delch (void)
{
  delch ();
}


