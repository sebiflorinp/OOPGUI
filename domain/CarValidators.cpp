#include "CarValidators.h"
#include "../misc/Exceptions.h"

void CarValidators::validateRegistrationNumber(const std::string &registrationNumber) {
    // check if the string is empty
    if (registrationNumber.empty()) {
        throw std::runtime_error("The registration number is invalid.\n");
    }

    // check if it is made of 7 characters
    if (registrationNumber.size() != 7) {
        throw std::runtime_error("The registration number is invalid.\n");
    }
}

void CarValidators::validateModel(const std::string &model) {
    // check if the string is empty
    if (model.empty()) {
        throw std::runtime_error("The model is invalid.\n");
    }
}

void CarValidators::validateType(const std::string &type) {
    // check if the string is empty
    if (type.empty()) {
        throw std::runtime_error("The type is invalid.\n");
    }
}

void CarValidators::validateProducer(const std::string &producer) {
    // check if the string is empty
    if (producer.empty()) {
        throw std::runtime_error("The producer is invalid.\n");
    }
}