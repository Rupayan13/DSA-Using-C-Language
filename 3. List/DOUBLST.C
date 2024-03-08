/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

typedef struct list // DECLARING NEW DATATYPE FOR THE DOUBLY LINKED LIST
{
	int info;
	struct list *prev;
	struct list *next;

}node;

node *head = NULL;
node *tail = NULL;

void TraverseInOrder(void)  // FORWARD TRAVERSAL
{
	node *ptr;
	if(head == NULL)
		printf("\tList empty. Nothing to display.");
	else
	{
		for(ptr = head ; ptr != NULL ; ptr = ptr->next)
			printf("\t%d", ptr->info);
	}
}

/*
	ALGORITHM:
	START
		IF HEAD IS NULL THEN
			PRINT "LIST IS EMPTY."
			RETURN
		ENDIF

		POSITION THE POINTER "PTR" AT THE HEAD NODE
		WHILE PTR IS NOT NULL
		DO
			PRINT PTR->INFO
			SET PTR = PTR->NEXT
		DONE
	STOP
*/

void TraverseInReverseOrder(void)  // BACKWARD TRAVERSAL
{
	node *ptr;
	if(tail == NULL)
		printf("\tList empty. Nothing to display.");
	else
	{
		for(ptr = tail ; ptr != NULL ; ptr = ptr->prev)
			printf("\t%d", ptr->info);
	}
}

/*
	ALGORITHM:
	START
		IF HEAD IS NULL THEN
			PRINT "LIST IS EMPTY."
			RETURN
		ENDIF

		POSITION THE POINTER "PTR" AT THE TAIL NODE
		WHILE PTR IS NOT NULL
		DO
			PRINT PTR->INFO
			SET PTR = PTR->PREV
		DONE
	STOP
*/

node *SearchElement(int n)  // SEARCHING FOR A PARTICULAR NUMBER PROVIDED
{			    // BY THE VARIABLE 'n' AND RETURNING ITS ADDRESS IF FOUND
			    // NOTE THE RETURN TYPE OF THE FUNCTION
	node *ptr;
	for(ptr = head ; ptr != NULL ; ptr = ptr->next)
	{
		if(ptr->info == n)
			return ptr;
	}
	return NULL;
}

/*
	ALGORITHM:
	START
		READ THE VALUE TO BE SEARCHED INTO THE VARIABLE "N"

		POSITION THE POINTER "PTR" AT THE HEAD NODE
		WHILE PTR IS NOT NULL
		DO
			IF PTR->INFO = N THEN
				RETURN PTR
			ENDIF
			INCREMENT PTR
		DONE
		RETUTN NULL
	STOP
*/

void InsertAtBeginning(void)  // INSERTING A NEW NODE BEFORE THE FIRST NODE
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter new node : ");
	scanf("%d", &ptr->info);
	ptr->prev = NULL;
	if(head == NULL)
	{
		ptr->next = NULL;
		head = ptr;
		tail = ptr;
	}
	else
	{
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}
	printf("\n\n\t\tNode inserted at beginning of list.");
	getch();
}

/*
	ALGORITHM:
	START
		CREATE A NEW NODE AND ASSIGN ITS ADDRESS TO POINTER "PTR"
		READ NEW VALUE INTO PTR->INFO
		SET PTR->PREV = NULL
		IF HEAD = NULL THEN
			SET PTR->NEXT = NULL
			SET HEAD = PTR
			SET TAIL = PTR
		ELSE
			SET PTR->NEXT = HEAD
			SET HEAD->PREV = PTR
			SET HEAD = PTR
		ENDIF
	STOP
*/

void InsertAtEnd(void)  // INSERTING A NEW NODE AFTER THE LAST NODE
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter new node : ");
	scanf("%d", &ptr->info);
	ptr->next = NULL;
	if(tail == NULL)
	{
		ptr->prev = NULL;
		head = ptr;
		tail = ptr;
	}
	else
	{
		ptr->prev = tail;
		tail->next = ptr;
		tail = ptr;
	}
	printf("\n\n\t\tNode inserted at end of list.");
	getch();
}

