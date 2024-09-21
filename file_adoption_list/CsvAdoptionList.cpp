#include <fstream>
#include "CsvAdoptionList.h"
#include "../../extra/exceptions.h"


void CsvAdoptionList::writeToFile() {
    std::ofstream file(this->fileName);
    if (!file.is_open()) {
        throw FileException("could not open file");
    }

    for (auto pet: this->pets) {
        file << pet;
    }

    file.close();
}

void CsvAdoptionList::displayAdoptionList() {
    // Specify the path to the Excel application on macOS
    std::string excelPath = "/Applications/Microsoft Excel.app";

    // Construct the command to open the CSV file in Excel
    std::string command = "open -a \"" + excelPath + "\" " + this->fileName;

    // Execute the command
    std::system(command.c_str());
}

void CsvAdoptionList::readFromFile() {
    std::ifstream file(this->fileName);
    if (!file.is_open()) {
        throw FileException("could not open file");
    }

    Pet pet;
    while (file >> pet) {
        this->pets.push_back(pet);
    }

    file.close();

}

void CsvAdoptionList::addPet(const Pet &pet) {
    AdoptionList::addPet(pet);
    this->writeToFile();
}
