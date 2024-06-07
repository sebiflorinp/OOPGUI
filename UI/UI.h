#ifndef OOPUI_UI_H
#define OOPUI_UI_H


#include <QWidget>
#include <QListWidget>
#include "../domain/Car.h"
#include "../controller/CarController.h"
#include "../controller/CarsToWashController.h"
#include "../misc/Observable.h"
#include "Cart.h"

class UI: QWidget, public Observer{
    Q_OBJECT;
private:
    QListWidget* carsList= new QListWidget();
    QListWidget* carsToWashList = new QListWidget();
    QWidget* dynamicButton = new QWidget();
    CarController& carController;
    CarsToWashController& carsToWashController;
    std::vector<Cart*> carts;

public:
    UI(CarController& carController, CarsToWashController& carsToWashController);

    void initUI();

    void refreshLists(std::vector<Car> carsToDisplay);

    void update() override;
};


#endif //OOPUI_UI_H
