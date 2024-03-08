/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

/*
	IMPLEMENTING THE OPERATION OF THE strrev() FUNCTION WITHOUT
	USING THE LIBRARY FUNCTION
*/

void main(void)
{
	char str[10];
	char *mystrrev(char *);

	clrscr();

	printf("\n\tEnter a string  : ");
	gets(str);

	mystrrev(str);

	printf("\n\tThe reverse of the string is : %s", str);

	getch();
}

char *mystrrev(char *s)
{
	/*
		THIS FUNCTION ACCEPTS A STRING, REVERSES IT, AND RETURNS
		THE STARTING ADDRESS OF	THE STRING
	*/

	int i, j;
	char temp;

	i = 0;
	for(j = 0 ; s[j] != '\0' ; j++);  // THIS LOOP TAKES THE COUNTER j TO THE LAST INDEX
	j--;  // INDEX j POINTING TO THE LAST CHARTACTER

	for( ; i < j ; i++, j--)
	{
		//  SWAPPING THE CONTENT OF THE i AND j INDEX
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}

	return &s[0];
}

/*
	ALGORITHM:
	START
		ACCEPT THE STARTING ADDRESSES OF THE STRINGS INTO "S" POINTER

		INTIALIZE COUNTER I TO 0
		INITALIZE COUNTER J TO THE INDEX OF THE LAST CHARACTER IN THE STRING

		WHILE I < J
		DO
			SWAP THE CONTENT OF THE INDICES I AND J
			INCREMENT I
			DECREMENT J
		DONE

		RETURN STARTING ADDRESS OF THE STRING
	STOP
*/