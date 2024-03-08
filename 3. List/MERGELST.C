/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

/*
	MERGING OF TWO SORTED LISTS
*/

typedef struct node_type
{
	int info;
	struct node_type *next;
}node;

node *head1 = NULL;
node *head2 = NULL;
node *head3 = NULL;

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

void Insert(int n)
{
	node *ptr, *loc;

	ptr = (node *)malloc(sizeof(node));

	ptr->info = n;
	ptr->next = NULL;

	if(head3 == NULL)
		head3 = ptr;
	else
	{
		for(loc = head3 ; loc->next != NULL ; loc = loc->next);
		loc->next = ptr;
	}

}

void Display1()
{
	node *ptr;

	if(head1 == NULL)
	{
		printf("\n\tThe list is empty. Nothing to display.");
		getch();
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
		printf("\n\tThe list is empty. Nothing to display.");
		getch();
		return;
	}
	for(ptr = head2 ; ptr != NULL ; ptr = ptr->next)
		printf("\t%d", ptr->info);
}

void Display3()
{
	node *ptr;

	if(head3 == NULL)
	{
		printf("\n\tThe list is empty. Nothing to display.");
		getch();
		return;
	}
	for(ptr = head3 ; ptr != NULL ; ptr = ptr->next)
		printf("\t%d", ptr->info);
}

void MergeList()
{
	node *ptr1 = head1, *ptr2 = head2;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1->info < ptr2->info)
		{
			Insert(ptr1->info);
			ptr1 = ptr1->next;
		}
		else if(ptr1->info > ptr2->info)
		{
			Insert(ptr2->info);
			ptr2 = ptr2->next;
		}

		else
		{
			Insert(ptr1->info);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}
	if(ptr1 != NULL)
	{
		while(ptr1 != NULL)
		{
			Insert(ptr1->info);
			ptr1 = ptr1->next;
		}
	}
	else if(ptr2 != NULL)
	{
		while(ptr2 != NULL)
		{
			Insert(ptr2->info);
			ptr2 = ptr2->next;
		}
	}
}

/*
	ALGORITHM:
	START
		SET PTR1 TO HEAD OF THE FIRST LIST
		SET PTR2 TO HEAD OF THE SECOND LIST

		WHILE PTR1 IS NOT NULL AND PTR2 IS NOT NULL
		DO
			IF PTR1->INFO < PTR2->INFO THEN
				CREATE NEW NODE WITH PTR1->INFO
				INSERT THE NEW NODE INTO THE RESULTANT LIST
				INCREMENT PTR1
			ELSE IF PTR1->INFO > PTR2->INFO THEN
				CREATE NEW NODE WITH PTR2->INFO
				INSERT THE NEW NODE INTO THE RESULTANT LIST
				INCREMENT PTR2
			ELSE
				CREATE NEW NODE WITH PTR1->INFO
				INSERT THE NEW NODE INTO THE RESULTANT LIST
				INCREMENT PTR1 AND PTR2
			ENDIF
		DONE

		IF PTR1 IS NOT NULL THEN
			WHILE PTR1 IS NOT NULL
			DO
				CREATE NEW NODE WITH PTR1->INFO
				INSERT THE NEW NODE INTO THE RESULTANT LIST
				INCREMENT PTR1
			DONE
		ELSE IF PTR2 IS NOT NULL THEN
			WHILE PTR2 IS NOT NULL
			DO
				CREATE NEW NODE WITH PTR2->INFO
				INSERT THE NEW NODE INTO THE RESULTANT LIST
				INCREMENT PTR2
			DONE
		ENDIF
	STOP
*/

void main(void)
{
	char ans = 'Y';

	clrscr();

	printf("\n\tEnter number into List 1 (in ascending order) : ");
	while(ans == 'Y' || ans == 'y')
	{
		InsertIntoList1();
		printf("\n\tDo you want to insert another node? (Y/N) : ");
		scanf("%c", &ans);
		fflush(stdin);
	}

	printf("\n\tEnter number into List 2 (in ascending order)  : ");

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

	MergeList();

	printf("\n\tThe merged list is :\n\n\t");
	Display3();

	getch();
}