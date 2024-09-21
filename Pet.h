#pragma once
#include <string>
#include <tuple>
#include <iostream>

class Pet {

    //? Class that represents a pet.
    //? A pet has a name, a breed, an age and a photo.
    //? The name and the breed are strings, the age is an integer and the photo is a string.
    //? A pet is uniquely identified by its name and its breed.

private:
    std::string name;
    std::string breed;
    int age;
    std::string photo;

public:

    //? Default constructor for a Pet.
    //? The name, the breed and the photo are empty strings, while the age is 0.
    Pet() : age(0) {};

    //? Constructor with parameters for a Pet.
    Pet(std::string const &name, std::string const &breed, int age, std::string const &photo);

    //? Copy constructor for a Pet.
    Pet(const Pet &other);

    //? Destructor for a Pet.
    ~Pet() = default;

    //? Overload of the = operator for a Pet.
    Pet &operator=(const Pet &other);

    //? Getters
    std::string getName() const;
    std::string getBreed() const;
    int getAge() const;
    std::tuple<std::string, std::string> getId() const; //? returns a tuple of strings (name, breed)
    std::string getPhoto() const;
    void setName(std::string const &newName);

    //? Setters
    void setBreed(std::string const &newBreed);
    void setAge(int newAge);
    void setPhoto(std::string const &newPhoto);


    //? Equality operator for a Pet.
    //? Two pets are equal if all their attributes are equal.
    bool operator==(const Pet &other) const;

    //? Inequality operator for a Pet.
    bool operator!=(const Pet &other) const;

    //? String representation of a Pet.
    std::string toString() const;

    //? Extraction operator for a Pet.
    friend std::istream &operator>>(std::istream &inputStream, Pet& pet);

    //? Insertion operator for a Pet.
    friend std::ostream &operator<<(std::ostream &outputStream, Pet& pet);
};