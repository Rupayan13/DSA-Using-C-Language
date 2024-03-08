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
	SINGLY LINKED LIST
*/

class Node
{
	int info;
	Node *next;

	public :
		Node()
		{
			info = NULL;
			next = NULL;
		}
		void InsertAtEnd();
		void InsertAtBeginning();
		void Display();
		void DeleteNode();
};

Node *head = NULL;

void Node :: InsertAtEnd(void)
{
	Node *ptr = new Node();
	Node *temp;

	cout<<"\n\tEnter a number : ";
	cin>>ptr->info;

	if(head == NULL)
		head = ptr;
	else
	{
		for(temp = head ; temp->next != NULL ; temp = temp->next);
		temp->next = ptr;
	}
}

void Node :: InsertAtBeginning()
{
	Node *ptr = new Node();

	cout<<"\n\tEnter a number : ";
	cin>>ptr->info;

	if(head == NULL)
		head = ptr;
	else
	{
		ptr->next = head;
		head = ptr;
	}
}

void Node :: DeleteNode()
{
	Node *ptr, *temp;
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

	if(ptr == head)  // IF IT IS THE FIRST NODE
		head = head->next;
	else if(ptr->next == NULL)  // IF IT IS THE LAST NODE
	{
		for(temp = head ; temp->next != ptr ; temp = temp->next);
		temp->next = NULL;
	}
	else  // IF IT IS A NODE IN THE MIDDLE
	{
		for(temp = head ; temp->next != ptr ; temp = temp->next);
		temp->next = ptr->next;
	}
	delete ptr;
}

void Node :: Display()
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
		cout<<"\n\t 3. Display";
		cout<<"\n\t 4. Delete Node";
		cout<<"\n\t 5. Exit";
		cout<<"\n\t\tEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case (1) : obj.InsertAtEnd();
					break;
			case (2) : obj.InsertAtBeginning();
					break;
			case (3) : obj.Display();
					break;
			case (4) : obj.DeleteNode();
					break;
			case (5) : cout<<"\n\t\tExiting...";
					getch();
					exit(0);
			default  : cout<<"\n\tInvalid input.";
		}
		getch();
	}
}