//
//  ASM.hpp
//  ADT
//
//  Created by Jalor on 2020/11/27.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef ASM_hpp
#define ASM_hpp

#include <iostream>
#include <algorithm>
using namespace std;

const int ASM_MAXN = 100;

class ASMClass{
private:
    int D[ASM_MAXN][ASM_MAXN];
public:
    int ASMCalcul(string p,string t);
};

#endif /* ASM_hpp */
