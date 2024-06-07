#ifndef OOPUI_CART_H
#define OOPUI_CART_H


#include <QWidget>
#include <QListWidget>
#include "../controller/CarsToWashController.h"
#include "../misc/Observer.h"
#include "../misc/Observable.h"

class Cart: QWidget, public Observer, public Observable{
    Q_OBJECT
private:
    CarsToWashController& carsToWashController;
    QListWidget* addedCars;

public:
    Cart(CarsToWashController& carsToWashController);

    void init();

    void refreshLists();

    void update() override;
};


#endif //OOPUI_CART_H
