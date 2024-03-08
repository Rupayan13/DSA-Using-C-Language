/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

/*
	BUCKET SORT
*/

#include<stdio.h>
#define MAX 5

void BucketSortMethod(int a[])
{
	int bucket[10][20], buck_count[10], b[10];
	int i, j, k, r, no_of_passes=0, divisor=1, largest, pass_no;
	largest=a[0];
	for(i = 1; i < MAX ; i++)  // FIND THE LARGEST NUMBER
	{
		if(a[i]>largest)
			largest = a[i];
	}
	while(largest > 0)  // FIND NUMBER OF DIGITS IN LARGEST NUMBER
	{
		no_of_passes++;  // THIS HELPS TO COUNT HOW MANY PASSES ARE REQUIRED AS no_of_passes WILL BE
		largest /= 10;     // EQUAL TO THE NUMBER OF DIGITS IN THE LARGEST NUMBER
	}
	for(pass_no = 0 ; pass_no < no_of_passes ; pass_no++)
	{
		for(k = 0 ; k < 10 ; k++)
			buck_count[k] = 0;  // INITIALIZE BUCKET COUNT
		for(i = 0 ; i < MAX ; i++)
		{
			r = (a[i] / divisor) % 10;  // PUTTING THE NUMBER IN APPROPRIATE BUCKET OF 0,1,2,...9
			bucket[r][buck_count[r]++] = a[i];
		}
		i = 0;
		for(k = 0 ; k < 10 ; k++)
		{
			for(j = 0 ; j < buck_count[k] ; j++)
				a[i++] = bucket[k][j];
		}
		divisor *= 10;  // MULTIPLYING DIVISOR BY 10 AFTER EACH PASS
	}
}

/*
	ALGORITHM:
	START
		DECLARE VARAIBLES DIGITCOUNT, PASS, I, DIGIT
		DELARE INTEGER ARRAY "BUCKET" OF SIZE 10 (FOR 10 DIGITS)
		ASSUME THE UNSORTED ARRAY IS "A[]" AND THE SIZE OF THE UNSORTED ARRAY AS "N"

		FIND THE LARGEST NUMBER IN THE ARRAY
		SET DIGITCOUNT = NUMBER OF DIGITS OF THAT LARGEST NUMBER
		FOR PASS = 1 TO DIGITCOUNT STEP 1
			INITIALIZE BUCKETS
			FOR I = 0 TO N-1 STEP 1
				SET DIGIT = DIGIT NUMBER AT "PASS" POSITION IN THE NUMBER AT A[I]
				PUT A[I] IN BUCKET[DIGIT]
				INCREMENT BUCKET COUNT FOR BUCKET[DIGIT]
			ENDFOR
			COLLECT ALL THE BUMBERS FROM THE ARRAY BUCKET IN SORTED ORDER
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
	BucketSortMethod(a);
	printf("\n\n\n\n\tSorted array is :\n\n\t\t\t");
	for(i = 0 ; i < MAX ; i++)
		printf("%d  ", a[i]);
	getch();
}
