/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

/*
IN A NORMAL QUEUE, INSERTION IS ALLOWED ONLY AT REAR AND DELETION IS ALLOWED ONLY AT THE
FRONT. IN A DOUBLY ENDED QUEUE, BOTH ENDS ARE ACTIVE, THAT IS, INSERTION AND DELETION IS 
ALLOWED AT BOTH THE ENDS. 

DOUBLEY ENDED QUEUE IS ABBREVIATED AS DEQueue, WHICH MUST NOT BE CONFUSED WITH THE dequeue()
OPERATION, THAT DELETES THE FIRST ELEMENT OF A NORMAL QUEUE.

THERE ARE TWO VARIATIONS OF THE DEQueue:
	1. INPUT RESTRICTED  :  INSERTION IS ALLOWED AT ANY ONE END (EITHER FRONT OR REAR), BUT 
			        DELETION IS ALLOWED AT BOTH THE ENDS (BOTH FRONT AND REAR)
	2. OUTPUT RESTRICTED :  INSERTION IS ALLOWED AT BOTH ENDS (BOTH FRONT AND REAR), BUT 
			        DELETION IS ALLOWED AT ANY ONE END (EITHER FRONT OR REAR)
*/

#include<stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

int IsEmpty(void)
{
	if(front == -1 && rear == -1)
		return 1;
	else
		return 0;
}

int IsFull(void)
{
	if(front == 0 && rear == MAX-1)
		return 1;
	else
		return 0;
}

void EnqueueAtFront(void)
{
	int i;
	if(IsFull())
	{
		printf("\n\tThe Queue is full. Cannot insert the new node.");
		getch();
		return;
	}
	if(IsEmpty())  // FIRST ELEMENT
	{
		front = 0;
		rear = 0;
	}
	else // TO INSERT AT FRONT ALL ELELMENTS ARE PUSHED BACKWARDS BY ONE POSITION
	{
		for(i = rear ; i >= front ; i--)
			queue[i+1] = queue[i];
		rear++;
	}	
	printf("\n\tEnter the number : ");
	scanf("%d", &queue[front]);
	fflush(stdin);
}

void EnqueueAtRear(void)
{
	if(IsFull())
	{
		printf("\n\tThe Queue is full. Cannot insert the new node.");
		getch();
		return;
	}
	if(front == -1)  // FIRST ELEMENT
	{
		front = 0;
		rear = 0;
	}
	else
		rear++;
	printf("\n\tEnter the number : ");
	scanf("%d", &queue[rear]);
	fflush(stdin);
}

void DeleteAtFront(void)
{
	int i;
	if(IsEmpty())
	{
		printf("\n\tThe Queue is empty. Cannot delete the new node.");
		getch();
		return;
	}
	if(front == rear) // ONLY ONE NODE
	{
		front = -1;
		rear = -1;
	}
	else
	{
		for(i = front ; i < rear ; i++) // COMPACTING
		{
			queue[i] = queue[i+1];
		}
		rear--;
	}
}

void DeleteAtRear(void)
{
	int i;
	if(IsEmpty())
	{
		printf("\n\tThe Queue is empty. Cannot delete the new node.");
		getch();
		return;
	}
	if(front == rear) // ONLY ONE NODE
	{
		front = -1;
		rear = -1;
	}
	else
		rear--;
}

void Display(void)
{
	int i;
	if(IsEmpty())
	{
		printf("\n\tThe Queue is empty. Cannot display the queue.");
		getch();
		return;
	}
	for(i = front ; i <= rear ; i++)
		printf("\t%d", queue[i]);
}

void main(void)
{
	int ch;
	int n;

	while(1)
	{
		clrscr();
		printf("\n\n\n\t\tMENU");
		printf("\n\t1. Enqueue at front.");
		printf("\n\t2. Enqueue at rear.");
		printf("\n\t3. Delete at front.");
		printf("\n\t4. Delete at rear.");
		printf("\n\t5. Display.");
		printf("\n\t6. Exit.");
		printf("\n\t\tEnter your choice : ");
		scanf("%d", &ch);
		fflush(stdin);

		switch(ch)
		{
			case 1 : EnqueueAtFront();
				 break;

			case 2 : EnqueueAtRear();
				 break;

			case 3 : DeleteAtFront();
				 break;

			case 4 : DeleteAtRear();
				 break;

			case 5 : Display();
				 break;

			case 6 : printf("\n\t\tExiting...");
				 getch();
				 exit(0);
			default: printf("\n\tInvalid Input.");
		}
		getch();
	}
}
