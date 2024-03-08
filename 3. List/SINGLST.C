/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

typedef struct list  // DECLARING NEW DATATYPE FOR THE SINGLY LINKED LIST
{
	int info;
	struct list *next;
}node;

node * head = NULL;

void FindLargestAndSmallestNode(void)
{
	node *ptr;
	int largest = head->info;
	int smallest = head->info;

	for(ptr = head->next ; ptr != (node *)NULL ; ptr = ptr->next)
	{
		if(ptr->info > largest)
			largest = ptr->info;
		if(ptr->info < smallest)
			smallest = ptr->info;
	}
	printf("\n\tLargest node : %d", largest);
	printf("\n\tSmallest node : %d", smallest);
}

/*
	ALGORITHM:
	START
		POSITION THE POITER "PTR" AT THE HEAD NODE
		INITIALIZE THE LARIABLES "LARGEST" AND "SAMLLEST" TO HEAD->INFO

		WHILE PTR IS NOT NULL
		DO
			IF LARGEST < PTR->INFO THEN
				LARGEST = PTR->INFO
			ELSE IF PTR->INFO < SMALLEST THEN
				SMALLEST = PTR->INFO
			ENDIF
			INCREMENT PTR
		DONE
		PRITN THE VALUES OF THE LERGEST AND SMALLEST VARIABLES
	STOP
*/

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
	getch();
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
			INCREMENT PTR
		DONE
	STOP
*/

void TraverseInReverseOrder(node *ptr)  // BACKWARD TRAVERSAL
{
	if(ptr->next != NULL)
		TraverseInReverseOrder(ptr->next);
	printf("\t%d", ptr->info);
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRESS OF THE NODE IN "PTR" POINTER

		IF PTR->NEXT IS NOT NULL THEN
			RECURSIVELY CALL THE ALGORITHM USING PTR->NEXT AS THE ARGUMENT
		ENDIF

		PRINT PTR->INFO
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
	ptr->next = head;
	head = ptr;
	printf("\n\n\t\tNode inserted at beginning of list.");
	getch();
}

/*
	ALGORITHM:
	START
		CREATE A NEW NODE AND ASSIGN ITS ADDRESS TO POINTER "PTR"
		READ NEW VALUE INTO PTR->INFO
		SET PTR->NEXT = HEAD
		SET HEAD = PTR
	STOP
*/

void InsertAtEnd(void)  // INSERTING A NEW NODE AFTER THE LAST NODE
{
	node *ptr, *loc;
	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter new node : ");
	scanf("%d", &ptr->info);
	ptr->next = NULL;
	if(head == NULL)
		head = ptr;
	else
	{
		for(loc = head ; loc->next != NULL ; loc = loc->next);  // THIS FOR LOOP TAKES THE POINTER 'ptr' AT THE LAST NODE
		loc->next = ptr;
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
			SET HEAD = PTR
		ELSE
			POSITION THE "LOC" POINTER AT THE HEAD NODE
			WHILE LOC->NEXT IS NOT NULL
			DO
				INCREMENT PTR
			DONE
			SET LOC->NEXT = PTR
		ENDIF
	STOP
*/

void InsertAfterElement(void)  // INSERTING A NEW NODE BEHIND A PARTICULAR NODE
{															   // NODE AFTER SEARCHING IT
	node *ptr, *loc;
	int n;
	printf("\n\tEnter the node after which you want to insert the new node : ");
	scanf("%d", &n);
	loc = SearchElement(n);
	if(loc == NULL)
	{
		printf("\n\n\t\t%d not found. Cannot insert the new node.",n);
		getch();
		return;
	}
	else
	{
		ptr = (node *)malloc(sizeof(node));
		printf("\n\tEnter the new node : ");
		scanf("%d", &ptr->info);
		ptr->next = loc->next;
		loc->next = ptr;
		printf("\n\n\t\tNode inserted after the node %d.",n);
		getch();
		return;
	}
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
		ELSE
			CREATE A NEW NODE AND ASSIGN ITS ADDRESS TO PTR
			READ THE NEW VALUE INTO PTR->INFO
			SET PTR->NEXT = LOC->NEXT
			SET LOC->NEXT = PTR
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
		if(head == ptr)  // THIS MEANS WE HAVE TO DELETE THE FIRST OR THE ONLY NODE
			head = head->next;
		else  // THIS MEANS WE HEVE TO DELETE THE MIDDLE OR THE LAST NODE
		{
			for(loc = head ; loc->next != ptr ; loc = loc->next);  // THIS FOR LOOP TAKES THE POINTER 'ptr' AT THE LAST NODE
			loc->next = ptr->next;
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
			IF HEAD = PTR THEN
				HEAD = HEAD->NEXT
			ELSE
				POSITION "LOC" POINTER AT HEAD
				WHILE LOC->NEXT IS NOT NULL
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
	int ch, n;
	node *ptr;

	while(1)
	{
		clrscr();
		printf("\n\n\n\t\t\tSINGLY LINKED LIST MENU");  //  DISPLAYING THE MENU
		printf("\n\t\t\t_______________________");
		printf("\n\n\t\t 1. Insert at end.");
		printf("\n\t\t 2. Insert at beginning.");
		printf("\n\t\t 3. Insert after a given element.");
		printf("\n\t\t 4. Display in forward order.");
		printf("\n\t\t 5. Display in reverse order.");
		printf("\n\t\t 6. Searching for an element.");
		printf("\n\t\t 7. Deleting an element.");
		printf("\n\t\t 8. Exit.");
		printf("\n\n\n\t\t\tEnter your choice : ");
		scanf("%d",&ch);
		fflush(stdin);

		switch(ch)
		{
			case(1) : InsertAtEnd();
					break;

			case(2) : InsertAtBeginning();
					break;

			case(3) : InsertAfterElement();
					break;

			case(4) : TraverseInOrder();
					break;

			case(5) : printf("\n\n\n\n");
				  TraverseInReverseOrder(head);
				  getch();
					break;

			case(6) : printf("\n\n\n\t\tEnter the element you want to search : ");
				  scanf("%d", &n);
				  fflush(stdin);
				  ptr = SearchElement(n);
				  if(ptr != NULL)
					printf("\n\n\n\n\t\tElement exists in the list.");
				  else
					printf("\n\n\n\n\t\tThis element does not exist in the list.");
				  getch();
					break;

			case(7) : DeleteNode();
					break;

			case(8) : printf("\n\n\n\n\t\tExiting Program.\n\n\n\t\t\t");
				  getch();
				  exit(0);

			default : printf("\n\n\n\n\t\tInvalid input.");
				  getch();
		}

	}
}