/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<iostream.h>
#include<conio.h>
#include<process.h>
#define MAX 5

class Stack
{
	int top;
	int arr[MAX];

	int IsEmpty()
	{
		if(top == -1)
			return 1;
		else
			return 0;
	}
	int IsFull()
	{
		if(top == MAX-1)
			return 1;
		else
			return 0;
	}

	public :
		Stack()
		{
			top = -1;
		}

		void Push();
		void Pop();
		void Peek();
		void Display();
};

void Stack :: Push()
{
	if(IsFull())
	{
		cout<<"\n\tThe stack is full. Cannot push new item.";
		getch();
		return;
	}
	else
	{
		cout<<"\n\tEnter the number : ";
		cin>>arr[++top];
	}
}

void Stack :: Pop()
{
	if(IsEmpty())
	{
		cout<<"\n\tThe stack is empty. Cannot pop.";
		getch();
		return;
	}
	else
		top--;
}

void Stack :: Peek()
{
	if(IsEmpty())
	{
		cout<<"\n\tThe stack is empty. Cannot peek.";
		getch();
		return;
	}
	else
		cout<<"\n\tThe top item is : "<<arr[top];
}

void Stack :: Display()
{
	int i;
	if(IsEmpty())
	{
		cout<<"\n\tThe stack is empty. Cannot display.";
		getch();
		return;
	}
	else
	{
		for(i = top ; i >= 0 ; i--)
			cout<<"\n\t\t"<<arr[i];
	}
}

void main(void)
{
	Stack obj;
	int ch;

	while(1)
	{
		clrscr();
		cout<<"\n\n\n\n\t\t\tMENU";
		cout<<"\n\t\t\t____";
		cout<<"\n\t\t 1. Push.";
		cout<<"\n\t\t 2. Pop.";
		cout<<"\n\t\t 3. Peek.";
		cout<<"\n\t\t 4. Display in LIFO.";
		cout<<"\n\t\t 5. Exit.";
		cout<<"\n\t\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case(1) : obj.Push();
					break;

			case(2) : obj.Pop();
					break;

			case(3) : obj.Peek();
					break;

			case(4) : obj.Display();
					break;

			case(5) : cout<<"\n\n\n\n\t\tExiting...";
				  getch();
				  exit(0);

			default : cout<<"\n\n\n\n\t\tInvalid input.";
				  getch();
		}
		getch();
	}
}



