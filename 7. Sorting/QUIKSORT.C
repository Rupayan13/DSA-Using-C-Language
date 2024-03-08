/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

/*
	QUICK SORT
*/

#include<stdio.h>
#define MAX 5

void SplitArray(int a[], int beg, int end, int *loc)
{  /*   a[] = The array
	beg = Beginning index of array
	end = Ending index of array
	loc = Pointer to the location where the array will be split
   */
	int left, right, done, temp;
	left = beg;
	*loc = beg;
	right = end;
	done = 0;
	while(!done)
	{
		while((a[*loc] <= a[right]) && (*loc != right))
			right--;  // MOVING BACKWARD FROM THE END
		if(*loc == right)
			done = 1;
		else if(a[*loc] > a[right])
		{
			// SWAPPING
			temp = a[*loc];
			a[*loc] = a[right];
			a[right] = temp;
			*loc = right;  // loc SHIFTED
		}
		if(!done)
		{
			while(( a[*loc] >= a[left]) && (*loc != left))
				left++;  // MOVING FORWARD TOWARDS THE END
			if(*loc == left)
				done = 1;
			else if(a[*loc] < a[left])
			{
				// SWAPPING
				temp = a[*loc];
				a[*loc] = a[left];
				a[left] = temp;
				*loc = left;  // loc SHIFTED
			}
		}
	}
}

void QuickSortRecursive(int a[], int lb, int ub)
{
	int loc;
	if(lb < ub)
	{
		SplitArray(a, lb, ub, &loc);
		QuickSortRecursive(a, lb, loc-1);
		QuickSortRecursive(a, loc+1, ub);
	}
}

/*
	ALGORITHM:
	START
		ASSUME THE UNSORTED ARRAY IS "A[]"
		DECLARE VARIABLES "LEFT", "RIGHT" AND "LOC"

		PLACE LEFT AND RIGHT VARIBLES TO BEGINNING AND ENDING INDEX OF THE ARRAY RESPECTIVELY.
		PLACE LOC AT LEFT INITIALLY.

		IF A[LEFT] <= A[RIGHT] THEN
			MOVE THAT VARIABLE WHICH IS NOT POINTED TO BY LOC ONE PLACE TOWARDS LOC
		ELSE IF A[LEFT] > a[RIGHT] THEN
			SWAP A[LEFT] AND A[RIGHT]
			MOVE LOC FROM LEFT TO RIGHT IF IT IS ON LEFT OR	MOVE LOC FROM RIGHT TO LEFT IF IT IS ON RIGHT
		ENDIF

		ULTIMATELY, left, right AND loc WOULD CONVERGE ON A SINGLE POINT
		KNOWN AS THE PIVOT POINT. ALL VALUES TO THE LEFT OF THE PIVOT
		POINT ARE LESS THAN THAT OF THE PIVOT POINT WHILEALL VALUES
		TO THE RIGHT OF THE PIVOT POINT ARE GREATER THAN THAT OF
		THE PIVOT POINT.

		RECURSIVELY FOLLOW THIS ALGORITHM ON LEFT AND RIGHT SUBARRAYS
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
	QuickSortRecursive(a, 0, MAX-1);
	printf("\n\n\n\n\tSorted array is :\n\n\t\t\t");
	for(i = 0 ; i < MAX ; i++)
		printf("%d  ", a[i]);
	getch();
}
