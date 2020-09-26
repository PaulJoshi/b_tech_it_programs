/*
Write a menu driven C program to implement stack using one dimensional array. Perform
the operations on the stack (i) Push (ii) Pop (iii) Status (iv) Display.
*/

#include <stdio.h>
#include <stdlib.h>
int stack[100], c, n, top = -1;

void push()
{
    if(top >= n-1)
        printf("\nStack overflow");
    else
    {
        int a;
        printf("Enter a value to push: ");
        scanf("%d", &a);
        top++;
        stack[top] = a;
    }
}

void pop()
{
    if(top <= -1)
        printf("Stack underflow");
    else
        printf("The popped element is %d", stack[top]);
        top--;
}

void status()
{	float a,b;
    if(top<0)
		printf("Stack is empty");
	else if(top>=n-1)
		printf("Stack is full");
	else
	{
        a = ((n-1)-top);
	    b = ((a/n)*100);
		printf("Space remaining is: %0.1f percent", b);
    }
}

void display()
{	
    if(top<0)
		printf("Stack is Empty\n\n");
	else
	{	printf("The stack elements are :");
        for(int i = top; i >= 0; i--)
            printf("  %d",stack[i]);
	}
}

void main()
{
    system("cls");
    printf("\nEnter the size of stack: ");
    scanf("%d", &n);
    printf("-------------------\n1 - Push\n2 - Pop\n3 - Status\n4 - Display\n5 - Exit\n-------------------");
    while(1)
    { 
        printf("\n\nEnter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                status();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf ("\nInvalid Choice");
        }
    }
}