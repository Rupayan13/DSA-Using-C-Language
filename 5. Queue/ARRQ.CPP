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

class Queue
{
	int front;
	int rear;
	int queue[MAX];

	int IsEmpty(void)
	{
		if(front == -1)
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

	public :
		Queue()
		{
			front = -1;
			rear = -1;
		}

		void Enqueue(int);
		void Dequeue();
		void PeekFront();
		void PeekRear();
		void Display();
		void Search(int);
};

void Queue :: Enqueue(int value)
{
	if(IsFull())
	{
		cout<<"\n\n\t\tQueue is full. Cannot push the new element.";
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
	queue[rear] = value;
	cout<<"\n\n\t\tElement "<<queue[rear]<<" is enqueued in the queue.";
	getch();
}

void Queue :: Dequeue(void)
{
	int i;
	if(IsEmpty())
	{
		cout<<"\n\n\t\tQueue is empty. Nothing to dequeue.";
		getch();
		return;
	}
	cout<<"\n\n\t\tFront element "<<queue[front]<<" is deleted.";
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

void Queue :: PeekFront(void)
{
	if(IsEmpty())
	{
		cout<<"\n\n\t\tQueue is empty. Cannot peek front element.";
		getch();
		return;
	}
	else
	{
		cout<<"\n\n\t\tFront element is : "<<queue[front];
		getch();
	}
}

void Queue :: PeekRear(void)
{
	if(IsEmpty())
	{
		cout<<"\n\n\t\tQueue is empty. Cannot peek rear element.";
		getch();
		return;
	}
	else
	{
		cout<<"\n\n\t\tRear element is : "<<queue[rear];
		getch();
	}
}

void Queue :: Display(void)
{
	int i;
	if(IsEmpty())
	{
		cout<<"\n\n\t\tQueue is empty. Nothing to display.";
		getch();
		return;
	}
	else
	{
		cout<<"\n\t\t";
		for(i = front ; i <= rear ; i++)
			cout<<"\t"<<queue[i];
		getch();
	}
}

void Queue :: Search(int value)
{
	int i;
	if(IsEmpty())
	{
		cout<<"\n\n\t\tQueue is empty. Nothing to search for.";
		getch();
		return;
	}
	else
	{
		for(i = front ; i <= rear ; i++)
		{
			if(queue[i] == value)
			{
				cout<<"\n\n\t\tElement "<<value<<" exists in the queue.";
				getch();
				return;
			}
		}
		cout<<"\n\n\t\tElement "<<value<<" does not exist in the queue.";
		getch();
	}
}

void main(void)
{
	int ch,value;

	Queue q;

	while(1)
	{
		clrscr();
		cout<<"\n\n\n\t\t\tARRAY QUEUE MENU";
		cout<<"\n\t\t\t________________";
		cout<<"\n\n\t\t 1. Enqueue.";
		cout<<"\n\n\t\t 2. Dequeue.";
		cout<<"\n\n\t\t 3. Peek Front.";
		cout<<"\n\n\t\t 4. Peek Rear.";
		cout<<"\n\n\t\t 5. Display in FIFO.";
		cout<<"\n\n\t\t 6. Search for an element.";
		cout<<"\n\n\t\t 7. Exit.";
		cout<<"\n\n\t\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case(1) : cout<<"\n\n\n\t\tEnter number : ";
				  cin>>value;
				  q.Enqueue(value);
					break;

			case(2) : q.Dequeue();
					break;

			case(3) : q.PeekFront();
					break;

			case(4) : q.PeekRear();
					break;

			case(5) : q.Display();
					break;

			case(6) : cout<<"\n\n\t\tEnter the element you want to search : ";
				  cin>>value;
				  q.Search(value);
					break;

			case(7) : cout<<"\n\n\t\tExiting Program.";
				  getch();
				  exit(0);

			default : cout<<"\n\n\t\tInvalid input.";
				  getch();
		}
	}
}
