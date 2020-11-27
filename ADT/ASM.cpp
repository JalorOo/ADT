//
//  ASM.cpp
//  ADT
//
//  Created by Jalor on 2020/11/27.
//  Copyright © 2020 Jalor. All rights reserved.
//

#include "ASM.hpp"

int min(int a,int b,int c){
    if(a > b){
        a = b;
    }
    if(a > c){
        a = c;
    }
    return a;
}

int ASMClass::ASMCalcul(string p,string t){
    int m = p.length();
    int n = t.length();
    int i,j;
    
    for (j = 0; j <= n; j++)
    {
        D[0][j] = 0;//样本与文本有0处不同
    }
    
    for (i = 0; i <= m;i++)
    {
        D[i][0] = i;//样本与文本有i处不同
    }
    
    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= m; i++)
        {
            if(p[i-1] == t[j-1]) {//若最后一个字符相等
                D[i][j] = min(D[i-1][j-1], D[i-1][j]+1, D[i][j-1]+1);//样本i与文本j的最小差距应该产生在前方
                //D[i-1][j-1];前字符串 比较的结果
                //D[i-1][j];前 样本字符串 与 现 文本字符串 比较的结果
                //D[i][j-1];现 样本字符串 与 前 文本字符串 比较的结果
            } else {//若最后一个字符不相等
                D[i][j] = min(D[i-1][j-1], D[i-1][j], D[i][j-1]) + 1;//样本i与文本j的最小差距应该产生在前方+1
            }
        }
        //if(D[m][j] <= k)return j;
    }
    return D[m][n];
}
