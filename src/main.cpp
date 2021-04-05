// Copyright 2021 Bogomazov
#include <iostream>
#include <string>

#include "../include/train.h"

int main() {
    Cage* f = new Cage();
    Cage* s = new Cage();
    Cage* t = new Cage();
    f->on();
    // t->on();
    Train tr = Train(f, s);
    // tr.printCagesState();
    // tr.addCage(t, true);
    // tr.printCagesState();
    std::cout << tr.findLength() << std::endl;
    return 0;
}

