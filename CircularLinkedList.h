//
// Created by user on 12.11.2022.
//

#ifndef UNTITLED10_CIRCULARLINKEDLIST_H
#define UNTITLED10_CIRCULARLINKEDLIST_H


#include "Node.h"
#include "Node_D.h"

using namespace std;

class CircularLinkedList {
    Node* root;
public:
    CircularLinkedList(){
        root = new Node();
    }
    void insertApartment(string apartmentName, int max_bandwith, string location);
    void insertFlat(string apartmentName, int flatLocation, int initial_bandWidth, int flat_id);
    void removeApartment(string apartmentName);
    void make_flat_empty(int id, string apartmentName);
    int find_sum_of_max_bandwidths();
    void merge_two_apartments(string apartment1, string apartment2);
    void relocate_flats_to_same_apartment(string apartment, int flatID, string list);
    void printList(ofstream& writeToFile);

};


#endif //UNTITLED10_CIRCULARLINKEDLIST_H
