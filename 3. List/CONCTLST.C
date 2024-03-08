/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

/*
	CONCATENATE THE FIRST LIST AT THE END OF THE SECOND LIST
*/

typedef struct node_type
{
	int info;
	struct node_type *next;
}node;

node *head1 = NULL;
node *head2 = NULL;

void InsertIntoList1()
{
	node *ptr, *loc;

	ptr = (node *)malloc(sizeof(node));

	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	fflush(stdin);

	ptr->next = NULL;

	if(head1 == NULL)
		head1 = ptr;
	else
	{
		for(loc = head1 ; loc->next != NULL ; loc = loc->next);
		loc->next = ptr;
	}
}

void InsertIntoList2()
{
	node *ptr, *loc;

	ptr = (node *)malloc(sizeof(node));

	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	fflush(stdin);

	ptr->next = NULL;

	if(head2 == NULL)
		head2 = ptr;
	else
	{
		for(loc = head2 ; loc->next != NULL ; loc = loc->next);
		loc->next = ptr;
	}
}

void Display1()
{
	node *ptr;
	if(head1 == NULL)
	{
		printf("\n\tList empty.");
		return;
	}
	for(ptr = head1 ; ptr != NULL ; ptr = ptr->next)
		printf("\t%d", ptr->info);
}

void Display2()
{
	node *ptr;
	if(head2 == NULL)
	{
		printf("\n\tList empty.");
		return;
	}
	for(ptr = head2 ; ptr != NULL ; ptr = ptr->next)
		printf("\t%d", ptr->info);
}

void ConcatList()
{
	node *ptr;
	for(ptr = head1 ; ptr->next != NULL ; ptr = ptr->next);
	ptr->next = head2;
}

/*
	ALGORITHM:
	START
		SET POINTER "PTR" TO HEAD NODE OF FIRST LIST
		WHILE PTR IS NOT NULL
		DO
				INCREMENT PTR
		DONE
		SET PTR->NEXT = HEAD2
	STOP
*/

void main(void)
{
	char ans = 'Y';

	clrscr();

	printf("\n\tEnter number into List 1 :");
	while(ans == 'Y' || ans == 'y')
	{
		InsertIntoList1();
		printf("\n\tDo you want to insert another node? (Y/N) : ");
		scanf("%c", &ans);
		fflush(stdin);
	}

	printf("\n\tEnter number into List 2 :");

	ans = 'Y';
	while(ans == 'Y' || ans == 'y')
	{
		InsertIntoList2();
		printf("\n\tDo you want to insert another node? (Y/N) : ");
		scanf("%c", &ans);
		fflush(stdin);
	}

	printf("\n\tList 1 is :\n\n\t");
	Display1();

	printf("\n\tList 2 is :\n\n\t");
	Display2();

	ConcatList();

	printf("\n\tList 1 after concatenation is :\n\n\t");
	Display1();

	getch();
}