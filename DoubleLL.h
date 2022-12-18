//
// Created by user on 13.11.2022.
//

#ifndef UNTITLED10_DOUBLELL_H
#define UNTITLED10_DOUBLELL_H


#include "Node_D.h"
using namespace std;
class DoubleLL {
    Node_D* head;
public:
    void insertFlat(int id, int initial_bandwidth, int index);
    void make_flat_empty(int id);
    int findCurrentBandWidth();
    bool is_empty();
    Node_D * headOfList();
    Node_D * lastNodeOfList();
    void makeNextHead();
    void makeListEmpty();
    void makeNodeHead(Node_D* a);

};


#endif //UNTITLED10_DOUBLELL_H
