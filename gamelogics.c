int legalmoves(int *p){
	int i;
	for (i = 0; i < 6; ++i)
		if (*(p+i) == (6-i))
			return 6-i;
	return 0;
}

void modifyboard(int seeder){
	int i;
	*(board+seeder-1)=0;
	for (i = seeder; i < 6; ++i)
		(*(board+i))++;
}

int boardstatus(int *check){
	int i;
	for (i = 0; i < 6; ++i)
		if (*(check+i))
			return 0;
	return 1;
}

int userinput(){
	int c;/* char range for all the keys will exceed it's size so int */
	static int highlight=1;
	princhoices(highlight);
	refresh();
	while(1)
	{
		c=getch();
		switch(c)
		{
			case 260:/* Left Key */
				if (highlight==1)
					highlight=6;
				else
					highlight--;
				break;
			case 261:/* Right Key */
				if (highlight==6)
					highlight=1;
				else
					highlight++;
				break;
			case 10:/* Enter Key */
				if ((*(board+n-1)==7-n)?0:1)
				{
					alert(1);
					break;
				}
				alert(0);
				return highlight;
		}
		princhoices(highlight);
		refresh();
	}
}
