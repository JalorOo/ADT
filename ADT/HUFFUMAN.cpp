//
//  HUFFUMAN.cpp
//  ADT
//
//  Created by Jalor on 2020/12/4.
//  Copyright © 2020 Jalor. All rights reserved.
//

#include "HUFFUMAN.hpp"

/* 构造一颗哈夫曼树 */
void HuffumanCode::HuffmanTree(HNodeType HuffNode[MAXNODE],  int n)
{
    /* i、j： 循环变量，m1、m2：构造哈夫曼树不同过程中两个最小权值结点的权值，
        x1、x2：构造哈夫曼树不同过程中两个最小权值结点在数组中的序号。*/
    int i, j, m1, m2, x1, x2;
    /* 初始化存放哈夫曼树数组 HuffNode[] 中的结点 */
    for (i = 0; i< 2*n-1 ; i++)
    {
        HuffNode[i].weight = -1;//权值
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }
 
    /* 输入 n 个叶子结点的权值 */
    for (i=0; i<n;)
    {
        for (j = 0; j < 30;j++) {
            if(Text[j]>0){
                HuffNode[i].weight = Text[j];
                i++;
            }
        }
        break;
    }
 
    /* 循环构造 Huffman 树 */
    for (i = n; i < 2*n-1; i++)
    {
        
        //************************************************************************************************
        m1 = m2 = MAXVALUE;//m1、m2中存放两个无父结点且结点权值最小的两个结点
        x1 = x2 = 0;//选择的节点
        /* 找出所有结点中权值最小、无父结点的两个结点，并合并之为一颗二叉树 */
        for (j = 0; j < 2*n-1; j++)
        {
            if (HuffNode[j].weight>0 && HuffNode[j].weight < m1 && HuffNode[j].parent==-1) {//最小
                
                m2 = m1;
                x2 = x1;
                m1 = HuffNode[j].weight;
                x1 = j;
                
            } else if (HuffNode[j].weight>0 && HuffNode[j].weight < m2 && HuffNode[j].parent==-1) {//次小
                
                m2 = HuffNode[j].weight;
                x2 = j;
                
            }
        }
        //************************************************************************************************
        
        HuffNode[x1].parent  = i;
        HuffNode[x2].parent  = i;
        HuffNode[i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
        HuffNode[i].lchild = x1;
        HuffNode[i].rchild = x2;
    }
}
 
//解码
void decodeing(char string[],HNodeType Buf[],int Num)
{
  int i,tmp=0,code[1024];
  int m=2*Num-1;
  char *nump;
  char num[1024];
  for(i=0;i<strlen(string);i++)
  {
   if(string[i]=='0')
  num[i]=0;
  else
  num[i]=1;
  }
  i=0;
  nump=&num[0];
  
 while(nump<(&num[strlen(string)]))
 {tmp=m-1;
  while((Buf[tmp].lchild!=-1)&&(Buf[tmp].rchild!=-1))
  {
  
   if(*nump==0)
   {
     tmp=Buf[tmp].lchild ;
   }
   else tmp=Buf[tmp].rchild;
   nump++;
        
  }
  
  printf("%d",Buf[tmp].value);
 }
}

HuffumanCode HuffumanCode::setContent(string s) {
    this->content = s;
    for (int i = 0; i< content.length(); i++) {
        if(Text[content[i] - 'a'] == 0){//若还没有录取进字库,统计字符个数
            TextSize++;
        }
        Text[content[i] -'a']++;
    }
    return *this;
}

string HuffumanCode::getZipContent() {
    return this->content;
}

void HuffumanCode::doZip(){
    HuffmanTree(HuffNode, TextSize);
}
