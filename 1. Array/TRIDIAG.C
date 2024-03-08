/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<math.h>
#define SIZE 4

/*
	TRI DIAGONAL MATRIX

	A MATRIX IS CALLED A TRI DIAGONAL MATRIX IF THERE ARE ZEROES FOR
	EVERY CELL WHERE THE DIFFERENCE OF THE ROW AND THE COLUMN INDEX IS
	WITHIN +/-1. THE REMAINING CELLS CAN HAVE NON-ZERO VALUES

	FOR A NxN TRI DIAGONAL MATRIX:
		THE MAIN DIAGONAL WHERE ROW AND COULMN INDEX ARE SAME
		CONTAINS N ELEMENTS

		THE DIAGONAL BELOW THE MAIN DIAGONAL, WHERE THE ROW INDEX IS
		1 GREATER THAN COULMN INDEX, HAS N-1 ELEMENTS

		SIMILARLY, THE DIAGONAL ABOVE THE MAIN DIAGONAL, WHERE THE
		COLUMN INDEX IS 1 GREATER THAN ROW INDEX, ALSO HAS N-1 ELEMENTS
*/

void main(void)
{
	int arr[SIZE][SIZE];
	int r, c;

	clrscr();

	for(r = 0 ; r < SIZE ; r++)
	{
		for(c = 0 ; c < SIZE ; c++)
			arr[r][c] = 0;
	}

	printf("\n\tEnter values into the diagonal matrix : ");

	for(r = 0 ; r < SIZE ; r++)
	{
		for(c = 0 ; c < SIZE ; c++)
		{
			if((r-c) > 1 || (c-r) > 1)
				continue;
			// IF |ROW - COLUMN| > 1 , ONLY THEN INPUT IS ACCEPTED
			else
			{
				printf("\n\tEnter into row  %d and col  %d : ", r, c);
				scanf("%d", &arr[r][c]);
			}
		}
	}

	printf("\n\tYou have entered : ");

	for(r = 0 ; r < SIZE ; r++)
	{
		printf("\n\t\t");
		for(c = 0 ; c < SIZE ; c++)
			printf("\t%d", arr[r][c]);
	}

	getch();
}


	/*
		ALGORITHM:
		START
			FOR R = 0 TO N-1 STEP 1
				FOR C = 0 TO N-1 STEP 1
					IF (R-C) > 1 OR (C-R) > 1 THEN
						CONTINUE;
					ELSE
						PRINT "ENTER NUMBER : "
						READ VALUE INTO ARR[R, C]
					ENDIF
				ENDFOR
			ENDFOR
		STOP
	*/