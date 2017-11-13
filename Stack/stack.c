/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月26日 星期四 20时33分17秒
 ************************************************************************/

#include<stdio.h>
int index = -1;
int stackEmpty(int stack[])
{
    if(index < 0)
        return 1;
    else
        return 0;
}
int stackFull(int *stack)
{
    if(index > 100)
        return 1;
    else
        return 0;
}

int Push(int *stack,int elem)
{
    if(stackFull(stack))
        return -1;
    else
    {
        index++;
        stack[index] = elem;
    }
    return 0;
}
int Pop(int *stack,int *elem)
{
    if(stackEmpty(stack))
        return -1;
    else
    {
        index--;
        *elem = stack[index];
    }
    return 0;
}
int Peek()
int main()
{
    int stack[20];
}
