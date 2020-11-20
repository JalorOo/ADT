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
#include "CALCUL.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
//    cout<<"Input func(e.g: 123+456 ):"<<endl;
//    BigNum num1;
//    BigNum num2;
//    string str;
//    cin>>str;
//
//    int idx;
//    idx = str.find('+');
//    if(idx > -1){
//        string s1 = str.substr(0,idx);
//        string s2 = str.substr(idx+1);
//        num1 = BigNum(s1);
//        num2 = BigNum(s2);
//        cout<<"="<<num1+num2<<endl;
//        return 0;
//    }
//    idx = str.find('-');
//    if(idx > -1){
//        string s1 = str.substr(0,idx);
//        string s2 = str.substr(idx+1);
//        num1 = BigNum(s1);
//        num2 = BigNum(s2);
//        cout<<"="<<num1-num2<<endl;
//        return 0;
//    }
//    idx = str.find('*');
//    if(idx > -1){
//        string s1 = str.substr(0,idx);
//        string s2 = str.substr(idx+1);
//        num1 = BigNum(s1);
//        num2 = BigNum(s2);
//        cout<<"="<<num1*num2<<endl;
//        return 0;
//    }
//    idx = str.find('/');
//    if(idx > -1){
//        string s1 = str.substr(0,idx);
//        string s2 = str.substr(idx+1);
//        num1 = BigNum(s1);
//        num2 = BigNum(s2);
//        cout<<"="<<num1/num2<<endl;
//        return 0;
//    }
    Calcul c = Calcul("9*9*7-1");
    cout<<c.calcul()<<endl;
    return 0;
}
