/*************************************************************************
	> File Name: gernal_tree.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 20时14分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}Node;
Node *root = NULL;
void Insert_tree(int data)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->lchild = NULL;
    p->rchild = NULL;
    p->data = data;
    if(root == NULL)
    {
        root = p;
    }
    else
    {
        Node *current = root;
        Node *parent = NULL;
        while(1)
        {
            parent = current;
            if(current->data > data)
            {
                current = current->lchild;
                if(current == NULL)
                {
                    parent->lchild = p;
                    return;
                }
            }
            else
            {
                current = current->rchild;
                if(current == NULL)
                {
                    parent->rchild = p;
                    return;
                }
            }

        }
    } 
}

Node *search_tree(int data)
{
    Node* current = root;
    if(current == NULL)
    {
        return NULL;
    }
    while(current != NULL && current->data != data)
    {
        printf("visited data %d  ",current->data);
        if(current->data > data)
        {
            current = current->lchild;
        }
        else
        {
            current = current->rchild;
        }

    }
    return current;
}
void pre_order_view(Node *root)
{
    if(root == NULL)
        return;
    printf("%d\t",root->data);
    pre_order_view(root->lchild);
    pre_order_view(root->rchild);
}
void in_order_view(Node *root)
{
    if(root == NULL)
        return;
    in_order_view(root->lchild);
    printf("%d\t",root->data);
    in_order_view(root->rchild);
}
void post_order_view(Node *root)
{
    if(root == NULL)
    return;
    post_order_view(root->lchild);
    post_order_view(root->rchild);
    printf("%d\t",root->data);
}
int main()
{
    int i;
    int array[7] = {27, 14, 35, 10, 19, 31, 42};

    for (i = 0; i < 7; i++)
    Insert_tree(array[i]);

    i = 31;
    Node *temp = search_tree(i);
    if(temp == NULL)
    {
        printf("element %d not found!\n", i);

    }
    else
    {
        printf("element %d found!\n", temp->data);

    }

    i = 15;
    temp = search_tree(i);
    if(temp == NULL)
    {
        printf("element %d not found!\n", i);

    }
    else
    {
        printf("element %d found!\n", temp->data);

    }
    printf("前序遍历结果:");
    pre_order_view(root);

    printf("\n中序遍历结果:");
    in_order_view(root);

    printf("\n后序遍历结果:");
    post_order_view(root);

    return 0;

}
