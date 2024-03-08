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
	CONCATENATE THE FIRST LIST AT THE END OF THE SECOND LIST
*/

class List
{
	int info;
	List *next;

	public :
		List()
		{
			info = NULL;
			next = NULL;
		}
		void InsertIntoList1();
		void InsertIntoList2();
		void Display1();
		void Display2();
		void ConcatList();
};

List *head1 = NULL;
List *head2 = NULL;

void List :: InsertIntoList1()
{
	List *ptr = new List();
	List *temp;

	cout<<"\n\tEnter a number : ";
	cin>>ptr->info;

	if(head1 == NULL)
		head1 = ptr;
	else
	{
		for(temp = head1 ; temp->next != NULL ; temp = temp->next);
		temp->next = ptr;
	}
}

void List :: InsertIntoList2()
{
	List *ptr = new List();
	List *temp;

	cout<<"\n\tEnter a number : ";
	cin>>ptr->info;

	if(head2 == NULL)
		head2 = ptr;
	else
	{
		for(temp = head2 ; temp->next != NULL ; temp = temp->next);
		temp->next = ptr;
	}
}

void List :: Display1()
{
	List *ptr;

	if(head1 == NULL)
	{
		cout<<"\n\tThe list is empty. Nothing to display.";
		getch();
		return;
	}
	for(ptr = head1 ; ptr != NULL ; ptr = ptr->next)
		cout<<"\t"<<ptr->info;
}

void List :: Display2()
{
	List *ptr;

	if(head2 == NULL)
	{
		cout<<"\n\tThe list is empty. Nothing to display.";
		getch();
		return;
	}
	for(ptr = head2 ; ptr != NULL ; ptr = ptr->next)
		cout<<"\t"<<ptr->info;
}

void List :: ConcatList()
{
	List *ptr;
	for(ptr = head1 ; ptr->next != NULL ; ptr = ptr->next);
	ptr->next = head2;
}

void main(void)
{
	List obj1, obj2;
	clrscr();
	char ans = 'Y';

	cout<<"\n\tEnter number into List 1 :";
	while(ans == 'Y' || ans == 'y')
	{
		obj1.InsertIntoList1();
		cout<<"\n\tDo you want to insert another node? (Y/N) : ";
		cin>>ans;
	}

	cout<<"\n\tEnter number into List 2 :";

	ans = 'Y';
	while(ans == 'Y' || ans == 'y')
	{
		obj2.InsertIntoList2();
		cout<<"\n\tDo you want to insert another node? (Y/N) : ";
		cin>>ans;
	}

	cout<<"\n\tList 1 is :\n\n\t";
	obj1.Display1();

	cout<<"\n\tList 2 is :\n\n\t";
	obj1.Display2();

	obj1.ConcatList();

	cout<<"\n\tList 1 after concatenation is :\n\n\t";
	obj1.Display1();

	getch();
}