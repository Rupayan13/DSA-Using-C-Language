/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define SIZE 5

typedef struct node_type
{
	int info;
	int prn;  // PRIORITY NUMBER, ASSUMING HIGHER NUMBER MEANS HIGHER PRIORITY
}Q;

Q Queue[SIZE];

int front = -1;
int rear = -1;

int IsEmpty()
{
	if(front == -1)
		return 1;
	else
		return 0;
}

int IsFull()
{
	if(rear == SIZE-1)
		return 1;
	else
		return 0;
}

void Enqueue()
{
	int i, j;
	Q temp;

	if(IsFull())
	{
		printf("\n\tPriority Queue is full.");
		getch();
		return;
	}
	if(IsEmpty())
	{
		front = 0;
		rear = 0;
	}
	else
		rear++;
	printf("\n\tEnter info : ");
	scanf("%d", &Queue[rear].info);
	fflush(stdin);

	printf("\n\tEnter priority : ");
	scanf("%d", &Queue[rear].prn);
	fflush(stdin);

	printf("\n\t\tNode entered.");

	for(i = front ; i < rear ; i++)
	{
		for(j = i+1 ; j <= rear ; j++)
		{
			if(Queue[i].prn < Queue[j].prn)
			{
				temp = Queue[i];
				Queue[i] = Queue[j];
				Queue[j] = temp;
			}
		}
	}
}

void Dequeue()
{
	int i;
	if(IsEmpty())
	{
		printf("\n\tPriority Queue is empty.");
		getch();
		return;
	}
	printf("\n\tThe node is deleted : ");
	printf("\n\t\tINFO      : %d", Queue[front].info);
	printf("\n\t\tPRIORITY  : %d", Queue[front].prn);

	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		for(i = front ; i < rear ; i++)
			Queue[i] = Queue[i+1];
		rear--;
	}
}

void Display()
{
	int i;
	if(IsEmpty())
	{
		printf("\n\tPriority Queue is empty.");
		getch();
		return;
	}
	printf("\n\n\t");
	for(i = front ; i <= rear ; i++)
		printf("\n\t\tValue : %d\tPriority : %d", Queue[i].info, Queue[i].prn);
	getch();
}

void main(void)
{
	int ch,value;

	while(1)
	{
		clrscr();
		printf("\n\n\n\n\t\t\tPRIORITY QUEUE MENU");  //  DISPLAYING THE MENU
		printf("\n\t\t\t___________________");
		printf("\n\n\n\t\t 1. Enqueue.");
		printf("\n\n\n\t\t 2. Dequeue.");
		printf("\n\n\n\t\t 3. Display in FIFO.");
		printf("\n\n\n\t\t 4. Exit.");
		printf("\n\n\n\t\t\tEnter your choice : ");
		scanf("%d",&ch);
		fflush(stdin);

		switch(ch)
		{
			case 1  : Enqueue(value);
					break;

			case 2  : Dequeue();
					break;

			case 3  : Display();
					break;

			case 4  : printf("\n\n\n\n\t\tExiting Program.\n\n\n\t\t\t");
				  getch();
				  exit(0);

			default : printf("\n\n\n\n\t\tInvalid input.");
				  getch();
		}
		getch();
	}

}



