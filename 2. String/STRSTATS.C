/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

void main(void)
{
	char text[1000];
	int i;
	int characters = 0, sentence = 0, word, spaces = 0;
	int vowel = 0, consonants = 0;

	clrscr();
	printf("\n\tEnter some text : ");
	gets(text);

	for(i = 0 ; text[i] != '\0' ; i++)
	{
		characters++;
		if(text[i] == '.')
			sentence++;
		else if(text[i] == ' ')
			spaces++;
		else if(text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U' || text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
			vowel++;
	}

	word = spaces + 1;

	consonants = characters - ( vowel + sentence + spaces );

	printf("\n\tCharacters   : %d", characters);
	printf("\n\tSentence     : %d", sentence);
	printf("\n\tSpaces       : %d", spaces);
	printf("\n\tVowels       : %d", vowel);
	printf("\n\tConsonants   : %d", consonants);
	printf("\n\tWords        : %d", word);

	getch();
}