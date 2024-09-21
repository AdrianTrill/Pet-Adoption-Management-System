#pragma once
#include <vector>
#include <string>
#include "../domain/Pet.h"


class PetException : public std::exception {

    //? Class that represents an exception for a pet.

private:
    std::vector<std::string> errors;

public:

    //? Constructor for a PetException.
    PetException(std::vector<std::string> errors);

    //? Getter for the errors.
    std::vector<std::string> getErrors() const;
};


class PetValidator {

    //? Class that represents a validator for a pet.

public:

    //? Default constructor for a PetValidator.
    PetValidator() = default;

    //? Validates a pet.
    static void validate(const Pet &pet);
};
