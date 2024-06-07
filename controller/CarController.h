#ifndef OOPUI_CARCONTROLLER_H
#define OOPUI_CARCONTROLLER_H

#include <unordered_map>
#include "../domain/Car.h"
#include "../domain/TypeDTO.h"
#include "../repository/CarRepository.h"
#include "../undo/Undo.h"

#include <memory>


class CarController {
private:
    AbstractCarRepo& carRepository;
    std::vector<std::unique_ptr<Undo>> actionsToUndo;
public:
    // Delete the copy constructor and the copy assignment operator in order for the unique_ptr to not break the app
    CarController(const CarController&) = delete;
    CarController& operator=(const CarController&) = delete;

    /*
     * The constructor of the CarRepository class.
     * Preconditions: carRepository: an instance of the CarRepository class
     * Post-conditions: -
     */
    explicit CarController(AbstractCarRepo& carRepository);

    /*
     * Returns the car with the received registrationNumber.
     * Preconditions: registrationNumber: a string
     * Post-conditions: an instance of the Car class
     * Raises: There is no car with the received registrationNumber
     */
    Car findCarByRegistrationNumber(const std::string& registrationNumber);

    /*
     * Returns a vector with all the cars in the repository.
     * Preconditions: -
     * Post-conditions: a vector with instances of the Car class
     */
    const std::vector<Car>& getAllCars();

    /*
     * Adds a new Car in the repository.
     * Preconditions: registrationNumber: a non-empty string
     *                type: a non-empty string
     *                model: a non-empty string
     *                producer: a non-empty string
     * Post-conditions: -
     * Raises: There is already a car with the registrationNumber of the received car
     */
    void addNewCar(const std::string& registrationNumber, const std::string& type, const std::string& model, const std::string& producer);

    /*
     * Updates the car with the received registrationNumber to match the received car
     * Preconditions: registrationNumber: a string
     *                newCar: an instance of the Car class
     * Post-conditions: -
     * Raises: There is no car with the received registrationNumber.
     *         The operation will lead to multiple cars having the same registrationNumber
     */
    void updateCarByRegistrationNumber(const std::string& registrationNumber, const std::string& newRegistrationNumber, const std::string& type, const std::string& model, const std::string& producer);

    /*
     * Deletes the car with the received registrationNumber.
     * Preconditions: registrationNumber: a string
     * Post-conditions: -
     * Raises: There is no car with the received registrationNumber
     */
    void deleteCarByRegistrationNumber(const std::string& registrationNumber);

    /*
     * Filters the instances of the Car class depending on the received string and function
     * Preconditions: toEqual: a string
     *                a function that takes a Car and a  string and return a bool
     * Post-conditions: a vector with instance of the car object
     */
    std::vector<Car> filter(std::string toEqual, std::vector<Car> (*filterByCriteria)(const std::vector<Car>&, const std::string&));

    /*
     * Sorts the instance of the Car class depending on the received string and function.
     * Preconditions: cars: an instance of the DynamicArray<Car> class.
     *                sortingOrder: a string that must be either "ASC" or "DESC"
     *                sortByCriteria: a function that takes as arguments an instance of the DynamicArray<Car> class and a string.
     */
    std::vector<Car> sort(const std::vector<Car>& cars, const std::string& sortingOrder, std::vector<Car> (*sortByCriteria)(std::vector<Car>,const std::string&));

    /*
     * Creates a report with the number of time each type appears in the repository.
     * Preconditions: -
     * Post-conditions: an unordered_map with the type as the key and the number of appearances as the value
     */
    std::unordered_map<std::string, TypeDTO> createTypeReport();

    /*
     * Saves the data from the repository to data.txt.
     * Preconditions: filename: a string
     * Post-conditions: -
     */
    void saveData(std::string filename = "data.txt");

    /*
     * Loads the data from data.txt to the repository.
     * Preconditions: filename: a string
     * Post-conditions: -
     */
    void loadData(std::string filename = "data.txt");

    /*
     * Undoes the last action.
     * Preconditions: -
     * Post-conditions: -
     * Raises: There is no action to undo.
     */
    void undo();
};

#endif //OOPUI_CARCONTROLLER_H
