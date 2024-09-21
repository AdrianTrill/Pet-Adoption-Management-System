#include "DataBaseRepository.h"
#include <iostream>
#include <sqlite3.h> // Include the SQLite header

DataBaseRepository::DataBaseRepository(const std::string &fileName) : fileName(fileName) {
    // Open a database connection
    int exit = sqlite3_open(fileName.c_str(), &db);
    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Opened Database Successfully!" << std::endl;
    }
}


void DataBaseRepository::writeToFile() {
    // Create a table
    std::string sql = "CREATE TABLE PETS("
                      "ID INT PRIMARY KEY     NOT NULL,"
                      "NAME           TEXT    NOT NULL,"
                      "BREED          TEXT    NOT NULL,"
                      "AGE            INT     NOT NULL,"
                      "PHOTO          TEXT    NOT NULL);";

    // Execute the SQL statement
    int exit = sqlite3_exec(db, sql.c_str(), nullptr, 0, nullptr);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
    } else {
        std::cout << "Table created Successfully" << std::endl;
    }
}


void DataBaseRepository::readFromFile() {
    // Create a SQL statement
    std::string sql = "SELECT * FROM PETS";

    // Execute the SQL statement
    int exit = sqlite3_exec(db, sql.c_str(), nullptr, 0, nullptr);
    if (exit != SQLITE_OK) {
        std::cerr << "Error SELECT" << std::endl;
    } else {
        std::cout << "Operation OK" << std::endl;
    }
}


void DataBaseRepository::add(const Pet element) {
    // Create a SQL statement
    std::string sql = "INSERT INTO PETS (ID, NAME, BREED, AGE, PHOTO) VALUES ("
                      + std::to_string(element.getID()) + ", '"
                      + element.getName() + "', '"
                      + element.getBreed() + "', "
                      + std::to_string(element.getAge()) + ", '"
                      + element.getPhoto() + "');";

    // Execute the SQL statement
    int exit = sqlite3_exec(db, sql.c_str(), nullptr, 0, nullptr);
    if (exit != SQLITE_OK) {
        std::cerr << "Error INSERT" << std::endl;
    } else {
        std::cout << "Records created Successfully" << std::endl;
    }
}


void DataBaseRepository::remove(int index) {
    // Create a SQL statement
    std::string sql = "DELETE FROM PETS WHERE ID = " + std::to_string(index) + ";";

    // Execute the SQL statement
    int exit = sqlite3_exec(db, sql.c_str(), nullptr, 0, nullptr);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
    } else {
        std::cout << "Records deleted Successfully" << std::endl;
    }
}


void DataBaseRepository::remove(const Pet &element) {
    // Create a SQL statement
    std::string sql = "DELETE FROM PETS WHERE ID = " + std::to_string(element.getID()) + ";";

    // Execute the SQL statement
    int exit = sqlite3_exec(db, sql.c_str(), nullptr, 0, nullptr);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
    } else {
        std::cout << "Records deleted Successfully" << std::endl;
    }
}


DataBaseRepository::~DataBaseRepository() {
    // Close the database connection
    sqlite3_close(db);
}


