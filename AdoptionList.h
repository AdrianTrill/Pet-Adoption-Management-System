#pragma once
#include <vector>
#include "Pet.h"


class AdoptionList {

    //? Class that represents an adoption list.

protected:
    std::vector<Pet> pets;
    int current;

public:

    //? Default constructor for an adoption list.
    //? Initialized empty
    AdoptionList() : current(0) {};

    //? Copy constructor for an adoption list.
    AdoptionList(const AdoptionList &other);

    //? Destructor for an adoption list.
    virtual ~AdoptionList() = default;

    //? Overload of the = operator for an adoption list.
    AdoptionList &operator=(const AdoptionList &adoptionList);

    //? Adds a pet to the adoption list.
    virtual void addPet(const Pet &pet);

    //? Gets all the pets from the adoption list.
    std::vector<Pet> getAll() const;

    //? Gets the size of the adoption list.
    int size();

    //? Checks if the adoption list is empty.
    bool empty();
};
