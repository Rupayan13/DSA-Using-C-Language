/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define SIZE 5

/*
	THIS PROGRAM DEMOSTRATES HOW TO PASS AN ARRAY TO A FUNCTION
*/
void main(void)
{
	int arr[SIZE];
	int i, s;
	int sum(int []);

	clrscr();
	for(i = 0 ; i < SIZE ; i++)
	{
		printf("\n\tEnter into index %d : ", i);
		scanf("%d", &arr[i]);
	}

	printf("\n\tYou have entered : ");
	for(i = 0 ; i < SIZE ; i++)
		printf("\t%d", arr[i]);

	s = sum(arr);

	printf("\n\tThe sum of these numbers is : %d", s);
	getch();
}

int sum(int arr[])
{
	int s = 0, i;

	for(i = 0 ; i < SIZE ; i++)
		s = s + arr[i];

	return s;
}