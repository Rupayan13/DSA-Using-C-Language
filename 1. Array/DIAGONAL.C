/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define SIZE 3

/*
	DIAGONAL MATRIX

	A MATRIX IS CALLED A DIAGONAL MATRIX WHERE THERE ARE VALUES
	IN EVERY CELL WHERE THE ROW INDEX AND THE COLUMN INDEX ARE SAME.
	THE OTHER CELLS CAN CONTAIN ZERO VALUES.
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
			if(r == c)  // IF ROW AND COLUMN INDICES ARE SAME, WE TAKE THE INPUT
			{
				printf("\n\tEnter into row  %d and col  %d : ", r, c);
				scanf("%d", &arr[r][c]);
			}
			else
				continue;
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
			INITILAIZE ALL THE CELLS OF THE ARRAY WITH 0
			FOR R = 0 TO ROW-1 STEP 1
				FOR C = 0 TO COL-1 STEP 1
					IF R = C THEN
						PRINT "ENTER VALUE : "
						READ VALUE INTO ARR[R, C]
					ELSE
						CONTINUE
					ENDIF
				ENDFOR
			ENDFOR
		STOP
	*/