#pragma once

#include "../domain/Pet.h"
#include "../validators/PetValidator.h"
#include "../domain/file_adoption_list/FileAdoptionList.h"
#include "../repository/file_repository/TxtRepository.h"


class PetService {

    //? Class that manages the business logic of the application.
    //? It is responsible for validating the data and calling the repository methods.

private:
    TxtRepository repository;
    FileAdoptionList *adoptionList;

public:
    //? Default constructor for a PetService.
    PetService() : repository("../files/data.txt"), adoptionList(nullptr) {};

    //? Constructor for a PetService object.
    PetService(const TxtRepository &repository, FileAdoptionList *adoptionList);

    //? Copy constructor for a PetService object.
    PetService(const PetService &other);

    //? Destructor for a PetService object.
    ~PetService() = default;

    //? Assignment operator for a PetService object.
    PetService &operator=(const PetService &other);

    //? Changes the file format of the adoption list.
    void modifyFileFormat(std::string const &fileFormat);

    //? Adds a new pet to the repository.
    void addPet(std::string const &name, std::string const &breed, int age, std::string const &photo);

    //? Removes a pet from the repository.
    void removePet(std::string const &name, std::string const &breed);

    //? Updates the data of a pet.
    void updatePet(std::string const &name, std::string const &breed, int newAge, std::string const &newPhoto);

    //? Returns a vector containing all the pets in the repository.
    std::vector<Pet> getAll();

    //? Adds a pet to the adoption list.
    void addPetToAdoptionList(std::string const &name, std::string const &breed);

    //? Returns a vector containing all the pets in the adoption list.
    std::vector<Pet> getAdoptionList() const;

    //? Saves the adoption list to a file.
    void saveAdoptionList();

    //? Saves and opens the adoption list.
    void openAdoptionList();

    //? Returns a vector containing all the pets in the repository that have an age less than a given age.
    std::vector<Pet> filterByAge(int age);

    //? Returns a vector containing all the pets in the repository that have a breed equal to a given breed and
    //? an age less than a given age.
    std::vector<Pet> filterByBreedAndAge(std::string const &breed, int age);
};
