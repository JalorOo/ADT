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

/*
 是否能被减的判断函数
 @param head 被减数的头指针
 @param a 被减数
 @param b 减数
 */
bool compare(int head,int tail,BigNum &a,const BigNum &b){
    
    string str1="",str2="";//比大小
    
    for(int i = head,j = b.length - 1;i >= tail; i--, j--){
        str1 += a.bit[i] + 48;//被减数
        if(j >= 0){
            str2 += b.bit[j] + 48;//减数
        } else {
            str2.insert(str2.begin(), '0');
        }
    }
    
    if(str1 >= str2)
        return 1;//
    else
        return 0;//如果大于等于就减 小于则不能减
}

/*
 函数减
 @param head 被减数的头指针
 @param a 被减数
 @param b 减数
 @param ans 答案
 */
void sub(int& head,int tail,BigNum &a,const BigNum &b,BigNum &ans){
    while(a.bit[head]==0)head--;//去除a前面的0 便于计算
    
    for(int i = tail,j = 0;i <= head; i++,j++){//从后往前减
        a.bit[i] = a.bit[i] - b.bit[j];//减法
        if(a.bit[i] < 0){//如果不够减借一位
            a.bit[i] += 10;
            a.bit[i+1] --;
        }
    }
    
    ans.bit[tail] ++;//统计答案
}

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
    bool originFlag = true;//记录原来的符号位
    if((*this).flag == false && another.flag == false){//若是 (-x) + (-y) 则转化为 - (y + x);
        this->flag = true;
        another.flag = true;
        originFlag = false;//原来的符号位为负
    } else if((*this).flag == false) {//若是 (-x) + y 则转换为 y - x;
        this->flag = true;
        return another - (*this);
        
    } else if(another.flag == false) {//若是 x + (-y) 则转化为 x - y
        another.flag = true;
        return (*this) - another;
    }
    
    int maxBit = max(this->length, another.length);//获得最少的位数
    
    /* 加法运算 */
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
    this->flag = originFlag;//设置符号位
    return (*this);
}

/*
 已经实现：大正-小正、位数不同的正正相减、正-负、负减负
 */
BigNum BigNum::operator -(BigNum& another){
    
    if((*this).flag == false && another.flag == false){//当(-x) - (-y),则转化为 y - x;
        another.flag = true;
        (*this).flag = true;
        return another - (*this);
    }else if((*this).flag == true && another.flag == false) {//当x - (-y), 则转化为x + y;
        another.flag = true;
        return (*this) + another;
    }else if ((*this).flag == false && another.flag == true) {//当 (-x) - y, 则转化为 (-x) + (-y)
        (another).flag = false;
        return (*this) + another;
    }
    
    
    /* 获得大的数、小的数 */
    BigNum& big = this->length < another.length ? another : (*this);//大位数
    BigNum& small = this->length < another.length ? (*this) : another;//小位数
    
    /* 若小的数为自己这个数 */
    if (big.length > (*this).length) {//若大数不是本数
        big.flag = false;//设置符号位为负
    } else if(small.length == big.length) {//若位数相等，逐一比对每位
        for (int i = big.length - 1;
             (big.flag == true) && i >= 0;
             i--) {//位相加
            if(big.bit[i] >= small.bit[i]){
                continue;
            } else {//大数与小数交换
                small.flag = false;
                BigNum temp = big;
                big = small;
                small = temp;
            }
        }
    }
    
    int maxBit = max(this->length, another.length);//获得最大的位数
    
    for (int i = 0; i < big.length; i++) {//位相减
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

/*
 乘法
 */
BigNum BigNum::operator *(const BigNum& another){
    //将结果储存在 resullt中，result[i + j] += a[i] * b[j]是关键算法
    
    BigNum result;
    /* 设置符号位 */
    if(this->flag != true && another.flag != true){//-x * -y
        result.flag = true;
    }else if(this->flag == false || another.flag == false){ //-x || -y
        result.flag = false;
    }
    
    /* 乘法运算 */
    for(int i = 0; i < this->length; i++)
    {
        for(int j = 0; j < another.length; j++)
        {
            result.bit[i + j] += this->bit[i] * another.bit[j];
        }
    }
     
    //从低位到高位进行进位
    for(int i = 0; i < (this->length + another.length); i++)
    {
        if(result.bit[i] > 9)
        {
            result.bit[i+1] += result.bit[i]/10;
            result.bit[i] %= 10;
        }
    }
    
    result.length = (this->length + another.length);
    return result;
}

/*
 除法
 */
BigNum BigNum::operator / (const BigNum& another){
    int head = (*this).length - 1;//被减数头指针
    BigNum result;//存储结果
    
    int tail = head - another.length + 1;//被除数的尾指针
    
    for(; tail >= 0;tail--){//查看该数放在哪一个位置
        if( !compare(head,tail,(*this),another) ){//如果a小于b 则继续下一层 即把b数往后挪一位
            continue;
        }
        else while( compare(head,tail,(*this),another) ){
            sub(head,tail,(*this),another,result);
        }
        //只要能减就一直减 直到a小于b 同时在    tail处统计答案
    }
    result.length = (*this).length;
    return result;
}


/*
 输出 大整数
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

