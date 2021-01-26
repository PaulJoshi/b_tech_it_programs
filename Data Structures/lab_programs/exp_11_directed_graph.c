/* Write a menu driven C program to perform the following operations on a directed graph
    (i) DFS
    (ii) BFS
    (iii) Display (using Adjacency Matrix) */

#include <stdio.h>
#include <stdlib.h>

int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];

int delete()
{
    int k;
    if((front > rear) || (front == -1))
        return(0);
    else
    {
        k = q[front++];
        return(k);
    }
}

void add(int item)
{
    if(rear == 19)
    printf("Queue Full");
    else
    {
        if(rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
        q[++rear] = item;
    }
}

void push(int item)
{
    if(top == 19)
        printf("Stack overflow ");
    else
        stack[++top] = item;
}

int pop()
{
    int k;
    if(top == -1)
        return(0);
    else
    {
        k = stack[top--];
        return(k);
    }
}

void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete();
    if(p != 0)
        printf(" %d", p);
    while(p != 0)
    {
        for(i = 1; i <= n; i++)
            if((a[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        p = delete();
        if(p != 0)
            printf(" %d ", p);
    }
    for(i = 1; i <= n; i++)
        if(vis[i] == 0)
            bfs(i, n);
}

void dfs(int s, int n)
{
    int i, k;
    push(s);
    vis[s] = 1;
    k = pop();
    if(k != 0)
        printf(" %d ", k);
    while(k != 0)
    {
        for(i = 1; i <= n; i++)
            if((a[k][i] != 0) && (vis[i] == 0))
            {
                push(i);
                vis[i] = 1;
            }
        k = pop();
        if(k != 0)
            printf(" %d ", k);
    }
    for(i = 1; i <= n; i++)
        if(vis[i] == 0)
            dfs(i, n);
}

void display(int n)
{
    printf("\nThe Adjacency Matrix of the Graph is:\n\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf(" %d", a[i][j]);
        printf("\n");
    }
}

void main()
{
    int n, i, s, ch, j;
    printf("\nEnter no. of vertices: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        while(1)
        {
            printf("Enter where %d has nodes with ( 1-%d ) ( -1 to exit ): ", i, n);
            scanf("%d", &j);
            if(j == -1)
                break;
            else a[i][j] = 1;
        }
    }

    printf("\nMenu\n1. B.F.S\n2. D.F.S\n3. Display\n4. Exit");

    while(1)
    {
        for(i = 1; i <= n; i++)
            vis[i] = 0;

        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter the source vertex: ");
                scanf("%d", &s);
                bfs(s, n);
                break;
            case 2:
                printf("\nEnter the source vertex: ");
                scanf("%d", &s);
                dfs(s, n);
                break;
            case 3:
                display(n);
                break;
            case 4:
                exit(0);
        }
    }
}