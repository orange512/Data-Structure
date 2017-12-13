/*************************************************************************
	> File Name: skiplist.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 13时42分36秒
 ************************************************************************/

#include"skiplist.h"
/**
 * Node head = new Node(-1);
 * random level = 2
 *3:
 *2:
 *1:
 *0:head->
 *data = -1;
 */
int search(Node *head,int value)
{
    Node *last = NULL;
    for(int i= max_level-1 ; i >= 0; --i )
    {
        while(NULL != head->nexts[i])
        {
            last = head->nexts[i];
            if(head->nexts[i]->data == value)
            {
                return 1;
            }
            if(head->nexts[i]->data > value)
            {
                break;    
            }
            head->nexts[i] = head->nexts[i]->nexts[i];
        }
        head->nexts[i] = last;

    }
    return 0;
}
/*void sort2_insert(Node* head,int value)//插入一个值并排序
{
    Node *node = create_node(value);
    Node *ptr1 = NULL;
    Node *ptr2 = NULL;
    int ran = myrandom(0,max_level-1);
    for(int i = 0;i<=ran;i++)
    {
        if(null == head->nexts[i])
        {
            head->nexts[i] = node;
            continue;
        }
        ptr1=head->nexts[i];
        ptr2=ptr1->nexts[i];
        while(ptr2 != NULL)
        {
            if(value <= ptr2->data && value >= ptr1->data)
            {
                node->nexts[i]=ptr2;
                ptr1->nexts[i]=node;
                break;
            }
            else
            {
                ptr1=ptr2;
                ptr2=ptr1->nexts[i];
            }
        }
        if(node->data > ptr1->data)
        {
            ptr1->nexts[i]=node;
        }
        else
        {
            node->nexts[i]=ptr1;
            head->nexts[i]=node;
        }

    }

}*/
void InsertList(Node **L,int m)
{
    Node *t,*s;
    t = create_node(m);
    s=*L;
    int ran = myrandom(0,max_level-1);
    for(int i = 0;i<=ran;i++)
    {
        if(NULL == s->nexts[i])
        {
            s = t;
            continue;
        }
        while(s->nexts[i]->data<m) s=s->nexts[i];        
        t->nexts[i]=s->nexts[i];
        s->nexts[i]=t;
    }

}
int main()
{
    srand((unsigned)time(0));
    Node *head = create_node(-1);
    while(1)
    {
        int data;
        scanf("%d",&data);
        if(data == 0)
            break;
        //head_insert(head,data);
        InsertList(&head,data);
    }
    
    print_node(head);
    if(search(head,2))
        printf("found\n");
    else
    {
        printf("not found\n");
    }
}
