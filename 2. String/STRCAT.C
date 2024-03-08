/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

/*
	IMPLEMENTING THE OPERATION OF THE strcat() FUNCTION WITHOUT
	USING THE LIBRARY FUNCTION
*/

void main(void)
{
	char str1[10], str2[10];
	int l;
	char *mystrcat(char *, char *);

	clrscr();

	printf("\n\tEnter first string  : ");
	gets(str1);

	printf("\n\tEnter second string : ");
	gets(str2);

	mystrcat(str1, str2);

	printf("\n\tThe first string now is : %s", str1);

	getch();
}

char *mystrcat(char *s1, char *s2)
{
	/*
		THIS FUNCTION ACCEPTS TWO STRINGS, APPENDS THE SECOND STRING
		AT THE END OF FIRST STRING, AND RETURNS THE STARTING ADDRESS
		OF THE FIRST STRING. THE PREVIOUS CONTENT OF THE FIRST STRING
		(IF ANY) IS NOT ERASED
	*/

	for( ; *s1 != '\0' ; s1++);  // THIS LOOP TAKES THE s1 POINTER AT THE END OF THE FIRST STRING

	for( ; *s2 != '\0' ; s2++, s1++)
		*s1 = *s2;
	*s1 = '\0';

	return &s1[0];
}

/*
	ALGORITHM:
	START
		ACCEPT THE STARTING ADDRESSES OF THE STRINGS INTO "S1" AND "S2" POINTERS RESPECTIVELY

		WHILE S1 POINTER DOES NOT REACH NULL (END OF THE STRING)
		DO
			INCREMENT S1 POINTER
		DONE
		WHILE S2 POINTER DOES NOT REACH NULL (END OF THE STRING)
		DO
			COPY THE CONTENT OF THE S2 POINTER'S HELD ADDRESS INTO THE S1 POINTER'S HELD ADDRESS
			INCREMENT S1 AND S2 POINTERS
		DONE

		STORE NULL IN THE CONTENT OF S1 POINTER'S HELD ADDRESS
		RETURN STARTING ADDRESS OF THE FIRST STRING
	STOP
*/