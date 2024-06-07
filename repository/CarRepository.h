#ifndef OOPUI_CARREPOSITORY_H
#define OOPUI_CARREPOSITORY_H

#include "../domain/Car.h"
#include "AbstractCarRepo.h"
#include <vector>

class CarRepository : public AbstractCarRepo {
private:
    std::vector<Car> cars;

public:
    /*
     * Returns an instance of the Car class with the received registrationNumber.
     * Preconditions: registrationNumber: a non-empty string made of 7 characters
     * Post-conditions: an instance of the Car class
     * Raises: No car with the received registrationNumber exists.
     */
    Car getCarByRegistrationNumber(const std::string& registrationNumber) override;

    /*
     * Returns a vector with all Car instances.
     * Preconditions: -
     * Post-conditions: a vector with instances of the Car class
     */
    const std::vector<Car>& getAllCars() const override;

    /*
     * Adds the received Car instance in the repository.
     * Preconditions: newCar: an instance of the Car class.
     * Post-conditions: -
     * Raises: There is already another car with the same registrationNumber
     */
    void addNewCar(const Car& newCar) override;

    /*
     * Deletes the instance of the Car class with the received registrationNumber
     * Preconditions: registrationNumber: a string made of 7 characters
     * Post-conditions: -
     * Raises: No car with the received registrationNumber exists.
     */
    void deleteCarByRegistrationNumber(const std::string& registrationNumber) override;

    /*
     * Updates the instance of the Car class with the received registrationNumber to match updatedCar.
     * Preconditions: registrationNumber: a string made of 7 characters
     *                updatedCar: an instance of the Car class.
     * Post-conditions: -
     * Raises: No car with the received registrationNumber exists.
     */
    void updateCarByRegistrationNumber(const std::string& registrationNumber, Car updatedCar) override;

    /*
     * Empties the repository.
     * Preconditions: -
     * Post-conditions: -
     */
    void emptyRepository() override;
};

#endif //OOPUI_CARREPOSITORY_H
