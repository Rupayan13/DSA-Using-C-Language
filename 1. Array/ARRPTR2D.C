/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define ROW 2
#define COL 3

void main(void)
{
	int arr[ROW][COL];
	int r, c;

	clrscr();

	for(r = 0 ; r < ROW ; r++)
	{
		printf("\n\tEnter into row index %d : ", r);
		for(c = 0 ; c < COL ; c++)
		{
			printf("\n\t\tColumn index %d : ", c);
			scanf("%d", *(arr+r)+c );
		}
	}

	printf("\n\tYou have entered : ");

	for(r = 0 ; r < ROW ; r++)
	{
		printf("\n\t");
		for(c = 0 ; c < COL ; c++)
			printf("\t%d", *(*(arr+r)+c) );
	}

	getch();
}