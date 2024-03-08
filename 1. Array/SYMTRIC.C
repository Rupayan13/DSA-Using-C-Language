/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define SIZE 3

/*
	CHECK WHETHER A MATRIX IS SYMMETRIC
*/

void main(void)
{
	int arr[SIZE][SIZE];
	int r, c;

	clrscr();

	for(r = 0 ; r < SIZE ; r++)
	{
		for(c = 0 ; c < SIZE ; c++)
		{
			printf("\n\tEnter number : ");
			scanf("%d", &arr[r][c]);
		}
	}

	printf("\n\You entered : ");

	for(r = 0 ; r < SIZE ; r++)
	{
		printf("\n");
		for(c = 0 ; c < SIZE ; c++)
		{
			printf("\t%d", arr[r][c]);
		}
	}

	for(r = 0 ; r < SIZE ; r++)
	{
		for(c = 0 ; c < SIZE ; c++)
		{
			if(arr[r][c] != arr[c][r])
			{
				printf("\n\tThe array is not Symmetric.");
				getch();
				exit(0);
			}
		}
	}

	printf("\n\tThe array is symmetric.");
	getch();
}
/*
	ALGORITHM:
	START
		FOR R = 0 TO SIZE-1 STEP 1
			FOR C = 0 TO SIZE-1 STEP 1
				IF ARR[R][C] != ARR[C][R] THEN
					PRINT "THE ARRAY IS NOT SYMMETRIC."
					RETURN
				ENDIF
			ENDFOR
		ENDFOR
		PRINT "THE ARRAY IS SYMMETRIC."
	STOP
*/