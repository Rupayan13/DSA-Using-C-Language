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
	int arr[SIZE];
	int i, n;
	char found = 'N';

	clrscr();
	for(i = 0 ; i < SIZE ; i++)
	{
		printf("\n\tEnter into index %d : ", i);
		scanf("%d", &arr[i]);
	}

	printf("\n\tYou have entered : ");
	for(i = 0 ; i < SIZE ; i++)
		printf("\t%d", arr[i]);

	printf("\n\tEnter the number which you want to search : ");
	scanf("%d", &n);

	for(i = 0 ; i < SIZE ; i++)
	{
		if(arr[i] == n)
		{
			found = 'Y';
			printf("\n\t%d found at index : %d", n, i);
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
		READ THE VALUE TO BE SEARCHED INTO VARIABLE 'N'

		ASSUME 'FOUND' AS THE FLAG VARIABLE

		FOUND = 'F'

		FOR I= 0 TO SIZE-1 STEP 1
			IF LIST[I] = N THEN
				FOUND = 'T'
				PRINT "THE VALUE IS FOUND AT INDEX ",I
				RETURN
			ENDIF
		ENDFOR

		IF FOUND = 'F' THEN
			PRINT "THE VALUE IS NOT FOUND."
		ENDIF
	STOP
*/