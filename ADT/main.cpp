//
//  main.cpp
//  ADT
//
//  Created by Jalor on 2020/9/1.
//  Copyright © 2020 Jalor. All rights reserved.
//
#include <iostream>
#include "HEAP.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
//    int vert[TSP_MAX];
//    int map[TSP_MAX][TSP_MAX];
//    for (int i = 0; i < TSP_MAX; i++) {
//        cin>>vert[i];
//    }
//    for (int i = 0 ; i < TSP_MAX; i++) {
//        for (int j = i + 1; j <TSP_MAX; j++) {
//            cin>>map[i][j];
//            map[j][i] = map[i][j];
//        }
//    }
//    TSP tsp = TSP(vert,TSP_MAX,TSP_MAX);
//    tsp.setMap((int*)map, TSP_MAX);
//    int s = 0;
//    int f[TSP_MAX] = {1};
//    tsp.setStart(0);
//    tsp.outSolution(s,f);
    Heap heap;
    heap.onCreate();
    heap.outArray();
    cout<<endl;
    heap.heapSort(MAX);
    heap.outArray();
    return 0;
}
