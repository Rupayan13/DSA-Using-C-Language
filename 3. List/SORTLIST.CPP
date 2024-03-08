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
	TAKING INPUT INTO THE LIST AND THEN SORT THE CONTENT OF THE NODES IN ASCENDING ORDER
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
		void InsertNode();
		void Display();
		void SortList();
};

List *head = NULL;

void List :: InsertNode()
{
	List *ptr = new List();
	List *temp;

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

void List :: Display()
{
	List *ptr;

	if(head == NULL)
	{
		cout<<"\n\tThe list is empty. Nothing to display.";
		getch();
		return;
	}
	for(ptr = head ; ptr != NULL ; ptr = ptr->next)
		cout<<"\t"<<ptr->info;
}

void List :: SortList()
{
	int temp;
	List *i, *j;

	for(i = head ; i->next != NULL ; i = i->next)
	{
		for(j = i->next ; j != NULL ; j = j->next)
		{
			if(i->info > j->info)
			{
				temp = i->info;
				i->info = j->info;
				j->info = temp;
			}
		}
	}
}

/*
	ALGORITHM:
	START
		DECLARE POINTERS "I" AND "J"
		DECLARE VARAIBLE "TEMP" OF INTEGER TYPE

		SET I TO HEAD OF THE LIST
		WHILE I IS NOT NULL
		DO
			SET J = I->NEXT
			WHILE J IS NOT NULL
			DO
				IF I->INFO > J->INFO THEN
					TEMP = I->INFO
					I->INFO = J->INFO
					J->INFO = TEMP
				ENDIF
				INCREMENT J
			DONE
			INCREMENT I
		DONE
	STOP
*/

void main(void)
{
	List obj;
	clrscr();
	char ans = 'Y';

	cout<<"\n\tEnter number in jumbled order :";
	while(ans == 'Y' || ans == 'y')
	{
		obj.InsertNode();
		cout<<"\n\tDo you want to insert another node? (Y/N) : ";
		cin>>ans;
	}

	cout<<"\n\tYou have entered :\n\n\t";
	obj.Display();

	obj.SortList();

	cout<<"\n\tThe sorted list is :\n\n\t";
	obj.Display();

	getch();
}