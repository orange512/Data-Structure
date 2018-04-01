/*************************************************************************
	> File Name: fapai.c
	> Author:    orange
	> Mail:      huiyi950512@gmail.com
	> Created Time: 2018年03月29日 星期四 16时10分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemenType;
typedef struct node
{
    ElemenType data;
    struct node *next;
}Node;

Node *create_list()
{
    Node *head = NULL;
    Node *cur = NULL;
    Node *temp = NULL;

    cur = head;
    for(int i = 0 ; i < 13;i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        temp ->data = 0;
        if(head ==  NULL)
            head = temp;
        else
            cur->next = temp;

        cur = temp;
    }
    cur->next = head;
    return head;
}
void Magician(Node *head)
{
    Node *p;
    int count_number = 2;
    p = head;
    p->data = 1;

    while(1)
    {
        for(int j = 0 ; j < count_number;j++)
        {
            p = p->next;
            if(p->data != 0)
            {
                p = p->next;
                j--;
            }
        }
        if(p->data == 0)
        {
            p->data = count_number;
            count_number++;
            if(count_number == 14)
                break;
        }
    }
}
int main()
{
    Node *head = create_list();
    Magician(head);
    printf("按以下序列输出\n");
    for(int i = 0 ; i < 13;i++)
    {
        printf("黑桃%d\n",head->data);
        head = head ->next;
    }
    return 0;
}
