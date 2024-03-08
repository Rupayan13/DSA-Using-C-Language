/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

/*
	SELECTION SORT
*/

#include<stdio.h>
#define MAX 5

void SelectionSortMethod(int a[])
{
	int temp, small, loc, i, j;
	for(i = 1 ; i <= MAX-1 ; i++)
	{
		small = a[i-1];
		loc = i-1;
		for(j = i ; j <= MAX-1 ; j++)
		{
			if(a[j] < small)
			{
				small = a[j];
				loc = j;
			}
		}
		if(loc != (i-1))
		{
			temp = a[i-1];
			a[i-1] = a[loc];
			a[loc] = temp;
		}
	}
}

/*
	ALGORITHM:
	START
		ASSUME THE UNSORTED ARRAY IS "A[]" AND THE SIZE OF THE UNSORTED ARRAY IS MAX
		DECLARE VARIABLES "TEMP", "SMALL", "LOC", "I", "J"

		FOR I = 1 TO MAX-1 STEP 1
			SET SMALL = A[I-1]
			SET LOC = I-1
			FOR J = I TO MAX-1 STEP 1
				IF A[J] < SMALL THEN
					SET SMALL = A[J]
					SET LOC = J
				ENDIF
			ENDFOR

			IF LOC NOT EQUAL TO I-1 THEN
				SET TEMP = A[I-1]
				SET A[I-1] = A[LOC]
				SET A[LOC] = TEMP
			ENDIF
		ENDFOR
	STOP
*/

void main(void)
{
	int a[MAX];
	int i;
	clrscr();
	printf("\n\n\n\tEnter elements in the array in unsorted order : ");
	for(i = 0 ; i < MAX ; i++)
	{
		printf("\n\n\t\tElement %d : ", i+1);
		scanf("%d", &a[i]);
		fflush(stdin);
	}
	clrscr();
	printf("\n\n\n\n\tYou entered :\n\n\t\t\t");
	for(i = 0 ; i < MAX ; i++)
		printf("%d  ", a[i]);
	SelectionSortMethod(a);
	printf("\n\n\n\n\tSorted array is :\n\n\t\t\t");
	for(i = 0 ; i < MAX ; i++)
		printf("%d  ", a[i]);
	getch();
}

