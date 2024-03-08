/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define SIZE 5

/*
	MERGING OF TWO SORTED SUBARRAYS
*/

void main(void)
{
	int a[SIZE], b[SIZE], c[2*SIZE];
	int i, j, k;

	clrscr();

	printf("\n\tEnter into first array in ascending order : ");

	for(i = 0 ; i < SIZE ; i++)
	{
		printf("\n\t\tEnter number : ");
		scanf("%d", &a[i]);
	}

	printf("\n\tEnter into second array in ascending order : ");

	for(j = 0 ; j < SIZE ; j++)
	{
		printf("\n\t\tEnter number : ");
		scanf("%d", &b[j]);
	}

	i = 0;
	j = 0;
	k = 0;

	while(i < SIZE && j < SIZE)
	{
		if(a[i] < b[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else if(a[i] > b[j])
		{
			c[k] = b[j];
			k++;
			j++;
		}
		else  // DUPLICATES ARE NOT ALLOWED
		{
			c[k] = a[i];
			k++;
			i++;
			j++;
		}
	}

	if(i < SIZE)
	{
		while(i < SIZE)
		{
			c[k] = a[i];
			k++;
			i++;
		}
	}
	else if(j < SIZE)
	{
		while(j < SIZE)
		{
			c[k] = b[j];
			k++;
			j++;
		}
	}

	printf("\n\tThe merged array is : ");

	for(i = 0 ; i < k ; i++)
		printf("  %d", c[i]);

	getch();
}

/*
	ALGORITHM:
	START
		I = 0
		J = 0
		K = 0

		WHILE I < SIZE AND J < SIZE
		DO
			IF A[I] < B[J] THEN
				C[K] = A[I]
				INCREMENT I, K
			ELSE I A[I] > B[J] THEN
				C[K] = B[J]
				INCREMENT J, K	
			ELSE
				C[K] = A[I]
				INCREMENT I, J, K
			ENDIF 
		DONE
		
		IF I < SIZE THEN
			WHILE I < SIZE
			DO
				C[K] = A[I]
				INCREMENT I, K
			DONE
		ELSE IF I < SIZE THEN
			WHILE I < SIZE
			DO
				C[K] = B[I]
				INCREMENT I, K
			DONE
		ENDIF

	STOP
*/