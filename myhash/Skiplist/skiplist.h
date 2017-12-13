/*************************************************************************
	> File Name: skiplist.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 15时30分45秒
 ************************************************************************/

#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
static int max_level = 4;
typedef struct node
{
    int data;
    struct node *nexts[0];
}Node;
Node* create_node(int data)
{
    Node *node = (Node*)malloc(sizeof(Node)+max_level*sizeof(Node*));
  //  node->nexts = (Node*)malloc(level*sizeof(Node*));
    node->data = data;
    return node;
}
int randomlevel(int max)
{
    int level = 1;
    while(rand()%2)
    {
        ++level;
    }
    return max>level?level:max;
}
int myrandom(int n,int m)
{
    return rand()%(m-n+1)+n;
}
void head_insert(Node *head,int data)
{
    Node *node = create_node(data);
    //ran = randomlevel(4);
    int ran = myrandom(0,max_level-1);
    for(int i = 0; i <= ran;i++)
    {
        if(NULL != head->nexts[i])
            node->nexts[i] = head->nexts[i];
        head->nexts[i] = node;
    }
}
void sort_insert(Node *head,int value)
{
    Node *node = create_node(value);
    int ran = myrandom(0,max_level-1);
    Node *temp = NULL;
    for(int i = 0 ; i <= ran;i++)
    {
        while(NULL != head->nexts[i])
        {
            if(head->nexts[i]->data > value)
            {
                node->nexts[i] = head->nexts[i];
            }
            head->nexts[i] = head->nexts[i]->nexts[i];
        }
    }
} 
void print_node(Node *head)
{
    for(int i = max_level-1;i>=0;--i)
    {
        Node *temp = head->nexts[i];
        printf("第%d层:",i);
        while(NULL != temp)
        {
            printf("%d--->",temp->data);
            temp = temp->nexts[i];
        }
        putchar(10);
    }

}
#endif
