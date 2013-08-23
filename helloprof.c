#include <stdio.h>
#include <curses.h>

main()
{
  int i = 0;
  
  initscr();
  clear();
  
  for(i=0; i<=LINES-1; i++)
    {
      move(i,i+2);
      if (i%2)
	standout();
      
      addstr("Hello, world");
      if (i%2)
	standend();
      
    }
  refresh();
  getch();
  endwin();
}
