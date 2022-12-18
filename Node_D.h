//
// Created by user on 13.11.2022.
//

#ifndef UNTITLED10_NODE_D_H
#define UNTITLED10_NODE_D_H
#include <string>

class Node_D {
public:
    int id;
    int initial_bandwidth;
    int is_empty = 0;
    Node_D* next;
    Node_D* prev;
    Node_D(){
    }

    Node_D(int id, int initial_bandwidth){
        this->id = id;
        this->initial_bandwidth = initial_bandwidth;
        this->next = NULL;
        this->prev = NULL;
    }

};


#endif //UNTITLED10_NODE_D_H
