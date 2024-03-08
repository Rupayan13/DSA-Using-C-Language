/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<iostream.h>
#include<conio.h>
#include<process.h>

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
		void Insert(int);
		void Display1();
		void Display2();
		void Display3();
		void MergeList();
};

List *head1 = NULL;
List *head2 = NULL;
List *head3 = NULL;

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

void List :: Insert(int n)
{
	List *ptr = new List();
	List *temp;

	ptr->info = n;

	if(head3 == NULL)
		head3 = ptr;
	else
	{
		for(temp = head3 ; temp->next != NULL ; temp = temp->next);
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

void List :: Display3()
{
	List *ptr;

	if(head3 == NULL)
	{
		cout<<"\n\tThe list is empty. Nothing to display.";
		getch();
		return;
	}
	for(ptr = head3 ; ptr != NULL ; ptr = ptr->next)
		cout<<"\t"<<ptr->info;
}

void List :: MergeList()
{
	List *ptr1 = head1, *ptr2 = head2;
	List obj;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1->info < ptr2->info)
		{
			obj.Insert(ptr1->info);
			ptr1 = ptr1->next;
		}
		else
		{
			obj.Insert(ptr2->info);
			ptr2 = ptr2->next;
		}
	}
	if(ptr1 != NULL)
	{
		while(ptr1 != NULL)
		{
			obj.Insert(ptr1->info);
			ptr1 = ptr1->next;
		}
	}
	else if(ptr2 != NULL)
	{
		while(ptr2 != NULL)
		{
			obj.Insert(ptr2->info);
			ptr2 = ptr2->next;
		}
	}
}

/*
	ALGORITHM:
	START
		SET PTR1 TO HEAD OF THE FIRST LIST
		SET PTR2 TO HEAD OF THE SECOND LIST
		
		WHILE PTR1 IS NOT NULL AND PTR2 IS NOT NULL
		DO
			IF PTR1->INFO < PTR2->INFO THEN
				CREATE NEW NODE WITH PTR1->INFO
				INSERT THE NEW NODE INTO THE RESULTANT LIST
				INCREMENT PTR1
			ELSE IF PTR1->INFO > PTR2->INFO THEN
				CREATE NEW NODE WITH PTR2->INFO
				INSERT THE NEW NODE INTO THE RESULTANT LIST
				INCREMENT PTR2
			ELSE
				CREATE NEW NODE WITH PTR1->INFO
				INSERT THE NEW NODE INTO THE RESULTANT LIST
				INCREMENT PTR1 AND PTR2
			ENDIF 
		DONE
		
		IF PTR1 IS NOT NULL THEN
			WHILE PTR1 IS NOT NULL
			DO
					CREATE NEW NODE WITH PTR1->INFO
					INSERT THE NEW NODE INTO THE RESULTANT LIST
					INCREMENT PTR1
			DONE
		ELSE IF PTR2 IS NOT NULL THEN
			WHILE PTR2 IS NOT NULL
			DO
					CREATE NEW NODE WITH PTR2->INFO
					INSERT THE NEW NODE INTO THE RESULTANT LIST
					INCREMENT PTR2
			DONE
		ENDIF
	STOP
*/

void main(void)
{
	List obj1, obj2, obj3;
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

	obj1.MergeList();

	cout<<"\n\tThe merged list is :\n\n\t";
	obj3.Display1();

	getch();
}