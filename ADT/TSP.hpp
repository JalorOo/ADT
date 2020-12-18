//
//  TSP.hpp
//  ADT
//
//  Created by Jalor on 2020/12/11.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef TSP_hpp
#define TSP_hpp

#include <iostream>
using namespace std;
const int TSP_MAX = 1;
class TSP{
private:
    int vert[TSP_MAX];//顶点集合
    int edge[TSP_MAX][TSP_MAX];//对应地图
    int vertNum = 0,edgeNum = 0;
    int ans = 0;
    bool found = false;
    int start = 0;
public:
    TSP(int[],int,int);
    void setMap(int* ,int);
    void setStart(int s);
    void outSolution(int s,int f[]);
};

#endif /* TSP_hpp */
