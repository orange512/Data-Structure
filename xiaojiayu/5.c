/*************************************************************************
	> File Name: 5.c
	> Author:    orange
	> Mail:      huiyi950512@gmail.com
	> Created Time: 2018年03月29日 星期四 20时06分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define N 3
void swap(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rotate(int a[][N],int n)
{
	int start = 0;
	int last = n;
	//交换矩阵中的行
    for(int i = 0 ; i < N;i++)
	{
		for(int j = 0 ; j < N;j--)
        {
            swap(&a[i][j],&a[i+N-1][j]);
        }
	}
	//交换a[i][j]和a[j][i]
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			swap(&a[i][j], &a[j][i]);
		}
	}
int main()
{
    int a[N][N];
    for(int i = 0 ; i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    return 0;
}
