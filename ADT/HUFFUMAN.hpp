//
//  HUFFUMAN.hpp
//  ADT
//
//  Created by Jalor on 2020/12/4.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef HUFFUMAN_hpp
#define HUFFUMAN_hpp

#include <iostream>
#include <cstdio>

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2 -1
using namespace std;

typedef struct
{
    int weight;//权值
    int parent;//父节点
    int lchild;//左孩子
    int rchild;//右孩子
    int value;//值
}HNodeType;
/* 结点结构体 */

class HuffumanCode {
private:
    string content;//内容
    string zip_content;//压缩内容
    HNodeType HuffNode[MAXNODE];
    int TextSize = 0;//文字包含每个字母数
    int Text[30] = {0};//各字母权值
    void HuffmanTree (HNodeType HuffNode[MAXNODE],  int n);
public:
    HuffumanCode setContent(string);//写入内容
    void doZip();//压缩
    string getZipContent();//获得压缩内容
};

#endif /* HUFFUMAN_hpp */
