#ifndef OOPUI_PROBABILITYREPO_H
#define OOPUI_PROBABILITYREPO_H

#include "AbstractCarRepo.h"

class ProbabilityRepo: public AbstractCarRepo{
private:
    float probability;
public:
    /*
     * Constructor for the ProbabilityRepo class.
     * Preconditions: probability: a float number between 0 and 1
     */
    ProbabilityRepo(float probability): probability(probability) {};
    /*
     * Returns an instance of the Car class with the received registrationNumber or throws a RandomError.
     * Preconditions: registrationNumber: a non-empty string made of 7 characters
     * Post-conditions: an instance of the Car class
     * Raises: No car with the received registrationNumber exists.
     *         You are unlucky, try again.
     */
    Car getCarByRegistrationNumber(const std::string& registrationNumber) override;

    /*
     * Returns a vector with all Car instances or throws a RandomError.
     * Preconditions: -
     * Post-conditions: a vector with instances of the Car class
     * Raises: You are unlucky, try again.
     */
    const std::vector<Car>& getAllCars() const override;

    /*
     * Adds the received Car instance in the repository or throws a RandomError.
     * Preconditions: newCar: an instance of the Car class.
     * Post-conditions: -
     * Raises: There is already another car with the same registrationNumber
     *         You are unlucky, try again.
     */
    void addNewCar(const Car& newCar) override;

    /*
     * Deletes the instance of the Car class with the received registrationNumber or throws a RandomError.
     * Preconditions: registrationNumber: a string made of 7 characters
     * Post-conditions: -
     * Raises: No car with the received registrationNumber exists.
     *         You are unlucky, try again.
     */
    void deleteCarByRegistrationNumber(const std::string& registrationNumber) override;

    /*
     * Updates the instance of the Car class with the received registrationNumber to match updatedCar or throws a RandomError.
     * Preconditions: registrationNumber: a string made of 7 characters
     *                updatedCar: an instance of the Car class.
     * Post-conditions: -
     * Raises: No car with the received registrationNumber exists.
     *         You are unlucky, try again.
     */
    void updateCarByRegistrationNumber(const std::string& registrationNumber, Car updatedCar) override;

    /*
     * Empties the repository or throws a RandomError.
     * Preconditions: -
     * Post-conditions: -
     * Raises: You are unlucky, try again.
     */
    void emptyRepository() override;

};

#endif //OOPUI_PROBABILITYREPO_H
