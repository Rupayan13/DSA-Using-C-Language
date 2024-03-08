/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define SIZE 5

void main(void)
{
	int arr[SIZE], n;
	int i, j, temp;
	int high, low, mid;
	char found = 'N';

	clrscr();
	for(i = 0 ; i < SIZE ; i++)
	{
		printf("\n\tEnter into index %d : ", i);
		scanf("%d", &arr[i]);
	}

	// SORTING THE ARRAY IN ASCENDING ORDER BEFORE USING IT

	for(i = 0 ; i < SIZE - 1 ; i++)
	{
		for(j = i+1 ; j < SIZE ; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("\n\tYou have entered : ");
	for(i = 0 ; i < SIZE ; i++)
		printf("\t%d", arr[i]);

	printf("\n\tEnter the number which you want to search : ");
	scanf("%d", &n);

	low = 0;
	high = SIZE-1;

	while(low <= high)
	{
		mid = (low+high)/2;
		if(n < arr[mid])
			high = mid -1;
		else if(n > arr[mid])
			low = mid + 1;
		else
		{
			found = 'Y';
			printf("\n\t%d found at index : %d", n, mid);
			break;
		}
	}
	if(found == 'N')
		printf("\n\t%d not found.", n);

	getch();
}

/*
	ALGORITHM:
	START
		LOW = 0
		HIGH = SIZE -1

		ASSUME 'FOUND' AS THE FLAG VARIABLE

		READ VALUE TO BE SEARCHED INTO VARIABLE 'N'

		FOUND = 'F'

		WHILE LOW <= HIGH
		DO
			MID = (LOW+HIGH)/2
			IF N < ARR[MID] THEN
				HIGH = MID -1
			ELSE IF N > ARR[MID] THEN
				LOW = MID + 1
			ELSE
				FOUND = 'T'
				PRINT "THE NUMBER IS FOUND AT INDEX : ", MID
				RETURN
			ENDIF
		DONE
		IF FOUND = 'F' THEN
			PRINT "THE NUMBER IS NOT FOUND."
		ENDIF
	STOP
*/