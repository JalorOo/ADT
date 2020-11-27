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
#include "ASM.hpp"
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
//    Calcul c = Calcul("0*1-9");
//    cout<<c.calcul()<<endl;
    ASMClass a;
//    cout<<"please input pattern:";
//    string p;
//    cin>>p;
//    cout<<"please input word:";
//    string t;
//    cin>>t;
//    int ans = a.ASMCalcul("hallo", "jalor");
    int ans = a.ASMCalcul("hello", "apxgv");
//    int ans =  a.ASMCalcul(p, t, 100);
    cout<<"found "<<ans<<" diff palces"<<endl;
    return 0;
}
