/*************************************************************************
	> File Name: fapai.c
	> Author:    orange
	> Mail:      huiyi950512@gmail.com
	> Created Time: 2018年03月29日 星期四 15时27分06秒
 ************************************************************************/

//约瑟夫问题　每隔Ｎ＋１人自杀　剩最后两个人是他和朋友
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct node  
{
    ElementType data;
    struct node *next;
}Node;

Node* init_list(int n)
{
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *p = NULL;
    p = head;
    Node *s = NULL;

    if( 0 != n )
    {
        for(int i = 1 ; i <= n;i++)
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = i;
            p->next = s;
            p = s;
        }
        s->next = head->next;
    }

    free(head);
    return s->next;
}
int main()
{
    int n = 41;
    int m = 3;
    int i;
    Node *p = init_list(n);
    Node *temp = NULL;
    
    m %= n;

    while ( p != p->next )
    {
        for(i = 1;i < m -1;i++)
        {
            p = p->next;
        }
        printf("%d->",p->next->data);
        temp = p->next;
        p->next = temp->next;
        free(temp);

        p= p->next;
    }
    printf("%d\n",p->data);
    return 0;

}

