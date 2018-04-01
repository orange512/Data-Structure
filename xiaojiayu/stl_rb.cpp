/*************************************************************************
	> File Name: 3.cpp
	> Author:    orange
	> Mail:      huiyi950512@gmail.com
	> Created Time: 2018年03月31日 星期六 13时52分06秒
 ************************************************************************/

#include <iostream>
#include<map>
using namespace std;

std::_Rb_tree<int,int,_Identity<int>,less<int>> mytree;
std::_Rb_tree<int,int,_Identity<int>,less<int>>::iterator iter;

auto jude = mytree.end();

int main()
{
    mytree._M_insert_unique(3);
    mytree._M_insert_unique(5);
    mytree._M_insert_unique(8);
    mytree._M_insert_unique(5);
    cout<<mytree.size()<<endl; //   3
    cout<<mytree.count(5)<<endl;//  1

    mytree._M_insert_equal(5);
    mytree._M_insert_equal(5);
    cout<<mytree.size()<<endl;//   5
    cout<<mytree.count(5)<<endl;// 3

   iter = mytree.find(5);
   if(iter == jude)
       cout<<"NULL";
   cout<<endl<<"search"<<*iter<<endl;
    for(iter = mytree.begin();iter != mytree.end();iter++)
        cout<<*iter<<"   ";

    return 0;

}
