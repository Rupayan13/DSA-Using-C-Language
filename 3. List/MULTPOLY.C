/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

typedef struct node_type
{
	int coeff;
	int power;
	struct node_type *next;
}node;

void InsertNode(node ***ptr, int coeff, int power)  // FUNCTION TO INSERT THE NEW TERM AT ITS PLACE IN THE POLYNOMINAL
{
	node *newnode, *loc, *ploc;
	newnode = (node *)malloc(sizeof(node));
	newnode->coeff = coeff;
	newnode->power = power;

	if(**ptr == (node *)NULL)
	{
		newnode->next = (node *)NULL;
		**ptr=newnode;
	}
	else
	{
		ploc = (node *)NULL;
		loc = **ptr;
		while((loc != (node *)NULL) && (power < loc->power))
		{
			ploc = loc;
			loc = loc->next;
		}
		if(loc == (node *)NULL)
		{
			newnode->next = ploc->next;
			ploc->next = newnode;
			return;
		}
		if(loc->power == newnode->power)
		{
			loc->coeff = loc->coeff + newnode->coeff;
			free(newnode);
		}
	}
}

void AddNode(node ***ptr, int coeff, int power)  // FUNCTION TO ADD THE POLYNOMINAL TERMS AT THE END OF LIST
{
	node *new;
	static node *last;
	new = (node *)malloc(sizeof(node));
	new->coeff = coeff;
	new->power = power;
	new->next = (node *)NULL;

	if(**ptr == (node *)NULL)
	{	last = new;
		**ptr = new;
	}
	else
	{
		last->next = new;
		last = new;
	}
}

void ReadPolynominal(node **p)  // FUNCTION TO READ A POLYNOMINAL
{
	int coeff,power;
	char ans;
	printf("\n\n\n\tEnter the terms in ascending order of power : ");
	while(1)
	{
		printf("\n\n\t\tEnter the power of x  : ");
		scanf("%d", &power);
		fflush(stdin);
		printf("\n\n\t\tEnter its coefficient : ");
		scanf("%d", &coeff);
		fflush(stdin);

		AddNode(&p, coeff, power);

		printf("\n\n\t\t\tAny more term ? (Y/N) : ");
		ans = getch();
		if(!(ans == 'Y' || ans == 'y'))
			break;
	}
}

void PrintPolynominal(node *ptr)  // FUNCTION TO PRINT A POLYNOMINAL
{
	if(ptr != (node *)NULL)
		printf("%dx^%d", ptr->coeff, ptr->power);
	for(ptr = ptr->next ; ptr != (node *)NULL ; ptr = ptr->next)
	{
		if(ptr->coeff > 0)
			printf(" + ");

		if(ptr->power == 0)
			printf("%d", ptr->coeff);

		else if(ptr->power == 1)
			printf("%dx", ptr->coeff);

		else
			printf("%dx^%d", ptr->coeff, ptr->power);
	}
}

node *Search(node *ptr, int power)  // FUNCTION THAT RETURNS THE LOCATION OF THE NODE WITH GIVEN POWER
{
	while(ptr != (node *)NULL)
	{
		if(ptr->power == power)
			break;
		ptr = ptr->next;
	}
	return ptr;
}

void MultiplyPolynominal(node *ptr1, node *ptr2, node **ptr3)  // FUNTION TO MULTIPLY TWO POLYNOMINALS
{
	int power;
	int coeff;
	node *temp, *loc, *tt;

	while(ptr1 != (node *)NULL)
	{
		temp = ptr2;
		while(temp != (node *)NULL)
		{

			coeff = ptr1->coeff * temp->coeff;
			power = ptr1->power + temp->power;
			tt = *ptr3;
			loc = Search(tt, power);
			if(loc == (node *)NULL)
				InsertNode(&ptr3, coeff, power);
			else
				loc->coeff += coeff;  // ADD COEFFICIENT
			temp = temp->next;
		}
		ptr1 = ptr1->next;
	}
}

/*
	ALGORITHM:
	START
		DECLARE VARIABLES "POWER" AND "COEFF"

		SET POINTER "PTR1" TO HEAD OF THE FIRST LIST
		SET POINTER "PTR2" TO HEAD OF THE SECOND LIST
		
		WHILE PTR1 IS NOT NULL
		DO
			SET POINTER "TEMP" TO PTR2
			WHILE TEMP IS NOT NULL
			DO
				COEFF = PTR1->COEFF * TEMP->COEFF
				POWER = PTR1->POWER + TEMP->POWER
				
				SEARCH INTO THE RESULTANT LIST FOR EXISTANCE OF A NODE WHOSE POWER IS EQUAL TO THE "POWER" VARAIBLE
				
				IF SUCH A NODE IS FOUND THEN
					ADD THE VARAIBLE "COEFF" TO THE COEFF PART OF THE FOUND NODE
				ELSE
					CREATE A NEW NODE WITH VARIABLES "POWER" AND "COEFF"
					ADD THE NEW NODE INTO THE RESULTANT LIST
				ENDIF
				INCREMENT TEMP
			DONE
			INCREMENT PTR1
		DONE
	STOP
*/

void DeletePolynominal(node **ptr)  // FUNCTION TO REMOVE A POLYNOMINAL FROM MEMORY
{
	node *temp;
	while(*ptr != (node *)NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->next;
		free(temp);
	}
}

void main(void)
{
	node *poly1 = (node *)NULL;
	node *poly2 = (node *)NULL;
	node *poly3 = (node *)NULL;
	clrscr();
	printf("\n\n\n\n\t\tProgram to multiply two polynominals");
	printf("\n\t\t********************************");

	printf("\n\n\n\t\tEnter FIRST polynominal : ");
	ReadPolynominal(&poly1);

	printf("\n\n\n\t\tEnter SECOND polynominal : ");
	ReadPolynominal(&poly2);

	MultiplyPolynominal(poly1, poly2, &poly3);

	printf("\n\n\n\t\tProduct of polynominals :\n\n\t\t\t\t");
	PrintPolynominal(poly1);

	printf("\n\n\t\t\t\t\tand\n\n\t\t\t\t");
	PrintPolynominal(poly2);

	printf("\n\n\t\t\t\t\tis\n\n\t\t\t\t");
	PrintPolynominal(poly3);

	getch();

	DeletePolynominal(&poly1);
	DeletePolynominal(&poly2);
	DeletePolynominal(&poly3);
}