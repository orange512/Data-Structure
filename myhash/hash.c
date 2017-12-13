/*************************************************************************
	> File Name: hash.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 10时50分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
/*
 *   1.定义数组
 *   2.存放数据
 *      1.hash(value)====>index====>数组下标
 *      2.根据下标判断是否冲突
 *      3.如果不冲突将冲突将数据直接存放
 *      4.如果冲突则线性增长
 * */
typedef struct
{
    int key;
    int crash;
}Datatype;
typedef struct hash
{
    Datatype *data;
    int tablesize;
}HashTable;
void create_hash(HashTable *hash,int arr,int n)
{
    
    Datatype *data = (Datatype*)malloc(n*sizeof(Datatype));
    for(int i = 0 ;i < n;i++)
    {
        hash->data[i].key = -1;
        hash->data[i].crash = -1;
    }
    hash->tablesize = n;
    int index;
    for(int i = 0 ; i < 10;i++)
    {
        index = arr[i] % n;
        if(hash.data[i].key == -1)
            hash.data[i].key = arr[i];
        else
            
    }
}
int main()
{
    int arr[10];
    for(int i= 0 ; i < 10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int hash[10];
    for(int i = 0 ; i  < 10;i++)
    {
        hash[i] = -1;
    }
    

}
