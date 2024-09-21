#pragma once
#include "../Repository.h"


class FileRepository : public Repository {

    //? Class that represents a repository that reads and writes to a file.

protected:
    std::string fileName;

protected:

    //? Writes the elements from the repository to the file.
    virtual void writeToFile() = 0;

    //? Reads the elements from the file to the repository.
    virtual void readFromFile() = 0;

public:

    //? Constructor for a file repository.
    FileRepository(const std::string &fileName);

    //? Adds an element to the repository.
    void add(Pet element) override;

    //? Removes an element from the repository by index.
    void remove(int index) override;

    //? Removes an element from the repository by value.
    void remove(const Pet &element) override;
};