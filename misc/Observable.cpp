#include <algorithm>
#include "Observable.h"

void Observable::addObserver(Observer *observer) {
    observers.push_back(observer);
}

void Observable::removeObserver(Observer *observer) {
    observers.erase(std::remove(begin(observers), end(observers), observer), end(observers));
}

void Observable::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}
