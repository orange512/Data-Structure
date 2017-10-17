/*************************************************************************
	> File Name: head_list.h
	> Author: 
	> Mail: 
	> Created Time: 2017年10月06日 星期五 21时29分10秒
 ************************************************************************/

#ifndef _HEAD_LIST_H
#define _HEAD_LIST_H
typedef int ElementType;
struct Node
{
    ElementType data;
    struct Node *next;
};
typedef struct Node ListNode,*LinkList;
void InitList(LinkList *head);//初始化链表
int ListEmpty(LinkList head);
ListNode *Get(LinkList head,int i);
ListNode *LocateElem(LinkList head,ElementType e);
int LocatePosition(LinkList head,ElementType e);
int InsertList(LinkList head,int i,ElementType e);
int DeleteList(LinkList head,int i,ElementType *e);
int ListLenth(LinkList head);
void DestroyList(LinkList head);
#endif
