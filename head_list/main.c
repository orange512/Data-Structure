/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月06日 星期五 21时31分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"head_list.h"
#include<malloc.h>
void DelElem(LinkList A,LinkList B)
{
    int i,position;
    int e;
    ListNode *p;
    for(i = 1;i<ListLenth(B);i++)
    {
        p = Get(B,i);
        if(p)
        {
            position = LocatePosition(A,p->data);
            if(position > 0)
                DeleteList(A,position,&e);
        }
    }
}
int main()
{
    int i;
    int a[] = {2,3,6,7,9,12,34,65,77};
    int b[] = {3,7,11,34,54,45.67};
    LinkList A,B;
    int e;
    ListNode *p;
    InitList(&A);
    InitList(&B);
    for(i = 1;i <= sizeof(a)/sizeof(int);i++)
    {
        if(InsertList(A,i,a[i-1]) == 0)
        {
            printf("插入失败\n");
            return -1;
        }
    }
    for(i = 1;i <= sizeof(b)/sizeof(int);i++)
    {
        if(InsertList(B,i,b[i-1]) == 0)
        {
            printf("插入失败\n");
            return -1;
        }
    }
    printf("A链表的长度为:%d\n",ListLenth(A));
    printf("B链表的长度为:%d\n",ListLenth(B));
    for(i = 1; i <= ListLenth(A);i++)
    {
        p = Get(A,i);
        if(p)
            printf("%4d",p->data);
    }
    putchar(10);

    for(i = 1; i <= ListLenth(B);i++)
    {
        p = Get(B,i);
        if(p)
            printf("%4d",p->data);
    }
    putchar(10);
    DelElem(A,B);
    printf("将在A中出现的B元素删除后（A-B),现在A中的元素个数还有%d个\n",ListLenth(A));
    for(i = 1; i <= ListLenth(A);i++)
    {
        p = Get(A,i);
        if(p)
            printf("%4d",p->data);
    }
    putchar(10);

}

