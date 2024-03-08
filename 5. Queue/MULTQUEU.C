/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define SIZE 10

int Queue[SIZE];

int front1 = -1;
int rear1 = -1;
int front2 = SIZE;
int rear2 = SIZE;

int IsEmpty1()
{
	if(front1 == -1)
		return 1;
	else
		return 0;
}

int IsEmpty2()
{
	if(front2 == SIZE)
		return 1;
	else
		return 0;
}

int IsFull()
{
	if(rear2 == rear1+1)
		return 1;
	else
		return 0;
}

void Enqueue1()
{
	if(IsFull())
	{
		printf("\n\tQueue1 is full.");
		getch();
		return;
	}
	else if(IsEmpty1())
	{
		front1 = 0;
		rear1 = 0;
	}
	else
		rear1++;
	printf("\n\tEnter the number : ");
	scanf("%d", &Queue[rear1]);
	fflush(stdin);
	printf("\n\tValue is appended into Queue1.");
}

void Enqueue2()
{
	if(IsFull())
	{
		printf("\n\tQueue2 is full.");
		getch();
		return;
	}
	else if(IsEmpty2())
	{
		front2 = SIZE-1;
		rear2 = SIZE-1;
	}
	else
		rear2--;
	printf("\n\tEnter the number : ");
	scanf("%d", &Queue[rear2]);
	fflush(stdin);
	printf("\n\tValue is appended into Queue2.");
}

void Dequeue1()
{
	int i;
	if(IsEmpty1())
	{
		printf("\n\tQueue1 is empty.");
		getch();
		return;
	}
	printf("\n\tFront element %d is deleted from Queue1.",Queue[front1]);
	getch();
	if(front1==rear1)
	{
		front1 = -1;
		rear1 = -1;
	}
	else
	{
		for(i = front1 ; i < rear1 ; i++)
			Queue[i] = Queue[i+1];
		rear1--;
	}
}

void Dequeue2()
{
	int i;
	if(IsEmpty2())
	{
		printf("\n\tQueue2 is empty.");
		getch();
		return;
	}
	printf("\n\tFront element %d is deleted from Queue2.",Queue[front2]);
	getch();
	if(front2==rear2)
	{
		front2 = SIZE;
		rear2 = SIZE;
	}
	else
	{
		for(i = front2 ; i > rear2 ; i--)
			Queue[i] = Queue[i-1];
		rear2++;
	}
}

void Display1(void)
{
	int i;
	if(IsEmpty1())
	{
		printf("\n\n\n\t\tQueue1 is empty.");
		getch();
		return;
	}
	else
	{
		printf("\n\n\t\t");
		for(i = front1 ; i <= rear1 ; i++)
			printf("%d\t",Queue[i]);
		getch();
	}
}

void Display2(void)
{
	int i;
	if(IsEmpty2())
	{
		printf("\n\n\n\t\tQueue2 is empty.");
		getch();
		return;
	}
	else
	{
		printf("\n\n\t\t");
		for(i = front2 ; i >= rear2 ; i--)
			printf("%d\t",Queue[i]);
		getch();
	}
}

void main(void)
{
	int ch;

	while(1)
	{
		clrscr();
		printf("\n\n\n\t\tMULTIPLE QUEUE MENU");
		printf("\n\t\t-------------------");
		printf("\n\n\t 1. Enqueue into QUEUE 1.");
		printf("\n\n\t 2. Enqueue into QUEUE 2.");
		printf("\n\n\t 3. Delete from QUEUE 1.");
		printf("\n\n\t 4. Delete from QUEUE  2.");
		printf("\n\n\t 5. Display QUEUE 1.");
		printf("\n\n\t 6. Display QUEUE  2.");
		printf("\n\n\t 7. Exit.");
		printf("\n\n\t\tEnter your choice : ");
		scanf("%d", &ch);
		fflush(stdin);

		switch(ch)
		{
			case (1) : Enqueue1();
					break;
			case (2) : Enqueue2();
					break;
			case (3) : Dequeue1();
					break;
			case (4) : Dequeue2();
					break;
			case (5) : Display1();
					break;
			case (6) : Display2();
					break;
			case (7) : printf("\n\t\t\tExiting...");
					getch();
					exit(0);
		}
		getch();
	}
}