/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>
#define MAX 5

int front = -1;  // FRONT AND REAR POINTERS
int rear = -1;

int queue[MAX];  // ARRAY QUEUE

int IsEmpty(void)  // TESTING FOR QUEUE UNDERFLOW
{
	if(front == -1)
		return 1;
	else
		return 0;
}

int IsFull(void)  // TESTING FOR QUEUE OVERFLOW
{
	if(front == 0 && rear == MAX-1)
		return 1;
	else
		return 0;
}

void Enqueue(void)  // PUSHING A NEW ELEMENT IN THE QUEUE
{
	if(IsFull())
	{
		printf("\n\n\t\tQueue is full. Cannot push the new element.");
		getch();
		return;
	}
	else if(IsEmpty())  // IF THE QUEUE IS INITIALLY EMPTY THEN BOTH FRONT AND REAR POINTERS POINT TO THE SAME ELEMENT
	{
		front = 0;
		rear = 0;
	}
	else
		rear++;
	printf("\n\n\n\t\tEnter number : ");
	scanf("%d", &queue[rear]);
	fflush(stdin);

	printf("\n\n\t\tElement %d is enqueued in the queue.", queue[rear]);
	getch();
}

/*
	ALGORITHM:
	START
		IF QUEUE IS FULL THEN
			PRINT "QUEUE IS FULL."
		ELSE IF QUEUE IS EMPTY THEN
			FRONT = 0
			REAR = 0
		ELSE
			INCREMENT REAR
		ENDIF
		READ NEW VALUE INTO QUEUE[REAR]
	STOP
*/

void Dequeue(void)  // DELETING THE FRONT ELEMENT
{
	int i;
	if(IsEmpty())
	{
		printf("\n\n\t\tQueue is empty. Nothing to dequeue.");
		getch();
		return;
	}
	printf("\n\n\t\tFront element %d is deleted.", queue[front]);
	getch();
	if(front == rear)  // IF THE QUEUE HAS ONLY ONE ELEMENT THEN BOTH FRONT AND REAR POINTERS ARE MADE NULL
	{
		front = -1;
		rear = -1;
	}
	else  // OTHERWISE ENTIRE QUEUE IS SHIFTED TOWARDS FRONT ONE PLACE ERASING THE FRONT ELEMENT
	{
		for(i = front ; i < rear ; i++)
			queue[i] = queue[i+1];
		rear--;
	}
}

/*
	ALGORITHM:
	START
		DECALRE VARAIBLE I
		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE IF FRONT = REAR THEN
			FRONT = -1
			REAR = -1
		ELSE
			FOR I = FRONT TO REAR-1 STEP 1
				SET QUEUE[I] = QUEUE[I+1]
			ENDFOR
			DECREMENT REAR
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
		printf("\n\n\t\tFront element is : %d", queue[front]);
		getch();
	}
}

/*
	ALGORITHM:
	START
		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE
			PRINT QUEUE[FRONT]
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
		printf("\n\n\t\tRear element is : %d", queue[rear]);
		getch();
	}
}

/*
	ALGORITHM:
	START
		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE
			PRINT QUEUE[REAR]
		ENDIF
	STOP
*/

void Display(void)  // DISPLAY ENTIRE QUEUE
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
		printf("\n\t\t");
		for(i = front ; i <= rear ; i++)
			printf("%d\t", queue[i]);
		getch();
	}
}

/*
	ALGORITHM:
	START
		DECALRE VARAIBLE I
		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE
			FOR I = FRONT TO REAR STEP 1
				PRINT QUEUE[I]
			ENDFOR
			DECREMENT REAR
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
		for(i = front ; i <= rear ; i++)
		{
			if(queue[i] == value)
			{
				printf("\n\n\t\tElement %d exists in the queue.", value);
				getch();
				return;
			}
		}
		printf("\n\n\t\tElement %d does not exist in the queue.", value);
		getch();
	}
}

/*
	ALGORITHM:
	START
		DECALRE VARAIBLE I
		PRINT "ENTER THE VALUE YOU WANT TO SEARCH "
		READ NEW VALUE INTO VARAIBLE "VALUE"

		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE
			FOR I = FRONT TO REAR STEP 1
				IF QUEUE[I] = VALUE THEN
					PRINT "VALUE IS FOUND."
					RETURN
				ENDIF
			ENDFOR
			PRINT "VALUE IS NOT FOUND."
		ENDIF
	STOP
*/

void main(void)
{
	int ch,value;

	while(1)
	{
		clrscr();
		printf("\n\n\n\t\t\tARRAY QUEUE MENU");  //  DISPLAYING THE MENU
		printf("\n\t\t\t________________");
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

			case(6) : printf("\n\n\t\tEnter the element you want to search : ");
				  scanf("%d",&value);
				  fflush(stdin);
				  Search(value);
					break;

			case(7) : printf("\n\n\t\tExiting Program.");
				  getch();
				  exit(0);

			default : printf("\n\n\t\tInvalid input.");
				  getch();
		}
	}
}
