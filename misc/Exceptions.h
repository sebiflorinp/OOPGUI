#ifndef OOPUI_EXCEPTIONS_H
#define OOPUI_EXCEPTIONS_H

#include <exception>
#include <stdexcept>
#include <utility>

class GenericException: std::exception {
public:
    explicit GenericException(std::string  errorMessage) : message(std::move(errorMessage)) {}

    std::string getErrorMessage();
private:
    const std::string message;
};

class CarNotFoundError : public GenericException {
    using GenericException::GenericException;
};

class InvalidDataError : public GenericException {
    using GenericException::GenericException;
};

class DuplicateDataError : public GenericException {
    using GenericException::GenericException;
};

class InvalidExportFormatError : public GenericException {
    using GenericException::GenericException;
};

class AddRandomCarsError : public GenericException {
    using GenericException::GenericException;
};

class UndoError : public GenericException {
    using GenericException::GenericException;
};

class RandomError : public GenericException {
    using GenericException::GenericException;
};

#endif //OOPUI_EXCEPTIONS_H
