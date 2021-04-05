// Copyright 2021 Bogomazov
#include <iostream>
#include <string>

#include "../include/train.h"

int main() {
    Cage* f = new Cage();
    Cage* s = new Cage();
    Cage* t = new Cage();
    Cage* fo = new Cage();
    Cage* fi = new Cage();
    Cage* si = new Cage();
    Cage* se = new Cage();
    f->on();
    fi->on();
    Train tr = Train(f, s);
    tr.addCage(t, true);
    tr.addCage(fo, false);
    tr.addCage(fi, true);
    tr.addCage(si, false);
    tr.addCage(se, true);
    tr.printCagesState();
    std::cout << tr.findLength() << std::endl;
    return 0;
}

