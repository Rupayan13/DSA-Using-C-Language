/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<conio.h>
#define MAX 5

int top = -1;  // TOP POINTER
int stack[MAX];  // ARRAY STACK

int IsEmpty(void)  // TESTING FOR STACK UNDERFLOW
{
	if(top == -1)
		return 1;
	else
		return 0;
}

int IsFull(void)  // TESTING FOR STACK OVERFLOW
{
	if(top == MAX-1)
		return 1;
	else
		return 0;
}

void Push(void)  // PUSHING A NEW ELEMENT IN THE STACK
{
	if(IsFull())
	{
		printf("\n\n\t\tStack is full. Cannot push the new element.");
		getch();
		return;
	}
	else
	{
		top++;
		printf("\n\t\tEnter number : ");
		scanf("%d", &stack[top]);
		printf("\n\n\t\tElement %d is pushed in the stack.", stack[top]);
		getch();
	}
}

/*
	ALGORITHM:
	START
		IF STACK IS FULL THEN
			PRINT "STACK OVERFLOW."
			RETURN
		ENDIF
		INCREMENT TOP
		READ NEW ELEMENT INTO STACK[TOP]
	STOP
*/

void Pop(void)  // DELETING THE TOP ELEMENT
{
	if(IsEmpty())
	{
		printf("\n\n\t\tStack is empty. Nothing to pop.");
		getch();
		return;
	}
	else
	{
		printf("\n\n\t\tTop element %d is deleted.", stack[top]);
		top--;
		getch();
	}
}
/*
	ALGORITHM:
	START
		IF STACK IS UNDERFLOW THEN
			PRINT "STACK UNDERFLOW."
			RETURN
		ENDIF
		DECREMENT TOP
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
		printf("\n\n\t\tTop element is : %d", stack[top]);
		getch();
	}
}

/*
	ALGORITHM:
	START
		IF STACK IS UNDERFLOW THEN
			PRINT "STACK UNDERFLOW."
			RETURN
		ENDIF
		PRINT STACK[TOP]
	STOP
*/

void Display(void)  // DISPLAY ENTIRE STACK IN LIFO ORDER
{
	int i;
	if(IsEmpty())
	{
		printf("\n\n\t\tStack is empty. Nothing to display.");
		getch();
		return;
	}
	else
	{
		for(i = top ; i >= 0 ; i--)
			printf("\n\t\t\t\t%d", stack[i]);
		getch();
	}
}

/*
	ALGORITHM:
	START
		DECLARE VARAIBLE I
		IF STACK IS UNDERFLOW THEN
			PRINT "STACK UNDERFLOW."
			RETURN
		ENDIF
		FOR I = TOP TO 0 STEP -1
			PRINT STACK[I]
		ENDFOR
	STOP
*/

void Search(void)  // SEARCHING FOR AN ELEMENT HAVING THE ' value'
{
	int i, value;
	if(IsEmpty())
	{
		printf("\n\n\t\tStack is empty. Nothing to search for.");
		getch();
		return;
	}
	printf("\n\t\tEnter the value you want to search : ");
	scanf("%d", &value);
	fflush(stdin);
	for(i = top ; i >= 0 ; i--)
	{
		if(stack[i] == value)
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
		DECLARE VARAIBLE I
		IF STACK IS UNDERFLOW THEN
			PRINT "STACK UNDERFLOW."
			RETURN
		ENDIF
		PRINT "ENTER THE VALUE YOU WANT TO SEARCH : "
		READ VALUE INTO THE VARIABLE "VALUE"

		FOR I = TOP TO 0 STEP -1
			IF STACK[I] = VALUE THEN
				PRINT "VALUE FOUND AT INDEX ", I
				RETURN
			ENDIF
		ENDFOR
		PRINT "THE VALUE HAS NOT BEEN FOUND."
	STOP
*/

void main(void)
{
	int ch,value;

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

