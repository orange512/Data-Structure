/*************************************************************************
	> File Name: perm.c
	> Author:    orange
	> Mail:      huiyi950512@gmail.com
	> Created Time: 2018年03月31日 星期六 11时09分31秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void swap(char *a,char *b)
{
    char ch = *a;
    *a = *b;
    *b = ch;
}
int judge(char a[],int k,int i)
{
    if(i > k)//  每层循环的后几位与最开始的比较
    {
        for(int t = k;t < i;t++)//每层交换的基准ｉ与当前循环的Ｋ
        {
            if(a[t] == a[i])
                return 0;
        }
    }
    return 1;//自己与自己交换
}
void Perm(char a[],int n,int k)
{
    if( k == n )
    {
        for(int i  = 0; i < n;i++)
        {
            printf("%c",a[i]);
        }
        putchar(10);
    }

    for(int i = k ; i < n;i++)
    {
        if(judge(a,k,i))
        {
            swap(&a[i],&a[k]);
            Perm(a,n,k+1);
            swap(&a[i],&a[k]);
        }
    }
}
int main()
{
    char a[] = "AABC";
    Perm(a,4,0);
}
