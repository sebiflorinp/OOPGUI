#ifndef OOPUI_ABSTRACTCARREPO_H
#define OOPUI_ABSTRACTCARREPO_H

#include <vector>
#include "../domain/Car.h"

class AbstractCarRepo {

protected:
    std::vector<Car> cars;
public:

    AbstractCarRepo() = default;

    /*
     * Returns an instance of the Car class with the received registrationNumber.
     * Preconditions: registrationNumber: a non-empty string made of 7 characters
     * Post-conditions: an instance of the Car class
     * Raises: No car with the received registrationNumber exists.
     */
    virtual Car getCarByRegistrationNumber(const std::string& registrationNumber) = 0;

    /*
     * Returns a vector with all Car instances.
     * Preconditions: -
     * Post-conditions: a vector with instances of the Car class
     */
    virtual const std::vector<Car>& getAllCars() const = 0;

    /*
     * Adds the received Car instance in the repository.
     * Preconditions: newCar: an instance of the Car class.
     * Post-conditions: -
     * Raises: There is already another car with the same registrationNumber
     */
    virtual void addNewCar(const Car& newCar) = 0;

    /*
     * Deletes the instance of the Car class with the received registrationNumber
     * Preconditions: registrationNumber: a string made of 7 characters
     * Post-conditions: -
     * Raises: No car with the received registrationNumber exists.
     */
    virtual void deleteCarByRegistrationNumber(const std::string& registrationNumber) = 0;

    /*
     * Updates the instance of the Car class with the received registrationNumber to match updatedCar.
     * Preconditions: registrationNumber: a string made of 7 characters
     *                updatedCar: an instance of the Car class.
     * Post-conditions: -
     * Raises: No car with the received registrationNumber exists.
     */
    virtual void updateCarByRegistrationNumber(const std::string& registrationNumber, Car updatedCar) = 0;

    /*
     * Empties the repository.
     * Preconditions: -
     * Post-conditions: -
     */
    virtual void emptyRepository() = 0;
};

#endif //OOPUI_ABSTRACTCARREPO_H
