/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

/*
	THIS PROGRAM FINDS A PATTERN IN A STRING, AND RETURNS THE FIRST
	INDEX FROM THE LEFT WHERE THE PATTERN IS FOUND
*/

void main(void)
{
	char str[100], pattern[10];
	int index;
	int match(char *, char *);

	clrscr();

	printf("\n\tEnter a string : ");
	gets(str);

	printf("\n\tEnter the pattern you want to match : ");
	gets(pattern);

	index = match(str, pattern);

	if(index == -1)
		printf("\n\tThe pattern could not be matched.");
	else
		printf("\n\tThe pattern's first occurance in the string is at index : %d", index);

	getch();
}

int match(char *s, char *p)
{
	int i, j, index = -1;

	for(i = 0 ; s[i] != '\0' ; i++)
	{
		j = 0;
		if(s[i] == p[j])
		{
			index = i;
			for( ; p[j] != '\0' ; i++, j++)
			{
				if(s[i] != p[j])
				{
					index = -1;
					break;
				}
			}
			if(p[j] == '\0')
				return index;
		}
	}
	return index;
}

/*
	ALGORITHM:
	START
		ACCEPT THE STARTING ADDRESSES OF THE STRINGS INTO "S1" POINTER
		ACCEPT THE STARTING ADDRESS OF THE PATTERNS INTO "S2" POINTER

		DECLARE INTEGER VARIABLES "I", "J", "INDEX"
		INITIALIZE THE INDEX VARIABLE TO -1 (SENTINEL VALUE)

		INITIALIZE I VARIABLE TO ZERO

		FOR I = 0 TO LAST INDEX STEP 1
			INITIALIZE J TO 0

			IF S[I] = P[J] THEN
			SET INDEX TO I

			WHILE NOT END OF THE PATTERN
			DO
				IF S[I] NOT EQUAL TO P[J] THEN
					SET INDEX TO -1
					BREAK
				ENDIF
				INCREMENT I
				INCREMENT J
			DONE
			IF P[J] IS NULL THEN
				RETURN INDEX
		ENDFOR
		RETURN INDEX
	STOP
*/