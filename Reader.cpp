//
// Created by user on 12.11.2022.
//
#include "Reader.h"
#include "CircularLinkedList.h"

using namespace std;

    void Reader::Read(string input, string output) {
        CircularLinkedList *list = new CircularLinkedList();
        ofstream writeToFile(output);

        string line;
        ifstream readFile(input);
        while (getline (readFile, line)){
            stringstream sstream;
            sstream << line;
            string command;
            sstream >> command;
            if (command == "add_apartment"){
                string apartmentName;
                string apartmentLocation;
                int maxBandWith;
                sstream >> apartmentName;
                sstream >> apartmentLocation;
                sstream >> maxBandWith;
                list->insertApartment(apartmentName,maxBandWith,apartmentLocation);

            }
            else if (command == "add_flat"){
                string apartmentName;
                int flatLocation;
                int initial_bandWidth;
                int flat_id;
                sstream >> apartmentName;
                sstream >> flatLocation;
                sstream >> initial_bandWidth;
                sstream >> flat_id;
                list->insertFlat(apartmentName, flatLocation, initial_bandWidth, flat_id);

            }
            else if (command == "remove_apartment"){
                string apartmentName;
                sstream >> apartmentName;
                list->removeApartment(apartmentName);
            }
            else if (command == "make_flat_empty"){
                string apartmentName;
                int id;
                sstream >> apartmentName;
                sstream >> id;
                list->make_flat_empty(id,apartmentName);
            }
            else if (command == "find_sum_of_max_bandwidths"){
                int a = list->find_sum_of_max_bandwidths();
                writeToFile<<"sum of bandwidth: "<<a<<endl<<endl;
            }
            else if (command == "merge_two_apartments"){
                string apartment1;
                string apartment2;
                sstream >> apartment1;
                sstream >> apartment2;
                list->merge_two_apartments(apartment1,apartment2);
            }
            else if (command == "relocate_flats_to_same_apartment"){
                string apartment;
                int flatID;
                string list1;
                sstream >> apartment;
                sstream >> flatID;
                sstream >> list1;
                list->relocate_flats_to_same_apartment(apartment,flatID,list1);
            }
            else if (command =="list_apartments"){
                list->printList(writeToFile);
            }
        }
        readFile.close();
    }
