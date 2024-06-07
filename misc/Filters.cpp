#include "Filters.h"
#include "algorithm"

std::vector<Car> filterByProducer(const std::vector<Car>& cars, const std::string& producer) {
    std::vector<Car> result;
    copy_if(cars.begin(), cars.end(), std::back_inserter(result), [&](const Car& car){return car.getProducer() == producer;});
    return result;
}

std::vector<Car> filterByType(const std::vector<Car>& cars, const std::string& type) {
    std::vector<Car> result;
    copy_if(cars.begin(), cars.end(), std::back_inserter(result), [&](const Car& car){return car.getType() == type;});
    return result;
}