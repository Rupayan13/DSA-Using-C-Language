/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

typedef struct column_node  // STRUCTURE OF COLUMN NODE
{
	int col;
	int element;
	struct column_node *link;
}cnode;

typedef struct row_node  // STRUCTURE OF ROW NODE
{
	int row;
	struct row_node *next;
	struct column_node *first;
}rnode;

typedef struct starter_node  // STRUCTURE OF STARTER NODE
{
	int nrow;
	int ncol;
	int num;
	struct row_node *start;
}hnode;

void Initialize(hnode **ptr, int rows, int cols)  // TO INITIALIZE THE HEADER NODE
{
	*ptr = (hnode *)malloc(sizeof(hnode));
	(*ptr)->nrow = rows;
	(*ptr)->ncol = cols;
	(*ptr)->num = 0;
	(*ptr)->start = (rnode *)NULL;
}

void Delete(hnode **ptr)  // TO DELETE HEADER NODE AFTER DELETING ALL ROWS AND COLUMNS
{
	rnode *rptr, *temp1;
	cnode *cptr, *temp2;
	rptr = (*ptr)->start;

	while(rptr != (rnode *)NULL)  // FIRST REMOVE COLUMN NODES
	{
		cptr = rptr->first;
		while(cptr != (cnode *)NULL)
		{
			temp2 = cptr;
			cptr = cptr->link;
			free(temp2);
		}
		rptr = rptr->next;
	}

	while((*ptr)->start!=(rnode *)NULL)  // THEN REMOVE ROW NODES
	{
		temp1 = (*ptr)->start;
		(*ptr)->start = (*ptr)->start->next;
		free(temp1);
	}
}

void StoreElement(hnode *sparse, int i, int j, int element)  // TO PUT THE MULTIPLIED VALUES IN THE RSULTANT SPARSE MATRIX
{
	rnode *rptr, *pptr1, *ptr1;
	cnode *cptr, *pptr2, *ptr2;

	sparse->num++;
	cptr = (cnode *)malloc(sizeof(cnode));
	cptr->col = j;
	cptr->element = element;
	if(sparse->start == NULL)  // IF SPARSE MATRIX IS EMPTY
	{
		rptr = (rnode *)malloc(sizeof(rnode));  // THEN CREATE FIRST EVER NODE AS THE NEW ROW
		sparse->start = rptr;
		rptr->next = (rnode *)NULL;  // SINCE IT IS THE ONLY ROW
		rptr->row = i;
		rptr->first = cptr;  // SINCE IT IS ALSO THE ONLY COLUMN
		cptr->link = (cnode *)NULL;
		return;
	}
	pptr1 = (rnode *)NULL;
	ptr1 = sparse->start;
	while((ptr1 != (rnode *)NULL) && (ptr1->row < i))  // TRAVERSING THE NODES TO FIND WHERE TO PUT THE VALUE
	{
		pptr1=ptr1;
		ptr1=ptr1->next;
	}
	if(ptr1->row == i)  // IF ROW ALREADY EXISTS
	{
		pptr2 = (cnode *)NULL;
		ptr2 = ptr1->first;
		while((ptr2 != (cnode *)NULL) && (ptr2->col < j))  // THEN TRAVERSE COLUMN TO FIND WHERE TO PUT THE VALUE
		{
			pptr2 = ptr2;
			ptr2 = ptr2->link;
		}
		if(pptr2 == (cnode *)NULL)  // INSERT AS FIRST COLUMN NODE
		{
			cptr->link = ptr1->first;
			ptr1->first = cptr;
		}
		else
		{
			cptr->link = ptr2;
			pptr2->link = cptr;
		}
		return;
	}
	else if(ptr1 == (rnode *)NULL)  // INSERT NEW NODE AT END
	{
		rptr = (rnode *)malloc(sizeof(rnode));  // CREATE NEW NODE AT LAST ROW
		pptr1->next = rptr;
		rptr->next = (rnode *)NULL;
		rptr->row = i;
		rptr->first = cptr;
		cptr->link = (cnode *)NULL;
		return;
	}
	else
	{
		rptr = (rnode *)malloc(sizeof(rnode));
		rptr->row = i;
		rptr->next = ptr1;
		pptr1->next = rptr;
		rptr->first = cptr;
		cptr->link = (cnode *)NULL;
	}
}

