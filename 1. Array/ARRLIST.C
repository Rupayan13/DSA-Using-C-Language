/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>
#define MAX 5

/*
	IMPLEMENTATION OF LINEAR LIST USING AN ARRAY
*/

int list[MAX];

int head = -1; // THIS ACTS LIKE THE NULL VALUE
int tail = -1;

int IsFull(void)
{
	if(tail == MAX - 1)
		return 1;
	else
		return 0;
}

int IsEmpty(void)
{
	if(head == -1)
		return 1;
	else
		return 0;
}

void InsertAtEnd(void)
{
	int info;
	printf("\n\tEnter number : ");
	scanf("%d", &info);
	fflush(stdin);
	if(IsFull())
	{
		printf("\n\tCannot insert the new value. No space is available.");
		getch();
		return;
	}
	else
	{
		if(IsEmpty())  // IF THIS IS THE FIRST ELEMENT
			head++;
		tail++;
		list[tail] = info;
	}
}
/*
	ALGORITHM:
	START
		IF THE LIST IS FULL THEN
			PRINT "CANNOT INSERT THE NEW VALUE."
			RETURN
		ELSE
			IF THE LIST IS EMPTY THEN
				INCREMENT HEAD
			ENDIF
			INCREMENT TAIL
		ENDIF
		SET LIST[TAIL] TO NEW VALUE
	END
*/

void InsertAtBeginning(void)
{
	int info;
	int i;
	printf("\n\tEnter number : ");
	scanf("%d", &info);
	fflush(stdin);
	if(IsFull())
	{
		printf("\n\tCannot insert the new value. No space is available.");
		getch();
		return;
	}
	else
	{
		if(IsEmpty())  // IF THIS IS THE FIRST ELEMENT
		{	head++;
			tail++;
		}
		else // IF NOT, WE HAVE TO PUSH THE ENTIRE ARRAY ONE PLACE TO THE RIGHT TO ALLOCATE THE NEW NODE AT THE BEGINNING
		{
			for(i = tail ; i >= head ; i--)
				list[i+1] = list[i];
			tail++;
		}
		list[head] = info;
	}
}
/*
	ALGORITHM:
	START
		IF THE LIST IS FULL THEN
			PRINT "CANNOT INSERT THE NEW VALUE."
			RETURN
		ELSE
			IF THE LIST IS EMPTY THEN
				INCREMENT HEAD
				INCREMENT TAIL
			ELSE
				FOR I= TAIL TO HEAD STEP -1
					SET LIST[I+1] = LIST[I]
				ENDFOR
				INCREMENT TAIL
			ENDIF
		ENDIF
		SET LIST[HEAD] TO NEW VALUE
	STOP
*/

void Display(void)
{
	int i;
	if(IsEmpty())
	{
		printf("\n\tCannot display the list. The list is empty.");
		getch();
		return;
	}
	else
	{
		for(i = head ; i <= tail ; i++)
			printf("\t%d", list[i]);
	}
}
/*
	ALGORITHM:
	START
		IF THE LIST IS EMPTY THEN
			PRINT "CANNOT DISPLAY THE LIST."
			RETURN
		ELSE
			FOR I= HEAD TO TAIL STEP 1
				PRINT LIST[I]
			ENDFOR
		ENDIF
	STOP
*/

int Search(int info)
{
	int i;
	if(IsEmpty())
		return -1;
	else
	{
		for(i = head ; i <= tail ; i++)
		{
			if(list[i] == info)
				return i;
		}
	}
	return -1;
}
/*
	ALGORITHM:
	START
		READ THE VALUE TO BE SEARCHED INTO VARIABLE 'INFO'
		IF THE LIST IS FULL THEN
			PRINT "CANNOT SEARCH THE LIST."
			RETURN SENTINEL VALUE
		ELSE
			FOR I= HEAD TO TAIL STEP 1
				IF LIST[I] = INFO THEN
					PRINT "THE VALUE IS FOUND AT INDEX ",I
					RETURN I
				ENDIF
			ENDFOR
		ENDIF
		PRINT "THE VALUE IS NOT FOUND."
	STOP
*/

