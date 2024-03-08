/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<string.h>

void main(void)
{
	char names[5][10], temp[10];
	int i, j;

	clrscr();

	for(i = 0 ; i < 5 ; i++)
	{
		printf("\n\tEnter name : ");
		gets(names[i]);
	}

	for(i = 0 ; i < 4 ; i++)
	{
		for(j = i+1 ; j < 5 ; j++)
		{
			if( strcmp(names[i], names[j]) > 0 )
			{
				strcpy(temp, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], temp);
			}
		}
	}

	printf("\n\tSorted names : ");

	for(i = 0 ; i < 5 ; i++)
		printf("\n\t%s", names[i]);

	getch();
}

