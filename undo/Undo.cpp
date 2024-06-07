#include "Undo.h"

void UndoAdd::doUndo() {
    // Undo the addition by deleting the added car
    carRepositoryReference.deleteCarByRegistrationNumber(car.getRegistrationNumber());
}

void UndoDelete::doUndo() {
    // Undo the deletion by adding back the deleted car
    carRepositoryReference.addNewCar(car);

}

void UndoUpdate::doUndo() {
    // Undo the update by updating the car to its previous state
    carRepositoryReference.updateCarByRegistrationNumber(newCar.getRegistrationNumber(), oldCar);
}
