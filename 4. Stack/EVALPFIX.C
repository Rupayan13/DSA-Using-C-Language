/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

typedef struct node  // DECLARING NEW DATATYPE FOR STACK
{
	float info;
	struct node *next;
}stack;

stack *top;  // TOP POINTER

void CreateStack(stack **top)  // CREATING EMPTY STACK BY PUTTING NULL VALUE AT THE TOP
{
	*top = NULL;
}

void Push(stack **top, float value)  // PUSHING A NEW ELEMENT
{
		stack *ptr;
		ptr = (stack *)malloc(sizeof(stack));
		ptr->info = value;
		ptr->next = *top;
		*top = ptr;
}

float Pop(stack **top)  // RETURNING THE TOP ELEMENT AFTER DELETING IT
{
	stack *ptr;
	char c;
	ptr = *top;
	c = ptr->info;
	*top = (*top)->next;
	free(ptr);
	return c;

}

float EvaluatePostfixExpression(char *exp)
{
	char c;
	stack *top;
	float op1, op2, value;
	CreateStack(&top);
	while(*exp)
	{
		if(*exp == ' ' || *exp == '\t' || *exp == ',')
		{
			exp++;
			continue;
		}
		if(isdigit(*exp))
			Push(&top, (float)(*exp-'0'));
		else
		{
			op2 = Pop(&top);
			op1 = Pop(&top);
			switch(*exp)
			{
				case '+' : value = op1+op2;
						break;
				case '-' : value = op1-op2;
						break;
				case '/' : value = op1/op2;
						break;
				case '*' : value = op1*op2;
						break;
				default  : printf("\n\n\n\t\tIllegal operation.");
					   getch();
					   exit(1);
			}
			Push(&top, value);
		}
		exp++;
	}
	return(Pop(&top));
}

/*
	ALGORITHM:
	START
		CREATE AN EMPTY STACK
		ASSUME SOURCE EXPRESSION IS "EXP"

		WHILE NOT END OF EXP
		DO
			IF EXP PRESENTLY CONTAIN AN OPERAND THEN
				PUSH CONTENT OF EXP INTO STACK
			ELSE
				POP THE TWO TOPMOST ELEMENT, ASSUME FIRST ONE IS "A" AND SECOND ONE IS "B"
				EVALUATE B OPERATED BY A AND STORE RESULT IN "C"
				PUSH C INTO STACK
			ENDIF
			INCREMENT EXP POINTER
		DONE
		POP STACK AND ASSING THE POPPED VALUE TO VARIABLE "RESULT"
	STOP
*/

void main(void)
{
	char postfix[20];
	float result;
	clrscr();
	printf("\n\n\n\n\tEnter a mathematical expression in postfix notation : ");
	gets(postfix);
	fflush(stdin);
	result = EvaluatePostfixExpression(postfix);
	printf("\n\n\tThe result of the postfix notation is : %f", result);
	getch();
}