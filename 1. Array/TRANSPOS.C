/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define SIZE 3

void main(void)
{
	int a[SIZE][SIZE], b[SIZE][SIZE];
	int r, c;

	clrscr();

	for(r = 0 ; r < SIZE ; r++)
	{
		printf("\n\tEnter for row index %d : ", r);
		for(c = 0 ; c < SIZE ; c++)
		{
			printf("\n\t\tColumn %d : ", c);
			scanf("%d", &a[r][c]);
		}
	}

	printf("\n\tOriginal matrix :\n");
	for(r = 0 ; r < SIZE ; r++)
	{
		printf("\n\t");
		for(c = 0 ; c < SIZE ; c++)
		{
			printf("\t%d", a[r][c]);
		}
	}

	for(r = 0 ; r < SIZE ; r++)          // TRANSPOSE, INTERCHANGING THE r AND c OF THE TWO MATRICES
	{
		for(c = 0 ; c < SIZE ; c++)
		{
			b[r][c] = a[c][r];
		}
	}

/*
	ALGORITHM:
	ASSUMING THERE ARE SQUARE MATRICES "A" AND "B" WITH DIMENSION "SIZE"
	START
		FOR R = 0 TO SIZE-1 STEP 1
			FOR C = 0 TO SIZE-1 STEP 1
				B[R][C] = A[R][C]
			ENDFOR
		ENDFOR
	STOP
*/

	printf("\n\tTransposed matrix :\n");
	for(r = 0 ; r < SIZE ; r++)
	{
		printf("\n\t");
		for(c = 0 ; c < SIZE ; c++)
		{
			printf("\t%d", b[r][c]);
		}
	}

	for(r = 0 ; r < SIZE ; r++)          // ROTATION
	{
		for(c = 0 ; c < SIZE ; c++)
		{
			b[c][SIZE-1 - r] = a[r][c];
		}
	}

/*
	ALGORITHM:
	ASSUMING THERE ARE SQUARE MATRICES "A" AND "B" WITH DIMENSION "SIZE"
	START
		FOR R = 0 TO SIZE-1 STEP 1
			FOR C = 0 TO SIZE-1 STEP 1
				B[C][SIZE-1-R] = A[R][C]
			ENDFOR
		ENDFOR
	STOP
*/

	printf("\n\tRotated matrix :\n");
	for(r = 0 ; r < SIZE ; r++)
	{
		printf("\n\t");
		for(c = 0 ; c < SIZE ; c++)
		{
			printf("\t%d", b[r][c]);
		}
	}

	getch();
}