//
//  BIGNUM.cpp
//  ADT
//
//  Created by Jalor on 2020/11/13.
//  Copyright © 2020 Jalor. All rights reserved.
//

#include "BIGNUM.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

BigNum::BigNum(){
    memset(this->bit, 0, sizeof(this->bit));
}

BigNum::BigNum(string s){
    memset(this->bit, 0, sizeof(this->bit));
    if(s[0] == '-'){//负数
        this->flag = false;
        for (int i = (int)(s.length() -2); i >= 0; i --) {
            this->bit[i] = (int)(s[s.length() -1 - i] - '0');
        }
        this->length = (int)s.length()-1;
    } else {//正数
        for (int i = (int)(s.length() -1); i >= 0; i --) {
            this->bit[i] = (int)(s[s.length() -1 - i] - '0');
        }
        this->length = (int)s.length();
    }
}

BigNum BigNum::setBigNum(string s){
    memset(this->bit, 0, sizeof(this->bit));
    if(s[0] == '-'){//负数
        this->flag = false;
        for (int i = (int)(s.length() -2); i >= 0; i --) {
            this->bit[i] = (int)(s[s.length() -1 - i] - '0');
        }
        this->length = (int)s.length()-1;
    } else {//正数
        for (int i = (int)(s.length() -1); i >= 0; i --) {
            this->bit[i] = (int)(s[s.length() -1 - i] - '0');
        }
        this->length = (int)s.length();
    }
    return (*this);
}

/*
 已经实现：正+正
 待实现：负+负、正+负
 */
BigNum BigNum::operator +(BigNum& another){
    bool originFlag = true;
    if((*this).flag == false && another.flag == false){//判断符号位,若是 (-x) + (-y) = - (y + x);
        this->flag = true;
        another.flag = true;
        originFlag = false;
        
    } else if((*this).flag == false) {//判断符号位,若是 (-x) + y = y - x;
        this->flag = true;
        return another - (*this);
        
    } else if(another.flag == false) {
        another.flag = true;
        return (*this) - another;
    }
    
    int maxBit = max(this->length, another.length);//获得最少的位数
    for (int i = 0; i < maxBit; i++) {//位相加
        int c = this->C ? 1 : 0;//判断是否有进位
        int bitAns = this->bit[i] + another.bit[i] + c;
        if(bitAns >= 10){//设置进位位
            this->C = true;
        } else {
            this->C = false;
        }
        this->bit[i] = bitAns%10;
    }
    this->length = maxBit;//设置长度
    this->flag = originFlag;
    return (*this);
}

/*
 已经实现：大正-小正、位数不同的正正相减、正-负、负减负
 */
BigNum BigNum::operator -(BigNum& another){
    
    if((*this).flag == false && another.flag == false){//判断符号位
        another.flag = true;
        (*this).flag = true;
        return another - (*this);
    }else if((*this).flag == true && another.flag == false) {
        another.flag = true;
        return (*this) + another;
    }else if ((*this).flag == false && another.flag == true) {
        (another).flag = false;
        return (*this) + another;
    }
    
    
    /*第一次获得位数*/
    BigNum& big = this->length < another.length ? another : (*this);//大位数
    BigNum& small = this->length < another.length ? (*this) : another;//小位数
    
    /*设置符号位*/
    if(big.length > (*this).length){//若大数不是本数
        big.flag = false;//设置符号位为负
    }else if(small.length == (*this).length){
        for (int i = big.length - 1;
             (big.flag == true) && i >= 0;
             i--) {//位相加
            if(big.bit[i] >= small.bit[i]){
                continue;
            } else {
                small.flag = false;
                BigNum temp = big;
                big = small;
                small = temp;
            }
        }
    }
    
    int maxBit = max(this->length, another.length);//获得最大的位数
    
    for (int i = 0; i < big.length; i++) {//位相加
        int c = big.C ? 1 : 0;//判断是否有借位
        int bitAns = big.bit[i] - small.bit[i] - c;
        if(bitAns < 0){//设置进位位
            big.C = true;
            big.bit[i] = bitAns + 10;
        } else {
            big.C = false;
            big.bit[i] = bitAns;
        }
    }
    
    this->length = maxBit;//设置长度
    return big;
}
//BigNum operator *(const BigNum&);
//BigNum operator /(const BigNum&);


/*
 输出大整数
 */
ostream& operator<<( ostream &output,const BigNum &num){
    bool cantOutZero = true;
    if(!num.flag)output<<"-";
    for (int i = num.length-1; i >= 0; i--) {
        if (cantOutZero && num.bit[i] == 0) {
            continue;
        } else {
            output<<num.bit[i];
            cantOutZero = false;
        }
    }
    return output;
}

/*
 输入大整数
 */
istream &operator>>( istream  &input,BigNum &bigNum){
    string s;
    input >> s;  //将"a+bi"作为字符串读入, "a+bi" 中间不能有空格
    bigNum.setBigNum(s);
    return input;
}

