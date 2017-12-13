/*************************************************************************
	> File Name: hash2.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 11时10分17秒
 ************************************************************************/

#include<stdio.h>


int hash(int value)
{
    return value % 5;
}
void set(int value,int hash_arr[])
{
    int key = hash(value);
    while(hash_arr[key] != -1)
    {
        key = hash(key+1);
    }
    hash_arr[key] = value;
}
int search(int value,int hash_arr[],int n)
{
    int key = hash(value);
    while(0!= n &&hash_arr[key] != value)
    {
        key = hash(key+1);
        n--;
    }
    return 0==n?-1:key;
}
int main()
{
    int data[5];
    for(int i = 0 ; i < 5;i++ )
    {
        scanf("%d",&data[i]);
    }
    int hash_arr[5];
    for(int i = 0 ; i < 5;i++)
    {
        hash_arr[i] = -1;
    }

    for(int i = 0;i < 5;i++)
    {
        set(data[i],hash_arr);
    }

    for(int i = 0 ; i < 5;i++)
    {
        printf("%5d",hash_arr[i]);
    }
    putchar(10);

    printf("input search key:");
    int a ;
    scanf("%d",&a);
    if(search(a,hash_arr,5) != -1)
        printf("找到元素下标为:%d\n",search(a,hash_arr,5));
    else
        printf("not found\n");
    return 0;
}
