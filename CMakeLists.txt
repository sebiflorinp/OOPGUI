cmake_minimum_required(VERSION 3.28)
project(OOPUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(OOPUI main.cpp
        domain/Car.cpp
        domain/Car.h
        domain/CarValidators.cpp
        domain/CarValidators.h
        domain/TypeDTO.cpp
        domain/TypeDTO.h
        misc/Exceptions.h
        misc/Exceptions.cpp
        misc/Filters.cpp
        misc/Filters.h
        misc/SortingFunctions.cpp
        misc/SortingFunctions.h
        misc/Utils.cpp
        misc/Utils.h
        repository/AbstractCarRepo.cpp
        repository/AbstractCarRepo.h
        repository/CarRepository.cpp
        repository/CarRepository.h
        repository/ProbabilityRepo.cpp
        repository/ProbabilityRepo.h
        controller/CarController.cpp
        controller/CarController.h
        controller/CarsToWashController.cpp
        controller/CarsToWashController.h
        undo/Undo.cpp
        undo/Undo.h
        UI/UI.cpp
        UI/UI.h
        UI/Cart.cpp
        UI/Cart.h
        misc/Observer.cpp
        misc/Observer.h
        misc/Observable.cpp
        misc/Observable.h
        UI/CartReadOnly.cpp
        UI/CartReadOnly.h)
target_link_libraries(OOPUI
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

