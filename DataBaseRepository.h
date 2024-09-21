#pragma once
#include "repository.h"
#include <string>
#include "dataBaseLibrary/sqlite3.h"
using namespace std;

class DataBaseRepository : public Repository {
private:
    string fileName;
    sqlite3* db{};
public:
    DataBaseRepository(const std::string &fileName);

    void readFromFile() override;

    void writeToFile() override;

    void add(const Pet element) override;

    void remove(int index) override;

    void remove(const Pet &element) override;

    ~DataBaseRepository();
};