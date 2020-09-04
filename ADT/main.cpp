//
//  main.cpp
//  ADT
//
//  Created by Jalor on 2020/9/1.
//  Copyright © 2020 Jalor. All rights reserved.
//

#include <iostream>
#include "SEQLIST.hpp"
#include "LINKLIST.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int a[] = {1,2,3,4,5,6,7,8,9};
    LinkList<int>l;
    cout<<"=========链表判断空=========="<<endl;
    cout<<l.Empty()<<endl;
    
    l = LinkList<int>(a,9);
    //SeqList<int>s = SeqList<int>(a, 7);
    //s.Insert(2, 10);
    cout<<"=========获得第三个数据========="<<endl;
    cout<<l.Get(3)<<endl;
    cout<<"=========获得1数据的位置=========="<<endl;
    cout<<l.Locate(1)<<endl;
    
    l.Insert(9, 10);
    cout<<"=========删除第4个数据=========="<<endl;
    cout<<l.Delete(4)<<endl;
    cout<<"=========链表的长度=========="<<endl;
    cout<<l.Length()<<endl;
    cout<<"=========链表判断空=========="<<endl;
    cout<<l.Empty()<<endl;
    cout<<"=========打印=========="<<endl;
    l.PrintList();
    cout<<"==================="<<endl;
    //s.Delete(1);
    //s.PrintList();
    return 0;
}
