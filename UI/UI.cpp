#include "UI.h"
#include "../misc/Exceptions.h"
#include "../misc/Filters.h"
#include "../misc/SortingFunctions.h"
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QSpacerItem>
#include <sstream>
#include "../controller/CarController.h"
#include "Cart.h"

UI::UI(CarController& carController, CarsToWashController& carsToWashController): carController(carController), carsToWashController(carsToWashController) {
    initUI();
    refreshLists(carController.getAllCars());
}

void UI::initUI() {
    carController.loadData();
    refreshLists(carController.getAllCars());
    // Create the app and its layout
    auto* app = new QWidget();
    auto* appLayout = new QGridLayout();

    // Create the form and its layout
    auto* form = new QWidget();
    auto* formLayout = new QGridLayout();

    // Create the necessary widgets for the form
    auto* registrationNumberLineEdit = new QLineEdit();
    auto* typeLineEdit = new QLineEdit();
    auto* modelLineEdit = new QLineEdit();
    auto* producerLineEdit = new QLineEdit();
    auto* producerFilterLineEdit = new QLineEdit();
    auto* typeFilterLineEdit = new QLineEdit();

    // Create the buttons for the form
    auto* addButton = new QPushButton("ADD");
    auto* updateButton = new QPushButton("UPDATE");
    auto* deleteButton = new QPushButton("DELETE");
    auto* undoButton = new QPushButton("UNDO");
    auto* filterByProducerButton = new QPushButton("FILTER");
    auto* filterByTypeButton = new QPushButton("FILTER");
    auto* resetFiltersButton = new QPushButton("RESET filters");
    auto* cartButton = new QPushButton("CART");
    auto* cartGUIButton = new QPushButton("CART GUI");

    // Create the buttons for sorting
    auto* sortByRegistrationNumberASCButton = new QPushButton("ASC");
    auto* sortByRegistrationNumberDESCButton = new QPushButton("DESC");
    auto* sortByTypeButtonASCButton = new QPushButton("ASC");
    auto* sortByTypeButtonDESCButton = new QPushButton("DESC");
    auto* sortByProducerAndModelButtonASCButton = new QPushButton("ASC");
    auto* sortByProducerAndModelButtonDESCButton = new QPushButton("DESC");
    auto* defaultOrderButton = new QPushButton("RESET car order");

    // Add the widgets in the form layout and set the layout
    // Actual form for addition, update and details
    formLayout->addWidget(new QLabel("Registration Number: "), 0, 0);
    formLayout->addWidget(registrationNumberLineEdit, 0, 1, 1, 4);
    formLayout->addWidget(new QLabel("Type: "), 1, 0);
    formLayout->addWidget(typeLineEdit, 1, 1, 1, 4);
    formLayout->addWidget(new QLabel("Model: "), 2, 0);
    formLayout->addWidget(modelLineEdit, 2, 1, 1, 4);
    formLayout->addWidget(new QLabel("Producer: "), 3, 0);
    formLayout->addWidget(producerLineEdit, 3, 1, 1, 4);

    // Buttons for CRUD operations
    formLayout->addWidget(addButton, 4, 0, 1, 1);
    formLayout->addWidget(updateButton, 4, 1, 1, 4);
    formLayout->addWidget(deleteButton, 5, 0, 1, 1);
    formLayout->addWidget(undoButton, 5, 1, 1, 4);

    // Filters section
    formLayout->addWidget(new QLabel("Filters:"), 6, 0, 1, 1);
    formLayout->addWidget(new QLabel("Producer"), 7, 0, 1, 1);
    formLayout->addWidget(producerFilterLineEdit, 7, 1 ,1, 2);
    formLayout->addWidget(filterByProducerButton, 7, 3, 1, 2);
    formLayout->addWidget(new QLabel("Type"), 8, 0, 1, 1);
    formLayout->addWidget(typeFilterLineEdit, 8, 1, 1, 2);
    formLayout->addWidget(filterByTypeButton, 8, 3, 1, 2);
    formLayout->addWidget(resetFiltersButton, 9 , 0, 1, 5);
    formLayout->addWidget(cartGUIButton, 15, 1, 1, 1);
    formLayout->addWidget(cartButton, 15, 2, 1, 2);

    // Sorting section
    formLayout->addWidget(new QLabel("Sorting:"), 10, 0);
    formLayout->addWidget(new QLabel("Registration number: "), 11, 0);
    formLayout->addWidget(sortByRegistrationNumberASCButton, 11, 2, 1, 1);
    formLayout->addWidget(sortByRegistrationNumberDESCButton, 11,3, 1, 1);
    formLayout->addWidget(new QLabel("Type: "), 12, 0);
    formLayout->addWidget(sortByTypeButtonASCButton, 12, 2, 1, 1);
    formLayout->addWidget(sortByTypeButtonDESCButton, 12,3, 1, 1);
    formLayout->addWidget(new QLabel("Producer and model: "), 13, 0);
    formLayout->addWidget(sortByProducerAndModelButtonASCButton, 13, 2, 1, 1);
    formLayout->addWidget(sortByProducerAndModelButtonDESCButton, 13,3, 1, 1);
    formLayout->addWidget(defaultOrderButton, 14, 0, 1, 4);
    form->setLayout(formLayout);

    // Create
    Cart* cartAppp = new Cart(carsToWashController);

    // Add the components of the layout
    appLayout->addWidget(carsList, 0, 0, 4, 1);
    appLayout->addWidget(form, 0, 1, 4, 5);
    appLayout->addWidget(dynamicButton, 10, 0, 1, 6);
    // Set the layout and display the app
    app->setLayout(appLayout);
    app->show();

    // create cart app
    auto* cartWidget = new QWidget();
    auto* cartLayout = new QGridLayout();

    // Add onClick event for addButton
    QObject::connect(addButton, &QPushButton::clicked, carsList, [=](){
        // Extract the data from the line edits
        auto registrationNumber = registrationNumberLineEdit->text().toStdString();
        auto type = typeLineEdit->text().toStdString();
        auto model = modelLineEdit->text().toStdString();
        auto producer = producerLineEdit->text().toStdString();

        // Add the car
        try {
            carController.addNewCar(registrationNumber, type, model, producer);
        } catch (InvalidDataError& e) {
            QMessageBox::warning(this, "Error", QString::fromStdString(e.getErrorMessage()));
        } catch (DuplicateDataError& e) {
            QMessageBox::warning(this, "Error", QString::fromStdString(e.getErrorMessage()));
        }

        // Refresh the list
        refreshLists(carController.getAllCars());

        // Save data
        carController.saveData();
    });

    // Add onClick event for carsList
    QObject::connect(carsList, &QListWidget::clicked, this, [=](){
        // Extract the registration number from the list and get the car
        auto registrationNumber = carsList->selectedItems()[0]->text().toStdString();
        auto car = carController.findCarByRegistrationNumber(registrationNumber);

        // Put the values in the line edits
        registrationNumberLineEdit->setText(QString::fromStdString(car.getRegistrationNumber()));
        typeLineEdit->setText(QString::fromStdString(car.getType()));
        modelLineEdit->setText(QString::fromStdString(car.getModel()));
        producerLineEdit->setText(QString::fromStdString(car.getProducer()));
    });

    // Add onClick event for updateButton
    QObject::connect(updateButton, &QPushButton::clicked, this, [=](){
        // Show a warning if there is no item selected
        if (carsList->selectedItems().size() == 0) {
            QMessageBox::warning(this, "Warning", "In order to perform an update you need to select a car.");
            return;
        }

        // Extract the values from the line edits and selected item
        auto newRegistrationNumber = registrationNumberLineEdit->text().toStdString();
        auto newType = typeLineEdit->text().toStdString();
        auto newModel = modelLineEdit->text().toStdString();
        auto newProducer = producerLineEdit->text().toStdString();
        auto oldRegistrationNumber = carsList->selectedItems()[0]->text().toStdString();

        // Try to perform the update
        try {
            carController.updateCarByRegistrationNumber(oldRegistrationNumber, newRegistrationNumber, newType, newModel, newProducer);
        } catch (InvalidDataError& e) {
            QMessageBox::warning(this, "Error", QString::fromStdString(e.getErrorMessage()));
        } catch (DuplicateDataError& e) {
            QMessageBox::warning(this, "Error", QString::fromStdString(e.getErrorMessage()));
        }

        // Save the data
        carController.saveData();

        // Refresh the lists
        refreshLists(carController.getAllCars());
    });

    // Add onClick event for undoButton
    QObject::connect(undoButton, &QPushButton::clicked, this, [=](){
        // Try to perform the undo, save the data and refresh the lists
        try {
            carController.undo();
            carController.saveData();
            refreshLists(carController.getAllCars());
        } catch (UndoError& e) {
            QMessageBox::warning(this, "Error", QString::fromStdString(e.getErrorMessage()));
        }
    });

    // Add onClick event for deleteButton
    QObject::connect(deleteButton, &QPushButton::clicked, this, [=](){
        // Check if any car was selected
        if (carsList->selectedItems().size() == 0) {
            QMessageBox::warning(this, "Warning", "In order to perform a delete operation, a car needs to be selectd.");
            return;
        }

        // Extract the registration number from the list, delete the car and save the data
        auto registrationNumber = carsList->selectedItems()[0]->text().toStdString();
        carController.deleteCarByRegistrationNumber(registrationNumber);
        carController.saveData();
        refreshLists(carController.getAllCars());
    });

    // Add onClick event for filterByProducerButton
    QObject::connect(filterByProducerButton, &QPushButton::clicked, this, [=](){
        // Check if there is anything in the line edit corresponding to this filter
        if (producerFilterLineEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Warning", "In order to filter by producer you need to input a producer in the designated space.");
            return;
        }
        // Extract the text from the designated edit line
        auto producer = producerFilterLineEdit->text().toStdString();

        // Display the filtered cars
        refreshLists(carController.filter(producer, filterByProducer));
    });

    // Add onClick event for filterByTypeButton
    QObject::connect(filterByTypeButton, &QPushButton::clicked, this, [=](){
        // Check if there is anything in the line edit corresponding to this filter
        if (typeFilterLineEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Warning", "In order to filter by type you need to input a type in the designated space.");
            return;
        }
        // Extract the text from the designated edit line
        auto type = typeFilterLineEdit->text().toStdString();

        // Display the filtered cars
        refreshLists(carController.filter(type, filterByType));
    });

    // Add onClick event to resetFiltersButton
    QObject::connect(resetFiltersButton, &QPushButton::clicked, this, [=](){
        // Refresh the list
        refreshLists(carController.getAllCars());
    });

    // Add onClick event to sort by registration ASC button
    QObject::connect(sortByRegistrationNumberASCButton, &QPushButton::clicked, this, [=](){
        // Refresh the list
        refreshLists(carController.sort(carController.getAllCars(), "ASC", sortCarsByRegistrationNumber));
    });

    // Add onClick event to sort by registration DESC button
    QObject::connect(sortByRegistrationNumberDESCButton, &QPushButton::clicked, this, [=](){
        // Refresh the list
        refreshLists(carController.sort(carController.getAllCars(), "DESC", sortCarsByRegistrationNumber));
    });

    // Add onClick event to sort by type ASC button
    QObject::connect(sortByTypeButtonASCButton, &QPushButton::clicked, this, [=](){
        // Refresh the list
        refreshLists(carController.sort(carController.getAllCars(), "ASC", sortCarsByType));
    });

    // Add onClick event to sort by type DESC button
    QObject::connect(sortByTypeButtonDESCButton, &QPushButton::clicked, this, [=](){
        // Refresh the list
        refreshLists(carController.sort(carController.getAllCars(), "DESC", sortCarsByType));
    });

    // Add onClick event to sort by producer and model ASC
    QObject::connect(sortByProducerAndModelButtonASCButton, &QPushButton::clicked, this, [=](){
        // Refresh the list
        refreshLists(carController.sort(carController.getAllCars(), "ASC", sortCarsByProducerAndModel));
    });

    // Add onClick event to sort by producer and model DESC
    QObject::connect(sortByProducerAndModelButtonDESCButton, &QPushButton::clicked, this, [=](){
        // Refresh the list
        refreshLists(carController.sort(carController.getAllCars(), "DESC", sortCarsByProducerAndModel));
    });

    // Add onClick event to reset the order
    QObject::connect(defaultOrderButton, &QPushButton::clicked, this, [=](){
        // Refresh the list
        refreshLists(carController.getAllCars());
    });


    // Add onClick event for cartButton
    QObject::connect(cartButton, &QPushButton::clicked, this, [=](){
        Cart* cartApp = new Cart(carsToWashController);
        //this.addObserver
    });

}

void UI::refreshLists(std::vector<Car> carsToDisplay) {
    // Get the cars to display in the list
    carsList->clear();
    for (auto car: carsToDisplay) {
        carsList->addItem(new QListWidgetItem(QString::fromStdString(car.getRegistrationNumber())));
    }

    auto* dynamicButtonsLayout = new QHBoxLayout();
    auto report = carController.createTypeReport();

    for (auto type: report) {
        // Create the QPushButton
        std::string  typeName = type.second.getType();
        int amount = type.second.getCount();

        // use stringstream to create a formatted string
        std::stringstream stringstream;
        stringstream << typeName << " (" << amount << ")";
        auto* button = new QPushButton(QString::fromStdString(stringstream.str()));

        // add the button in the layout
        dynamicButtonsLayout->addWidget(button);
    }

    // set the layout to the widget
    QLayoutItem *child;
    if (dynamicButton->layout()) {
        while (!dynamicButton->layout()->isEmpty()) {
            child = dynamicButton->layout()->takeAt(0);
            delete child;
        }
    }

    delete dynamicButton->layout();
    dynamicButton->setLayout(dynamicButtonsLayout);
}

void UI::update() {
}

