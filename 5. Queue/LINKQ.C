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
	int info;
	struct node_type *next;
}queue;

queue *front = NULL;
queue *rear = NULL;

int IsEmpty(void)
{
	if(front == NULL && rear == NULL)
		return 1;
	else
		return 0;
}

// IN LINKED IMPLEMENTATION OF QUEUE, THERE IS NO OVERFLOW, SO IsFull() IS NOT IMPLEMENTED

void Enqueue(void)  // TO INSERT A NEW NODE AT THE REAR
{
	queue *ptr;
	ptr = (queue *)malloc(sizeof(queue));
	printf("\n\n\t\tEnter number : ");
	scanf("%d", &ptr->info);
	ptr->next = NULL;
	if(IsEmpty())  // IF THE QUEUE IS INITIALLY EMPTY
	{
		front = ptr;
		rear = ptr;
	}
	else  // ELSE INSERT THE NEW NODE AT THE REAR
	{
		rear->next = ptr;
		rear = ptr;
	}
	printf("\n\n\t\tElement %d is enqueued in the queue.", ptr->info);
	getch();
}

/*
	ALGORITHM:
	START
		CREATE A NEW NODE AND STORE THE ADDRESS INTO POINTER "PTR"
		READ NEW VALUE INTO PTR->INFO
		SET PTR->NEXT = NULL
		IF THE QUEUE IS EMPTY THEN
			SET FRONT = PTR
			SET REAR = PTR
		ELSE
			SET REAR->NEXT = PTR
			SET REAR = PTR
		ENDIF
	STOP
*/

void Dequeue(void)  // DELETING THE FRONT ELEMENT
{
	queue *ptr;
	ptr = front;
	if(IsEmpty())
	{
		printf("\n\n\t\tQueue is empty. Nothing to Peek.");
		getch();
		return;
	}
	else if(front == rear)  // IF ONLY ONE NODE IN QUEUE
	{
		front = NULL;
		rear = NULL;
	}
	else
		front = front->next;
	printf("\n\n\t\tElement %d is deleted.", ptr->info);
	getch();
	free(ptr);
}

/*
	ALGORITHM:
	START
		DECALRE POINTER "PTR"
		SET PTR = FRONT
		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE IF FRONT = REAR THEN
			SET FRONT = NULL
			SET REAR = NULL
		ELSE
			FRONT = FRONT->NEXT
		ENDIF
	STOP
*/

void PeekFront(void)  // VIEWING THE FRONT ELEMENT WITHOUT DELETING IT
{
	if(IsEmpty())
		printf("\n\n\t\tQueue is empty. Nothing to Peek.");
	else
		printf("\n\n\t\tThe front element is : %d", front->info);
	getch();
	return;
}

/*
	ALGORITHM:
	START
		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE
			PRINT FRONT->INFO
		ENDIF
	STOP
*/

void PeekRear(void)  // VIEWING THE REAR ELEMENT WITHOUT DELETING IT
{
	if(IsEmpty())
		printf("\n\n\t\tQueue is empty. Nothing to Peek.");
	else
		printf("\n\n\t\tThe rear element is : %d", rear->info);
	getch();
	return;
}

/*
	ALGORITHM:
	START
		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE
			PRINT REAR->INFO
		ENDIF
	STOP
*/

void Display(void)
{
	queue *ptr;
	if(IsEmpty())
		printf("\n\n\t\tThe Queue is empty. Nothing to display.");
	else
	{
		printf("\n\n");
		for(ptr = front ; ptr != NULL ; ptr = ptr->next)
			printf("\t%d", ptr->info);
	}
	getch();
}

/*
	ALGORITHM:
	START
		DECALRE POINTER "PTR"
		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE
			SET PTR = FRONT
			WHILE PTR IS NOT NULL
			DO
				PRINT PTR->INFO
				INCREMENT PTR
			ENDFOR
		ENDIF
	STOP
*/

void Search(void)
{
	queue *ptr;
	int value;
	if(IsEmpty())
	{
		printf("\n\n\t\tThe Queue is empty. Nothing to search.");
		getch();
	}
	else
	{
		printf("\n\n\t\tEnter the value to search : ");
		scanf("%d", &value);
		fflush(stdin);
		for(ptr = front ; ptr != NULL ; ptr = ptr->next)
		{
			if(ptr->info == value)
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
		DECALRE POINTER "PTR"

		RPINT "ENTER THE VALUE YOU WANT TO SEARCH"
		READ NEW VALUE INTO VARIABLE "VALUE"

		IF QUEUE IS EMPTY THEN
			PRINT "QUEUE IS EMPTY."
		ELSE
			SET PTR = FRONT
			WHILE PTR IS NOT NULL
			DO
				IF PTR->INFO = VALUE THEN
					PRINT "VALUE IS FOUND"
					RETURN
				ENDIF
				INCREMENT PTR
			ENDFOR
			PRINT "VALUE IS NOT FOUND."
		ENDIF
	STOP
*/

void DeleteQueue(void)
{
	queue *ptr;
	if(IsEmpty())
	{
		printf("\n\n\t\tThe Queue is empty. Nothing to delete.");
		getch();
		return;
	}
	while(front != NULL)
	{
		ptr = front;
		front = front->next;
		free(ptr);
	}
	rear = NULL;
	printf("\n\n\t\tEntire queue is deleted.");
	getch();
}

void main(void)
{
	int ch,value;

	while(1)
	{
		clrscr();
		printf("\n\n\t\t\tARRAY QUEUE MENU");  //  DISPLAYING THE MENU
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

			case(6) : Search();
					break;

			case(7) : printf("\n\n\t\tExiting Program.");
				  getch();
				  exit(0);

			default : printf("\n\n\t\tInvalid input.");
				  getch();
		}
	}
}
