---

# Pet Adoption Management System

## Overview

This project is a **Pet Adoption Management System** built using C++, with support for CSV, HTML, and SQLite file storage. The application provides a Qt-based GUI for administrators and users to manage pets for adoption. It includes features for adding, removing, and filtering pets, and it supports both CSV and HTML formats for exporting adoption lists.

### Features

- **Pet Management**: Add, remove, and update pets in the repository.
- **File Storage**: Supports saving pet data in text, CSV, HTML, and SQLite databases.
- **Adoption List**: Manage a list of pets ready for adoption, with the ability to save and open the list in CSV or HTML formats.
- **User and Admin Modes**: Separate modes for administrators (manage pets) and users (view and adopt pets).
- **Undo/Redo**: Supports undo/redo functionality for administrative actions.
- **Data Validation**: Ensures valid input for pet data, including non-empty fields and age validation.
- **Statistics Visualization**: Displays pet statistics, including a pie chart for pets by age category.
- **GUI**: A simple and intuitive graphical user interface (GUI) built using Qt.

## Project Structure

```bash
.
├── domain/               # Domain models for Pet and Adoption List
│   ├── Pet.h             # Pet class declaration
│   ├── Pet.cpp           # Pet class definition
│   ├── AdoptionList.h    # Adoption List class declaration
│   └── AdoptionList.cpp  # Adoption List class definition
│   └── file_adoption_list/ # CSV and HTML Adoption List handling
│       ├── CsvAdoptionList.h
│       └── CsvAdoptionList.cpp
│       ├── HtmlAdoptionList.h
│       └── HtmlAdoptionList.cpp
├── repository/           # Repository for managing pets and data storage
│   ├── TxtRepository.h   # Text file repository for pet data
│   ├── TxtRepository.cpp # Txt repository implementation
│   ├── DataBaseRepository.h  # SQLite repository for pet data
│   └── DataBaseRepository.cpp
├── service/              # Business logic for the system
│   ├── PetService.h      # Pet service class declaration
│   └── PetService.cpp    # Pet service class definition
├── validators/           # Data validation logic
│   ├── PetValidator.h    # Validator for Pet class
│   └── PetValidator.cpp
├── extra/                # Extra components
│   ├── exceptions.h      # Custom exceptions
│   ├── Utilities.h       # Utility functions (e.g., string tokenization)
├── qtui/                 # Qt GUI interface for the application
│   ├── qtui.h            # GUI class declaration
│   └── qtui.cpp          # GUI class definition
├── files/                # Data files and export formats
│   ├── data.txt          # Initial pet data in text format
│   ├── adoption_list.csv # CSV format of the adoption list
│   ├── adoption_list.html# HTML format of the adoption list
├── resources/            # Resource files (images)
│   └── dog.jpeg          # Sample image for pets
├── main.cpp              # Application entry point
└── README.md             # README file for project description
```

## How It Works

- **Pet and Adoption List Models**:
  - The system includes two core models: `Pet` and `AdoptionList`. The `Pet` class represents each pet's details, including name, breed, age, and a photo link. The `AdoptionList` class manages a collection of pets ready for adoption.
  - Pets can be exported to both CSV and HTML formats for easy viewing.

- **Repository**:
  - The repository manages CRUD operations for pets and provides support for saving/loading from files (TXT, CSV, HTML, SQLite).

- **Service**:
  - The service layer handles business logic, including adding/removing pets, filtering pets by breed and age, and managing the adoption list.

- **GUI**:
  - The system uses the Qt framework for the graphical user interface. There are separate windows for admins to manage pets and for users to adopt pets.
  - Supports undo/redo functionality for admin actions.

## Build and Run Instructions

### Prerequisites

- **Qt**: Install Qt on your system.
- **C++11**: Make sure your compiler supports C++11 or later.
- **SQLite**: Ensure SQLite is installed if you plan to use the database feature.

### Build Instructions

1. Clone the repository:

   ```bash
   git clone https://github.com/your-repository-link/pet-adoption-system.git
   ```

2. Open the project in Qt Creator, or navigate to the project folder and build it using qmake:

   ```bash
   qmake
   make
   ```

3. Run the application:

   ```bash
   ./pet-adoption-system
   ```

### Usage

- **Admin Mode**: Allows you to add, remove, and update pets in the repository. Supports undo/redo of operations.
- **User Mode**: Lets users view and adopt pets. Adoption lists can be viewed in either CSV or HTML formats.
- **File Format**: The application allows saving and loading of data from CSV, HTML, or SQLite databases.

### Example Data

Sample data in the `data.txt` file:

```
Bella,Golden Retriever,3,https://example.com/dog-photo
Max,Labrador,2,https://example.com/dog-photo
```

## Extending the System

- **Add New Features**: You can extend the system by implementing additional features like more advanced filtering, enhanced file formats, or different data storage options.
- **Expand the Domain Model**: Add more attributes to the `Pet` class or create new entities (e.g., `Owner`, `AdoptionRecord`).

## License

MIT License. Feel free to use, modify, and distribute this project.

---