int RetriveElement(hnode *sparse, int i, int j)  // TO ACCESS ELEMENT IN row=i AND col=j
{  // IF NON-ZERO ELEMENT IS NOT FOUND 0 IS RETURNED, SO THAT MULTIPLIED VALUE WILL ALSO BE 0
	rnode *rptr;
	cnode *cptr;
	int returnvalue;
	rptr = sparse->start;
	while((rptr != (rnode *)NULL) && (rptr->row < i))
		rptr=rptr->next;
	if(rptr == (rnode *)NULL)  // ROW NOT FOUND
		returnvalue = 0;
	else if(rptr->row > i)  // ROW i DOES NOT EXIST
		returnvalue = 0;
	else if(rptr->row == i)  // IF ROW i IS FOUND
	{
		cptr = rptr->first;  // SEARCH FOR COLUMN
		while((cptr != (cnode *)NULL) && (cptr->col < j))
			cptr = cptr->link;
		if(cptr == (cnode *)NULL)  // COLUMN NOT FOUND
			returnvalue = 0;
		else if(cptr->col > j)  // COLUMN j DOES NOT EXISTS
			returnvalue = 0;
		else if(cptr->col == j)  // IF ROW i IS FOUND
			returnvalue = cptr->element;
	}
	return returnvalue;
}

void ReadMatrix(hnode *ptr)
{  // READS THE NON-ZERO VALUES PROVIDED BY THE USER INTO THE SPARSE MATRIX
	int i, j, element;
	char yes_no;
	while(1)
	{
		printf("\n\n\n\tEnter row number    : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\tEnter column number : ");
		scanf("%d", &j);
		fflush(stdin);
		printf("\n\n\tEnter element       : ");
		scanf("%d", &element);
		fflush(stdin);
		StoreElement(ptr, i, j, element);
		printf("\n\n\tAny more element?(Y/N) : ");
		yes_no=getch();
		fflush(stdin);
		if((yes_no=='Y') || (yes_no=='y'))
			continue;
		else
			break;
	}
}

void PrintMatrix(hnode *ptr)
{
	int i, j, element;
	for(i=1; i<=ptr->nrow ; i++)
	{
		printf("\n\n");
		for(j = 1; j <= ptr->ncol ; j++)
		{
			element = RetriveElement(ptr, i, j);
			printf("%4d", element);
		}
	}
}

void main(void)
{
	int i, j, k, l, m, n, p, q, element, temp;
	hnode *sparse1, *sparse2, *sparse3=(hnode *)NULL;
	clrscr();
	printf("\n\n\n\n\tEnter number of rows in the first matrix     : ");
	scanf("%d", &m);
	fflush(stdin);
	printf("\n\n\tEnter number of columns in the first matrix  : ");
	scanf("%d", &n);
	fflush(stdin);
	printf("\n\n\tEnter number of rows in the second matrix    : ");
	scanf("%d", &p);
	fflush(stdin);
	printf("\n\n\tEnter number of columns in the second matrix : ");
	scanf("%d", &q);
	fflush(stdin);
	if(n != p)
	{
		printf("\n\n\tProduct is not feasible.");
		getch();
		return;
	}
	Initialize(&sparse1, m, n);  // INITIALISING THE THREE MATRICES
	Initialize(&sparse2, p, q);
	Initialize(&sparse3, m, q);
	printf("\n\n\n\n\tEnter non-zero elements of the first sparse matrix  :");
	ReadMatrix(sparse1);
	printf("\n\n\n\n\tEnter non-zero elements of the second sparse matrix :");
	ReadMatrix(sparse2);
	for(i = 1 ; i <= m ; i++)
	{
		for(j = 1 ; j <= q; j++)
		{
			temp = 0;
			for(k = 1 ; k <= n ; k++)
			{
				temp += RetriveElement(sparse1, i, k) * RetriveElement(sparse2, k, j);

				StoreElement(sparse3, i, j, temp);
			}
		}
	}
	printf("\n\n\n\tProduct of the sparse matrix :\n\n");  // OUTPUT THE MATRICES
	PrintMatrix(sparse1);
	printf("\n\n\n\t\t\tand\n\n");
	PrintMatrix(sparse2);
	printf("\n\n\n\t\t\tequals\n\n");
	PrintMatrix(sparse3);
	getch();
	Delete(&sparse1);
	Delete(&sparse2);
	Delete(&sparse3);
}