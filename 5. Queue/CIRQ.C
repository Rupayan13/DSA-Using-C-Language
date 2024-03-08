/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define MAX 5

int front = -1;  // FRONT AND REAR POINTERS
int rear = -1;

int cqueue[MAX];  // ARRAY CIRCULAR QUEUE

int IsEmpty(void)  // TESTING FOR CIRCULAR QUEUE UNDERFLOW
{
	if(front == -1)
		return 1;
	else
		return 0;
}

int IsFull(void)  // TESTING FOR CIRCULAR QUEUE OVERFLOW
{
	if((front == 0 && rear == MAX-1) || (front == rear+1))  // IF FRONT IS JUST BEHIND REAR EVEN THEN THE CIRCULAR QUEUE IS FULL
		return 1;
	else
		return 0;
}

void Enqueue(void)  // PUSHING A NEW ELEMENT IN THE CIRCULAR QUEUE
{
	if(IsFull())
	{
		printf("\n\n\t\tQueue is full. Cannot push the new element.");
		getch();
		return;
	}
	else if(IsEmpty())  // IF THE CIRCULAR QUEUE IS INITIALLY EMPTY THEN BOTH FRONT AND REAR POINTERS POINT TO THE SAME ELEMENT
	{
		front = 0;
		rear = 0;
	}
	else if(rear == MAX-1) // IF REAR HAS REACHED THE LIMIT BUT THE CIRCULAR QUEUE IS NOT YET FULL THEN REAR IS BROUGHT TO 0
		rear = 0;
	else
		rear++;
	printf("\n\n\n\n\t\tEnter number : ");
	scanf("%d",&cqueue[rear]);
	fflush(stdin);

	printf("\n\n\t\tElement %d is enqueued in the cqueue.", cqueue[rear]);
	getch();
}

/*
	ALGORITHM:
	START
		IF CIRCULAR QUEUE IS FULL THEN
			PRINT "QUEUE IS FULL."
			RETURN
		ELSE IF CIRCULAR QUEUE IS EMPTY THEN
			FRONT = 0
			REAR = 0
		ELSE IF REAR IS ON LARGEST INDEX THEN
			REAR = 0
		ELSE
			INCREMENT REAR
		ENDIF

		READ NEW VALUE INTO CQUEUE[REAR]
	STOP
*/

void Dequeue(void)  // DELETING THE FRONT ELEMENT
{
	if(IsEmpty())
	{
		printf("\n\n\t\tQueue is empty. Nothing to dequeue.");
		getch();
		return;
	}
	printf("\n\n\t\tFront element %d is deleted.", cqueue[front]);
	getch();
	if(front == rear)  // IF THE CIRCULAR QUEUE HAS ONLY ONE ELEMENT THEN BOTH FRONT AND REAR POINTERS ARE MADE NULL
	{
		front = -1;
		rear = -1;
	}
	else if(front == MAX-1)  // IF FRONT HAS REACHED THE LIMIT BUT THE CIRCULAR QUEUE IS NOT YET EMPTY THEN FRONT IS BROUGHT TO 0
		front = 0;
	else
		front++;
}

/*
	ALGORITHM:
	START
		IF CIRCULAR QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
			RETURN
		ELSE IF FRONT = REAR THEN
			FRONT = -1
			REAR = -1
		ELSE IF FRONT IS ON LARGEST INDEX THEN
			FRONT = 0
		ELSE
			INCREMENT FRONT
		ENDIF
	STOP
*/

void PeekFront(void)  // PRINTING THE FRONT ELEMENT WITHOUT DELETING IT
{
	if(IsEmpty())
	{
		printf("\n\n\t\tQueue is empty. Cannot peek front element.");
		getch();
		return;
	}
	else
	{
		printf("\n\n\t\tFront element is : %d", cqueue[front]);
		getch();
	}
}

/*
	ALGORITHM:
	START
		IF CIRCULAR QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
			RETURN
		ELSE
			PRINT CQUEUE[FRONT]
		ENDIF
	STOP
*/

void PeekRear(void)  // PRINTING THE REAR ELEMENT WITHOUT DELETING IT
{
	if(IsEmpty())
	{
		printf("\n\n\t\tQueue is empty. Cannot peek rear element.");
		getch();
		return;
	}
	else
	{
		printf("\n\n\t\tRear element is : %d", cqueue[rear]);
		getch();
	}
}

/*
	ALGORITHM:
	START
		IF CIRCULAR QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
			RETURN
		ELSE
			PRINT CQUEUE[REAR]
		ENDIF
	STOP
*/