/*
	ALGORITHM:
	START
		CREATE A NEW NODE AND ASSIGN ITS ADDRESS TO POINTER "PTR"
		READ NEW VALUE INTO PTR->INFO
		SET PTR->NEXT = NULL
		IF HEAD = NULL THEN
			SET PTR->PREV = NULL
			SET TAIL = PTR
			SET PREV = PTR
		ELSE
			SET PTR->PREV = TAIL
			SET TAIL->NECT = PTR
			SET TAIL = PTR
		ENDIF
	STOP
*/

void InsertAfterElement(void)  // INSERTING A NEW NODE BEHIND A PARTICULAR
{           															    // NODE AFTER SEARCHING IT
	node *ptr,*loc;
	int n;
	printf("\n\tEnter the node after which you want to insert the new node : ");
	scanf("%d", &n);
	loc = SearchElement(n);
	if(loc == NULL)
	{
		printf("\n\n\t\t%d not found. Cannot insert the new node.", n);
		getch();
		return;
	}
	ptr = malloc(sizeof(node));
	printf("\n\tEnter the new node : ");
	scanf("%d", &ptr->info);
	if(loc->next == NULL)  // IF 'n' NODE IS LAST NODE
	{
		ptr->next = NULL;
		loc->next = ptr;
		ptr->prev = tail;
		tail = ptr;
	}
	else
	{
		ptr->prev = loc;
		ptr->next = loc->next;
		(loc->next)->prev = ptr;
		loc->next = ptr;
	}
	printf("\n\n\t\tNode inserted after the node %d.", n);
	getch();
	return;
}

/*
	ALGORITHM:
	START
		PRINT "ENTER THE VALUE AFTER WHICH YOU WANT TO INSERT THE NEW NODE"
		READ VALUE INTO VARAIBLE "N"
		SEARCH N IN THE LIST AND RETURN THE ADDRESS OF THE FOUND NODE TO POINTER "LOC"
		IF LOC = NULL THEN
			PRINT "NODE NOT FOUND"
			RETURN
		ENDIF

		CREATE A NEW NODE AND ASSIGN ITS ADDRESS TO POINTER "PTR"
		READ NEW VALUE INTO PTR->INFO

		IF LOC->NEXT = NULL THEN
			SET PTR->NEXT = NULL
			SET LOC->NEXT = PTR
			SET PTR->PREV = TAIL
			SET TAIL = PTR
		ELSE
			SET PTR->PREV = LOC
			SET PTR->NEXT = LOC->NEXT
			(LOC->NEXT)->PREV = PTR
			SET LOC->NEXT = PTR
		ENDIF
	STOP
*/

void InsertBeforeElement(void)  // INSERTING A NEW NODE BEFORE A PARTICULAR
{																			 // NODE AFTER SEARCHING IT
	node *ptr, *loc;
	int n;
	printf("\n\tEnter the node before which you want to insert the new node : ");
	scanf("%d", &n);
	loc = SearchElement(n);
	if(loc == NULL)
	{
		printf("\n\n\t\t%d not found. Cannot insert the new node.", n);
		getch();
		return;
	}
	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter new node : " );
	scanf("%d", &ptr->info);
	if(loc->prev == NULL)  // IF 'n' NODE IS FIRST NODE
	{
		ptr->prev = NULL;
		loc->prev = ptr;
		ptr->next = head;
		head = ptr;
	}
	else
	{
		ptr->prev = loc->prev;
		ptr->next = loc;
		(loc->prev)->next = ptr;
		loc->prev = ptr;
	}
	printf("\n\n\t\tNode inserted before the node %d.", n);
	getch();
	return;
}

/*
	ALGORITHM:
	START
		PRINT "ENTER THE VALUE AFTER WHICH YOU WANT TO INSERT THE NEW NODE"
		READ VALUE INTO VARAIBLE "N"
		SEARCH N IN THE LIST AND RETURN THE ADDRESS OF THE FOUND NODE TO POINTER "LOC"
		IF LOC = NULL THEN
			PRINT "NODE NOT FOUND"
			RETURN
		ENDIF

		CREATE A NEW NODE AND ASSIGN ITS ADDRESS TO POINTER "PTR"
		READ NEW VALUE INTO PTR->INFO

		IF LOC->PREV = NULL THEN
			SET PTR->PREV = NULL
			SET LOC->PREV = PTR
			SET PTR->NEXT = TAIL
			SET HEAD = PTR
		ELSE
			SET PTR->NEXT = LOC
			SET PTR->PREV = LOC->PREV
			(LOC->PREV)->NEXT = PTR
			SET LOC->PREV = PTR
		ENDIF
	STOP
*/

