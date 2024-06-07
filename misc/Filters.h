#ifndef OOPUI_FILTERS_H
#define OOPUI_FILTERS_H

#include <vector>
#include "../domain/Car.h"

/*
 * Filters the cars by the producer.
 * Preconditions: cars: an instance of the DynamicArray class.
 *                producer: a string
 * Post-conditions: an instance of the DynamicArray class.
 */
std::vector<Car> filterByProducer(const std::vector<Car>& cars, const std::string& producer);

/*
 * Filters the cars by the type.
 * Preconditions: cars: an instance of the DynamicArray class.
 *                producer: a string
 * Post-conditions: an instance of the DynamicArray class.
 */
std::vector<Car> filterByType(const std::vector<Car>& cars, const std::string& type);

#endif //OOPUI_FILTERS_H
