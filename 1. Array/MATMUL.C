/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define MAX 10

void main(void)
{
	int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
	int i, j, k, temp;
	int m, n;  // ROW AND COL FOR THE FIRST MATRIX
	int p, q;  // ROW AND COL FOR THE SECOND MATRIX

	clrscr();

	label:

	printf("\n\tEnter the number of ROWS for the FIRST matrix : ");
	scanf("%d", &m);

	printf("\n\tEnter the number of COLS for the FIRST matrix : ");
	scanf("%d", &n);

	printf("\n\tEnter the number of ROWS for the SECOND matrix : ");
	scanf("%d", &p);

	printf("\n\tEnter the number of COLS for the SECOND matrix : ");
	scanf("%d", &q);

	if(n != p)
	{
		printf("\n\tThe COL of FIRST matrix and the ROW of SECOND matrix mismatch.");
		printf("\n\tProduct is not feasible. Enter the correct value.\n\n");
		goto label;
	}
	else
	{
		printf("\n\tEnter values into FIRST matrix : ");

		for(i = 0 ; i < m ; i++)
		{
			printf("\n\tROW index %d : ", i);
			for(j = 0 ; j < n ; j++)
			{
				printf("\n\t\tCOL index %d : ", j);
				scanf("%d", &a[i][j]);
			}
		}

		printf("\n\tEnter values into SECOND matrix : ");

		for(i = 0 ; i < p ; i++)
		{
			printf("\n\tROW index %d : ", i);
			for(j = 0 ; j < q ; j++)
			{
				printf("\n\t\tCOL index %d : ", j);
				scanf("%d", &b[i][j]);
			}
		}

		printf("\n\tYou have entered : ");

		printf("\n\tFIRST matrix : ");

		for(i = 0 ; i < m ; i++)
		{
			printf("\n\n\t\t");
			for(j = 0 ; j < n ; j++)
			{
				printf("\t%d", a[i][j]);
			}
		}

		printf("\n\tSECOND matrix : ");

		for(i = 0 ; i < p ; i++)
		{
			printf("\n\n\t\t");
			for(j = 0 ; j < q ; j++)
			{
				printf("\t%d", b[i][j]);
			}
		}

		// THE RESULTANT MATRIX SHOULD HAVE m ROWS AND q COLS

		for(i = 0 ; i < m ; i++)
		{
			for(j = 0 ; j < q ; j++)
			{
				temp = 0;
				for(k = 0 ; k < n ; k++)
					temp = temp + a[i][k] * b[k][j];
				c[i][j] = temp;
			}
		}

		printf("\n\tRESULTANT matrix : ");

		for(i = 0 ; i < m ; i++)
		{
			printf("\n\n\t\t");
			for(j = 0 ; j < q ; j++)
			{
				printf("\t%d", c[i][j]);
			}
		}
	}

	getch();
}
/*
	ALGORITHM:
	START
		DECLARE VARIABLES I, J, K, TEMP
		ASSUME M AS THE NUMBER OF ROWS OF THE FIRST MATRIX 'A'
		ASSUME Q AS THE NUMBER OF COLUMNS OF THE SECOND MATRIX 'B'
		ASSUME N AS THE NUMBER OF COLUMNS OF THE FIRST MATRIX 'A'
		ASSUME 'C' ID THE RESULTANT MATRIX		

		FOR I = 0 TO M-1 STEP 1
			FOR J = 0 TO Q-1 STEP 1
				TEMP = 0
				FOR K = 0 TO N-1 STEP 1
					TEMP = TEMP + A[I][K] * B [K][J]
				ENDFOR
				C[I][J] = TEMP
			ENDFOR
		ENDFOR
	STOP
*/

