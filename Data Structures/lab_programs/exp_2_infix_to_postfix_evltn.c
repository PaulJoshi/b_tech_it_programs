//Write a C program to perform i) Infix to postfix conversion ii) Postfix evaluation

#include <ctype.h>
#include <stdio.h>

char stack[50];
int top = -1;

void push(char elem)
{ 
	stack[++top] = elem;
}

char pop()
{ 
	return (stack[top--]);
}

int  power(int base, unsigned int exp)
{
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

int  precedence(char elem)
{ 
	switch (elem)
	{
		case '#':
			return 0;
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		case '^':
			return 5;
	}
}

void RemoveSpaces(char* source)
{
	char* i = source;
	char* j = source;
	while(*j != 0)
    {
		*i = *j++;
		if(*i != ' ')
			i++;
	}
	*i = 0;
}

void infix_to_postfix(char *infix, char *postfix)
{
	char ch, elem;
	int i = 0, k = 0;
	
	RemoveSpaces(infix);
	push('#');
	
	while ((ch = infix[i++]) != '\n')
	{
		if (ch == '(')
			push(ch);
		else if (isalnum(ch))
			postfix[k++] = ch;
		else if (ch == ')')
        {
			while (stack[top] != '(')
				postfix[k++] = pop();
			elem = pop();
		} else
        {
			while (precedence(stack[top]) >= precedence(ch))
				postfix[k++] = pop();
			push(ch);
		}
	}
	
	while (stack[top] != '#') /* Pop from stack till empty */
	postfix[k++] = pop();
  
	postfix[k] = 0; /* Make postfix as valid string */
}

int  eval_postfix(char *postfix)
{
	char ch;
	int i = 0, op1, op2;
	while((ch = postfix[i++]) != 0)
    {
		if(isdigit(ch)) 
			push(ch-'0');
		else
        {
			op2 = pop();
			op1 = pop();
			switch(ch) {
				case '+' : push(op1+op2); 
				break;
				case '-' : push(op1-op2); 
				break;
				case '*' : push(op1*op2);
				break;
				case '/' : push(op1/op2);
				break;
				case '^' : push(power(op1,op2));
				break;
			}
		}
	}
	return stack[top];
}

void main()
{
	char infix[50], postfix[50];
	printf("\nInput the infix expression: ");
	fgets(infix, 50, stdin);
	
	infix_to_postfix(infix, postfix);

	printf("\nGiven Infix Expression: %sPostfix Expression: %s", infix, postfix);
	top = -1;
	printf("\nResult: %d", eval_postfix(postfix));
}