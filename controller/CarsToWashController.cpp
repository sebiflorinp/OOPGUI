#include <fstream>
#include "CarsToWashController.h"
#include "../misc/Utils.h"
#include "../misc/Exceptions.h"

CarsToWashController::CarsToWashController(CarRepository& carRepositoryReference): carRepositoryReference(carRepositoryReference) {
}

std::vector<Car> CarsToWashController::GetAllCars() {
    return carsToWashRepository.getAllCars();
}

void CarsToWashController::addCarToWashRepository(const std::string& registrationNumber) {
    Car car = carRepositoryReference.getCarByRegistrationNumber(registrationNumber);
    carsToWashRepository.addNewCar(car);
}

void CarsToWashController::emptyRepository() {
    carsToWashRepository.emptyRepository();
}

void CarsToWashController::addRandomCars(int totalNumberOfCars) {
    CarRepository carsToChooseFrom = carRepositoryReference;

    // Check if there are already more cars in the carsToWashRepository than the total number of cars
    if (carsToWashRepository.getAllCars().size() >= totalNumberOfCars) {
        throw AddRandomCarsError("There are already more cars in the carsToWashRepository than the total number of cars.");
    }

    // Check if there are enough cars in the carRepository
    if (carRepositoryReference.getAllCars().size() < totalNumberOfCars) {
        throw AddRandomCarsError("There are not enough cars in the carRepository.");
    }

    // Remove all the cars that are already in the carsToWashRepository
    for (const Car& car : carsToWashRepository.getAllCars()) {
        carsToChooseFrom.deleteCarByRegistrationNumber(car.getRegistrationNumber());
    }

    // Add random cars to the carsToWashRepository until there are enough cars
    unsigned currentNumberOfCarsInWashRepository = carsToWashRepository.getAllCars().size();
    while (currentNumberOfCarsInWashRepository < totalNumberOfCars) {
        // Get a random index
        int size = carsToChooseFrom.getAllCars().size();
        unsigned randomIndex = getRandomIndex(size);

        // Add the car and delete it from carsToChooseFrom
        Car randomCar = carsToChooseFrom.getAllCars()[randomIndex];
        carsToWashRepository.addNewCar(randomCar);
        carsToChooseFrom.deleteCarByRegistrationNumber(randomCar.getRegistrationNumber());
        currentNumberOfCarsInWashRepository++;
    }
}

void CarsToWashController::exportCarsToWash(std::string exportFormat, std::string exportName) {
    // Delete all cars that are not in the reference but are in the carsToWashRepository
    for (const Car& car : carsToWashRepository.getAllCars()) {
        try {
            carRepositoryReference.getCarByRegistrationNumber(car.getRegistrationNumber());
        } catch (CarNotFoundError& e) {
            carsToWashRepository.deleteCarByRegistrationNumber(car.getRegistrationNumber());
        }

        if (exportFormat == "CSV") {
            std::ofstream csv(exportName + ".csv");
            for (auto car: carsToWashRepository.getAllCars()) {
                csv << car.getRegistrationNumber() << "," << car.getType() << "," << car.getModel() << "," << car.getProducer() + "\n";
            }
            csv.close();
        } else if (exportFormat == "HTML") {
            std::ofstream html(exportName + ".html");
            html << "<!DOCTYPE html><html><head><title>" + exportName + "</title></head><body><table><tr><th>Registration number</th><th>Type</th><th>Model</th><th>Producer</th></tr>" << std::endl;
            for (auto car: carsToWashRepository.getAllCars()) {
                html << "<tr><td>" << car.getRegistrationNumber() << "</td><td>" << car.getType() << "</td><td>" << car.getModel() << "</td><td>" << car.getProducer() << "</td></tr>" << std::endl;
            }
            html << "</table></body></html>";
        } else {
            throw InvalidExportFormatError("The export format is invalid.");
        }
    }
}

std::vector<Car> CarsToWashController::GetAllAvailableCars() {
    return carRepositoryReference.getAllCars();
}
