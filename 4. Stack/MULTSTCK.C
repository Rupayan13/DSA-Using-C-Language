/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#define SIZE 6

int stack[SIZE];
int top1 = -1;
int top2 = SIZE;

int IsEmpty1(void)
{
	if(top1 == -1)
		return 1;
	else
		return 0;
}

int IsEmpty2(void)
{
	if(top2 == SIZE)
		return 1;
	else
		return 0;
}

int IsFull(void)
{
	if(top2 == top1+1)
		return 1;
	else
		return 0;
}

void Push1(void)
{
	if(IsFull())
	{
		printf("\n\n\tStack is Full. Cannot push.");
		getch();
		return;
	}
	top1++;
	printf("\n\n\tEnter the number : ");
	scanf("%d", &stack[top1]);
	fflush(stdin);
	printf("\n\t\tValue is pushed into Stack 1.");
}

void Push2(void)
{
	if(IsFull())
	{
		printf("\n\n\tStack is Full. Cannot push.");
		getch();
		return;
	}
	top2--;
	printf("\n\n\tEnter the number : ");
	scanf("%d", &stack[top2]);
	fflush(stdin);
	printf("\n\t\tValue is pushed into Stack 2.");
}

void Pop1(void)
{
	if(IsEmpty1())
	{
		printf("\n\n\tStack 1 is empty. Cannot pop.");
		getch();
		return;
	}
	top1--;
	printf("\n\t\tValue is popped from Stack 1.");
}

void Pop2(void)
{
	if(IsEmpty2())
	{
		printf("\n\n\tStack 2 is empty. Cannot pop.");
		getch();
		return;
	}
	top2++;
	printf("\n\t\tValue is popped from Stack 2.");
}

void Display1(void)
{
	int i;
	if(IsEmpty1())
	{
		printf("\n\n\tStack 1 is empty. Cannot display.");
		getch();
		return;
	}
	for(i = top1 ; i >= 0 ; i--)
		printf("\n\t\t%d", stack[i]);
}

void Display2(void)
{
	int i;
	if(IsEmpty2())
	{
		printf("\n\n\tStack 2 is empty. Cannot display.");
		getch();
		return;
	}
	for(i = top2 ; i < SIZE ; i++)
		printf("\n\t\t%d", stack[i]);
}

void main(void)
{
	int ch;

	while(1)
	{
		clrscr();
		printf("\n\n\n\t\tMULTIPLE STACK MENU");
		printf("\n\t\t-------------------");
		printf("\n\n\t 1. Push into STACK 1.");
		printf("\n\t 2. Push into STACK 2.");
		printf("\n\t 3. Pop from STACK 1.");
		printf("\n\t 4. Pop from STACK 2.");
		printf("\n\t 5. Display STACK 1.");
		printf("\n\t 6. Display STACK 2.");
		printf("\n\t 7. Exit.");
		printf("\n\t\tEnter your choice : ");
		scanf("%d", &ch);
		fflush(stdin);

		switch(ch)
		{
			case (1) : Push1();
					break;
			case (2) : Push2();
					break;
			case (3) : Pop1();
					break;
			case (4) : Pop2();
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