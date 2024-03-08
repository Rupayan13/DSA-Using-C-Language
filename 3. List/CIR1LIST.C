/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

// CIRCULARLY LINKED LIST

typedef struct list  // DECLARING NEW DATATYPE FOR THE CIRCULAR SINGLY LINKED LIST
{
	int info;
	struct list *next;
}node;

node *head = NULL;

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

/*
	ALGORITHM:
	START
		CREATE A NEW NODE AND ASSIGN ITS ADDRESS TO POINTER "PTR"
		READ NEW VALUE INTO PTR->INFO

		IF HEAD = NULL THEN
			SET HEAD = PTR
		ELSE
			POSITION THE "LOC" POINTER AT THE HEAD NODE
			WHILE LOC->NEXT IS NOT EQUAL TO HEAD
			DO
				INCREMENT LOC
			DONE
			SET LOC->NEXT = PTR
		ENDIF
		SET PTR->NEXT = HEAD
	STOP
*/

void Traversal(void)
{
	node *ptr;

	if(head == NULL)
	{
		printf("\n\n\t\tList is empty. Nothing to display.");
		getch();
		return;
	}
	for( ptr = head ; ptr->next != head ; ptr = ptr->next)
		printf("\t%d", ptr->info);
	printf("\t%d", ptr->info);
}

/*
	ALGORITHM:
	START
		IF HEAD IS NULL THEN
			PRINT "LIST IS EMPTY."
			RETURN
		ENDIF

		POSITION THE POINTER "PTR" AT THE HEAD NODE
		WHILE PTR->NEXT IS NOT EQUAL TO HEAD
		DO
			PRINT PTR->INFO
			INCREMENT PTR
		DONE
		PRINT PTR->INFO
	STOP
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

/*
	ALGORITHM:
	START
		READ THE VALUE TO BE SEARCHED INTO THE VARIABLE "ITEM"
		IF HEAD IS NULL
			RETURN NULL
		ELSE
			POSITION THE POINTER "PTR" AT THE HEAD NODE
			WHILE PTR->NEXT IS NOT EQUAL TO HEAD
			DO
				IF PTR->INFO = ITEM THEN
					RETURN PTR
				ENDIF	
				INCREMENT PTR
			DONE
			IF PTR->INFO = ITEM THEN
				RETURN PTR
			ELSE 
				RETURN NULL
		ENDIF	
	STOP
*/

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
	ptr = SearchElement(item);
	if(ptr == NULL)
	{
		printf("\n\n\t\tthe value %d does not exist in the list", item);
		getch();
		return;
	}
	if(ptr == head)  // DELETING THE FIRST NODE
	{
		for( loc = head ; loc->next != head ; loc = loc->next);
		head = head->next;
		loc->next=head;
	}
	else if(ptr->next == head)  // DELETING THE LAST NODE
	{
		for(loc = head ; loc->next != ptr ; loc = loc->next);
		loc->next = head;
	}
	else  // DELETING ANY OTHER NODE
	{
		for(loc = head ; loc->next != ptr ; loc = loc->next);
		loc->next = ptr->next;
	}
	free(ptr);
}


/*
	ALGORITHM:
	START
		PRINT "ENTER THE NODE YOU WANT TO DELETE"
		READ VALUE INTO VARAIBLE "ITEM"

		SEARCH ITEM IN THE LIST AND RETURN THE ADDRESS OF THE FOUND NODE TO POINTER "PTR"
		IF PTR = NULL THEN
			PRINT "NODE NOT FOUND"
			RETURN
		ELSE
			IF HEAD = PTR THEN
				POSITION "LOC" POINTER AT HEAD
				WHILE LOC->NEXT IS NOT EQUAL TO HEAD
				DO
					INCREMENT LOC
				DONE
				HEAD = HEAD->NEXT
				LOC->NEXT = HEAD
			ELSE IF PTR->NEXT = HEAD THEN
				POSITION "LOC" POINTER AT HEAD
				WHILE LOC->NEXT IS NOT EQUAL TO PTR
				DO
					INCREMENT LOC
				DONE
				LOC->NEXT = HEAD
			ELSE
				POSITION "LOC" POINTER AT HEAD
				WHILE LOC->NEXT IS NOT EQUAL TO PTR
				DO
					INCREMENT LOC
				DONE
				LOC->NEXT = PTR->NEXT
			ENDIF
			DELETE THE NODE POINTED TO BY PTR
		ENDIF
	STOP
*/

void main(void)
{
	int ch;

	while(1)
	{
		clrscr();
		printf("\n\n\n\t\t\tMENU");
		printf("\n\n\t\t 1. Insert Node");
		printf("\n\t\t 2. Display");
		printf("\n\t\t 3. Delete node");
		printf("\n\t\t 4. Exit");
		printf("\n\t\t\tEnter your choice : ");
		scanf("%d", &ch);
		fflush(stdin);

		switch(ch)
		{
			case (1) : InsertAtEnd();
					break;

			case (2) : Traversal();
					break;

			case (3) : DeleteNode();
					break;

			case (4) : printf("\n\tExiting...");
					getch();
					exit(0);
		}
		getch();
	}
}
