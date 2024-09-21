#include <vector>
#pragma once
#include "../domain/Pet.h"


class Repository {

    //? Class that represents a repository.

protected:
    std::vector<Pet> elements;

public:

    //? Constructor for a repository.
    Repository() = default;

    //? Copy constructor for a repository.
    Repository(const Repository &other);

    //? Destructor for a repository.
    ~Repository() = default;

    //? Assignment operator for a repository.
    Repository &operator=(const Repository &other);

    //? Adds an element to the repository.
    virtual void add(Pet element);

    //? Removes an element from the repository by index.
    virtual void remove(int index);

    //? Removes an element from the repository by value.
    virtual void remove(const Pet &element);

    //? Overload of the [] operator.
    Pet &operator[](int index);

    //? Returns all the elements from the repository.
    std::vector<Pet> getAll();

    //? Returns the size of the repository.
    int size();

    //? Checks if the repository is empty.
    bool empty();

    //? Searches for an element in the repository.
    bool search(const Pet &element);

    virtual void readFromFile();

    virtual void writeToFile();
};
