#ifndef OOPUI_CARTREADONLY_H
#define OOPUI_CARTREADONLY_H


#include <QWidget>
#include "../misc/Observer.h"
#include "../controller/CarsToWashController.h"

class CartReadOnly: QWidget, public Observer{
    Q_OBJECT
private:
    CarsToWashController& carsToWashController;
    void initUI();
    void paintEvent(QPaintEvent *event) override;
    void update() override;
public:
    explicit CartReadOnly(CarsToWashController& carsToWashController);
};


#endif //OOPUI_CARTREADONLY_H
