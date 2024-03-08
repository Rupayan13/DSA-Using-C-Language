/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

/*
	HEAP SORT
*/

/*
	A HEAP IS A KIND OF BINARY TREE (BUT NOT BINARY SEARCH TREE), THAT ALWAYS MAINTAINS THE FOLLWING TWO PROPERTIES

	1. SHAPE PROPERTY: A HEAP MUST ALWAYS REMAIN A COMPLETE BINARY TREE
	2. ORDER PROPERTY: ACCORDING TO ORDER PROPERTY A HEAP CAN BE OF TWO TYPES:
		A. MIN HEAP: THE VALUE IN THE PARENT NODE MUST BE LESS THAN THE VALUES IN THE IMMEDIATE CHILDREN
		A. MAX HEAP: THE VALUE IN THE PARENT NODE MUST BE GREATER THAN THE VALUES IN THE IMMEDIATE CHILDREN
*/

#include<stdio.h>
#define MAX 5

void Heapify(int a[])
{
	int i, index;
	index = MAX / 2;

	for(i = index ; i >= 1 ; i--)
		Downheap(a, i, MAX-1);
}

void Downheap(int a[], int start, int finish)
{
	int index, lchild, rchild, maximum, temp;

	lchild = 2 * start;  // INDEX OF LEFT CHILD
	rchild = lchild + 1;  // INDEX OF RIGHT CHILD

	if(lchild <= finish)  // IF LEFT CHILD NOT LESS THAN FINISH VALUE
	{
		maximum = a[lchild];  // THEN THIS IS THE MAXIMUM CVALUE
		index = lchild;
		if(rchild <= finish)  // IF RIGHT CHILD NOT LESS THAN FINISH VALUE
		{
			if(a[rchild] > maximum)
			{
				maximum = a[rchild];  // SETTING NEW MAXIMUM VALUE
				index = rchild;
			}
		}  // UPTO THIS POINT WE HAVE TO REMEMBER THE MAXIMUM VALUE AND ITS INDEX
		if(a[start] < a[index])
		{
			// INTEERCHANGE VALUES IF PARENT IS LESS THAN CHILD
			temp = a[start];
			a[start] = a[index];
			a[index] = temp;
			Downheap(a, index, finish);  // CONTINUE THIS RECURSIVELY
		}
	}
}

void HeapSort(int a[])
{
	int i, temp;
	Heapify(a);
	for(i = MAX; i > 1; i--)  // LEAVING OUT THE LAST ELEMENT
	{
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		Downheap(a, 1, i-1);
	}
}

/*
	THEORY
	
	CONSTRUCT A MIN HEAP USING THE UNSORTED VALUES
	
	WHILE THE MIN HEAP IS NOT EMPTY
	DO
		DELETE THE ROOT NODE AND PUT THE VALUE IN THE RESULTANT ARRAY
		RECONSTRUCT THE MIN HEAP
	DONE
*/

/*
	ALGORITHM:
	START
		ASSUME THE UNSORTED ARRAY IS "A[]" AND THE SIZE OF THE ARRAY IS "N"
		CALL HEAPIFY ALGORITHM

		FOR I = N TO 2 STEP -1
			INTERCHANGE ELEMENTS AT A[1] AND A[I]
			CALL DOWNHEAP ALGORITHM WITH A[], 1 AND I-1
		ENDFOR
	STOP
*/

void main(void)
{
	int a[MAX];
	int i;
	clrscr();
	printf("\n\n\n\tEnter elements in the array in unsorted order : ");
	for(i=0; i<MAX; i++)
	{
		printf("\n\n\t\tElement %d : ",i+1);
		scanf("%d", &a[i]);
		fflush(stdin);
	}
	clrscr();
	printf("\n\n\n\n\tYou entered :\n\n\t\t\t");
	for(i=0; i<MAX; i++)
		printf("%d  ", a[i]);
	HeapSort(a);
	printf("\n\n\n\n\tSorted array is :\n\n\t\t\t");
	for(i=0; i<MAX; i++)
		printf("%d  ", a[i]);
	getch();
}

