#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ncurses.h>
int row,col;
typedef enum { False, True } Bool;
const Bool number[][15] ={
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
void prinboard(int *p,int bowl)/* row print start at (row-7)/2                */
{					  		   /* col print at's 3, 11, 19, 27, 35, 43, 51, 59*/
	draw_number(*p, (row-7)/2,  3);p++;
	draw_number(*p, (row-7)/2, 11);p++;
	draw_number(*p, (row-7)/2, 19);p++;
	draw_number(*p, (row-7)/2, 27);p++;
	draw_number(*p, (row-7)/2, 35);p++;
	draw_number(*p, (row-7)/2, 43);p++;
	if (!(bowl/10))
	{
		draw_number(bowl, (row-7)/2, 59);
		return ;
	}
	draw_number(bowl/10, (row-7)/2, 51);
	draw_number(bowl, (row-7)/2, 59);
	return ;
}
int *boardinit()
{
	return winningboards[rand()%9];
}
int legalmoves(int *p)
{
	int i;
	for (i = 0; i < 6; ++i)
		if (*(p+i)==(6-i))
			return 1;
	return 0;
}
void modifyboard(int seeder,int *b)
{
	int i;
	*(b+seeder-1)=0;
	for (i = seeder; i < 6; ++i)
		(*(b+i))++;
}
void princhoices(int highlight)/* spill the junk which aren't changing.. */
{
	static WINDOW *cois;
	if (highlight==1)
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, 3, "enter!  ");
	if (highlight==1)
		attroff(A_REVERSE);
	if (highlight==2)
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, 11, "enter!  ");
	if (highlight==2)
		attroff(A_REVERSE);
	if (highlight==3)
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, 19, "enter!  ");
	if (highlight==3)
		attroff(A_REVERSE);
	if (highlight==4)
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, 27, "enter!  ");
	if (highlight==4)
		attroff(A_REVERSE);
	if (highlight==5)
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, 35, "enter!  ");
	if (highlight==5)
		attroff(A_REVERSE);
	if (highlight==6)
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, 43, "enter!  ");
	if (highlight==6)
		attroff(A_REVERSE);
	refresh();
}
int userinput()
{
	int c,highlight=1;
	princhoices(1);
	refresh();
	while(1)
	{
		c=getch();
		switch(c)
		{
			case 260:
				if (highlight==1)
					highlight=6;
				else
					highlight--;
				break;
			case 261:
				if (highlight==6)
					highlight=1;
				else
					highlight++;
				break;
			case 10:
				return highlight;
				break;
		}
		princhoices(highlight);
		refresh();
	}
}
int boardstatus(int *check)
{
	int i;
	for (i = 0; i < 6; ++i)
		if (*(check+i))
			return 0;
	return 1;
}
void Winner()
{
	int row,col;
	getmaxyx(stdscr,row,col);
	clear();
	mvprintw(row/2,(col-7)/2, "WINNER!");
}
void Loser()
{
	int row,col;
	getmaxyx(stdscr,row,col);
	clear();
	mvprintw(row/2,(col-8)/2, "LOSER :(");
}
int gameinit(int rows, int cols)
{
	int *board=boardinit();
	int bowl=0;
	while(legalmoves(board))
	{
		prinboard(board,bowl);
		refresh();
		modifyboard(userinput(), board);
		bowl++;
	}
	prinboard(board,bowl);
	return boardstatus(board);
}
int main(int argc, char const *argv[])
{
	int i;
	initscr();
	raw();
	noecho();
	curs_set(0);
	keypad(stdscr,TRUE);
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
	getch();
	endwin();
	return 0;
}