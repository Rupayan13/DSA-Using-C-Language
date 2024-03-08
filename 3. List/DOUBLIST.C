/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

typedef struct node_type
{
	struct node_type *prev;
	int info;
	struct node_type *next;
}node;

node *head = NULL;
node *tail = NULL;

void InsertAtEnd(void)
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	ptr->next = NULL;

	if(head == NULL)  // THEN THE NEWLY CREATED NODE IS THE FIRST AN ONLY NODE
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
			SET TAIL->NEXT = PTR
			SET TAIL = PTR
		ENDIF
	STOP
*/

void InsertAtBeginning(void)
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	printf("\n\tEnter number : ");
	scanf("%d", &ptr->info);
	ptr->prev = NULL;

	if(tail == NULL)  // THEN THE NEWLY CREATED NODE IS THE FIRST AN ONLY NODE
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
}

/*
	ALGORITHM:
	START
		CREATE A NEW NODE AND ASSIGN ITS ADDRESS TO POINTER "PTR"
		READ NEW VALUE INTO PTR->INFO
		SET PTR->PREV = NULL
		IF TAIL = NULL THEN
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

void ForwardDisplay(void)
{
	// EXACTLY SAME AS IN SINGLY LINKED LIST

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
			SET PTR = PTR->NEXT
		DONE
	STOP
*/

void BackwardDisplay(void)
{
	node *ptr;

	if(tail == NULL)
	{
		printf("\n\tList empty.");
		return;
	}

	for(ptr = tail ; ptr != NULL ; ptr = ptr->prev)
		printf("\t%d", ptr->info);
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

node *Search(int n)
{
	// EXACLY SAME AS IN SINGLY LINKED LIST

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

	ptr->prev = loc;
	ptr->next = loc->next;
	(loc->next)->prev = ptr;
	loc->next = ptr;

	if(ptr->next == NULL)
		tail = ptr;
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

		SET PTR->PREV = LOC
		SET PTR->NEXT = LOC->NEXT
		SET (LOC->NEXT)->PREV = PTR
		SET LOC->NEXT = PTR

		IF PTR->NEXT = NULL THEN
			SET TAIL = PTR
		ENDIF
	STOP
*/

void InsertBeforeAGivenNode(void)
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

	ptr->next = loc;
	ptr->prev = loc->prev;
	(loc->prev)->next = ptr;
	loc->prev = ptr;

	if(ptr->prev == NULL)
		head = ptr;
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

		SET PTR->NEXT = LOC
		SET PTR->PREV = LOC->PREV
		SET (LOC->PREV)->NEXT = PTR
		SET LOC->PREV = PTR

		IF PTR->PREV = NULL THEN
			SET HEAD = PTR
		ENDIF
	STOP
*/

void DeleteNode(void)
{
	node *ptr;
	int n;

	printf("\n\tEnter the number you want to delete : ");
	scanf("%d", &n);

	ptr = Search(n);

	if(ptr == NULL)
	{
		printf("\n\tNot found.");
		return;
	}

	if(head == ptr && tail == ptr)  // ONLY NODE
	{
		head = NULL;
		tail = NULL;
	}
	else if(head == ptr)  // FIRST NODE
	{
		head = head->next;
		head->prev = NULL;
	}
	else if(tail == ptr)  // LAST NODE
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	else  // MIDDLE NODE
	{
		(ptr->next)->prev = ptr->prev;
		(ptr->prev)->next = ptr->next;
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
			IF HEAD = PTR AND TAIL = PTR THEN
				HEAD = NULL
				TAIL = NULL
			ELSE IF HEAD = PTR THEN
				HEAD = HEAD->NEXT
				HEAD->PREV = NULL
			ELSE IF TAIL = PTR THEN
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
		printf("\n\t6. Insert Before A Given Node.");
		printf("\n\t7. Delete Node.");
		printf("\n\t8. Exit.");
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
			case 4 : BackwardDisplay();
					break;
			case 5 : InsertAfterAGivenNode();
					break;
			case 6 : InsertBeforeAGivenNode();
					break;
			case 7 : DeleteNode();
					break;
			case 8 : exit(0);
			default: printf("\n\tInvalid choice.");
		}
		getch();
	}
}








