/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

/*
	BUBBLE SORT
*/

#include<stdio.h>
#define MAX 5

void BubbleSortMethod(int a[])
{
	int temp, i, j;
	for(i = 0 ; i < MAX-1 ; i++)
	{
		for(j=i+1 ; j < MAX ; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

/*
	ALGORITHM:
	START
		DECLARE VARIABLES I, J, TEMP
		ASSUME THE SIZE OF THE ARRAY IS "MAX"

		FOR I = 0 TO MAX-2 STEP 1
			FOR J = I+1 TO MAX-1 STEP 1
				IF A[I] > A[J] THEN
					TEMP = A[I]
					A[I] = A[J]
					A[J] = TEMP
				ENDIF
			ENDFOR
		ENDFOR
	STOP
*/

void main(void)
{
	int a[MAX];
	int i;
	clrscr();
	printf("\n\n\n\tEnter elements in the array in unsorted order : ");
	for(i = 0; i < MAX ; i++)
	{
		printf("\n\n\t\tElement %d : ", i+1);
		scanf("%d", &a[i]);
		fflush(stdin);
	}
	clrscr();
	printf("\n\n\n\n\tYou entered :\n\n\t\t\t");
	for(i=0 ; i < MAX ; i++)
		printf("%d  ", a[i]);
	BubbleSortMethod(a);
	printf("\n\n\n\n\tSorted array is :\n\n\t\t\t");
	for(i = 0 ; i < MAX ; i++)
		printf("%d  ", a[i]);
	getch();
}


