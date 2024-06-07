#include <stdexcept>
#include "Car.h"
#include "../misc/Exceptions.h"


Car::Car(const std::string& registrationNumber, const std::string& producer, const std::string& model,
         const std::string& type) {
    std::string errors = "";

    // check if the registrationNumber is valid and assign it if it is
    try {
        CarValidators::validateRegistrationNumber(registrationNumber);
        this->registrationNumber = registrationNumber;
    } catch (const std::runtime_error& error) {
        errors.append(error.what());
    }

    // check if the producer is valid and assign it if it is
    try {
        CarValidators::validateProducer(producer);
        this->producer = producer;
    } catch (const std::runtime_error& error) {
        errors.append(error.what());
    }

    // check if the model is valid and assign it if it is
    try {
        CarValidators::validateModel(model);
        this->model = model;
    } catch (const std::runtime_error& error) {
        errors.append(error.what());
    }

    // check if the type is valid and assign it if it is
    try {
        CarValidators::validateType(type);
        this->type = type;
    } catch (const std::runtime_error& error) {
        errors.append(error.what());
    }

    if (!errors.empty()) {
        throw InvalidDataError(errors);
    }

}



std::string Car::getRegistrationNumber() const {
    return this->registrationNumber;
}

std::string Car::getModel() const {
    return this->model;
}

std::string Car::getProducer() const {
    return this->producer;
}

std::string Car::getType() const {
    return this->type;
}

void Car::setRegistrationNumber(const std::string& newRegistrationNumber) {
    // check if the newRegistrationNumber is valid and set is if it is
    CarValidators::validateRegistrationNumber(newRegistrationNumber);
    this->registrationNumber = newRegistrationNumber;
}

void Car::setModel(const std::string& newModel) {
    // check if the newModel is valid and set it if it is
    CarValidators::validateModel(newModel);
    this->model = newModel;
}

void Car::setProducer(const std::string& newProducer) {
    // check if the newProducer is valid and set it if it is
    CarValidators::validateProducer(newProducer);
    this->producer = newProducer;
}

void Car::setType(const std::string& newType) {
    // check if the newType is valid and set it if it is
    CarValidators::validateType(newType);
    this->type = newType;
}

bool Car::compareCars(Car carToCompareWith) {
    // compare all fields and if one is not equal return false
    if (
            this->registrationNumber != carToCompareWith.getRegistrationNumber() ||
            this->model!= carToCompareWith.getModel() ||
            this->producer!= carToCompareWith.getProducer() ||
            this->type!= carToCompareWith.getType()
            ) {
        return false;
    }
    return true;
}

Car::Car(const Car &car) {
    registrationNumber = car.registrationNumber;
    model = car.model;
    producer = car.producer;
    type = car.type;

    printf("Constructor\n");
}

Car::Car() {
}
