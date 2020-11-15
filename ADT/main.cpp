//
//  main.cpp
//  ADT
//
//  Created by Jalor on 2020/9/1.
//  Copyright © 2020 Jalor. All rights reserved.
//

#include <iostream>
#include "SEQLIST.hpp"
#include "LINKLIST.h"
#include "BIGNUM.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    cout<<"Input num1:"<<endl;
    BigNum num1;
    cin>>num1;
    cout<<"Input num2:"<<endl;
    BigNum num2;
    cin>>num2;
    BigNum num3 = num1 + num2;
    cout<<"Ans:"<<endl<<num3<<endl;
    return 0;
}
