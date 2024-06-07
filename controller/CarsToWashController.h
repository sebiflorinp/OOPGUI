#ifndef OOPUI_CARSTOWASHCONTROLLER_H
#define OOPUI_CARSTOWASHCONTROLLER_H
#include "../repository/CarRepository.h"

#ifndef CPPLAB_CARSTOWASHCONTROLLER_H
#define CPPLAB_CARSTOWASHCONTROLLER_H

#endif //CPPLAB_CARSTOWASHCONTROLLER_H

class CarsToWashController {
private:
    CarRepository& carRepositoryReference;
    CarRepository carsToWashRepository;
public:
    /*
     * The constructor of the CarsToWashController class.
     * Preconditions: carRepository: a reference to a CarRepository object.
     * Post-conditions: -
     */
    explicit CarsToWashController(CarRepository& carRepository);

    /*
     * Returns all the cars that can be added in the list.
     * Preconditions: -
     * Post-conditions: a vector with Car objects.
     */
    std::vector<Car> GetAllAvailableCars();

    /*
     * Returns all the cars from the carRepositoryReference.
     * Preconditions: -
     * Post-conditions: a vector of Car objects.
     */
    std::vector<Car> GetAllCars();

    /*
     * Adds a car in the carsToWashRepository.
     * Preconditions: registrationNumber: a string
     * Post-conditions: -
     * Raises: DuplicateDataError: There is already another car with the same registrationNumber.
     */
    void addCarToWashRepository(const std::string& registrationNumber);

    /*
     * Empties the carsToWashRepository.
     * Preconditions: -
     * Post-conditions: -
     */
    void emptyRepository();

    /*
     * Adds cars randomly in the carsToWashRepository until there are a certain number of cars.
     * Preconditions: totalNumberOfCars: an integer
     * Post-conditions: -
     */
    void addRandomCars(int totalNumberOfCars);

    /*
     * Exports the cars from the carsToWashRepository in a certain format.
     * Preconditions: exportFormat: a string
     *                exportName: a string
     * Post-conditions: -
     * Raises: InvalidExportFormatError: The export format is not valid.
     */
    void exportCarsToWash(std::string exportFormat, std::string exportName);
};
#endif //OOPUI_CARSTOWASHCONTROLLER_H
