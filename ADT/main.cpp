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
using namespace std;

int main(int argc, const char * argv[]) {
    int a[] = {1,2,3,4,5,6,7};
    LinkList<int>l = LinkList<int>();
    SeqList<int>s = SeqList<int>(a, 7);
    s.Insert(2, 10);
    s.PrintList();
    cout<<"==================="<<endl;
    s.Delete(1);
    s.PrintList();
    return 0;
}
