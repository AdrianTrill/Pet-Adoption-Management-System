#pragma once
#include "FileAdoptionList.h"


class CsvAdoptionList : public FileAdoptionList {

    //? Class that represents an adoption list stored in a csv file.

public:

    //? Constructor for a csv adoption list.
    CsvAdoptionList(const std::string &fileName) : FileAdoptionList(fileName) {};

    void addPet(const Pet &pet) override;

    //? Writes the adoption list to a csv file.
    void writeToFile() override;

    void readFromFile() override;

    //? Displays the adoption list, opening it with Microsoft Excel.
    void displayAdoptionList() override;
};