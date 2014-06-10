#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ncurses.h>
typedef enum { False, True } Bool;
const Bool number[][15] =
{
     {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1}, /* 0 */
     {0,0,1,0,0,1,0,0,1,0,0,1,0,0,1}, /* 1 */
     {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1}, /* 2 */
     {1,1,1,0,0,1,1,1,1,0,0,1,1,1,1}, /* 3 */
     {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1}, /* 4 */
     {1,1,1,1,0,0,1,1,1,0,0,1,1,1,1}, /* 5 */
     {1,1,1,1,0,0,1,1,1,1,0,1,1,1,1}, /* 6 */
     {1,1,1,0,0,1,0,0,1,0,0,1,0,0,1}, /* 7 */
     {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1}, /* 8 */
     {1,1,1,1,0,1,1,1,1,0,0,1,1,1,1}, /* 9 */
};
void draw_number(int n, int x, int y)
{
     int i, sy = y;

     for(i = 0; i < 30; ++i, ++sy)
     {
        if(sy == y + 6)
        {
            sy = y;
            ++x;
        }
        if (number[n][i/2])
	    {
	    	attron(A_STANDOUT);
	    	bkgdset(COLOR_PAIR(number[n][i/2]));
	    	mvaddch(x,sy,' ');
	    	attroff(A_STANDOUT);
        }
        else
        {
        	mvaddch(x,sy,' ');
        }
    }
    refresh();
     return;
}
int winningboards[9][6]={
	0,0,4,2,2,1,
	0,5,3,1,1,0,
	0,5,3,1,1,1,
	6,4,2,3,1,1,
	6,4,2,3,1,0,
	6,4,2,0,2,1,
	6,4,2,0,2,0,
	6,4,2,0,0,1,
	6,4,2,0,0,0,
};
void prinboard(int *p)/* row print start at (row-7)/2 */
{					  /* col print at's 3, 11, 19, 27, 35, 43, 51, 59*/
	
}
int *boardinit()
{
	return winningboards[rand()%9];
}
int gameinit(int rows, int cols)
{
	int *board=boardinit();
	int bowl=0;
	while(legalmoves(board))
	{
		prinboard(board,bowl)
		refresh();
		modifyboard(userinput(), board);	
	}
	prinboard(board);
	return boardstatus(board);
}
int main(int argc, char const *argv[])
{
	int row,col,i;
	initscr();
	raw();
	noecho();
	attron(A_BOLD);
	getmaxyx(stdscr,row,col);
	mvprintw(0,(col-27)/2,"Welcome to the Lone-Mancala\n");
	move(2,0);
	for (i = 0; i < col; ++i)
		printw("-");
	attroff(A_BOLD);
	if(gameinit(row,col))
	{
		Winner();
	}
	else
	{
		Loser();
	}
	sleep(5);
	getch();
	endwin();
	return 0;
}