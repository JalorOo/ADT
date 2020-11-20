//
//  CALCUL.hpp
//  ADT
//
//  Created by Jalor on 2020/11/20.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef CALCUL_hpp
#define CALCUL_hpp
#include <iostream>
using namespace std;

const int MAXN = 5;

class Calcul{
private:
    string str;
    int OPND[MAXN];//操作数
    char OPTR[MAXN];//运算符
    int opndPtr = -1;//操作数指针
    int optrPtr = -1;//运算符指针
public:
    Calcul(string s);
    int calcul();//计算
};

#endif /* CALCUL_hpp */
