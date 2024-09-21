#pragma once
#include "FileAdoptionList.h"


class HtmlAdoptionList : public FileAdoptionList {

    //? Class that represents an adoption list stored in a html file.

public:

    //? Constructor for a html adoption list.
    HtmlAdoptionList(const std::string &fileName) : FileAdoptionList(fileName) {};

    void addPet(const Pet &pet) override;

    //? Writes the adoption list to a html file.
    void writeToFile() override;

    //? Reads the adoption list from a html file.
    void readFromFile() override;

    //? Displays the adoption list, opening it with Google Chrome.
    void displayAdoptionList() override;
};
