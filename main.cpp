#include <iostream>
#include <fstream>
#include "Reader.h"
using namespace std;

int main(int argc, char *argv[]) {
    Reader::Read(argv[1], argv[2]);
    return 0;
}