void Display(void)  // DISPLAY ENTIRE CIRCULAR QUEUE
{
	int i;
	if(IsEmpty())
	{
		printf("\n\n\t\tQueue is empty. Nothing to display.");
		getch();
		return;
	}
	else
	{
		printf("\n\n\t\t");
		if(front <= rear)  // IF REAR IS BEHIND FRONT OR ONLY ONE ELEMENT PRESENT
		{
			for(i = front ; i <= rear ; i++)
				printf("%d\t", cqueue[i]);
		}
		else  // IF FRONT IS BEHIND REAR
		{
			for(i = front ; i <= MAX-1 ; i++)
				printf("%d\t", cqueue[i]);
			for(i = 0 ; i <= rear ; i++)
				printf("%d\t", cqueue[i]);
		}
		getch();
	}
}

/*
	ALGORITHM:
	START
		DECLARE VARIABLE I

		IF CIRCULAR QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
			RETURN
		ELSE
			IF FRONT <= REAR THEN
				FOR I = FRONT TO REAR STEP 1
					PRINT CQUEUE[I]
				ENDFOR
			ELSE
				FOR I = FRONT TO MAX-1 STEP 1
					PRINT CQUEUE[I]
				ENDFOR
				FOR I = 0 TO REAR STEP 1
					PRINT CQUEUE[I]
				ENDFOR
			ENDIF
		ENDIF
	STOP
*/

void Search(int value)  // SEARCHING FOR AN ELEMENT HAVING THE 'value'
{
	int i;
	if(IsEmpty())
	{
		printf("\n\n\t\tQueue is empty. Nothing to search for.");
		getch();
		return;
	}
	else
	{
		if(front <= rear)  // IF REAR IS BEHIND FRONT OR ONLY ONE ELEMENT PRESENT
		{
			for(i = front ; i <= rear ; i++)
			{
				if(cqueue[i] == value)
				{
					printf("\n\n\t\tElement %d exists in the Circular queue.", cqueue[i]);
					getch();
					return;
				}
			}
		}
		else  // IF FRONT IS BEHIND REAR
		{
			for(i = front ; i <= MAX-1 ; i++)
			{
				if(cqueue[i] == value)
				{
					printf("\n\n\t\tElement %d exists in the Circular queue.", cqueue[i]);
					getch();
					return;
				}
			}
			for(i = 0 ; i <= rear ; i++)
			{
				if(cqueue[i] == value)
				{
					printf("\n\n\t\tElement %d exists in the Circular queue.", cqueue[i]);
					getch();
					return;
				}
			}
		}
		printf("\n\n\t\tElement %d does not exist in the circular queue", value);
		getch();
	}
}

/*
	ALGORITHM:
	START
		DECLARE VARIABLE I

		PRINT "ENTER THE VALUE YOU WANT TO SEARCH "
		READ NEW VALUE INTO VARAIBLE "VALUE"

		IF CIRCULAR QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
			RETURN
		ELSE
			IF FRONT <= REAR THEN
				FOR I = FRONT TO REAR STEP 1
					IF CQUEUE[I] = VALUE THEN
						PRINT "VALUE IS FOUND."
						RETURN
					ENDIF
				ENDFOR
			ELSE
				FOR I = FRONT TO MAX-1 STEP 1
					IF CQUEUE[I] = VALUE THEN
						PRINT "VALUE IS FOUND."
						RETURN
					ENDIF
				ENDFOR
				FOR I = 0 TO REAR STEP 1
					IF CQUEUE[I] = VALUE THEN
						PRINT "VALUE IS FOUND."
						RETURN
					ENDIF
				ENDFOR
			ENDIF
		ENDIF
	STOP
*/

void main(void)
{
	int ch,value;

	while(1)
	{
		clrscr();
		printf("\n\n\n\t\t\tCIRCULAR ARRAY QUEUE MENU");  //  DISPLAYING THE MENU
		printf("\n\t\t\t__________________________");
		printf("\n\n\t\t 1. Enqueue.");
		printf("\n\n\t\t 2. Dequeue.");
		printf("\n\n\t\t 3. Peek Front.");
		printf("\n\n\t\t 4. Peek Rear.");
		printf("\n\n\t\t 5. Display in FIFO.");
		printf("\n\n\t\t 6. Search for an element.");
		printf("\n\n\t\t 7. Exit.");
		printf("\n\n\t\t\tEnter your choice : ");
		scanf("%d",&ch);
		fflush(stdin);

		switch(ch)
		{
			case(1) : Enqueue();
					break;

			case(2) : Dequeue();
					break;

			case(3) : PeekFront();
					break;

			case(4) : PeekRear();
					break;

			case(5) : Display();
					break;

			case(6) : printf("\n\n\n\t\tEnter the element you want to search : ");
				  scanf("%d", &value);
				  fflush(stdin);
				  Search(value);
					break;

			case(7) : printf("\n\n\n\n\t\tExiting Program.\n\n\n\t\t\t");
				  getch();
				  exit(0);

			default : printf("\n\n\n\n\t\tInvalid input.");
				  getch();
		}
	}
}

