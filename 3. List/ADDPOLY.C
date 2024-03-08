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

void AddNode(node **ptr, int coeff, int power)  // FUNCTION TO ADD TERM TO THE BEGINNING OF LIST
{
	node *new;
	new = (node *)malloc(sizeof(node));
	new->coeff = coeff;
	new->power = power;
	if(*ptr == (node *)NULL)
	{
		new->next = (node *)NULL;
		*ptr = new;
	}
	else
	{
		new->next = *ptr;
		*ptr = new;
	}
}

void ReadPolynominal(node **ptr)  // FUNCTION TO READ A POLYNOMINAL
{
	int coeff,power;
	char ans;
	printf("\n\n\n\tEnter the terms in ascending order of power : ");
	while(1)
	{
		printf("\n\n\t\tEnter the power of x  : ");
		scanf("%d",&power);
		fflush(stdin);
		printf("\n\n\t\tEnter its coefficient : ");
		scanf("%d",&coeff);
		fflush(stdin);
		AddNode(ptr, coeff, power);
		printf("\n\n\t\t\tAny more term ? (Y/N) : ");
		ans=getch();
		fflush(stdin);
		if(!(ans == 'Y' || ans == 'y'))
			return;
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

void AddPolynominal(node *ptr1, node *ptr2, node **ptr3)  // FUNTION TO ADD TWO POLYNOMINALS
{
	int power;
	int coeff;
	while((ptr1 != (node *)NULL) && (ptr2 != (node *)NULL))
	{
		if(ptr1->power > ptr2->power)
		{
			coeff = ptr1->coeff;
			power = ptr1->power;
			ptr1 = ptr1->next;
		}
		else if(ptr1->power<ptr2->power)
		{
			coeff = ptr2->coeff;
			power = ptr2->power;
			ptr2 = ptr2->next;
		}
		else
		{
			coeff = ptr1->coeff + ptr2->coeff;
			power = ptr1->power;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		if(coeff != 0)
			AddNode(ptr3, coeff, power);
	}

	if(ptr1 == (node *)NULL)
	{
		for( ; ptr2 != (node *)NULL ; ptr2 = ptr2->next)
			AddNode(ptr3, ptr2->coeff, ptr2->power);
	}
	else if(ptr2 == (node *)NULL)
	{
		for( ; ptr1 != (node *)NULL ; ptr1 = ptr1->next)
			AddNode(ptr3, ptr1->coeff, ptr1->power);
	}
}

/*
	ALGORITHM:
	START
		SET POINTER "PTR1" TO HEAD NODE OF FIRST LIST
		SET POINTER "PTR2" TO HEAD NODE OF SECOND LIST

		WHILE PTR1 IS NOT NULL AND PTR2 IS NOT NULL
		DO
			IF PTR1->POWER > PTR2->POWER THEN
				CREATE NEW NODE WITH PTR1->COEFF AND PTR1->POWER
				ADD THE NEW NODE TO THE RESULTANT LIST
				INCREMENT PTR1
			ELSE IF PTR1->POWER < PTR2->POWER THEN
				CREATE NEW NODE WITH PTR2->COEFF AND PTR2->POWER
				ADD THE NEW NODE TO THE RESULTANT LIST
				INCREMENT PTR2
			ELSE
				CREATE NEW NODE WITH PTR1->COEFF + PTR2->COEFF AND PTR1->POWER
				ADD THE NEW NODE TO THE RESULTANT LIST
				INCREMENT PTR1 AND PTR2
			ENDIF
		DONE

		IF PTR1 IS NULL THEN
			WHILE PTR2 IS NOT NULL
			DO
				ADD THE NODE POINTED TO BY PTR2 TO THE RESULTANT LIST
				INCREMENT PTR2
			DONE
		ELSE IF PTR2 IS NULL THEN
			WHILE PTR1 IS NOT NULL
			DO
				ADD THE NODE POINTED TO BY PTR1 TO THE RESULTANT LIST
				INCREMENT PTR1
			DONE
		ENDIF
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
	printf("\n\n\n\n\t\tProgeram to add two polynominals");
	printf("\n\t\t********************************");

	printf("\n\n\n\t\tEnter first polynominal : ");
	ReadPolynominal(&poly1);

	printf("\n\n\n\t\tEnter second polynominal : ");
	ReadPolynominal(&poly2);

	AddPolynominal(poly1,poly2,&poly3);

	printf("\n\n\n\t\tSum of polynominals :\n\n\t\t\t\t");
	PrintPolynominal(poly1);

	printf("\n\n\t\t\t\tand\n\n\t\t\t\t");

	PrintPolynominal(poly2);

	printf("\n\n\t\t\t\tis\n\n\t\t\t\t");

	PrintPolynominal(poly3);

	getch();
	DeletePolynominal(&poly1);
	DeletePolynominal(&poly2);
	DeletePolynominal(&poly3);
}