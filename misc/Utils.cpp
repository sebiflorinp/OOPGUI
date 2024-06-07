#include "Utils.h"
#include <random>

unsigned getRandomIndex(int size) {
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<> dist(0, size - 1);
    return dist(mt);
}
