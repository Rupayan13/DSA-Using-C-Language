/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<iostream.h>
#include<conio.h>
#include<process.h>

/*
	DOUBLY LINKED LIST
*/

class Node
{
	int info;
	Node *prev;
	Node *next;

	public :
		Node()
		{
			info = NULL;
			prev = NULL;
			next = NULL;
		}

		void InsertAtBeginning();
		void InsertAtEnd();
		void InsertBeforeAGivenNode();
		void InsertAfterAGivenNode();
		void DisplayForward();
		void DisplayBackward();
		void DeleteNode();
};

Node *head = NULL;
Node *tail = NULL;

void Node :: InsertAtBeginning()
{
	Node *ptr = new Node();

	cout<<"\n\tEnter the number : ";
	cin>>ptr->info;

	if(head == NULL)  // IF THIS IS THE FIRST NODE
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		head->prev = ptr;
		ptr->next = head;
		head = ptr;
	}
}

void Node :: InsertAtEnd()
{
	Node *ptr = new Node();

	cout<<"\n\tEnter the number : ";
	cin>>ptr->info;

	if(head == NULL)  // IF THIS IS THE LAST NODE
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail->next = ptr;
		ptr->prev = tail;
		tail = ptr;
	}
}

void Node :: InsertBeforeAGivenNode()
{
	Node *ptr = new Node();
	Node *loc;
	int n, flag = 0;

	cout<<"\n\tEnter the number : ";
	cin>>ptr->info;

	cout<<"\n\tEnter the number before which you want to insert this number : ";
	cin>>n;

	for(loc = head ; loc != NULL ; loc = loc->next)
	{
		if(loc->info == n)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		cout<<"\n\tThe number "<<n<<" does not exist in the list";
		getch();
		return;
	}
	if(loc == head)  // IN CASE WE NEED TO INSERT THE NEW NODE BEFORE THE HEAD
	{
		ptr->next = head;
		loc->prev = ptr;
		head = ptr;
	}
	else
	{
		ptr->next = loc;
		ptr->prev = loc->prev;
		(loc->prev)->next = ptr;
		loc->prev = ptr;
	}
}

void Node :: InsertAfterAGivenNode()
{
	Node *ptr = new Node();
	Node *loc;
	int n, flag = 0;

	cout<<"\n\tEnter the number : ";
	cin>>ptr->info;

	cout<<"\n\tEnter the number after which you want to insert this number : ";
	cin>>n;

	for(loc = head ; loc != NULL ; loc = loc->next)
	{
		if(loc->info == n)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		cout<<"\n\tThe number "<<n<<" does not exist in the list";
		getch();
		return;
	}
	if(loc == tail)  // IN CASE WE NEED TO INSERT THE NEW NODE AFTER THE HEAD
	{
		ptr->prev = tail;
		loc->next = ptr;
		tail = ptr;
	}
	else
	{
		ptr->prev = loc;
		ptr->next = loc->next;
		(loc->next)->prev = ptr;
		loc->next = ptr;
	}
}

void Node :: DisplayForward()
{
	Node *ptr;

	if(head == NULL)
	{
		cout<<"\n\tThe list is empty. Nothing to display.";
		getch();
		return;
	}
	for(ptr = head ; ptr != NULL ; ptr = ptr->next)
		cout<<"\t"<<ptr->info;
}

void Node :: DisplayBackward()
{
	Node *ptr;

	if(tail == NULL)
	{
		cout<<"\n\tThe list is empty. Nothing to display.";
		getch();
		return;
	}
	for(ptr = tail ; ptr != NULL ; ptr = ptr->prev)
		cout<<"\t"<<ptr->info;
}

void Node :: DeleteNode()
{
	Node *ptr, *loc;
	int n, flag = 0;

	cout<<"\n\tEnter the node which you want to delete : ";
	cin>>n;

	for(ptr = head ; ptr != NULL ; ptr = ptr->next)
	{
		if(ptr->info == n)
		{
			flag = 1;
			break;
		}
	}

	if(flag == 0)
	{
		cout<<"\n\tThe number "<<n<<" does not exist in the list.";
		getch();
		return;
	}

	if(ptr == head && ptr == tail)  // IF IT IS THE ONLY NODE
	{
		head = NULL;
		tail = NULL;
	}
	else if(ptr == head)  // IF IT IS THE FIRST NODE
	{
		head = head->next;
		head->prev = NULL;
	}
	else if(ptr == tail)  // IF IT IS THE LAST NODE
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	else  // IF IT IS A NODE IN THE MIDDLE
	{
		(ptr->prev)->next = ptr->next;
		(ptr->next)->prev = ptr->prev;
	}
	delete ptr;
}



void main(void)
{
	Node obj;
	int ch;

	while(1)
	{
		clrscr();
		cout<<"\n\n\t\tMENU";
		cout<<"\n\t\t----";
		cout<<"\n\t 1. Insert At End";
		cout<<"\n\t 2. Insert At Beginning";
		cout<<"\n\t 3. Insert After A Given Node";
		cout<<"\n\t 4. Insert Before A Given Node";
		cout<<"\n\t 5. Display Forward";
		cout<<"\n\t 6. Display Backward";
		cout<<"\n\t 7. Delete Node";
		cout<<"\n\t 8. Exit";
		cout<<"\n\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case (1) : obj.InsertAtEnd();
					break;
			case (2) : obj.InsertAtBeginning();
					break;
			case (3) : obj.InsertAfterAGivenNode();
					break;
			case (4) : obj.InsertBeforeAGivenNode();
					break;
			case (5) : obj.DisplayForward();
					break;
			case (6) : obj.DisplayBackward();
					break;
			case (7) : obj.DeleteNode();
					break;
			case (8) : cout<<"\n\t\tExiting...";
					getch();
					exit(0);
			default  : cout<<"\n\tInvalid input.";
		}
		getch();
	}
}



