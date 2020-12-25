//
//  HEAP.cpp
//  ADT
//
//  Created by Jalor on 2020/12/25.
//  Copyright © 2020 Jalor. All rights reserved.
//

#include "HEAP.hpp"

void Heap::onCreate(){
    int i = 0;
    srand(time(NULL));
    for (i = 1; i <= MAX; i++) {
        a[i] = 1 + rand() % 100;
    }
}//创建数组

void Heap::heapSort(int n){
    int i = 0;
    for (i = n/2; i >= 1; i--) {//从最后一个非叶子结点开始堆调整
        Sift(i,n);
    }
    for (i = 1; i < n; i++) {//头与尾交换排序
        a[0] = a[1];
        a[1] = a[n - i + 1];
        a[n - i + 1] = a[0];
        Sift(1, n - i);//调整堆
    }
}//堆排序

void Heap::outArray(){
    for (int i = 1; i <= MAX; i++) {
        cout<<" "<<a[i];
    }
}//输出

void Heap::Sift(int k,int m){
    int i = k,j = 2 * i;
    while (j <= m) {
        if (j < m && a[j] < a[j+1]) {//指向孩子中的最大者
            j++;
        }
        if (a[i] > a[j]) {//若已经排序完成，则不再进行排序
            break;
        } else {//调整父母与孩子的位置，使之满足堆的定义
            a[0] = a[i];
            a[i] = a[j];
            a[j] = a[0];
            
            //孩子打乱了，对孩子进行堆调整。
            
            i = j;
            j = 2 * i;
        }
    }
}//堆调整
