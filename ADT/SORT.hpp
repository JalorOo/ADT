//
//  SORT.hpp
//  ADT
//
//  Created by Jalor on 2020/9/7.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef SORT_hpp
#define SORT_hpp

#include <iostream>
using namespace std;

template <typename DataType>
class Sort {
public:
    Sort();//建立空的链表
    void InsertSort(DataType data[],int n);
private:
    int n;
};

//template <typename DataType>
//void Sort::InsertSort(DataType data[],int n){
//    DataType i,j,tmp;
//    for (i = 1; i < n; i ++) {
//        if(data[i]<data[i-1]){
//            tmp = data[i];
//            data[i] = data[i-1];
//            for (j = i-1; j>=0 && data[j]> tmp; j--) {
//                data[j+1] = data[j];
//            }
//            data[j+1] = tmp;
//        }
//    }
//}
#endif /* SORT_hpp */
