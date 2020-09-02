//
//  LINKLIST.h
//  ADT
//
//  Created by Jalor on 2020/9/2.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef LINKLIST_h
#define LINKLIST_h
#include <iostream>
#include "NODE.h"
using namespace std;

template <typename DataType>
class LinkList {
public:
    LinkList();//建立空的链表
    LinkList(DataType a[],int n);//建立长度为n的c链表
    ~LinkList(){}//x析构函数
    int Length();//求线性表的长度
    DataType Get(int i);//按位查找，查找第i个元素的值
    int Locate(DataType x);//按值查找，查找值为x的元素的序号
    void Insert(int i, DataType x);//插入操作，在第i位插入值为x的元素
    DataType Delete(int i);//删除操作
    int Empty();//判断线性表是否为空
    void PrintList();//打印线性表
private:
    Node<DataType>* first;
};

/*创建链表*/
template <typename DataType>
LinkList<DataType>::LinkList() {
    first = new Node<DataType>;
    first -> next = nullptr;
}

#endif /* LINKLIST_h */
