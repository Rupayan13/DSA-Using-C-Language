/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<stdio.h>

class Student
{
	int roll;
	char name[10];
	public :
		void input();
		void output();
		void search();
		void delete_record();
		void modify();
};

void Student :: input()
{
	fstream file;
	file.open("Student.txt", ios::app);

	cout<<"\n\tEnter roll : ";
	cin>>roll;
	cout<<"\n\tEnter name : ";
	cin>>name;

	file.write((char*)this,sizeof(Student));
	file.close();
}

void Student :: output()
{
	fstream file;
	file.open("Student.txt", ios::in | ios::nocreate);

	if(file.fail())  // THIS FUNCTION RETURNS TRUE IF THE FILE CANNOT BE OPENED
	{
		cout<<"\n\tThe file has no data. Please input some data first.";
		getch();
		return;
	}

	while(!file.eof())
	{
		file.read((char*)this,sizeof(Student));
		cout<<"\n\t\tROLL : "<<roll;
		cout<<"\n\tNAME : "<<name;
	}

	file.close();
}

void Student :: search()
{
	fstream file;
	int r;
	char found = 'F';
	file.open("Student.txt", ios::in | ios::nocreate);

	if(file.fail())  // THIS FUNCTION RETURNS TRUE IF THE FILE CANNOT BE OPENED
	{
		cout<<"\n\tThe file has no data. Please input some data first.";
		getch();
		return;
	}

	cout<<"\n\tEnter the roll number you want to search : ";
	cin>>r;

	while(!file.eof())
	{
		file.read((char*)this,sizeof(Student));
		if(roll == r)
		{
			found = 'T';
			cout<<"\n\t\tROLL : "<<roll;
			cout<<"\n\tNAME : "<<name;
			break;
		}
	}

	if(found == 'F')
		cout<<"\n\tThe roll number is not found.";

	file.close();
}

void Student :: delete_record()
{
	fstream file, temp;
	int r;
	char found = 'F';
	file.open("Student.txt", ios::in | ios::nocreate);
	temp.open("Temp.txt", ios::out);

	if(file.fail())  // THIS FUNCTION RETURNS TRUE IF THE FILE CANNOT BE OPENED
	{
		cout<<"\n\tThe file has no data. Please input some data first.";
		getch();
		return;
	}

	cout<<"\n\tEnter the roll number you want to delete : ";
	cin>>r;

	while(!file.eof())
	{
		file.read((char*)this,sizeof(Student));
		if(roll == r)
		{
			found = 'T';
			cout<<"\n\t\tROLL : "<<roll;
			cout<<"\n\tNAME : "<<name;
			cout<<"\n\t\tThe above record is deleted.";
		}
		else
			temp.write((char*)this,sizeof(Student));
	}

	if(found == 'F')
		cout<<"\n\tThe roll number is not found.";

	file.close();
	temp.close();

	remove("Student.txt");
	rename("Temp.txt", "Student.txt");
}

void Student :: modify()
{
	fstream file, temp;
	int r;
	char found = 'F';
	file.open("Student.txt", ios::in | ios::nocreate);
	temp.open("Temp.txt", ios::out);

	if(file.fail())  // THIS FUNCTION RETURNS TRUE IF THE FILE CANNOT BE OPENED
	{
		cout<<"\n\tThe file has no data. Please input some data first.";
		getch();
		return;
	}

	cout<<"\n\tEnter the roll number you want to modify : ";
	cin>>r;

	while(!file.eof())
	{
		file.read((char*)this,sizeof(Student));
		if(roll == r)
		{
			found = 'T';
			cout<<"\n\tROLL         : "<<roll;
			cout<<"\n\tEnter new roll : ";
			cin>>roll;
			cout<<"\n\tNAME           : "<<name;
			cout<<"\n\tEnter new name : ";
			cin>>name;
			cout<<"\n\t\tThe above record is modified.";
		}
		temp.write((char*)this,sizeof(Student));
	}

	if(found == 'F')
		cout<<"\n\tThe roll number is not found.";

	file.close();
	temp.close();

	remove("Student.txt");
	rename("Temp.txt", "Student.txt");
}

void main(void)
{
	Student obj;
	int choice;

	while(1)
	{
		clrscr();
		cout<<"\n\n\tM E N U";
		cout<<"\n\n\t1. Input Record";
		cout<<"\n\t2. Output Record";
		cout<<"\n\t3. Search Record";
		cout<<"\n\t4. Delete Record";
		cout<<"\n\t5. Modify Record";
		cout<<"\n\t6. Exit.";
		cout<<"\n\t\tEnter your choice : ";
		cin>>choice;

		switch(choice)
		{
			case 1 : obj.input();
					break;
			case 2 : obj.output();
					break;
			case 3 : obj.search();
					break;
			case 4 : obj.delete_record();
					break;
			case 5 : obj.modify();
					break;
			case 6 : exit(0);
			default: cout<<"\n\tInvalid choice.";
		}
		getch();
	}
}