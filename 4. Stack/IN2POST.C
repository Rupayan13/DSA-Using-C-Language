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

char GetPriority(char op)
{
	// SETTING RELATIVE PRIORITY FOR OPERATORS
	int returnvalue;
	if(op == '^')
		returnvalue = 2;
	else if(op=='/' || op=='*' || op=='%')
		returnvalue = 1;
	else if(op=='+' || op=='-')
		returnvalue = 0;
	return returnvalue;
}

void InfixToPostfix(char *source, char *target)
{
	char *s, *t, ch1;
	stack *top;
	float op1, op2, value;
	CreateStack(&top);  // CREATING AN EMPTY STACK
	s = source;
	t = target;
	while(*s)
	{
		if((*s == ' ') || (*s == '\t'))  // SKIP WHITE SPACES
		{
			s++;
			continue;
		}
		else if(*s == '(')
		{
			Push(&top, *s);
			s++;
		}
		else if(*s == ')')
		{
			while((!IsEmpty(top)) && (Peek(&top) != '('))
			{
				*t = Pop(&top);
				t++;
			}
			if(IsEmpty(top))
			{
				printf("\n\n\tERROR : Incorrect expression.");
				getch();
				exit(1);
			}
			Pop(&top);  // REMOVE LEFT PARENTHESIS FROM THE STACK
			s++;
		}
		else if(isdigit(*s) || isalpha(*s))
		{
			*t = *s;
			t++;
			s++;
		}
		else if( *s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%' )
		{
			while(!IsEmpty(top) && Peek(&top) != '(' && (GetPriority(Peek(&top)) >= GetPriority(*s)) )
			{
				*t = Pop(&top);
				t++;
			}
			Push(&top, *s);
			s++;
		}
		else
		{
			printf("\n\n\tERROR : Incorrect expression.");
			getch();
			exit(1);
		}
	}  // ENDWHILE
	while((!IsEmpty(top)) && (Peek(&top) != '('))
	{
		*t = Pop(&top);
		t++;
	}
	if(Peek(&top) == '(')
	{
		printf("\n\n\tERROR : Incorrect expression.");
		getch();
		exit(1);
	}
	*t = '\0';
}

/*
	ALGORITHM:
	START
		CREATE AN EMPTY STACK
		ASSUME THE SOURCE EXPRESSION IS "S"
		ASSUME THE DESTINATION EXPRESSION IS "T"

		WHILE NOT END OF THE SOURCE EXPRESSION S
		DO
			SCAN S FROM LEFT TO RIGHT
			IF S PRESENTLY CONTAINS LEFT PARENTHESES THEN
				PUSH LEFT PARENTHESES IN THE STACK
			ELSE IF S PRESENTLY CONTAINS RIGHT PARENTHESES THEN
				WHILE STACK IS NOT EMPTY AND TOP OF STACK IS NOT LEFT PARENTHESIS
				DO
					POP FROM STACK AND APPEND THE POPPED ELEMENT INTO DESTINATION EXPRESSION T
				DONE
				IF STACK IS EMPTY THEN
					PRINT "ERROR : INCORRECT EXPRESSION."
					EXIT
				ENDIF
				POP THE LEFT PARENTHESES FROM STACK
			ELSE IF S PRESENTLY CONTAINS AN OPERAND THEN
				APPEND THE OPERAND TO T
			ELSE IF S PRESENTLY CONTAINS AN OPERATOR THEN
				WHILE STACK TOP CONTAINS AN OPERATOR AND STACK IS NOT EMPTY AND ITS PRECEDENCE >= THE PRECEDENCE OF THE OPERATOR AT S
				DO
					POP FROM STACK AND APPEND INTO T
				DONE
				PUSH THE PRESENT CONTENT OF A INTO THE STACK
			ELSE
				PRINT "ERROR : INCORRECT ELEMENT IN EXPRESSION."
				EXIT
			ENDIF
		DONE

		WHILE STACK IS NOT EMPTY AND TOP OF STACK IS NOT A LEFT PARENTHESES
		DO
			POP FROM STACK AND APPEND INTO T
		DONE

		IF TOP OF STACK IS A LEFT PARENTHESES THEN
			PRINT "ERROR : INCORRECT EXPRESSION."
		ENDIF
	STOP
*/

void main(void)
{
	char infix[20], postfix[20];
	clrscr();
	printf("\n\n\n\n\tEnter a mathematical expression in infix notation : ");
	gets(infix);
	fflush(stdin);
	InfixToPostfix(infix, postfix);
	printf("\n\n\tThe expression in postfix notation is : %s", postfix);
	getch();
}
