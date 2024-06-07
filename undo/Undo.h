#ifndef OOPUI_UNDO_H
#define OOPUI_UNDO_H


#include <string>
#include <utility>
#include "../repository/CarRepository.h"

class Undo {
public:
    /*
     * Reverts the previous action
     * Preconditions: -
     * Post-conditions: -
     */
    virtual void doUndo() = 0;

    /*
     * Destructor for Undo
     * Preconditions: -
     * Post-conditions: -
     */
    virtual ~Undo() = default;
};

class UndoAdd: public Undo {
private:
    Car car;
    AbstractCarRepo& carRepositoryReference;
public:
    /*
     * Constructor for UndoAdd
     * Preconditions: car: An instance of the Car class
     *               carRepositoryReference: reference to an instance of the CarRepository class
     */
    UndoAdd(const Car& car, AbstractCarRepo& carRepositoryReference): car(car), carRepositoryReference(carRepositoryReference) {};

    /*
     * Reverts the addition of the previously added car.
     * Preconditions: -
     * Post-conditions: -
     */
    void doUndo() override;
};

class UndoDelete: public Undo {
private:
    Car car;
    AbstractCarRepo& carRepositoryReference;
public:
    /*
     * Constructor for UndoDelete
     * Preconditions: car: An instance of the Car class
     *                carRepositoryReference: reference to an instance of the CarRepository class
     */
    UndoDelete(const Car& car, AbstractCarRepo& carRepositoryReference): car(car), carRepositoryReference(carRepositoryReference) {};

    /*
     * Reverts the deletion of the previously deleted car.
     * Preconditions: -
     * Post-conditions: -
     */
    void doUndo() override;
};

class UndoUpdate: public Undo {
private:
    Car oldCar;
    Car newCar;
    AbstractCarRepo& carRepositoryReference;
public:
    /*
     * Constructor for UndoUpdate
     * Preconditions: oldCar: An instance of the Car class
     *                newCar: An instance of the Car class
     *                carRepositoryReference: reference to an instance of the CarRepository class
     */
    UndoUpdate(const Car& oldCar, const Car& newCar, AbstractCarRepo& carRepositoryReference): oldCar(oldCar), newCar(newCar), carRepositoryReference(carRepositoryReference) {};

    /*
     * Reverts the update of the previously updated car.
     * Preconditions: -
     * Post-conditions: -
     */
    void doUndo() override;
};

#endif //OOPUI_UNDO_H
