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
	struct list *prev;
}node;

node *head = NULL;
node *tail = NULL;

void InsertAtBeginning(void)
{
	node *ptr;

	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	fflush(stdin);

	if(head == NULL)
	{
		head = ptr;
		tail = ptr;
		ptr->prev = tail;
		ptr->next = head;
	}
	else
	{
		tail->next = ptr;
		ptr->prev = tail;
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}
}

/*
void InsertAtEnd(void)
MAKE A COMPLEMENT OF THE ABOVE FUNCTION
*/

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


void DeleteAtBeginning(void)
{
	node *ptr;

	ptr = head;

	if(head == tail)  // DELETING THE ONLY NODE
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->next;
		head->prev = tail;
		tail->next = head;
	}
	free(ptr);
}

/*
void DeleteAtEnd(void)
MAKE A COMPLEMENT OF THE ABOVE FUNCTION
*/

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

void InsertAfterNode(void)
{
	node *ptr, *loc;
	int n;

	printf("\n\tEnter The number after which you want to insert the new node : ");
	scanf("%d", &n);

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
	(loc->next)->prev = ptr;
	ptr->prev = loc;
	loc->next = ptr;

	if(loc == tail)
		tail = ptr;
}

void DeleteNode(void)
{
	node *ptr, *loc;
	int item;

	printf("\n\t\tEnter the value of the node to be deleted : ");
	scanf("%d",&item);
	fflush(stdin);

	loc = SearchElement(item);
	if(loc == NULL)
	{
		printf("\n\n\t\tthe value %d does not exist in the list", item);
		getch();
		return;
	}
	if(loc == head && loc == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else if(loc == head)  // DELETING THE FIRST NODE
	{
		head = head->next;
		head->prev = tail;
		tail->next = head;
	}
	else if(loc == tail)  // DELETING THE LAST NODE
	{
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
	}
	else  // DELETING ANY OTHER NODE
	{
		(loc->prev)->next = loc->next;
		(loc->next)->prev = loc->prev;
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
/*			case (2) : InsertAtEnd();
					break;
*/			case (3) : DeleteAtBeginning();
					break;
/*			case (4) : DeleteAtEnd();
					break;
*/			case (5) : InsertAfterNode();
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

