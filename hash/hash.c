/*************************************************************************
	> File Name: hash.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 20时43分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct   //元素类型定义
{
    int key;    //关键字
    int hi;    //冲突次数
}DataType;

typedef struct  //哈希表的类型
{
    DataType *data;
    int tablesize;   //哈希表的长度
    int cursize;     //关键字个数
}HashTable;

void create_hash(HashTable *H,int m,int p,int hash[],int n)
{
    int sum;    //冲突的次数
    int addr;   //记录哈希函数的地址
    int di;     //保存冲突后的位置
    int k=1;    //k为线性增长的长度

    H->data=(DataType*)malloc(m*sizeof(DataType));

    for(int i = 0;i < m;i++)   //初始化哈希表
    {
        H->data[i].key = -1;
        H->data[i].hi = 0;
    }

    for(int i = 0;i < n;i++)
    {
        sum = 0;
        addr=hash[i] % p; //利用余数法求哈希函数地址

        if(H->data[addr].key == -1)   //如果不冲突则将元素存储到表中
        {
            H->data[addr].key = hash[i];
            H->data[addr].hi = 0;
        }
        else
        {
            di = addr;
            do{
                di = (di + k) % m;
                sum += 1;
            }while(H->data[di].key != -1);
            (*H).data[di].key=hash[i];
            (*H).data[di].hi=sum+1;
        }

        H->tablesize = m;  //哈希表的长度
        H->cursize = n;
    }
}

void display_hash(HashTable H,int m )
{
    printf("哈希表的地址:");
    for(int i = 0; i < m;i++)
        printf("%-5d",i);
    putchar(10);
    printf("关键字key:  ");
    for(int i = 0; i < m;i++)
        printf("%-5d",H.data[i].key);
    putchar(10);
    printf("冲突次数:    ");
    for(int i = 0; i < m;i++)
        printf("%-5d",H.data[i].hi);
    putchar(10);
    
}
int  serch_hash(HashTable H,int k)
{
    int d,d1,m;
    m = H.tablesize;
    d = d1 = k % m;
    while(H.data[d].key != -1)
    {
        if(H.data[d].key == k)
            return d;
        else
            d = (d+1)%m;
        if(d == d1)
            return 0;
    }
}
int main()
{
    int hash[]={23,35,12,56,123,39,342,90};
    int m=11,p=11,n=8,pos;
    int k;
    HashTable H;
    create_hash(&H,m,p,hash,n);
    display_hash(H,m);

    k = 123;
    pos = serch_hash(H,k);
    printf("要查的关键字为%d   位置在%d\n",k,pos);
    return 0;
}
