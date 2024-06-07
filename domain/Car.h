#ifndef OOPUI_CAR_H
#define OOPUI_CAR_H

#include <string>
#include "CarValidators.h"

class Car {
private:
    std::string registrationNumber;
    std::string producer;
    std::string model;
    std::string type;
    CarValidators validators = CarValidators();

public:
    /*
     * Default constructor.
     * Preconditions: -
     * Post-conditions: -
     */
    Car();
    /*
     * The constructor of the Car class.
     * Preconditions: registrationNumber: a non-empty string
     *                producer: a non-empty string
     *                model: a non-empty string
     *                type: a non-empty string
     * Post-conditions: -
     * Raises: Invalid data.
     */
    Car(const std::string& registrationNumber, const std::string& producer, const std::string& model, const std::string& type);

    /*
     * A copy constructor.
     */
    Car(const Car& car);

    /*
     * RegistrationNumber getter.
     * Preconditions: -
     * Post-conditions: a string
     */
    std::string getRegistrationNumber() const;

    /*
     * Producer getter.
     * Preconditions: -
     * Post-conditions: a string
     */
    std::string getProducer() const;

    /*
     * Producer getter.
     * Preconditions: -
     * Post-conditions: a string
     */
    std::string getModel() const;

    /*
     * Model getter.
     * Preconditions: -
     * Post-conditions: a string
     */
    std::string getType() const;

    /*
     * RegistrationNumber setter.
     * Preconditions: newRegistrationNumber: a non-empty string
     * Post-conditions: -
     */
    void setRegistrationNumber(const std::string& newRegistrationNumber);

    /*
     * Producer setter.
     * Preconditions: newProducer: a non-empty string
     * Post-conditions: -
     */
    void setProducer(const std::string& newProducer);

    /*
     * Model setter.
     * Preconditions: newModel: a non-empty string
     * Post-conditions: -
     */
    void setModel(const std::string& newModel);

    /*
     * Type setter.
     * Preconditions: newType: a non-empty string
     * Post-conditions: -
     */
    void setType(const std::string& newType);

    /*
     * Compares this instance with another instance of the Car class.
     * Preconditions: carToCompareWith: instance of the Car class.
     * Post-conditions: a boolean
     */
    bool compareCars(Car carToCompareWith);

};

#endif //OOPUI_CAR_H
