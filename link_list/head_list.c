/*************************************************************************
	> File Name: head_list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月26日 星期二 16时33分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char ElementType;
struct Node
{
    ElementType data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node  DNodelist;
typedef struct Node* DLinklist;

int init(DLinklist *head)
{
    *head = (DNodelist*)malloc(sizeof(DNodelist));
    (*head) -> data = 0;
    (*head) -> left = NULL;
    (*head) -> right = NULL;
    return 1;
}
int create_Dlist(DLinklist head,int n)
{
    DNodelist *p = NULL;
    DNodelist *q = NULL;
    char e;
    q = head;//指向最后一个结构体
    for(int i = 1 ; i <= n;i++)
    {
        printf("请输入%d插入的元素\n",i);
        e = getchar();
        p = (DNodelist *)malloc(sizeof(DNodelist));
        p->data = e;
        p->right = q->right;
        p->left = q;
        q->left = p;
        head->right = p;
        q = p;
        getchar();
    }
    return 1;
}
int Print(DNodelist* head)
{
    DNodelist *p = NULL;
    p = head->right;
    while(1)
    {
        if(p == head)
            break;
        printf("%c ",p->data);
    printf(".....222222222222\n");
        p = p->right;
    printf("ffffff22222\n");
    }
    putchar(10);
    return 1;
}

DNodelist * GetElem(DLinklist head,int i)
{
    DNodelist *p;
    int j =1;
    p = head->right;
    while(p!=head && j < i)
    {
        p = p->right;
        j++;
    }
    if(p == head || j > i)
        return NULL;
    return p;
}
int Insert_Dlist(DLinklist head,int i,char e)
{
    DNodelist *p,*s;
    p = GetElem(head,i);
    if(!p)
        return -1;
    s = (DNodelist*)malloc(sizeof(DNodelist));
    s->data = e;
    s->left = p->left;
    p->left->right = s;
    s->right = p;
    p->left = s;
    return 1;
}

int main()
{
    DLinklist h;
    int n;
    init(&h);
    printf("请输入链表的长度：");
    scanf("%d",&n);
    printf("ffffff\n");
    create_Dlist(h,n);
    getchar();
    Print(h);
    return 0;
}
