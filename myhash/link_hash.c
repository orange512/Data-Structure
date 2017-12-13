/*************************************************************************
	> File Name: link_hash.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 11时42分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;
void init_head_node(Node *p)
{
    p->value = -1;
    p->next = NULL;
}

int hash(int value)
{
    return value % 5;
}

void set(int data,Node* hash_arr[])
{
    int key = hash(data);
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->value = data;
    if(hash_arr[key]->next != NULL)
    {
        temp->next = hash_arr[key]->next;
    }
    hash_arr[key]->next = temp;
}
void print_hash(Node *hash_arr[])
{
    for(int i = 0 ; i < 5;i++)
    {
        Node *p = hash_arr[i];
        p = p->next;
        printf("list[%d]---->",i+1);
        while(p!=NULL)
        {
            printf("%d--->",p->value);
            p = p->next;
        }
        putchar(10);
    }
}

int main()
{
    Node* hash_arr[5];
    for(int i = 0 ; i < 5;i++)
    {
        hash_arr[i] = (Node*)malloc(sizeof(Node));
        init_head_node(hash_arr[i]);
    }
    while(1)
    {
        int data;
        scanf("%d",&data);
        if(data == 0)
            break;
        set(data,hash_arr);
    }
    print_hash(hash_arr);

}
