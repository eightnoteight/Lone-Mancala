#include "lone-mancala.h"

int gameinit(int rows, int cols){
	srand(getpid());
	board=winningboards[rand()%9];
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

int main(int argc, char const *argv[]){
	int i;
	initscr();
	raw();
	noecho();
	curs_set(0);
	keypad(stdscr,TRUE);
	getmaxyx(stdscr,row,col);
	if(row < MinHEI || col < MinWID)
	{
		mvprintw(row/2, (col-24)/2, "Increase Terminal Size.!");
		getch();
		endwin();
		exit(1);
	}
	attron(A_BOLD);
	mvprintw(0,(col-27)/2,"Welcome to the Lone-Mancala\n");
	move(2,0);
	for (i = 0; i < col; ++i)
		printw("-");
	attroff(A_BOLD);
	if(gameinit(row,col))
		Winner();
	else
		Loser();
	getch();
	endwin();
	return 0;
}