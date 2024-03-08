/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

/*
	SORTING OF A LIST
*/

typedef struct node_type
{
	int info;
	struct node_type *next;
}node;

node *head = NULL;

void InsertNode()
{
	node *ptr, *loc;

	ptr = (node *)malloc(sizeof(node));

	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	fflush(stdin);

	ptr->next = NULL;

	if(head == NULL)
		head = ptr;
	else
	{
		for(loc = head ; loc->next != NULL ; loc = loc->next);
		loc->next = ptr;
	}
}

void Display()
{
	node *ptr;

	if(head == NULL)
	{
		printf("\n\tThe list is empty. Nothing to display.");
		getch();
		return;
	}
	for(ptr = head ; ptr != NULL ; ptr = ptr->next)
		printf("\t%d", ptr->info);
}

void SortList()
{
	int temp;
	node *i, *j;

	for(i = head ; i->next != NULL ; i = i->next)
	{
		for(j = i->next ; j != NULL ; j = j->next)
		{
			if(i->info > j->info)
			{
				temp = i->info;
				i->info = j->info;
				j->info = temp;
			}
		}
	}
}

/*
	ALGORITHM:
	START
		DECLARE POINTERS "I" AND "J"
		DECLARE VARAIBLE "TEMP" OF INTEGER TYPE

		SET I TO HEAD OF THE LIST
		WHILE I IS NOT NULL
		DO
			SET J = I->NEXT
			WHILE J IS NOT NULL
			DO
				IF I->INFO > J->INFO THEN
					TEMP = I->INFO
					I->INFO = J->INFO
					J->INFO = TEMP
				ENDIF
				INCREMENT J
			DONE
			INCREMENT I
		DONE
	STOP
*/

void main(void)
{
	char ans = 'Y';
	
	clrscr();


	printf("\n\tEnter number in jumbled order : ");
	while(ans == 'Y' || ans == 'y')
	{
		InsertNode();
		printf("\n\tDo you want to insert another node? (Y/N) : ");
		scanf("%c", &ans);
	}

	printf("\n\tYou have entered :\n\n\t");
	Display();

	SortList();

	printf("\n\tThe sorted list is :\n\n\t");
	Display();

	getch();
}