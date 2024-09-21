#pragma once
#include "../AdoptionList.h"


class FileAdoptionList : public AdoptionList {

    //? Class that represents an adoption list stored in a file.
    //? It is an abstract class.

protected:
    std::string fileName;

public:

    //? Constructor for a file adoption list.
    FileAdoptionList(const std::string &fileName) : fileName(fileName) {};

    //? Writes the adoption list to a file.
    virtual void writeToFile() = 0;

    //? Reads the adoption list from a file.
    virtual void readFromFile() = 0;

    //? Displays the adoption list, opening it with the appropriate application.
    virtual void displayAdoptionList() = 0;
};
