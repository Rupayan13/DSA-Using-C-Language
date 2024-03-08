/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

typedef struct node  // DECLARING NEW DATATYPE FOR STACK
{
	int info;
	struct node *next;
}stack;

stack *top = NULL;  // TOP POINTER

int IsEmpty(void)  // TESTING FOR STACK UNDERFLOW
{
	if(top == NULL)
		return 1;
	else
		return 0;
}

// IN LINKED IMPLEMENTATION THERE IS NO IsFull()

void Push(void)  // PUSHING A NEW ELEMENT
{
	stack *ptr;
	ptr=(stack *)malloc(sizeof(stack));
	printf("\n\t\tEnter number : ");
	scanf("%d", &ptr->info);
	ptr->next = top;
	top = ptr;
	printf("\n\n\t\tElement %d is pushed in the stack.", top->info);
	getch();
}

/*
	ALGORITHM:
	START
		CREATE A NEW NODE AND ASSIGN ITS ADDRESS TO POINTER "PTR"
		READ NEW VALUE INTO PTR->INFO
		SET PTR->NEXT = TOP
		SET TOP = PTR
	STOP
*/

void Pop(void)  // DELETING THE TOP ELEMENT
{
	stack *ptr;
	if(IsEmpty())
	{
		printf("\n\n\t\tStack is empty. Nothing to pop.");
		getch();
		return;
	}
	else
	{
		ptr = top;
		top = top->next;
		printf("\n\n\t\tTop element %d is deleted.", ptr->info);
		free(ptr);
		getch();
	}
}

/*
	ALGORITHM:
	START
		DECLARE POINTER "PTR"
		IF STACK IS EMPTY THEN
			PRINT "STACK UNDERFLOW."
			RETURN
		ELSE
			SET PTR = TOP
			SET TOP = TOP->NEXT
			DELETE THE NODE POINTED TO BY PTR
		ENDIF
	STOP
*/

void Peek(void)  // PRINTING THE TOP ELEMENT WITHOUT DELETING IT
{
	if(IsEmpty())
	{
		printf("\n\n\t\tStack is empty. Nothing to peek.");
		getch();
		return;
	}
	else
	{
		printf("\n\n\t\tTop element is : %d", top->info);
		getch();
	}
}

/*
	ALGORITHM:
	START
		IF STACK IS EMPTY THEN
			PRINT "STACK UNDERFLOW."
			RETURN
		ELSE
			PRINT TOP->INFO
		ENDIF
	STOP
*/

void Display(void)  // PRINTING THE TOP ELEMENT WITHOUT DELETING IT
{
	stack *ptr;
	if(IsEmpty())
	{
		printf("\n\t\tStack is empty. Nothing to display.");
		getch();
		return;
	}
	else
	{
		for(ptr = top ; ptr != NULL ; ptr = ptr->next)
			printf("\n\t\t\t\t%d", ptr->info);
		getch();
	}
}

/*
	ALGORITHM:
	START
		DECLARE POINTER "PTR"
		IF STACK IS EMPTY THEN
			PRINT "STACK UNDERFLOW."
			RETURN
		ELSE
			SET PTR = TOP
			WHILE PTR IS NOT NULL
			DO
				PRINT PTR->INFO
				SET PTR = PTR->NEXT
			DONE
		ENDIF
	STOP
*/

void Search(void)  // SEARCHING FOR AN ELEMENT HAVING THE ' value'
{
	stack *ptr;
	int value;
	if(IsEmpty())
	{
		printf("\n\n\t\tStack is empty. Nothing to search for.");
		getch();
		return;
	}

	printf("\n\t\tEnter the value which you want to search : ");
	scanf("%d", &value);
	for(ptr = top ; ptr != NULL ; ptr = ptr->next)
	{
		if(ptr->info == value)
		{
			printf("\n\n\t\tElement %d exists in the stack.", value);
			getch();
			return;
		}
	}
	printf("\n\n\t\tElement %d does not exist in the stack.", value);
	getch();
}

/*
	ALGORITHM:
	START
		DECLARE POINTER "PTR"

		PRINT "ENTER THE VALUE YOU WANT TO SEARCH"
		READ VALUE INTO VARAIBLE "VALUE"

		IF STACK IS EMPTY THEN
			PRINT "STACK UNDERFLOW."
			RETURN
		ELSE
			SET PTR = TOP
			WHILE PTR IS NOT NULL
			DO
				IF PTR->INFO = VALUE THEN
					PRINT "VALUE FOUND IN THE STACK."
					RETURN
				ENDIF
				SET PTR = PTR->NEXT
			DONE
			PRINT "VALUE NOT FOUND IN THE SATCK."
		ENDIF
	STOP
*/

void DeleteEntireStack(void)  // DELETING EVERY ELEMENT IN THE STACK AND PUTTING NULL VALUE AT TOP
{
	stack *ptr;
	if(IsEmpty())
	{
		printf("\n\n\n\t\tStack empty. Nothing to delete.");
		getch();
		return;
	}
	else
	{
		while(top != NULL)
		{
			ptr = top;
			top = top->next;
			free(ptr);
		}
		printf("\n\n\n\t\tEntire stack is deleted.");
		getch();
		return;
	}
}

void main(void)
{
	int ch,value;
	stack *top;

	while(1)
	{
		clrscr();
		printf("\n\n\n\n\t\t\tARRAY STACK MENU");  //  DISPLAYING THE MENU
		printf("\n\t\t\t________________");
		printf("\n\n\t\t 1. Push.");
		printf("\n\n\t\t 2. Pop.");
		printf("\n\n\t\t 3. Peek.");
		printf("\n\n\t\t 4. Display in LIFO.");
		printf("\n\n\t\t 5. Search for an element.");
		printf("\n\n\t\t 6. Exit.");
		printf("\n\n\t\t\tEnter your choice : ");
		scanf("%d",&ch);
		fflush(stdin);

		switch(ch)
		{
			case(1) : Push();
					break;

			case(2) : Pop();
					break;

			case(3) : Peek();
					break;

			case(4) : Display();
					break;

			case(5) : Search();
					break;

			case(6) : printf("\n\n\t\tExiting Program.");
				  getch();
				  exit(0);

			default : printf("\n\n\t\tInvalid input.");
				  getch();
		}
	}
}