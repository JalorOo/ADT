//
//  BIGNUM.hpp
//  ADT
//
//  Created by Jalor on 2020/11/13.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef BIGNUM_hpp
#define BIGNUM_hpp

#include <iostream>
using namespace std;
class BigNum{
private:
    int bit[100];//计算位
    bool C = false;//进位标志位
    int length = 0 ;//当前数字的位数
    bool flag = true;//符号位
public:
    /*定义加减乘除、输入输出*/
    BigNum(string s);
    BigNum setBigNum(string s);
    BigNum();
    BigNum operator +(BigNum&);
    BigNum operator -(BigNum&);
    BigNum operator *(const BigNum&);
    BigNum operator /(const BigNum&);
    friend ostream & operator <<(ostream &output,const BigNum &);
    friend istream & operator >>( istream &input,BigNum &);
};
#endif /* BIGNUM_hpp */
