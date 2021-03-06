#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
/* Minimum Width and Height*/
#define MinWID 66
#define MinHEI 22

/* Global Declarations */
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
int winningboards[][6]={
	{0,0,4,2,2,1},
	{0,5,3,1,1,0},
	{0,5,3,1,1,1},
	{6,4,2,3,1,1},
	{6,4,2,3,1,0},
	{6,4,2,0,2,1},
	{6,4,2,0,2,0},
	{6,4,2,0,0,1},
	{6,4,2,0,0,0},
};
int *board=winningboards[0];

/* Prototypes */


/* lone-mancala.c */
int gameinit(int , int );

/* winnerandlose.c */
void Winner();
void Loser();

/* printing.c */
void draw_number(int , int , int );
void prinboard(int* );
void princhoices(int );
void alert(int );

/* gamelogics.c */
int legalmoves(int*);
void modifyboard(int seeder);
int boardstatus(int *check);
int userinput();
