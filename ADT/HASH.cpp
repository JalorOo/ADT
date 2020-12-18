//
//  HASH.cpp
//  ADT
//
//  Created by Jalor on 2020/12/18.
//  Copyright © 2020 Jalor. All rights reserved.
//

#include "HASH.hpp"
Hash::Hash(int* data,int n,const int mode){
    this->mode = mode;
    num = 11;
    this->data = new int[num]{0};
    
    for (int i = 0; i < n; i++) {
        int idx = hashFun(data[i]);
        
        stealFun(idx, 0);
        
        this->data[idx] = data[i];
    }
    
}

void Hash::outHash(){
    for (int i = 0; i < num; i++) {
        cout<<"data["<<i<<"]"<<data[i]<<" idx:"<<hashFun(data[i])<<endl;
    }
}

int Hash::search(int var){
    
    int idx = hashFun(var);
    di = 0;
    
    stealFun(idx, var);
    
    if(idx < num){
        return idx;
    }
    
    return -1;
}

int Hash::hashFun(int key){
    int idx = key % (num);
    return idx;
}

void Hash::stealFun(int& idx,int standerd){
    switch (mode) {
        case LINEAR:
            while(this->data[idx] != standerd && idx < num){
                idx++;
                di++;
            }
            break;
        case PAIR:
            int temp = idx;
            int i = 1;
            int single = 1;
            while(this->data[idx] != standerd && idx < num){
                idx = temp;
                if(single % 2 == 1)
                    idx += i*i;
                else {
                    idx -= i*i;
                    i++;
                }
                single++;
                di++;//比较次数
            }
            break;
    }
}
