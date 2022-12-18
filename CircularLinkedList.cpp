//
// Created by user on 12.11.2022.
//
#include "CircularLinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
void CircularLinkedList::insertApartment(string apartmentName, int max_bandwith, string location) {
    if (location.size()==4){ // I understand here it says head
        root->apartmentName = apartmentName;
        root->max_bandwith = max_bandwith;
        root->next = root;
    }
    else {
        Node *newNode = new Node(apartmentName, max_bandwith);
        Node *head = root;

        if (location.size() == 7) { // I understand here it says after_X
            location.erase(0, 6);
            while ((head->apartmentName) != location) {
                head = head->next;
            }
            newNode->next = head->next;
            head->next = newNode;
        } else if (location.size() == 8) { // I understand here it says before_X
            location.erase(0, 7);
            if (location == head->apartmentName){
                newNode->next = head;
                while (head->next != root){
                    head = head->next;
                }
                head->next = newNode;
                root = newNode;
            }
            else {
                while ((head->next->apartmentName) != location) {
                    head = head->next;
                }
                newNode->next = head->next;
                head->next = newNode;
            }
        }
    }
}


void CircularLinkedList::insertFlat(string apartmentName, int flatLocation, int initial_bandWidth, int flat_id) {
    Node* temp = root;
    if (temp->apartmentName==apartmentName){
        int a = temp->flatList->findCurrentBandWidth();
        if (temp->max_bandwith < a + initial_bandWidth){
            initial_bandWidth = temp->max_bandwith - a;
        }
        temp->flatList->insertFlat(flat_id,initial_bandWidth,flatLocation);
    }
    temp = temp->next;
    while (temp!=root){
        if (temp->apartmentName==apartmentName){
            int a = temp->flatList->findCurrentBandWidth();
            if (temp->max_bandwith < a + initial_bandWidth){
                initial_bandWidth = temp->max_bandwith - a;
            }
            temp->flatList->insertFlat(flat_id,initial_bandWidth,flatLocation);
        }
        temp = temp->next;
    }
}


void CircularLinkedList::removeApartment(string apartmentName) {
    Node* temp = root;
    if (temp->next==NULL){
        root=NULL;
    }
    else{
        int a = 1;
        while (temp->next->apartmentName != apartmentName){
            temp = temp->next;
        }
        if (temp->next == root){
            root = temp->next->next;
        }
        temp->next = temp->next->next;
    }

}


void CircularLinkedList::make_flat_empty(int id, string apartmentName) {
    Node* temp = root;
    while ((temp->apartmentName)!=apartmentName){
        temp = temp->next;
    }
    temp->flatList->make_flat_empty(id);
}


int CircularLinkedList::find_sum_of_max_bandwidths() {
    Node* temp = root;
    int sum = 0;
    while (temp->next != root){
        sum += temp->max_bandwith;
        temp = temp->next;
    }
    return sum + temp->max_bandwith;
}


void CircularLinkedList::merge_two_apartments(string apartment1, string apartment2) {
    Node* temp = root;
    Node* temp2 = root;
    while ((temp->next->apartmentName)!=apartment1){
        temp = temp->next;
    }
    while ((temp2->next->apartmentName)!=apartment2){
        temp2 = temp2->next;
    }
    temp->next->max_bandwith += temp2->next->max_bandwith;
    if (temp->next->flatList->is_empty()==1){
        Node_D *headOfApartment1 = temp->next->flatList->headOfList();
        Node_D *headofApartment2 = temp2->next->flatList->headOfList();
        headOfApartment1 = headofApartment2;
        removeApartment(apartment2);

    }
    else{
        Node_D *lastOfApartment1 = temp->next->flatList->lastNodeOfList();
        Node_D *headofApartment2 = temp2->next->flatList->headOfList();
        if (headofApartment2!= NULL) {
            lastOfApartment1->next = headofApartment2;
            headofApartment2->prev = lastOfApartment1;
            removeApartment(apartment2);
        }
        else{
            removeApartment(apartment2);
        }
    }
}

