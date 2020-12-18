//
//  TSP.cpp
//  ADT
//
//  Created by Jalor on 2020/12/11.
//  Copyright © 2020 Jalor. All rights reserved.
//

#include "TSP.hpp"
TSP::TSP(int a[],int n,int e){
    for (int i = 0; i < n; i++) {
        vert[i] = a[i];
    }
    vertNum = n;
    edgeNum = e;
}

void TSP::setMap(int* a,int n){
    for (int i = 0 ; i < TSP_MAX; i++) {
        for (int j = i; j <TSP_MAX; j++) {
            if(i == j){
                edge[i][j] = 0;
                continue;
            }
            edge[i][j] = *(a+i*n+j);
            edge[j][i] = edge[i][j];
        }
    }
}

void TSP::outSolution(int s,int f[]){
    
    int flag[TSP_MAX] = {0};//标志位
    
    bool allArrive = true;//是否全部读取完毕
    
    for (int i = 0; i<TSP_MAX; i++) {
        flag[i] = f[i];
        if(!flag[i]){
            allArrive = false;
        }
    }
    
    if(allArrive){
        ans += edge[s][start];
        cout<<ans<<endl;
        found = true;
        return;
    }
    
    int max = 1000;
    int c = s;
    
    int cant[TSP_MAX] = {0};
    
    while(!found){
        
        for (int i = 0; i<TSP_MAX; i++) {
            if(edge[s][i]<max && edge[s][i] && !cant[i] && !flag[i]){
                c = i;
                max = edge[s][i];
            }
        }
        
        if(c == s){
            return;
        }
        
        flag[c] = 1;
        ans += edge[s][c];
        
        outSolution(c, flag);
        
        cant[c] = 1;
        ans -= edge[s][c];
        flag[c] = 0;
    }
}

void TSP::setStart(int s){
    start = s;
}
