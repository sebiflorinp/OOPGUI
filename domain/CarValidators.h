#ifndef OOPUI_CARVALIDATORS_H
#define OOPUI_CARVALIDATORS_H

#include <string>

class CarValidators {
public:
    /*
     * Validates the received registrationNumber.
     * Preconditions: registrationNumber: a string
     * Post-conditions: -
     * Raises: Invalid registrationNumber
     */
    static void validateRegistrationNumber(const std::string &registrationNumber);
    /*
     * Validates the received producer.
     * Preconditions: producer: a string
     * Post-conditions:
     * Raises: Invalid producer
     */
    static void validateProducer(const std::string &producer);

    /*
     * Validates the received model.
     * Preconditions: model: a string
     * Post-conditions:
     * Raises: Invalid model
     */
    static void validateModel(const std::string &model);

    /*
     * Validates the received type.
     * Preconditions: type: a string
     * Post-conditions:
     * Raises: Invalid type.
     */
    static void validateType(const std::string &type);

};

#endif //OOPUI_CARVALIDATORS_H
