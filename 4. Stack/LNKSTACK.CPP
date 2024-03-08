/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<iostream.h>
#include<conio.h>
#include<process.h>

class Stack
{
	int info;
	Stack *next;

	public :
		Stack()
		{
			info = NULL;
			next = NULL;
		}
		void Push();
		void Pop();
		void Peek();
		void Display();
};

Stack *top = NULL;

void Stack :: Push()
{
	Stack *ptr = new Stack();

	cout<<"\n\tEnter number : ";
	cin>>ptr->info;

	if(top == NULL)  // IF THIS IS THE FIRST ELEMENT
		top = ptr;
	else
	{
		ptr->next = top;
		top = ptr;
	}
}

void Stack :: Pop()
{
	Stack *ptr;

	if(top == NULL)  // IF STACK IS ALREADY EMPTY
	{
		cout<<"\n\tCannot pop. Stack is empty.";
		getch();
		return;
	}
	else
	{
		ptr = top;
		top = top->next;
	}
	delete ptr;
}

void Stack :: Peek()
{
	if(top == NULL)  // IF STACK IS ALREADY EMPTY
	{
		cout<<"\n\tCannot peek. Stack is empty.";
		getch();
		return;
	}
	else
		cout<<"\n\t\tTop element : "<<top->info;
}

void Stack :: Display()
{
	Stack *ptr;

	if(top == NULL)  // IF STACK IS ALREADY EMPTY
	{
		cout<<"\n\tCannot display. Stack is empty.";
		getch();
		return;
	}
	else
	{
		for(ptr = top; ptr != NULL ; ptr = ptr->next)
			cout<<"\n\n\t\t\t"<<ptr->info;
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


