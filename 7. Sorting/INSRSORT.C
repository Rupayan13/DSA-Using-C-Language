/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

/*
	INSERTION SORT
*/

#include<stdio.h>
#define MAX 5

void InsertionSortMethod(int a[])
{
	int k, temp, j;
	for(k = 1 ; k <= MAX-1 ; k++)
	{
		temp = a[k];
		j = k-1;
		while((temp < a[j]) && (j >= 0))
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = temp;
	}
}

/*
	ALGORITHM:
	START
		DECLARE VARIABLES K, TEMP, J
		ASSUME THE UNSORTED ARRAY IS "A[]" AND THE SIZE OF THE ARRAY IS "MAX"

		FOR K = 1 TO MAX-1 STEP 1
			SET TEMP = A[K]
			SET J = K-1

			WHILE TEMP < A[J] ND J >= 0
			DO
				SET A[J+1] = A[J];
				SET J = J-1
			DONE
			SET A[J+1] = TEMP
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
	InsertionSortMethod(a);
	printf("\n\n\n\n\tSorted array is :\n\n\t\t\t");
	for(i = 0 ; i < MAX ; i++)
		printf("%d  ", a[i]);
	getch();
}

