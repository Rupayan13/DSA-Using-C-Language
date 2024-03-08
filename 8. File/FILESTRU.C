/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>

typedef struct
{
	int roll;
	char name[10];
}student;

student s;

void Input(void)
{
	FILE *fp;

	fp = fopen("STUDENT.TXT", "a");

	printf("\n\tEnter ROLL : ");
	scanf("%d", &s.roll);
	fflush(stdin);

	printf("\n\tEnter NAME : ");
	gets(s.name);
	fflush(stdin);

	fwrite(&s, sizeof(student), 1, fp);

	fclose(fp);
}

void Output(void)
{
	FILE *fp;

	fp = fopen("STUDENT.TXT", "r");

	if(feof(fp))
	{
		printf("\n\tThe file is empty. Please input some record first.");
		fclose(fp);
		getch();
		return;
	}

	while(!feof(fp))
	{
		fread(&s, sizeof(student), 1, fp);

		printf("\n\n\tROLL : %d", s.roll);
		printf("\n\tNAME : %s", s.name);
	}

	fclose(fp);
}

void Search(void)
{
	int r;
	char found = 'F';
	FILE *fp;

	fp = fopen("STUDENT.TXT", "r");

	if(feof(fp))
	{
		printf("\n\tThe file is empty. Please input some record first.");
		fclose(fp);
		getch();
		return;
	}

	printf("\n\tEnter the roll number of the student you want to search : ");
	scanf("%d", &r);
	fflush(stdin);

	while(!feof(fp))
	{
		fread(&s, sizeof(student), 1, fp);
		if(s.roll == r)
		{
			found = 'T';
			printf("\n\n\tROLL : %d", s.roll);
			printf("\n\tNAME : %s", s.name);
		}
	}

	if(found == 'F')
	{
		printf("\n\tThis roll number is not found in the file.");
		getch();
	}

	fclose(fp);
}

void Delete(void)
{
	int r;
	char found = 'F';
	FILE *fp1, *fp2;

	fp1 = fopen("STUDENT.TXT", "r");

	if(feof(fp1))
	{
		printf("\n\tThe file is empty. Please input some record first.");
		fclose(fp1);
		getch();
		return;
	}

	fp2 = fopen("TEMP.TXT", "w");

	printf("\n\tEnter the roll number of the student you want to delete : ");
	scanf("%d", &r);
	fflush(stdin);

	while(!feof(fp1))
	{
		fread(&s, sizeof(student), 1, fp1);
		if(s.roll == r)
		{
			found = 'T';
			printf("\n\n\tROLL : %d", s.roll);
			printf("\n\tNAME : %s", s.name);
			printf("\n\n\tThis record is being deleted.");
		}
		else
			fwrite(&s, sizeof(student), 1, fp2);
	}

	if(found == 'F')
	{
		printf("\n\tThis roll number is not found in the file.");
		getch();
	}

	fclose(fp1);
	fclose(fp2);

	remove("STUDENT.TXT");
	rename("TEMP.TXT", "STUDENT.TXT");
}

void Modify(void)
{
	int roll, r;
	char name[10];
	char found = 'F';
	FILE *fp1, *fp2;

	fp1 = fopen("STUDENT.TXT", "r");

	if(feof(fp1))
	{
		printf("\n\tThe file is empty. Please input some record first.");
		fclose(fp1);
		getch();
		return;
	}

	fp2 = fopen("TEMP.TXT", "w");

	printf("\n\tEnter the roll number of the student you want to modify : ");
	scanf("%d", &r);
	fflush(stdin);

	while(!feof(fp1))
	{
		fread(&s, sizeof(student), 1, fp1);

		if(s.roll == r)
		{
			found = 'T';

			printf("\n\n\tROLL : %d", s.roll);
			printf("\n\tEnter new roll : ");
			scanf("%d", &s.roll);
			fflush(stdin);

			printf("\n\tNAME : %s", s.name);
			printf("\n\tEnter new name : ");
			gets(s.name);
			fflush(stdin);

			printf("\n\n\tThis record is modified.");
		}
		fwrite(&s, sizeof(student), 1, fp2);
	}

	if(found == 'F')
	{
		printf("\n\tThis roll number is not found in the file.");
		getch();
	}

	fclose(fp1);
	fclose(fp2);

	remove("STUDENT.TXT");
	rename("TEMP.TXT", "STUDENT.TXT");
}

void main(void)
{
	int ch;

	while(1)
	{
		clrscr();
		printf("\n\t\tM E N U");
		printf("\n\t\t-------");
		printf("\n\n\t1. Input Data Into File");
		printf("\n\t2. Output Data From File");
		printf("\n\t3. Search Data From File");
		printf("\n\t4. Delete Data From File");
		printf("\n\t5. Modify Data In File");
		printf("\n\t6. Exit.");
		printf("\n\t\tEnter your choice : ");
		scanf("%d", &ch);
		fflush(stdin);

		switch(ch)
		{
			case 1 : Input();
					break;
			case 2 : Output();
					break;
			case 3 : Search();
					break;
			case 4 : Delete();
					break;
			case 5 : Modify();
					break;
			case 6 : printf("\n\tExiting...");
					getch();
					exit(1);
			default : printf("\n\tInvalid input.");
		}
		getch();
	}
}