void DeleteNode(void)
{
	node *ptr, *loc;
	int n;

	printf("\n\tEnter the node you want to delete : ");
	scanf("%d", &n);
	ptr = SearchElement(n);
	if(ptr == NULL)
	{
		printf("\n\n\t\t%d not found. Cannot delete the new node.");
		getch();
		return;
	}
	else
	{
		if(head == ptr && tail == ptr)  // DELETING THE ONLY NODE
		{
			head = NULL;
			tail = NULL;
		}
		else if(head == ptr)  // DELETING THE FIRST NODE
		{
			head = head->next;
			head->prev = NULL;
		}
		else if(tail == ptr)  // DELETING THE LAST NODE
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		else  // DELETING A NODE SOMEWHERE IN THE MIDDLE
		{
			(ptr->next)->prev = ptr->prev;
			(ptr->prev)->next = ptr->next;
		}
		free(ptr);
		printf("\n\n\t\tNode is deleted.");
		getch();
	}
}

/*
	ALGORITHM:
	START
		PRINT "ENTER THE NODE YOU WANT TO DELETE"
		READ VALUE INTO VARAIBLE "N"
		SEARCH N IN THE LIST AND RETURN THE ADDRESS OF THE FOUND NODE TO POINTER "PTR"
		IF PTR = NULL THEN
			PRINT "NODE NOT FOUND"
			RETURN
		ELSE
			IF HEAD = PTR AND TAIL = PTR THEN
				HEAD = NULL
				TAIL = NULL
			ELSE IF HEAD = PTR THEN
				HEAD = HEAD->NEXT
				HEAD->PREV = NULL
			ELSE IF TAIL = PTR
				TAIL = TAIL->PREV
				TAIL->NEXT = NULL
			ELSE
				(PTR->NEXT)->PREV = PTR->PREV
				(PTR->PREV)->NEXT = PTR->NEXT
			ENDIF

			DELETE THE NODE POINTED TO BY PTR
		ENDIF
	STOP
*/

void main(void)
{
	int ch, n;
	node *ptr;

	while(1)
	{
		clrscr();
		printf("\n\n\n\n\t\t\tDOUBLY LINKED LIST MENU");  //  DISPLAYING THE MENU
		printf("\n\t\t\t_______________________");
		printf("\n\t\t 1. Insert at end.");
		printf("\n\t\t 2. Insert at beginning.");
		printf("\n\t\t 3. Insert after a given element.");
		printf("\n\t\t 4. Insert before a given element.");
		printf("\n\t\t 5. Display in forward order.");
		printf("\n\t\t 6. Display in reverse order.");
		printf("\n\t\t 7. Searching for an element.");
		printf("\n\t\t 8. Deleting an element.");
		printf("\n\t\t 9. Exit.");
		printf("\n\n\n\t\t\tEnter your choice : ");
		scanf("%d", &ch);
		fflush(stdin);

		switch(ch)
		{
			case(1) : InsertAtEnd();
					break;

			case(2) : InsertAtBeginning();
					break;

			case(3) : InsertAfterElement();
					break;

			case(4) : InsertBeforeElement();
					break;

			case(5) : TraverseInOrder();
					break;

			case(6) : TraverseInReverseOrder();
					break;

			case(7) : printf("\n\n\n\t\tEnter the element you want to search : ");
				  scanf("%d", &n);
				  fflush(stdin);
				  ptr = SearchElement(n);
				  if(ptr != NULL)
					printf("\n\n\n\n\t\tElement exists in the list.");
				  else
					printf("\n\n\n\n\t\tThis element does not exist in the list.");
				  getch();
					break;

			case(8) : DeleteNode();
					break;

			case(9): printf("\n\n\n\n\t\tExiting Program.\n\n\n\t\t\t");
				  getch();
				  exit(0);

			default : printf("\n\n\n\n\t\tInvalid input.");
				  getch();
		}
		getch();
	}
}



