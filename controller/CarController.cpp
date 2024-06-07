#include "CarController.h"
#include "../misc/Exceptions.h"
#include "../undo/Undo.h"
#include <fstream>

CarController::CarController(AbstractCarRepo& carRepository): carRepository(carRepository) {}

void CarController::addNewCar(
        const std::string& registrationNumber,
        const std::string& type,
        const std::string& model,
        const std::string& producer
) {
    // create new car object and try to add it in the repository
    Car newCar(registrationNumber, producer, model, type);
    carRepository.addNewCar(newCar);
    // Add the action in the list of actions that will be undone
    actionsToUndo.push_back(std::make_unique<UndoAdd>(newCar, carRepository));
}

Car CarController::findCarByRegistrationNumber(const std::string& registrationNumber) {
    // return the car with the given registrationNumber or throw an error
    return this->carRepository.getCarByRegistrationNumber(registrationNumber);
}

const std::vector<Car>& CarController::getAllCars() {
    return this->carRepository.getAllCars();
}

void CarController::deleteCarByRegistrationNumber(const std::string& registrationNumber) {
    // Save a copy of the car that will be deleted
    Car carToDelete = findCarByRegistrationNumber(registrationNumber);
    // Deletes the car with the given registrationNumber or throw an error if there is no car with the given registrationNumber
    this->carRepository.deleteCarByRegistrationNumber(registrationNumber);
    // Add the action in the list of actions that will be undone
    actionsToUndo.push_back(std::make_unique<UndoDelete>(carToDelete, carRepository));
}

void CarController::updateCarByRegistrationNumber(const std::string& registrationNumber, const std::string& newRegistrationNumber, const std::string& type, const std::string& model, const std::string& producer) {
    // Save a copy of the old car.
    Car oldCar = findCarByRegistrationNumber(registrationNumber);
    // Create the updated car
    Car updatedCar = Car(newRegistrationNumber, producer, model, type);
    // Updates the car
    this->carRepository.updateCarByRegistrationNumber(registrationNumber, updatedCar);
    // Add the action in the list of actions to be undone
    actionsToUndo.push_back(std::make_unique<UndoUpdate>(oldCar, updatedCar, carRepository));
}

std::vector<Car> CarController::filter(std::string toEqual,std::vector<Car> (*filterByCriteria)(const std::vector<Car>&,const std::string&)) {
    return filterByCriteria(carRepository.getAllCars(), toEqual);
}

std::vector<Car>
CarController::sort(const std::vector<Car> & cars, const std::string& sortingOrder, std::vector<Car> (*sortByCriteria)(std::vector<Car>, const std::string&)) {
    return sortByCriteria(cars, sortingOrder);
}

std::unordered_map<std::string, TypeDTO> CarController::createTypeReport() {
    // Use a map to store the types of cars and their frequency
    std::unordered_map<std::string, int> typeReportWithoutDTO;
    for (auto car: carRepository.getAllCars()) {
        typeReportWithoutDTO[car.getType()]++;
    }

    // Create a map with TypeDTOs
    std::unordered_map<std::string, TypeDTO> typeReportWithDTO;
    for (auto pair: typeReportWithoutDTO) {
        typeReportWithDTO[pair.first] = TypeDTO(pair.first, pair.second);

    }
    return typeReportWithDTO;
}

void CarController::saveData(std::string filename) {
    // Create (or override) a data.txt file and save the data.
    std::ofstream out(filename);
    for (auto car: carRepository.getAllCars()) {
        out << car.getRegistrationNumber() << " " << car.getType() << " " << car.getModel() << " " << car.getProducer() << "\n";
    }
}

void CarController::loadData(std::string filename) {
    // Empty the repository
    for (auto car: carRepository.getAllCars()) {
        carRepository.deleteCarByRegistrationNumber(car.getRegistrationNumber());
    }

    // Load the data from the data.txt file
    std::ifstream in(filename);
    std::string registrationNumber, type, model, producer;
    while (in >> registrationNumber >> type >> model >> producer) {
        Car newCar = Car(registrationNumber, producer, model, type);
        carRepository.addNewCar(newCar);
    }
}

void CarController::undo() {
    // Check if there is any action to undo.
    if (actionsToUndo.empty()) {
        throw UndoError("There is no action to undo.");
    }

    // Perform the undo and delete the last element from the list.
    actionsToUndo.back()->doUndo();
    actionsToUndo.pop_back();
}
