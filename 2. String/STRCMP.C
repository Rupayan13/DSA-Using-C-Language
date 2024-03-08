/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

/*
	IMPLEMENTING THE OPERATION OF THE strcmp() FUNCTION WITHOUT
	USING THE LIBRARY FUNCTION
*/

void main(void)
{
	char str1[20], str2[20];
	int mystrcmp(char *, char *);

	int c;

	clrscr();

	printf("\n\tEnter first string  : ");
	gets(str1);

	printf("\n\tEnter second string : ");
	gets(str2);

	c = mystrcmp(str1, str2);

	if(c > 0)
		printf("\n\tFirst string is greater.");
	else if(c < 0)
		printf("\n\tSecond string is greater.");
	else
		printf("\n\tStrings are equal.");



	getch();
}


int mystrcmp(char *s1, char *s2)
{
	/*
		 THIS FUCNTION ACCEPTS TWO STRINGS, COMPARES THE TWO STRINGS
		 CHARACTER BY CHARACTER, AND RETURNS THE DIFFERENCE IN THE
		 ASCII VALUES OF THE CHARACTERS WHERE THEY DIFFER. IF THE
		 FIRST STRING IS GREATER, THEN THE FUNCTION RETURNS A POSITIVE
		 INTEGER. IF THE SECOND STRING IS GREATER, THEN THE FUCNTION
		 RETURNS A NEGATIVE INTEGER. IF THE TWO STRIG ARE EQUAL, THE
		 FUNCTION RETURNS 0
	*/
	for( ; *s1 != '\0' && *s2 != '\0' ; s1++, s2++)
	{
		if(*s1 != *s2)
			return (*s1 - *s2);
	}
	if(*s1 != '\0')
		return 1;
	else if(*s2 != '\0')
		return -1;
	else
		return 0;
}

/*
	ALGORITHM:
	START
		ACCEPT THE STARTING ADDRESSES OF THE STRINGS INTO "S1" AND "S2" POINTERS RESPECTIVELY

		WHILE BOTH S1 AND S2 POINTERS DO NOT REACH NULL (END OF THE STRING)
		DO
			IF THE CHARACTERS POINTED TO BY S1 AND S2 POINTERS ARE DIFFERENT THEN
				RETURN THE DIFFERENCE IN THEIR ASCII VALUES
			ELSE
				INCREMENT S1 AND S2 POINTERS
			ENDIF
		DONE
		IF S1 POINTER HAS NOT REACHED NULL THEN
			RETURN +1 (POSITIVE VALUE)
		ELSE IF S2 POINTER HAS NOT REACHED NULL THEN
			RETURN -1 (NEGATIVE VALUE)
		ELSE
			RETURN 0
		ENDIF
	STOP
*/
