/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<iostream.h>
#include<conio.h>
#include<process.h>

class Queue
{
	int info;
	Queue *next;
	public :
		Queue()
		{
			info = NULL;
			next = NULL;
		}
		void Enqueue();
		void Dequeue();
		void PeekFront();
		void PeekRear();
		void Display();
};

Queue *front = NULL;
Queue *rear = NULL;

void Queue :: Enqueue()
{
	Queue *ptr = new Queue();

	cout<<"\n\tEnter number : ";
	cin>>ptr->info;

	if(rear == NULL)  // IF THE QUEUE IS EMPTY
	{
		front = ptr;
		rear = ptr;
	}
	else
	{
		rear->next = ptr;
		rear = ptr;
	}
}

void Queue :: Dequeue()
{
	Queue *ptr = front;

	if(front == NULL)  // IF THE QUEUE IS EMPTY
	{
		cout<<"\n\tThe queue is empty. Nothing to delete.";
		getch();
		return;
	}
	else if(front == rear)  // IF IT IS THE ONLY NODE
	{
		front = NULL;
		rear = NULL;
	}
	else
		front = front->next;

	delete ptr;
}

void Queue :: PeekFront()
{
	if(front == NULL)
	{
		cout<<"\n\tThe queue is empty. Cannot peek front element.";
		getch();
		return;
	}
	cout<<"\n\tThe front element is : "<<front->info;
}

void Queue :: PeekRear()
{
	if(rear == NULL)
	{
		cout<<"\n\tThe queue is empty. Cannot peek rear element.";
		getch();
		return;
	}
	cout<<"\n\tThe rear element is : "<<rear->info;
}

void Queue :: Display()
{
	Queue *ptr;

	if(front == NULL)  // IF THE QUEUE IS EMPTY
	{
		cout<<"\n\tThe queue is empty. Nothing to display.";
		getch();
		return;
	}
	for(ptr = front ; ptr != NULL ; ptr = ptr->next)
		cout<<"\t"<<ptr->info;
}

void main(void)
{
	int ch;
	Queue obj;

	while(1)
	{
		clrscr();
		cout<<"\n\n\n\n\t\t\tLINKED QUEUE MENU";  //  DISPLAYING THE MENU
		cout<<"\n\t\t\t_________________";
		cout<<"\n\t\t 1. Enqueue.";
		cout<<"\n\t\t 2. Dequeue.";
		cout<<"\n\t\t 3. Peek Front.";
		cout<<"\n\t\t 4. Peek Rear.";
		cout<<"\n\t\t 5. Display in FIFO.";
		cout<<"\n\t\t 6. Exit.";
		cout<<"\n\n\t\t\tEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case(1) : obj.Enqueue();
					break;

			case(2) : obj.Dequeue();
					break;

			case(3) : obj.PeekFront();
					break;

			case(4) : obj.PeekRear();
					break;

			case(5) : obj.Display();
					break;

			case(6) : cout<<"\n\t\tExiting...";
					getch();
					exit(0);

			default : cout<<"\n\n\n\n\t\tInvalid input.";
				  getch();
		}
		getch();
	}
}