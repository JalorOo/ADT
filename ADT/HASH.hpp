//
//  HASH.hpp
//  ADT
//
//  Created by Jalor on 2020/12/18.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef HASH_hpp
#define HASH_hpp

#include <iostream>
using namespace std;

const int LINEAR = 0;
const int PAIR = 1;

class Hash{
private:
    int* data;//散列数组
    int num;//数组长度
    int m;//模
    int hashFun(int);//散列函数
    void stealFun(int &,int );//解决冲突方法
    int mode = 0;
public:
    int di;
    Hash(int*,int,const int);
    int search(int);
    void outHash();
};


#endif /* HASH_hpp */
