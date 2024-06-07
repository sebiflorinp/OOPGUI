#include "Cart.h"
#include "../misc/Exceptions.h"
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>

void Cart::init() {
    // Create the app and layout
    auto* app = new QWidget();
    auto* appLayout = new QGridLayout();

    // Create the needed components for the app
    auto* fillButton = new QPushButton("FILL");
    auto* emptyButton = new QPushButton("EMPTY");
    auto* fillLineEdit = new QLineEdit();
    addedCars = new QListWidget();

    // Add the components in the layout
    appLayout->addWidget(addedCars, 0, 0, 1, 2);
    appLayout->addWidget(fillButton, 1, 0, 1, 1);
    appLayout->addWidget(fillLineEdit, 1,1, 1, 1);
    appLayout->addWidget(emptyButton, 2, 0, 1, 2);

    app->setLayout(appLayout);
    app->show();

    // Add onClick event for the fill button
    QObject::connect(fillButton, &QPushButton::clicked,app, [=](){
        auto number = fillLineEdit->text().toInt();
        try {
            carsToWashController.addRandomCars(number);
            refreshLists();
            notify();
        } catch (AddRandomCarsError& e) {
            QMessageBox::warning(this, "Error", "Car not found.");
        }
    });
}

void Cart::refreshLists() {
    auto carsToWash = carsToWashController.GetAllCars();

    // Add cars in the cars to wash list
    addedCars->clear();
    for (auto car: carsToWash) {
        auto* item = new QListWidgetItem(QString::fromStdString(car.getRegistrationNumber()));
        addedCars->addItem(item);
    }
}

Cart::Cart(CarsToWashController &carsToWashController): carsToWashController(carsToWashController) {
    init();
    refreshLists();
}

void Cart::update() {
    refreshLists();
}
