/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

typedef struct list  // DECLARING NEW DATATYPE FOR THE CIRCULAR SINGLY LINKED LIST
{
	int info;
	struct list *next;
}node;

node *head = NULL;

void InsertAtBeginning(void)
{
	node *ptr, *loc;

	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	fflush(stdin);

	if(head == NULL)  // IF THE NODE IS INITIALLY EMPTY
		head = ptr;

	ptr->next = head;

	for( loc = head ; loc->next != head ; loc = loc->next );
	// loc GOES TO THE LAST NODE
	loc->next = ptr;

	head = ptr;

}

void InsertAtEnd(void)
{
	node *ptr, *loc;

	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	fflush(stdin);

	if(head == NULL)  // IF THE NODE IS INITIALLY EMPTY
		head = ptr;
	else
	{
		for( loc = head ; loc->next != head ; loc = loc->next );
		// loc GOES TO THE LAST NODE
		loc->next = ptr;
	}
	ptr->next = head;
}


void Display(void)
{
	node *ptr;
	if(head == NULL)
	{
		printf("\n\n\tList is empty.");
		return;
	}
	printf("\n\n\tThe list at this point is : ");
	for( ptr = head ; ptr->next != head ; ptr = ptr->next)
		printf("\t%d", ptr->info);
	printf("\t%d", ptr->info);

}


node *SearchElement(int item)  // SEARCHING FOR A PARTICULAR NUMBER PROVIDED
{
	node *ptr;
	if(head == NULL)
		return NULL;
	for( ptr = head ; ptr->next != head ; ptr = ptr->next)
	{
		if(ptr->info == item)
			return ptr;
	}
	if(ptr->info == item)
		return ptr;
	else
		return NULL;
}

void DeleteAtBeginning(void)
{
	node *ptr, *loc;

	loc = head;

	for( ptr = head ; ptr->next != head ; ptr = ptr->next);
	head = head->next;
	ptr->next=head;

	free(loc);
}

void DeleteAtEnd(void)
{
	node *ptr, *loc;
	for(ptr = head ; ptr->next != head ; ptr = ptr->next)
		loc = ptr;
	loc->next = head;

	free(ptr);	
}


void InsertAfterNode(void)
{
	node *ptr, *loc;
	int n;

	printf("\n\tEnter the number after which you want to insert the new node : ");
	scanf("%d", &n);
	fflush(stdin);

	loc = SearchElement(n);

	if(loc == NULL)
	{
		printf("\n\n\t\tthe value %d does not exist in the list", n);
		getch();
		return;
	}	
	
	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	fflush(stdin);
	
	ptr->next = loc->next;
	loc->next = ptr;
}

void DeleteNode(void)
{
	node *ptr, *loc;
	int item;

	printf("\n\t\tEnter the value of the node to be deleted : ");
	scanf("%d",&item);
	fflush(stdin);

	if(head == NULL)
	{
		printf("\n\n\t\tList is empty. Nothing to delete.");
		getch();
		return;
	}
	loc = SearchElement(item);
	if(loc == NULL)
	{
		printf("\n\n\t\tthe value %d does not exist in the list", item);
		getch();
		return;
	}
	if(loc == head && loc->next == head) // DELETING THE ONLY NODE
	{
		head = NULL;
	}
	if(loc == head)  // DELETING THE FIRST NODE
	{
		for( ptr = head ; ptr->next != head ; ptr = ptr->next);
		head = head->next;
		ptr->next=head;
	}
	else if(loc->next == head)  // DELETING THE LAST NODE
	{
		for(ptr = head ; ptr->next != loc ; ptr = ptr->next);
		ptr->next = head;
	}
	else  // DELETING ANY OTHER NODE
	{
		for(ptr = head ; ptr->next != loc ; ptr = ptr->next);
		ptr->next = loc->next;
	}
	free(loc);
}

void main(void)
{
	int ch;

	while(1)
	{
		clrscr();
		printf("\n\n\n\t\t\tMENU");
		printf("\n\n\t\t 1. Insert At Beginning");
		printf("\n\t\t 2. Insert At End");
		printf("\n\t\t 3. Delete At Beginning");
		printf("\n\t\t 4. Delete At End.");
		printf("\n\t\t 5. Insert After Node.");
		printf("\n\t\t 6. Delete Node.");
		printf("\n\t\t 7. Exit");
		printf("\n\t\t\tEnter your choice : ");
		scanf("%d", &ch);
		fflush(stdin);

		switch(ch)
		{
			case (1) : InsertAtBeginning();
					break;
			case (2) : InsertAtEnd();
					break;
			case (3) : DeleteAtBeginning();
					break;
			case (4) : DeleteAtEnd();
					break;
			case (5) : InsertAfterNode();
					break;
			case (6) : DeleteNode();
					break;
			case (7) : printf("\n\tExiting...");
					getch();
					exit(0);
		}
		Display();
		getch();
	}
}