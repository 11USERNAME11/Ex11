// Copyright 2021 Bogomazov
#ifndef INCLUDE_TRAIN_H
#define INCLUDE_TRAIN_H
class Cage {
 private:
    bool light;
 public:
    Cage* next;
    Cage* prev;
    Cage(): light(false), next(nullptr), prev(nullptr) {}
    void on()  { this->light = true;}
    void off() { this->light = false; }
    bool get() const  { return light;  }
};

class Train {
 private:
    Cage* first;
    Cage* last;
 public:
    Train(Cage* _first = nullptr,
                Cage* _last = nullptr);
    void addCage(Cage* newCage, bool turnLightOn = false);
    void printCagesState();
    int findLength();
};

#endif  //  INCLUDE_TRAIN_H
