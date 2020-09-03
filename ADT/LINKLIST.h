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

/*建立长度为n的c链表*/
template <typename DataType>
LinkList<DataType>::LinkList(DataType a[],int n){
    first = new Node<DataType>;
    Node<DataType> *ptr = nullptr;//指针
    for (int i = 0; i < n; i ++) {
        Node<DataType> *node = new Node<DataType>;//新对象
        if(i == 0) first -> next = node;
        else ptr -> next = node;//上一个对象的下一个对象指向这个
        node -> data = a[i];
        node -> next = nullptr;
        ptr = node;
    }
}

/*打印链表*/
template <typename DataType>
void LinkList<DataType>::PrintList() {
    Node<DataType> * p = first -> next;
    while (p) {
        cout<<p -> data <<"\t";
        p = p -> next;
    }
    cout<<endl;
}

#endif /* LINKLIST_h */
