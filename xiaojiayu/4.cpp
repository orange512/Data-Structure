/*************************************************************************
	> File Name: 4.cpp
	> Author:    orange
	> Mail:      huiyi950512@gmail.com
	> Created Time: 2018年03月31日 星期六 19时00分12秒
 ************************************************************************/

#include <iostream>
using namespace std;

int fun()
{
    const int a = 100;
    int *p = (int *)&a;
    *p = 200;
    cout<<a<<"  "<<*p<<endl;
    return 0;
}


int main()
{
    fun();
}
