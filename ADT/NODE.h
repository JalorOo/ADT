//
//  NODE.h
//  ADT
//
//  Created by Jalor on 2020/9/2.
//  Copyright © 2020 Jalor. All rights reserved.
//

#ifndef NODE_h
#define NODE_h

//结点
template <typename DataType>
struct Node
{
    DataType data;
    Node<DataType>* next;
};

#endif /* NODE_h */
