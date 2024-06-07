#ifndef OOPUI_OBSERVABLE_H
#define OOPUI_OBSERVABLE_H


#include <vector>
#include "Observer.h"

class Observable {
protected:
    std::vector<Observer*> observers;
    void notify();

public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
};


#endif //OOPUI_OBSERVABLE_H
