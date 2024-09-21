#pragma once
#include "FileRepository.h"


class TxtRepository : public FileRepository {

    //? Class that represents a repository that reads and writes to a text file.

public:

    //? Constructor for a text repository.
    TxtRepository(const std::string &fileName);

    //? Writes the elements from the repository to the file.
    void writeToFile() override;

    //? Reads the elements from the file to the repository.
    void readFromFile() override;
};

