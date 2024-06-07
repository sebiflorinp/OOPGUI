#include <vector>
#include <algorithm>
#include "SortingFunctions.h"

std::vector<Car> sortCarsByRegistrationNumber(std::vector<Car> cars, const std::string& sortingOrder) {
    std::sort(cars.begin(), cars.end(), [&](const Car& car1, const Car& car2){return sortingOrder == "ASC" ? car1.getRegistrationNumber() < car2.getRegistrationNumber() : car1.getRegistrationNumber() > car2.getRegistrationNumber();});
    return cars;
}

std::vector<Car> sortCarsByType(std::vector<Car> cars, const std::string& sortingOrder) {
    std::sort(cars.begin(), cars.end(), [&](const Car& car1,const Car& car2){return sortingOrder == "ASC" ? car1.getType() < car2.getType() : car1.getType() > car2.getType();});
    return cars;
}

std::vector<Car> sortCarsByProducerAndModel(std::vector<Car> cars, const std::string& sortingOrder) {
    std::sort(cars.begin(), cars.end(), [&](const Car &car1, const Car &car2) { return compareProducersAndModels(car1, car2, sortingOrder) == 1;});
    return cars;
}

int compareRegistrationNumbers(const Car& firstCar,const Car& secondCar,const std::string& sortingOrder) {
    if (sortingOrder == "ASC") {
        if (firstCar.getRegistrationNumber() < secondCar.getRegistrationNumber()) {
            return 1;
        } else if (firstCar.getRegistrationNumber() > secondCar.getRegistrationNumber()) {
            return -1;
        } else {
            return 0;
        }
    } else {
        return compareRegistrationNumbers(firstCar, secondCar, "ASC") * -1;
    }
}

int compareTypes(Car& firstCar, Car& secondCar, const std::string& sortingOrder) {
    if (sortingOrder == "ASC") {
        if (firstCar.getType() < secondCar.getType()) {
            return 1;
        } else if (firstCar.getType() > secondCar.getType()) {
            return -1;
        } else {
            return 0;
        }
    } else {
        return compareTypes(firstCar, secondCar, "ASC") * -1;
    }
}

int compareProducersAndModels(const Car& firstCar,const Car& secondCar,const std::string& sortingOrder) {
    if (sortingOrder == "ASC") {
        if (firstCar.getProducer() < secondCar.getProducer()) {
            return 1;
        } else if (firstCar.getProducer() > secondCar.getProducer()) {
            return -1;
        } else {
            if (firstCar.getModel() < secondCar.getModel()) {
                return 1;
            } else if (firstCar.getModel() > secondCar.getModel()) {
                return -1;
            } else {
                return 0;
            }
        }
    } else {
        return compareProducersAndModels(firstCar, secondCar, "ASC") * -1;
    }
}

