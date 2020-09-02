//
//  SQELIST.hpp
//  ADT
//
//  Created by Jalor on 2020/9/1.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef SQELIST_hpp
#define SQELIST_hpp

#include <iostream>
using namespace std;

const int Maxsize = 100;

template<typename DataType>
class SeqList
{
public:
    SeqList(){}//建立空的顺序表
    SeqList(DataType a[],int n);//建立长度为n的c顺序表
    ~SeqList(){}//x析构函数
    int Length();//求线性表的长度
    DataType Get(int i);//按位查找，查找第i个元素的值
    int Locate(DataType x);//按值查找，查找值为x的元素的序号
    void Insert(int i, DataType x);//插入操作，在第i位插入值为x的元素
    DataType Delete(int i);//删除操作
    int Empty();//判断线性表是否为空
    void PrintList();//打印线性表
private:
    DataType data[Maxsize];//存放数据元素的数组
    int length;//长度
};

/*构造函数
 建立长度为n的顺序表*/
template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
    if(n > Maxsize) throw "parama illege";
    for(int i = 0; i < n; i++){
        data[i] = a[i];
    }
    length = n;
}

/*返回顺序表的长度*/
template <typename DataType>
int SeqList<DataType>::Length()
{
    return length;
}

/*按位查找*/
template <typename DataType>
DataType SeqList<DataType>::Get(int i){
    if(i < 0 || i > length) throw "illage num";
    return data[i];
}

/*按值查找*/
template <typename DataType>
int SeqList<DataType>::Locate(DataType x){
    for (int i = 0; i < length; i++) {
        if(data[i] == x){
            return i+1;//如果查找成功，则返回元素的序号（不是下标）
        }
    }
    return -1;
}

/*往第i个位置插入值x*/
template <typename DataType>
void SeqList<DataType>::Insert(int i, DataType x){
    if(length == Maxsize)throw "array flow";
    if(i < 0 || i > length)throw "array insert pos error";
    for (int j = length; j >= i; j--) {
        data[j] = data[j - 1];//第j个元素存在第j-1个下标处
    }
    data[i-1] = x;
    length++;
}

/*删除第i个位置的值x，并展示出来*/
template <typename DataType>
DataType SeqList<DataType>::Delete(int i){
    if(length == 0)throw "array flow";
    if(i < 1 || i > length)throw "array insert pos error";
    DataType x = data[i - 1];
    for (int j = i - 1; j < length - 1; j++) {
        data[j] = data[j+1];//第j个元素存在第j-1个下标处
    }
    length --;
    return x;
}

/*判断是否为空 0 = 为空， 其他数字 = 不为空*/
template <typename DataType>
int SeqList<DataType>::Empty()
{
    return length;
}

/*遍历操作
 并且打印*/
template <typename DataType>
void SeqList<DataType>::PrintList()
{
    
    for(int i = 0; i < length; i++){
        cout<<data[i]<<"\t"<<endl;
    }
}

#endif /* SQELIST_hpp */