void CircularLinkedList::relocate_flats_to_same_apartment(std::string apartment, int flatID, std::string list) {

    list = list.substr(1,list.size()-2);
    stringstream ss(list);
    for (int i; ss>>i;) {
        if (ss.peek() == ',')
            ss.ignore();
        Node *temp = root;
        Node *temp2 = root;
        while ((temp->apartmentName)!=apartment){
            temp = temp->next;
        }
        Node_D* headOfFlat = temp->flatList->headOfList();
        while (headOfFlat->id != flatID){
            headOfFlat = headOfFlat->next;
        }
        int ifFounded = 0;
        while (temp2->next != root && ifFounded == 0 ){
            Node_D* tempOfFlatList = temp2->flatList->headOfList();
            while (tempOfFlatList != NULL && ifFounded == 0){
                if (tempOfFlatList->id == i){
                    temp2->max_bandwith -= tempOfFlatList->initial_bandwidth;
                    temp->max_bandwith += tempOfFlatList->initial_bandwidth;
                    ifFounded = 1;
                    Node_D* a = headOfFlat->prev;
                    Node_D* c = tempOfFlatList->prev;
                    Node_D* d = tempOfFlatList->next;
                    if (c != NULL && d != NULL){
                        c->next = d;
                        d->prev = c;
                    }
                    else if (c == NULL && d!= NULL){
                        d->prev = NULL;
                        temp2->flatList->makeNextHead();
                    }
                    else if (c !=NULL && d==NULL){
                        c->next = NULL;
                    }
                    else if (c == NULL && d==NULL){
                        temp2->flatList->makeListEmpty();
                    }
                    if (a != NULL){
                        a->next = tempOfFlatList;
                        headOfFlat->prev = tempOfFlatList;
                        tempOfFlatList->prev = a;
                        tempOfFlatList->next = headOfFlat;
                    }
                    else if (a == NULL){
                        tempOfFlatList->prev = a;
                        headOfFlat->prev = tempOfFlatList;
                        tempOfFlatList->next = headOfFlat;
                        temp->flatList->makeNodeHead(tempOfFlatList);
                    }
                }
                tempOfFlatList = tempOfFlatList->next;
            }
            temp2 = temp2->next;
        }
        Node_D* tempOfFlatList = temp2->flatList->headOfList();
        while (tempOfFlatList != NULL && ifFounded == 0){
            if (tempOfFlatList->id == i){
                temp2->max_bandwith -= tempOfFlatList->initial_bandwidth;
                temp->max_bandwith += tempOfFlatList->initial_bandwidth;
                ifFounded = 1;
                Node_D* a = headOfFlat->prev;
                Node_D* c = tempOfFlatList->prev;
                Node_D* d = tempOfFlatList->next;
                if (c != NULL && d != NULL){
                    c->next = d;
                    d->prev = c;
                }
                else if (c == NULL && d!= NULL){
                    d->prev = NULL;
                    temp2->flatList->makeNextHead();
                }
                else if (c !=NULL && d==NULL){
                    c->next = NULL;
                }
                else if (c == NULL && d==NULL){
                    temp2->flatList->makeListEmpty();
                }
                if (a != NULL){
                    a->next = tempOfFlatList;
                    headOfFlat->prev = tempOfFlatList;
                    tempOfFlatList->prev = a;
                    tempOfFlatList->next = headOfFlat;
                }
                else if (a == NULL){
                    tempOfFlatList->prev = a;
                    headOfFlat->prev = tempOfFlatList;
                    tempOfFlatList->next = headOfFlat;
                    temp->flatList->makeNodeHead(tempOfFlatList);
                }
            }
            tempOfFlatList = tempOfFlatList->next;
        }
    }


}


void CircularLinkedList::printList(ofstream& writeToFile){
    Node *temp = root;
    while (temp->next!=root){
        writeToFile<<(temp->apartmentName)<<"("<<temp->max_bandwith<<")\t";
        Node_D* headFlat = temp->flatList->headOfList();
        while (headFlat!=NULL){
            writeToFile<<"Flat"<<headFlat->id<<"("<<headFlat->initial_bandwidth<<")"<<"\t";
            headFlat = headFlat->next;
        }
        writeToFile<<"\n";
        temp = temp->next;
    }
    writeToFile<<(temp->apartmentName)<<"("<<temp->max_bandwith<<")\t";
    Node_D* headFlat = temp->flatList->headOfList();
    while (headFlat!=NULL){
        writeToFile<<"Flat"<<headFlat->id<<"("<<headFlat->initial_bandwidth<<")"<<"\t";
        headFlat = headFlat->next;
    }
    writeToFile<<"\n";
    temp = temp->next;
    writeToFile<<endl;
}
