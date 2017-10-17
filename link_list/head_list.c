/*************************************************************************
	> File Name: head_list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月26日 星期二 16时33分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int ElementType;
struct Node
{
    ElementType data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node  Nodelist;
typedef struct Node* DNodePoint;


int init(DNodePoint *head)
{
    *head = (Nodelist*)malloc(sizeof(Nodelist));
    (*head) -> data = 0;
    (*head) -> left = NULL;
    (*head) -> right = NULL;
    return 1;
}
Nodelist tail_Insert(DNodePoint *head,ElementType elem)
{
    Nodelist* p = (Nodelist*)malloc(sizeof(Nodelist));
    p -> data = elem;
    p -> right = NULL;

    while((*head) -> right != NULL)
    {
        (*head)->right = (*head) ->right;        
    }
    (*head)->right = p;
    return head;
}


int main()
{
    
}
