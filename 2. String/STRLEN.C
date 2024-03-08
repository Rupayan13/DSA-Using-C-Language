/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

/*
	IMPLEMENTING THE OPERATION OF THE strlen() FUNCTION WITHOUT
	USING THE LIBRARY FUNCTION
*/

void main(void)
{
	char str[10];
	int l;
	int mystrlen(char *);

	clrscr();

	printf("\n\tEnter a string : ");
	gets(str);

	l = mystrlen(str);

	printf("\n\tThe string contains %d characters.", l);

	getch();
}

int mystrlen(char *s)
{
	/*
		THIS FUNCTION ACCEPTS A STRING, CALCULATES THE NUMBER
		OF CHARACTERS IN IT, AND RETURNS THE INTEGER.
	*/
	int c = 0;

	for( ; *s != '\0' ; s++)
		c++;

	return c;
}

/*
	ALGORITHM:
	START
		ACCEPT THE STARTING ADDRESS OF THE STRING INTO "S" POINTER
		INITIALISE C (COUNTER VARIABLE) TO 0

		WHILE S POINTER DOES NOT REACH NULL (END OF THE STRING)
		DO
			INCREMENT C
			INCREMENT S POINTER
		DONE
		RETURN C
	STOP
*/
