/*************************************************************************
	> File Name: 3.c
	> Author:    orange
	> Mail:      huiyi950512@gmail.com
	> Created Time: 2018年03月29日 星期四 19时24分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void move_array(int a[],int n)
{
    int i,j = 0;
    for(i= 0;i<n;i++)
    {
        if(a[i] != 0 )
        {
            a[j] = a[i];
            j++;
        }
        /* while(1) */
        /* { */
        /*     if(a[i] != 0) */
        /*     { */
        /*         i++; */
        /*     } */
        /*     else */
        /*         break; */
        /* } */
        /* while(1) */
        /* { */
        /*     if(a[j] == 0) */
        /*     j++; */
        /*     else */
        /*         break; */
        /* } */
        /* swap(&a[i],&a[j]); */
        /* i++; */
    }
    for(;j < n;j++)
    {
        a[j] = 0;
    }
}
int main()
{
    int n =0;
    scanf("%d",&n);

    int a[n];
    for(int i = 0 ; i < n ; i ++)
    {
        scanf("%d",&a[i]);
    }
    move_array(a,n);
    for(int i = 0 ; i < n;i++)
    {
        printf("%d\n",a[i]);
    }
}
