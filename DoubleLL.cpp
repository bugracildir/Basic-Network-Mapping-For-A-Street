//
// Created by user on 13.11.2022.
//

#include <iostream>
#include "DoubleLL.h"
using namespace std;
void DoubleLL::insertFlat(int id, int initial_bandwidth, int index) {
    if (head==NULL){
        head= new Node_D(id,initial_bandwidth);
    }
    else{
        Node_D* newNode = new Node_D(id,initial_bandwidth);
        Node_D* temp = head;
        if (index==0){
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            while (index > 1) {
                temp = temp->next;
                index -= 1;
            }
            if (temp->next==NULL){
                temp->next=newNode;
                newNode->prev = temp;
            }
            else {
                Node_D* next = temp->next;
                newNode->next = next;
                newNode->prev = temp;
                temp->next = newNode;
                next->prev = newNode;
            }
        }


    }
}
void DoubleLL::make_flat_empty(int id) {
    Node_D* temp = head;
    while ((temp->id)!=id){
        temp = temp->next;
    }
    temp->is_empty = 1;
    temp->initial_bandwidth = 0;
}
int DoubleLL::findCurrentBandWidth() {
    int a = 0;
    Node_D* temp = head;
    if (temp != NULL) {
        a = temp->initial_bandwidth;
        temp = temp->next;
        while (temp != NULL) {
            a += temp->initial_bandwidth;
            temp = temp->next;
        }
        return a;
    }
    else{
        return 0;
    }
}
bool DoubleLL::is_empty() {
    return head==NULL;
}
Node_D * DoubleLL::headOfList() {
    return head;
}
Node_D * DoubleLL::lastNodeOfList() {
    Node_D* temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}
void DoubleLL::makeNextHead(){
    head = head->next;
}
void DoubleLL::makeListEmpty(){
    head = NULL;
}
void DoubleLL::makeNodeHead(Node_D* a) {
    head = a;
}
