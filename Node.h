//
// Created by user on 12.11.2022.
//

#ifndef UNTITLED10_NODE_H
#define UNTITLED10_NODE_H
#include <string>
#include "DoubleLL.h"

using namespace std;
class Node{
public:
    string apartmentName;
    int max_bandwith;
    DoubleLL *flatList = new DoubleLL();

    Node* next;
    Node(){
    }

    Node(string apartmentName, int max_bandwith){
        this->apartmentName = apartmentName;
        this->max_bandwith = max_bandwith;
        this->next = NULL;
    }
};

#endif //UNTITLED10_NODE_H
