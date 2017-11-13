/*************************************************************************
	> File Name: arr_queue.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 10时28分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Queue
{
    int cap;
    int front,rear;
    int count;
    int *array;
}Que;

Que *init(int n)
{
    Que *p = (Que*)malloc(sizeof(Que));
    p->cap = n;
    p->front = 0;
    p->rear = -1;
    p->count = 0;
    p->array = (int *)malloc(n*sizeof(int));
//    memset(p->array,0,sizeof(p->array));
    return p;
}
int Is_empty(Que *p)
{
    if(p->count == 0)
        return 1;
    else
        return 0;
}
int Is_full(Que *p)
{
    if(p->count == p->cap)
        return 1;
    else
        return 0;
}
int Que_size(Que *p)
{
    return p->count;
}
int En_Que(Que *p,int e)
{
    if(Is_full(p))
        return -1;
    else
    {
        if(p->rear == p->cap-1)
            p->rear = 0;
        else 
            p->rear++;
        p->count++;
    }
    p->array[p->rear] = e;
    return 1;
}
int De_Que(Que *p,int *e)
{
    if(Is_empty(p))
        return -1;
    else
    {
        *e = p->array[p->front++];
        p->count--;
        if(p->front == p->cap)
        {
            p->front = 0;
        }
    }
    return 0;
}
int Des_Que(Que *p)
{
    if(p == NULL)
        return -1;
    free(p->array);
    free(p);
}
int main()
{
    int n;
    int e;
    printf("请输入队列大小\n");
    scanf("%d",&n);
    Que *p = init(n);
    En_Que(p,3);
    En_Que(p,5);
    En_Que(p,6);
    En_Que(p,8);
    printf("队列元素个数%d\n",Que_size(p));
    De_Que(p,&e);
    printf("%d\n",e);
    De_Que(p,&e);
    printf("%d\n",e);
    
    printf("队列元素个数%d\n",Que_size(p));

    Des_Que(p);

}

