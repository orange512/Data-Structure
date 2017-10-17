/*************************************************************************
	> File Name: circle_list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月11日 星期三 21时05分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct  Node ListNode;
typedef struct  Node *Linklist;

Linklist Creat_list(int n)//创建一个不带头节点的循环链表
{
    int e;
    ListNode *p,*q;
    p = NULL;
    q = NULL;
    Linklist head = NULL;
    int i = 1;//节点索引号
    while(i <= n)
    {
        printf("请输入要添加%d的元素",i);
        scanf("%d",&e);
        if(i == 1)//创建第一个节点
        {
            head = (Linklist)malloc(sizeof(ListNode));
            head -> data = e;
            head -> next = NULL;
            q = head;//指针指向最后一个节点
        }
        else
        {
            p = (Linklist)malloc(sizeof(ListNode));
            q -> next = p;
            p -> data = e;
            p -> next = NULL;
            q = p;
        }
        i++;
    }
    if(q != NULL)
        q -> next = head;//将最后一个节点指向head
    return head;
}
void Display_ciclelist(ListNode* head)
{
    ListNode *p;
    p = head;
    if( p == NULL )
    {
        printf("链表是一个空链表\n");
        return ;
    }
    else
    {
        while((p -> next) != head)
        {
            printf("%4d",p->data);
            p = p->next;
        }
        printf("%4d\n",p->data);
    }
}
int main()
{
    Linklist h;
    int n;
    printf("这是一个创建循环链表\n");
    printf("请输入你要创建的循环链表个数\n");
    scanf("%d",&n);
    h = Creat_list(n);
    printf("显示循环链表\n");
    Display_ciclelist(h);
    return 0;
}
