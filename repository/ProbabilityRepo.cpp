#include <algorithm>
#include "ProbabilityRepo.h"
#include "../misc/Exceptions.h"
#include "../misc/Utils.h"



Car ProbabilityRepo::getCarByRegistrationNumber(const std::string &registrationNumber) {
    // Throw the dice
    unsigned int diceResult = getRandomIndex(100);

    // If the result is less than the probability, throw an error
    if (diceResult < probability * 100) {
        throw RandomError("You are unlucky. Try again.");
    }

    // find the car with the received registration
    auto result = std::find_if(cars.begin(), cars.end(), [&](const Car& car){return car.getRegistrationNumber() == registrationNumber;});
    if (result == cars.end()) {
        throw CarNotFoundError("There is no car with the input registration number.");
    } else {
        return *result;
    }

}

const std::vector<Car> &ProbabilityRepo::getAllCars() const {
    // Throw the dice
    unsigned int diceResult = getRandomIndex(100);

    // If the result is less than the probability, throw an error
    if (diceResult < probability * 100) {
        throw RandomError("You are unlucky. Try again.");
    }



    return cars;
}

void ProbabilityRepo::addNewCar(const Car &newCar) {
    // Throw the dice
    unsigned int diceResult = getRandomIndex(100);

    // If the result is less than the probability, throw an error
    if (diceResult < probability * 100) {
        throw RandomError("You are unlucky. Try again.");
    }

    // check if there is already a Car with the registrationNumber of the received one.
    auto result = std::find_if(cars.begin(), cars.end(), [&](const Car& car){return newCar.getRegistrationNumber() == car.getRegistrationNumber();});
    if (result == cars.end()) {
        cars.push_back(newCar);
        return;
    } else {
        throw DuplicateDataError("The is already a car with the input registration number");
    }

}

void ProbabilityRepo::deleteCarByRegistrationNumber(const std::string &registrationNumber) {
    // Throw the dice
    unsigned int diceResult = getRandomIndex(100);

    // If the result is less than the probability, throw an error
    if (diceResult < probability * 100) {
        throw RandomError("You are unlucky. Try again.");
    }

    // find the car that needs to be deleted
    auto result = std::find_if(cars.begin(), cars.end(), [&](const Car& car){return car.getRegistrationNumber() == registrationNumber;});
    if (result != cars.end()) {
        cars.erase(result);
        return ;
    } else {
        throw CarNotFoundError("The is no car with the input registration number");
    }

}

void ProbabilityRepo::updateCarByRegistrationNumber(const std::string &registrationNumber, Car updatedCar) {
    // Throw the dice
    unsigned int diceResult = getRandomIndex(100);

    // If the result is less than the probability, throw an error
    if (diceResult < probability * 100) {
        throw RandomError("You are unlucky. Try again.");
    }

    // ensure that the update operation will not lead to multiple cars with the same registration number
    if (registrationNumber != updatedCar.getRegistrationNumber()) {
        for (auto & car : cars) {
            if (car.getRegistrationNumber() == updatedCar.getRegistrationNumber()) {
                // throw an error because the update will create multiple cars with the same registration number
                throw DuplicateDataError("The update operation would create multiple cars with the same registration number.");
            }
        }
    }
    // find the car that will be updated
    for (auto & car : cars) {
        if (car.getRegistrationNumber() == registrationNumber) {
            car = updatedCar;
            return;
        }
    }

    // if no car was found throw an error
    throw  CarNotFoundError("There is not car with the input registration number.");

}

void ProbabilityRepo::emptyRepository() {
    // Throw the dice
    unsigned int diceResult = getRandomIndex(100);

    // If the result is less than the probability, throw an error
    if (diceResult < probability * 100) {
        throw RandomError("You are unlucky. Try again.");
    }

    cars.clear();
}
