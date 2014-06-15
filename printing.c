void draw_number(int n, int x, int y){
    
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
        	mvaddch(x,sy,' ');
    }
    return;
}

void prinboard(int bowl){

	int *p=board;
	draw_number(*p, (row-7)/2, (col-66)/2 +  0);p++;
	draw_number(*p, (row-7)/2, (col-66)/2 +  8);p++;
	draw_number(*p, (row-7)/2, (col-66)/2 + 16);p++;
	draw_number(*p, (row-7)/2, (col-66)/2 + 24);p++;
	draw_number(*p, (row-7)/2, (col-66)/2 + 32);p++;
	draw_number(*p, (row-7)/2, (col-66)/2 + 40);p++;
	if (!(bowl/10))
	{
		draw_number(bowl, (row-7)/2, (col-66)/2 + 60);
    	refresh();
		return ;
	}
	draw_number(bowl/10, (row-7)/2, (col-66)/2 + 52);
	draw_number(bowl%10, (row-7)/2, (col-66)/2 + 60);
    refresh();
	return ;
}

void princhoices(int highlight){
	if (highlight==1)
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, (col-66)/2 +  0, "enter!");
	if (highlight==1)		
		attroff(A_REVERSE);

	printw("  ");

	if (highlight==2)		
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, (col-66)/2 +  8, "enter!");
	if (highlight==2)		
		attroff(A_REVERSE);
	
	printw("  ");
	
	if (highlight==3)		
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, (col-66)/2 + 16, "enter!");
	if (highlight==3)		
		attroff(A_REVERSE);
	
	printw("  ");
	
	if (highlight==4)		
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, (col-66)/2 + 24, "enter!");
	if (highlight==4)		
		attroff(A_REVERSE);
	
	printw("  ");
	
	if (highlight==5)		
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, (col-66)/2 + 32, "enter!");
	if (highlight==5)		
		attroff(A_REVERSE);
	
	printw("  ");
	
	if (highlight==6)		
		attron(A_REVERSE);
	mvprintw((row-7)/2 + 8, (col-66)/2 + 40, "enter!");
	if (highlight==6)		
		attroff(A_REVERSE);
	
	refresh();
}

void alert(int noticeactivate){
	char c[15]="              ";
	if (noticeactivate)
		strcpy(c,"Illegal move");
	if (c[1]=='l')
		attron(A_STANDOUT);
	mvprintw((row - ((row-7)/2 + 6))/2, (col - 12)/2, "%s", c);
	if (c[1]=='l')
		attroff(A_STANDOUT);
}