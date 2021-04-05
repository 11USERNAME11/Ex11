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
        newCage->next = first;
        newCage->prev->next = newCage;
        last = newCage;
        first->prev = newCage;
    } else {
        last = newCage;
        first->prev = newCage;
        last->next = first;
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
        Cage* cage = first->next;
        while (!cage->get()) {
            i++;
            cage = cage->next;
        }
        cage->off();
        if (!first->get())
            found = true;
    }
    return i + 1;
}
