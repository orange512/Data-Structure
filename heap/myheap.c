/*************************************************************************
	> File Name: myheap.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月14日 星期二 20时00分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
//大顶堆
typedef struct heap
{
    int *pdata;
    int nsize;
}Heap;

int increase_key(Heap*h,int pos)//进行比较并调整插入节点的位置
{
    while(pos>1)//循环和他的父亲节点比较
    {
        int temp = h->pdata[pos];
        int parent = pos/2;
        if(temp > h->pdata[parent])
        {
            h->pdata[pos] = h->pdata[parent];
            h->pdata[parent] = temp;
            pos = parent;
        }
        else
            break;
    }
}
Heap* init(int n)
{
    Heap *h = (Heap*)malloc(sizeof(Heap));
    h->pdata = (int *)malloc(n*sizeof(int));
    h->nsize = 0;
}
int insert_heap(Heap* h,int data)
{
    h->nsize++;//数组0号不用，为了获得父亲不能要0号节点
    h->pdata[h->nsize] = data;
    increase_key(h,h->nsize);
    return 1;
}
int pop_max_heap(Heap *h)
{
    int max = h->pdata[1];
    int pos = 1;
    int child = pos *2;
    while(child <= h->nsize)
    {
        int temp = h->pdata[child];
        if(child+1 <= h->nsize && temp < h->pdata[child+1])
        {
            temp = h->pdata[++child];//比较孩子那个大temp保存那个
        }
        h->pdata[pos] = temp;
        pos = child;
        child *= 2;
    }
    h->pdata[pos] = h->pdata[h->nsize];//将那个空结点放到末尾;
    h->nsize--;
    return max;    
}

int main()
{
    Heap *h = init(12);
    for(int i = 1 ; i <= 10;i++)
        insert_heap(h,i);
    for(int j = 1; j <= 10;j++ )
        printf("%d ",h->pdata[j]);
    putchar(10);
    while(h->nsize > 0)
    {
        printf("%d ",pop_max_heap(h));
    }
    putchar(10);
    return 0;
}
