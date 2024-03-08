/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

/*
	MERGE SORT
*/

#include<stdio.h>
#define MAX 5

void MergingSortedSubArrays(int a[MAX], int lb, int lr, int rb, int rr)
{  /*   a[] = The array
	lb  = Beginning index of left subarray
	lr  = Rear index of left subarray
	rb  = Beginning index of right subarray
	rr  = Rear index of right subarray
   */
	int na, nb, nc, k, c[MAX];
	na = lb;
	nb = rb;
	nc = lb;
	while((na <= lr) && (nb <= rr))  // TILL THE END OF LEFT AND RIGHT SUBARRAY
	{
		if(a[na] < a[nb])
			c[nc] = a[na++];
		else
			c[nc] = a[nb++];
		nc++;
	}
	if(na > lr)  // REMAINING ELEMENTS OF RIGHT SUBARRAY
	{
		while(nb <= rr)
			c[nc++] = a[nb++];
	}
	else
	{
		while(na <= lr)
			c[nc++] = a[na++];
	}
	for(k = lb ; k <= rr ; k++)
		a[k] = c[k];
}

/*
	ALGORITHM:
	START
		ASSUME "A[]" AS THE UNSORTED ARRAY
		ASSUME "LB" AS THE BEGINNING INDEX OF THE LEFT SUBARRAY
		ASSUME "LR" AS THE REAR INDEX OF THE LEFT SUBARRAY
		ASSUME "RB" AS THE BEGINNING INDEX OF THE RIGHT SUBARRAY
		ASSUME "RR" AS THE REAR INDEX OF THE RIGHT SUBARRAY

		DECLARE VAIABLES NA, NB, NC, K,
		DECLARE TEMPORARY ARRAY C[MAX]

		SET NA = LB;
		SET NB = RB;
		SET NC = LB;

		WHILE NA <= LR AND NB <= RR
		DO
			IF A[NA] < A[NB] THEN
				C[NC] = A[NA]
				INCREMENT NA
			ELSE
				C[NC] = A[NB]
				INCREMENT NB
			ENDIF
			INCREMENT NC
		DONE

		IF NA > LR THEN
			WHILE NB <= RR
			DO
				C[NC] = A[NB]
				INCREMENT NB AND NC
			DONE
		ELSE
			WHILE NA <= LR
			DO
				C[NC] = A[NA]
				INCREMENT NA AND NC
			DONE
		ENDIF

		FOR K = LB TO RR STEP 1
			SET A[K] = C[K]
		ENDFOR
	STOP
*/

void MergeSortMethod(int a[], int beg, int end)
{  /*   a[] = The original array
	beg = Beginning index of the original array
	end = Rear index of the original array
   */
	int mid;
	if(beg < end)
	{
		mid = (beg + end) / 2;
		MergeSortMethod(a, beg, mid);
		MergeSortMethod(a, mid+1, end);
		MergingSortedSubArrays(a, beg, mid, mid+1, end);
	}
}

/*
	ALGORITHM:
	START
		ASSUME THE BEGINNING INDEX OF THE SUBARRAY AS "BEG"
		ASSUME THE ENDING INDEX OF THE SUBARRAY AS "END"
		DECLARE VARIABLE "MID"

		IF BEG < END THEN
			SET MID = (BEG + END) / 2

			DIVIDE THE ARRAY INTO TWO HALVES : LEFT SUBARRAY AS BEG TO MID, AND RIGHT SUBARRAY AS MID+1 TO END
			RECURSIVELY CALL THE ALGORITHM WITH BEG TO MID
			RECURSIVELY CALL THE ALGORITHM WITH BEG+1 TO END
			CALL MERGE ALGORITHM WITH THE LEFT AND RIGHT SUBARRAY
		ENDIF
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
		printf("\n\n\t\tElement %d : ",i+1);
		scanf("%d", &a[i]);
		fflush(stdin);
	}
	clrscr();
	printf("\n\n\n\n\tYou entered :\n\n\t\t\t");
	for(i = 0 ; i < MAX ; i++)
		printf("%d  ", a[i]);
	MergeSortMethod(a, 0, MAX-1);
	printf("\n\n\n\n\tSorted array is :\n\n\t\t\t");
	for(i = 0 ; i < MAX ; i++)
		printf("%d  ", a[i]);
	getch();
}
