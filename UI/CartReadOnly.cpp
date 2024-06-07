#include "CartReadOnly.h"
#include <QWidget>
#include <QGridLayout>
#include <QPainter>
#include <random>


void CartReadOnly::initUI() {
    // Create the app
    auto app = new QWidget();
    app->resize(1000, 1000);
    app->show();
}

void CartReadOnly::paintEvent(QPaintEvent *event) {
    QPainter painter{this};
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 30));
    for (auto car: carsToWashController.GetAllCars()) {
        // Generate random x and y
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> xCordGenerator(50, this->width()-50), yCrodGenerator(50, this->height()-50);
        int x= xCordGenerator(rng), y =  yCrodGenerator(rng);

        // Draw the text in a circle
        painter.drawEllipse(x, y, 50, 50);
        painter.drawText(x, y, 50, 50, Qt::AlignCenter, QString::fromStdString(car.getRegistrationNumber()));
    }

}

void CartReadOnly::update() {
    repaint();
}

CartReadOnly::CartReadOnly(CarsToWashController &carsToWashController): carsToWashController(carsToWashController) {
    initUI();
}
