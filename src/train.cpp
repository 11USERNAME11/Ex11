// Copyright 2021 Bogomazov
#include <iostream>
#include "../include/train.h"
Train::Train(Cage* _first,
                Cage* _last) {
    first = _first;
    last = _last;
    first->prev = last;
    first->next = last;
    last->prev = first;
    last->next = first;
}

void Train::addCage(Cage* newCage, bool turnLightOn) {
    if (turnLightOn) {
        newCage->on();
    }
    if (last) {
        newCage->prev = last;
        newCage->prev->next = newCage;
        last = newCage;
    } else {
        last = newCage;
    }
}

void Train::printCagesState() {
    int i = 0;
    Cage* cage = first;
    while (cage != last) {
        std::cout << "Number: " << i << "; Light is "
            << ((cage->get()) ? "on":"off") << std::endl;
        cage = cage->next;
        i++;
    }
    std::cout << "Number: " << i << "; Light is "
            << ((cage->get()) ? "on":"off") << std::endl;
}

int Train::findLength() {
    bool found = false;
    int i;
    while (!found) {
        first->on();
        i = 0;
        std::cout << "JOPA\n";
        Cage* cage = first->next;
        std::cout << "JOPAa\n";
        while (!cage->get()) {
            i++;
            std::cout << "JOPAb\n";
            cage = cage->next;
        }
        std::cout << "JOPA1\n";
        cage->off();
        if (!first->get())
            found = true;
        std::cout << "JOPA2\n";
    }
    return i + 1;
}
