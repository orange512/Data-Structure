/*************************************************************************
	> File Name: point_stack.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月26日 星期四 20时58分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int top;
    int size;
    int *data;
}Stack;
Stack* init(int n)
{
    Stack* p  = (Stack*)malloc(sizeof(Stack));
    p->data = (int *)malloc(n*sizeof(int));
    p->size = n;
    p->top = -1;
    return p;
}
_Bool IsEmpty(Stack *stack)
{
    if(stack->top < 0)
    {
        printf("stack is empty\n");
        return 1;
    }
    else
        return 0;
}
_Bool IsFull(Stack* stack)
{
    if(stack->top == stack->size-1)
    {
        printf("stack is full\n");
        return 1;
    }
    else
        return 0;
}
_Bool stackPush(Stack* stack,int elem)
{
    if(IsFull(stack))
        return -1;
    else
    {
        stack->data[++stack->top] = elem;
        return 0;
    }
}
_Bool stackPop(Stack *stack,int *elem)
{
    if(IsEmpty(stack))
        return -1;
    else
    {
        *elem = stack->data[stack->top--];
        return 0;
    }
}
int stackPeek(Stack *stack)
{
    if(IsEmpty(stack))
        return -1;
    else
        return stack->data[stack->top];
}
_Bool destroy(Stack *stack)
{
    if(stack == NULL)
        return -1;
    else
    {
        free(stack->data);
        free(stack);
        return 0;
    }
}
int main()
{
    int elem;
    Stack *stack = init(20);
    stackPush(stack,3);
    stackPush(stack,5);
    stackPop(stack,&elem);
    printf("elem:%d\n",elem);
    stackPop(stack,&elem);
    printf("elem:%d\n",elem);
    destroy(stack);
    return 0;
}
