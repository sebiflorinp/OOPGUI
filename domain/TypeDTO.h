#ifndef OOPUI_TYPEDTO_H
#define OOPUI_TYPEDTO_H

#include <string>
#include <utility>

class TypeDTO {
private:
    std::string type;
    int count;
public:
    /*
     * Default constructor
     * Preconditions: -
     */
    TypeDTO(): type("Undefined"), count(0) {};

    /*
     * Constructor
     * Preconditions: type: a string
     *                count: an integer
     */
    TypeDTO(std::string type, const int& count) : type(std::move(type)), count(count) {};

    /*
     * Type getter.
     * Preconditions: -
     * Post-conditions: a string
     */
    std::string getType();

    /*
     * Count getter.
     * Preconditions: -
     * Post-conditions: an integer
     */
    int getCount() const;
};


#endif //OOPUI_TYPEDTO_H
