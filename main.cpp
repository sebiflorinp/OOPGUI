#include <QApplication>
#include <QPushButton>
#include "repository/CarRepository.h"
#include "controller/CarController.h"
#include "controller/CarsToWashController.h"
#include "UI/UI.h"
#include <QGridLayout>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    CarRepository repo = CarRepository();
    CarController carsController = CarController(repo);
    CarsToWashController carsToWashController = CarsToWashController(repo);
    UI ui = UI(carsController, carsToWashController);


    return QApplication::exec();
}
