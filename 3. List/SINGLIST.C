/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

// SINGLY LINKED LIST

typedef struct node_type
{
	int info;
	struct node_type *next;
}node;

node *head = NULL;

void InsertAtEnd(void)
{
	node *ptr, *loc;

	ptr = (node *)malloc(sizeof(node));

	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	ptr->next = NULL;

	if(head == NULL)  // THEN THE NEWLY CREATED NODE IS THE FIRST NODE
		head = ptr;
	else
	{
		for(loc = head ; loc->next != NULL ; loc = loc->next);
		// THIS FOR LOOP HAS NO BODY. IT ONLY TAKES THE loc POINTER
		// TO THE LAST NODE
		loc->next = ptr;
	}
}

/*
ptr = (node *)malloc(sizeof(node));

sizeof(node) => THE SIZEOF() OPERATOR TAKES THE NAME OF ANY DATATYPE AS ITS ARGUMENT AND
		RETURNS AN INTEGER VALUE, WHICH IS THE SIZE OF THAT DATATYPE (IN BYTES)

malloc(int)  => THE MALLOC() FUNCTION TAKES THE INTEGER VALUE RETURNED BY SIZEOF(), 
		ALLOCATES A BLOCK OF MEMORY OF THOSE MANY BYTES, AND RETURNS THE STARTING
		ADDRESS OF THE MEMORY BLOCK

(node *)void  => THE ADDRESS RETURNED BY MALLOC() IS NOT IN ANY DATATYPE (VOID TYPE), WHICH 
		MUST BE	TYPECAST INTO THE POINTER FORMAT OF THE NODE DATATYPE

ptr =        => THE TYPECAST ADDRESS IS FINALLY STORED IN THE ptr POINTER. IN OTHER WORDS
		ptr POINTER POINTS TO THE NEWLY CREATED NODE
*/

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
				INCREMENT LOC
			DONE
			SET LOC->NEXT = PTR
		ENDIF
	STOP
*/

void InsertAtBeginning(void)
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	ptr->next = head;
	head = ptr;
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

void ForwardDisplay(void)
{
	node *ptr;
	if(head == NULL)
	{
		printf("\n\tList empty.");
		return;
	}
	for(ptr = head ; ptr != NULL ; ptr = ptr->next)
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
		WHILE PTR IS NOT NULL
		DO
			PRINT PTR->INFO
			INCREMENT PTR
		DONE
	STOP
*/

void BackwardDisplay(node *ptr)
{
	if(ptr->next != NULL)
		BackwardDisplay(ptr->next);
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

node *Search(int n)
{
	/*
	THIS FUNCTION SEARCHES FOR THE NUMBER 'n' IN THE LIST AND RETURNS THE
	ADDRESS OF THE NODE WHERE THE NUMBER IS FOUND (NOTE THE RETURN TYPE
	OF THE FUNCTION). IF NOT FOUND, THE FUNCTION RETURNS NULL
	*/

	node *ptr;
	for(ptr = head ; ptr != NULL ; ptr = ptr->next)
	{
		if(ptr->info == n)
			return ptr;
	}
	return NULL;
}

void InsertAfterAGivenNode(void)
{
	node *ptr, *loc;
	int n;

	printf("\n\tEnter the number after which you want to insert the new node : ");
	scanf("%d", &n);

	loc = Search(n);

	if(loc == NULL)
	{
		printf("\n\tNot found.");
		return;
	}
	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter new number : ");
	scanf("%d", &ptr->info);

	ptr->next = loc->next;
	loc->next = ptr;
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

	printf("\n\tEnter the number you want to delete : ");
	scanf("%d", &n);

	ptr = Search(n);

	if(ptr == NULL)
	{
		printf("\n\tNot found.");
		return;
	}

	if(head == ptr)  // FIRST OR ONLY NODE
		head = head->next;
	else  // MIDDLE OR LAST NODE
	{
		for(loc = head ; loc->next != ptr ; loc = loc->next);
		// THIS LOOP HAS NO BODY. IT ONLY TAKES THE loc POINTER TO
		// THE NODE PRIOR TO THE NODE WE WANT TO DELETE
		loc->next = ptr->next;
	}
	free(ptr);
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
	int ch;

	while(1)
	{
		clrscr();

		printf("\n\tMENU.");
		printf("\n\t1. Insert At End.");
		printf("\n\t2. Insert At Beginning.");
		printf("\n\t3. Forward Display.");
		printf("\n\t4. Backward Display.");
		printf("\n\t5. Insert After A Given Node.");
		printf("\n\t6. Delete Node.");
		printf("\n\t7. Exit.");
		printf("\n\t\tEnter your choice : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1 : InsertAtEnd();
					break;
			case 2 : InsertAtBeginning();
					break;
			case 3 : ForwardDisplay();
					break;
			case 4 : BackwardDisplay(head);
					break;
			case 5 : InsertAfterAGivenNode();
					break;
			case 6 : DeleteNode();
					break;
			case 7 : exit(0);
			default: printf("\n\tInvalid choice.");
		}
		getch();
	}
}