void InsertAfterAGivenNode(void)
{
	int i, j;
	int info;
	if(IsFull())
	{
		printf("\n\tCannot insert the new value. No space is available.");
		getch();
		return;
	}
	printf("\n\tEnter the node after which you want to insert the new node : ");
	scanf("%d", &info);
	i = Search(info);
	if(i == -1)
	{
		printf("\n\tThis value does not exist in the list.");
		getch();
		return;
	}
	else
	{
		// WE HAVE TO PUSH EACH ELEMENT ONE PLACE TOWARDS THE END OF THE ARRAY FROM LOCATION i
		tail++;
		for(j = tail ; j > i ; j--)
			list[j+1] = list[j];
		printf("\n\tEnter the new node : ");
		scanf("%d", &list[i+1]);
	}
}
/*
	ALGORITHM:
	START
		IF THE LIST IS FULL THEN
			PRINT "CANNOT INSERT INTO THE LIST."
			RETURN
		ENDIF
		PRINT "ENTER THE NODE AFTER WHICH YOU WANT TO INSERT THE NEW NODE : "
		READ THE VALUE INTO VARIABLE 'INFO'

		SEARCH THE VALUE IN THE LIST AND RETURN THE INDEX INTO VARIABLE 'I'

		IF I = -1 THEN
			PRINT "THE VALUE IS NOT FOUND."
			RETURN
		ELSE
			INCREMENT TAIL
			FOR J = TAIL TO I+1 STEP -1
				LIST[J+1] = LIST[J]
			ENDFOR
			PRINT "ENTER THE NEW NODE : "
			READ NEW VALUE INTO LIST[I+1]
		ENDIF
	STOP
*/


void DeleteAnyNode(void)
{
	int i;
	int info;
	printf("\n\tEnter the node which you want to delete from the list : ");
	scanf("%d", &info);
	i = Search(info);
	if(i == -1)
	{
		printf("\n\tThis value does not exist in the list.");
		getch();
		return;
	}
	else
	{
		if(head == tail)  // IF THIS IS THE ONLY NODE
		{
			head = -1;
			tail = -1;
		}
		else  // IF NOT, WE HAVE TO PUSH THE ENTIRE ARRAY ONE PLACE TO THE LEFT TO OVERWRITE THE NODE
		{
			for( ; i < tail ; i++)
				list[i] = list[i+1];
			tail--;
		}
	}
}
/*
	ALGORITHM:
	START
		PRINT "ENTER THE NODE YOU WANT TO DELETE : "
		READ THE VALUE INTO VARIABLE 'INFO'

		SEARCH THE VALUE IN THE LIST AND RETURN THE INDEX INTO VARIABLE 'I'

		IF I = -1 THEN
			PRINT "THE VALUE IS NOT FOUND."
			RETURN
		ELSE
			IF HEAD = TAIL THEN
				HEAD = -1
				TAIL = -1
			ELSE
				WHILE I <= TAIL
				DO
					LIST[I] = LIST[I+1]
					INCREMENT I
				DONE
				DECREMENT TAIL
			ENDIF
		ENDIF
	STOP
*/

void main(void)
{
	int ch;

	while(1)
	{
		clrscr();
		printf("\n\n\n\t\tMENU");
		printf("\n\t\t~~~~");
		printf("\n\n\t\t 1. Insert Node At End");
		printf("\n\t\t 2. Insert Node At Beginning");
		printf("\n\t\t 3. Insert After A Given Node");
		printf("\n\t\t 4. Display List");
		printf("\n\t\t 5. Delete A Node");
		printf("\n\t\t 6. Exit");
		printf("\n\t\t\tEnter your choice : ");
		scanf("%d", &ch);
		fflush(stdin);

		switch(ch)
		{
			case (1) : InsertAtEnd();
					break;
			case (2) : InsertAtBeginning();
					break;
			case (3) : InsertAfterAGivenNode();
					break;
			case (4) : Display();
					break;
			case (5) : DeleteAnyNode();
					break;
			case (6) : printf("\n\t\tExiting...");
					getch();
					exit(0);
			default  : printf("\n\t\tInvalid input.");
		}
		getch();
	}
}

