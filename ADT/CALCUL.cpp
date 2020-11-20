//
//  CALCUL.cpp
//  ADT
//
//  Created by Jalor on 2020/11/20.
//  Copyright © 2020 Jalor. All rights reserved.
//

#include "CALCUL.hpp"

int charPor(char &c){
    switch (c) {
        case '+':
            return 1;
            
        case '-':
            return 1;
            
        default:
            return 2;
    }
}

/*
 构造函数
 保存为后缀表达式
 @param s 字符串
 @return 无
 */
Calcul::Calcul(string s){
    //保存为后缀表达式
    str = s;
}


/*
 计算函数
 @return OPND[opndPtr] 答案
 */
int Calcul::calcul() {
    for(int i = 0;i < str.length();i++){
        char cur = str[i];
        if (cur - '0' > 9 || cur - '0' < 0) {//当前字符为运算符
            if (optrPtr >= 0) {//指针已经初始化
                char t = OPTR[optrPtr];//栈顶符号
                int cmp = charPor(cur) - charPor(t);//比较优先级
                int b;
                int a;
                int ans;
                switch (cmp) {
                    case 0://相等
                        b = OPND[opndPtr--];
                        a = OPND[opndPtr--];
                        ans = a * b;//默认乘法
                        if(t == '/'){//除法
                            ans = a / b;
                        }else if(t == '+'){
                            ans = a + b;
                        }else if(t == '-'){
                            ans = a - b;
                        }
                        optrPtr --;
                        OPTR[++optrPtr] = cur;
                        OPND[++opndPtr] = ans;
                        break;
                        
                    case 1://大于
                        OPTR[++optrPtr] = cur;
                        break;
                        
                    default://小于
                        b = OPND[opndPtr--];
                        a = OPND[opndPtr--];
                        ans = a * b;//默认乘法
                        if(t == '/'){//除法
                            ans = a / b;
                        }
                        optrPtr --;
                        OPTR[++optrPtr] = cur;
                        OPND[++opndPtr] = ans;
                        break;
                }
                
            } else {//若指针没有初始化，则直接接入
                OPTR[++optrPtr] = cur;
            }
            
        } else {//当前字符为操作数
            OPND[++opndPtr] = (cur - '0');
        }
    }
    
    while (optrPtr >= 0) {//当运算符栈不为空
        int b = OPND[opndPtr--];//弹出操作数栈栈顶
        int a = OPND[opndPtr--];//弹出操作数栈栈顶
        char f = OPTR[optrPtr--];//弹出运算符栈栈顶
        int ans = a + b;//运算
        if(f == '-'){
            ans = a - b;
        }
        OPND[++opndPtr] = ans;//操作数栈push答案
    }
    
    return OPND[opndPtr];//返回答案
}
