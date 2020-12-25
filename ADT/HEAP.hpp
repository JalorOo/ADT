//
//  HEAP.hpp
//  ADT
//
//  Created by Jalor on 2020/12/25.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef HEAP_hpp
#define HEAP_hpp

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 10;

class Heap {
private:
    int a[MAX+1] = {0};
    void Sift(int,int);//堆调整
public:
    void onCreate();//创建数组
    void heapSort(int);//堆排序
    void outArray();//输出
};

#endif /* HEAP_hpp */
