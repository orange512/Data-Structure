/*************************************************************************
	> File Name: DFS.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月26日 星期日 11时07分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int arr[5][5]={0};
int input_edge()
{
    int vertex[5]={'A','B','C','D','E'};
    int n;
    char a,b;
    int a1,a2;
    printf("请输入边的个数\n");
    scanf("%d",&n);
    while(n--)
    {
        printf("顶点为ABCDE，请输入边\n");
        scanf("%c %c",&a,&b);
        for(int i=0;i<5;i++)
        {
            if(vertex[i]==a)
                a1=i;
        }
        for(int i=0;i<5;i++)
        {
            if(vertex[i]==b)
                a2=i;
        }
        arr[a1][a2]=1;
        arr[a2][a1]=1;
    }
}
