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
	char info;
	struct node *next;
}stack;

stack *top;  // TOP POINTER

void CreateStack(stack **top)  // CREATING EMPTY STACK BY PUTTING NULL VALUE AT THE TOP
{
	*top = NULL;
}

int IsEmpty(stack *ptr)
{
	if(ptr == NULL)
		return 1;
	else
		return 0;
}

void Push(stack **top, char value)  // PUSHING A NEW ELEMENT
{
	stack *ptr;
	ptr = (stack *)malloc(sizeof(stack));
	ptr->info = value;
	ptr->next = *top;
	*top = ptr;
}

char Pop(stack **top)  // RETURNING THE TOP ELEMENT AFTER DELETING IT
{
	stack *ptr;
	char c;
	ptr = *top;
	c = ptr->info;
	*top = (*top)->next;
	free(ptr);
	return c;

}

char Peek(stack **top)  // RETURNING THE TOP ELEMENT WITHOUT DELETING IT
{
	char c;
	c = (*top)->info;
	return c;

}

char GetMatchingSymbol(char ch)
{
	char returnvalue;
	switch(ch)
	{
		case '(' : returnvalue = ')';
				break;
		case ')' : returnvalue =  '(';
				break;
		case '{' : returnvalue =  '}';
				break;
		case '}' : returnvalue =  '{';
				break;
		case '[' : returnvalue =  ']';
				break;
		case ']' : returnvalue =  '[';
	}
	return returnvalue;
}

void ParenthesisChecker(char *exp)
{
	char ch;
	stack *top;
	CreateStack(&top);
	while(*exp)
	{
		if(*exp == '(' || *exp == '{' || *exp == '[')
			Push(&top, *exp);
		else if(*exp == ')' || *exp == '}' || *exp == ']')
		{
			if(IsEmpty(top))
			{
				printf("\n\n\tERROR : No matching open symbol.");
				return;
			}
			else
			{
				ch = Pop(&top);
				if(ch != GetMatchingSymbol(*exp))
				{
					printf("\n\n\tERROR : Incorrect nesting of symbol.");
					return;
				}
			}
		}
		exp++;
	}

	if(!IsEmpty(top))
	{
		printf("\n\n\tERROR : Missing closing symbol.");
		return;
	}
	else
		printf("\n\n\tInput expression is OK.");
}

/*
	ALGORITHM:
	START
		READ THE INFIX EXPRESSION INTO CHARACTER ARRAY "EXP"
		CREATE AN EMPTY STACK

		FOR EACH CHARACTER AS "C" IN EXP
			IF C IS A LEFT PARENTHESES THEN
				PUSH C IN THE STACK
			ELSE IF C IS A RIGHT PARENRTHESES THEN
				IF STACK IS EMPTY THEN
					PRINT "ERROR : NO MATCHING OPEN SYMBOL."
					EXIT
				ELSE
					POP THE TOP CHARACTER (ANY KIND OF LEFT PARENTHESES) FROM THE STACK
					IF THE POPPED PARENTHESES DOES NOT CORRESPOND TO C
						PRINT "INCORRECT NESTING OF SYMBOLS."
						EXIT
					ENDIF
				ENDIF
			ENDIF
		ENDFOR

		IF STACK IS NOT EMPTY THEN
			PRINT "ERROR : MISSING CLOSING SYEMBOL."
		ELSE
			PRITN "INPUT EXPRESSION IS OK."
		ENDIF
	STOP
*/

void main(void)
{
	char expression[20];
	clrscr();
	printf("\n\n\n\n\tEnter a mathematical expression in infix notation : ");
	gets(expression);
	fflush(stdin);
	ParenthesisChecker(expression);
	getch();
}