/*************************************************************************
	> File Name: head_list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月06日 星期五 20时47分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"head_list.h"

void InitList(LinkList *head)//初始化链表
{
    if((*head = (LinkList)malloc(sizeof(ListNode))) == NULL)
        exit(-1);
    (*head) -> next = NULL;
}
//判断链表是否为空
int ListEmpty(LinkList head)
{
    if(head->next == NULL)
        return 1;
    else
        return 0;
}
//按序号查找操作
ListNode *Get(LinkList head,int i)
{
    ListNode *p;
    int j = 0;
    if(ListEmpty(head))
        return NULL;
    if(i < 1)
        return NULL;
    p = head;
    while(p->next != NULL && j < i)
    {
        p = p -> next;
        j++;
    }
    if(j == i)
        return p;
    else
        return NULL;
}
//按内容查找
ListNode *LocateElem(LinkList head,ElementType e)
{
    ListNode *p;
    p = head -> next;
    while(p)
    {
        if(p -> data != e)
            p = p -> next;
        else
            break;
    }
    if(!p)
        return NULL;
    else
        return p;
}
//定位操作
int LocatePosition(LinkList head,ElementType e)
{
    ListNode *p;
    p = head->next;
    int i = 1;
    if(ListEmpty(head))
        return 0;
    while(p)
    {
        if(p -> data == e)
            return i;
        else
        {
            p = p -> next;
            i++;
        }
    }
    if(!p)
        return 0;

}
//插入操作
int InsertList(LinkList head,int i,ElementType e)
{
    ListNode *p,*pre;//p是新生成的节点 pre是第i个节点的前一个节点
    int j = 0;
    pre = head;
    while(pre -> next != NULL && j < i-1)
    {
        pre = pre -> next;
        j++;
    }
    if( j != i-1 )
    {
        printf("插入位置有误!\n");
        return 0;
    }
    p = (LinkList)malloc(sizeof(ListNode));
    p -> data = e;
    p -> next = pre -> next;
    pre -> next = p;
    return 1;
}
int DeleteList(LinkList head,int i,ElementType *e)
{
    ListNode *pre,*p;
    int j = 0;
    pre = head;
    while(pre -> next != NULL && pre->next->next != NULL && j < i-1)
    {
        pre = pre -> next;
        j++;
    }
    if(j != i-1)
    {
        printf("删除的位置错误！\n");
        return 0;
    }
    p = pre -> next;
    *e = p -> data;
    pre -> next = p -> next;
    free(p);
    return 1;
}
//求表长操作
int ListLenth(LinkList head)
{
    ListNode *p;
    p = head;
    int count = 0;
    while(p -> next != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}
//销毁链表
void DestroyList(LinkList head)
{
    ListNode *p,*q;
    p = head;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
}

