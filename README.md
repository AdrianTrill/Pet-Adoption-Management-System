---

# Pet Adoption Management System

## Overview

The **Pet Adoption Management System** is a C++ application designed to manage the process of pet adoptions. It features a comprehensive pet management interface, allowing administrators to add, remove, update, and filter pets. Users can view available pets and add them to their adoption list. The system leverages Qt for a clean, intuitive graphical user interface (GUI), and supports multiple storage formats (CSV, HTML, SQLite) for persistent data handling.

### Key Features

- **Pet Management**: Easily add, remove, update, and filter pets based on attributes such as age and breed.
- **Multiple File Storage Options**: Supports saving pet data in text, CSV, HTML, and SQLite database formats for flexible data management.
- **Adoption List**: Users can create and manage their own list of adopted pets, with export options in CSV or HTML.
- **User and Admin Modes**: The system distinguishes between administrator functionalities (pet management) and user functionalities (pet browsing and adoption).
- **Undo/Redo Functionality**: Provides support for undoing and redoing actions in the admin panel.
- **Data Validation**: Ensures all pet data is valid and properly formatted before adding it to the repository.
- **Statistics Visualization**: Includes graphical features, such as pie charts, to represent statistics (e.g., distribution of pets by age).
- **Cross-Platform**: Built using C++ and Qt, making it compatible across multiple platforms.

---

## Project Structure

```bash
.
├── domain/                      # Domain models for Pet and Adoption List
│   ├── Pet.h                    # Pet class definition
│   ├── Pet.cpp                  # Pet class implementation
│   ├── AdoptionList.h           # Adoption List definition
│   └── AdoptionList.cpp         # Adoption List implementation
│   └── file_adoption_list/      # CSV and HTML adoption list management
│       ├── CsvAdoptionList.h    
│       └── CsvAdoptionList.cpp  
│       ├── HtmlAdoptionList.h   
│       └── HtmlAdoptionList.cpp 
├── repository/                  # Repositories for managing pet data
│   ├── TxtRepository.h          # Text file repository definition
│   ├── TxtRepository.cpp        # Txt repository implementation
│   ├── DataBaseRepository.h     # SQLite database repository definition
│   └── DataBaseRepository.cpp   # SQLite database repository implementation
├── service/                     # Business logic for pet management
│   ├── PetService.h             # Pet service definition
│   └── PetService.cpp           # Pet service implementation
├── validators/                  # Pet data validation
│   ├── PetValidator.h           # PetValidator definition
│   └── PetValidator.cpp         # PetValidator implementation
├── extra/                       # Utility and exception handling
│   ├── exceptions.h             # Custom exceptions
│   ├── Utilities.h              # Utility functions
├── qtui/                        # Qt GUI interface for the application
│   ├── qtui.h                   # GUI definition
│   └── qtui.cpp                 # GUI implementation
├── files/                       # Data files for storage and export
│   ├── data.txt                 # Initial pet data (text format)
│   ├── adoption_list.csv        # CSV format of adoption list
│   ├── adoption_list.html       # HTML format of adoption list
├── resources/                   # Static resources (images)
│   └── dog.jpeg                 # Sample pet image
├── main.cpp                     # Application entry point
└── README.md                    # README file (you are here)
```

---

## System Components

### **Pet and Adoption List Models**
- The system's core models are the `Pet` and `AdoptionList` classes. Each `Pet` has attributes such as name, breed, age, and a photo link, which are managed in an `AdoptionList` for adoption purposes.
  
### **Repository**
- **TxtRepository**: Manages pet data stored in text files.
- **DataBaseRepository**: Handles pet data stored in a SQLite database.
  
### **Service Layer**
- The `PetService` class implements business logic for interacting with the repository, including adding, removing, and updating pet data, as well as managing the adoption list.

### **GUI Layer**
- Built using the Qt framework, the GUI provides an intuitive interface with separate windows for administrators and users. It supports CRUD operations for pets, file export, and real-time adoption management.

---

## Features

### **Administrator Mode**
Administrators can:
- **Add new pets** with complete details (name, breed, age, photo link).
- **Update existing pet information**.
- **Remove pets** from the repository.
- **View a list of all pets** with the option to filter by breed or age.
- **Undo/Redo** previous actions using a simple button interface.

### **User Mode**
Users can:
- **Browse available pets** and filter them by breed and age.
- **Adopt pets**, adding them to their personal adoption list.
- **Save the adoption list** in either CSV or HTML format.
- **View adoption statistics** through dynamic visualizations (e.g., pie charts).

### **File Format Support**
- **CSV**: Exports the adoption list for spreadsheet applications.
- **HTML**: Exports the adoption list as a webpage.
- **SQLite**: Stores and manages the pet data in a relational database.

---

## Installation and Setup

### Prerequisites

- **Qt**: Install Qt on your system.
- **C++11**: Ensure your compiler supports C++11 or later.
- **SQLite**: Install SQLite if using the database storage option.

### Build and Run Instructions

1. Clone the repository:

   ```bash
   git clone https://github.com/your-repository-link/pet-adoption-system.git
   ```

2. Open the project in Qt Creator, or navigate to the project directory and build using `qmake`:

   ```bash
   qmake
   make
   ```

3. Run the application:

   ```bash
   ./pet-adoption-system
   ```

---

## Usage

### Admin Mode:
1. Run the application.
2. Select "Admin" from the entry window.
3. Add, remove, or update pets using the provided interface.
4. Undo or redo operations as needed.

### User Mode:
1. Select "User (CSV)" or "User (HTML)" from the entry window.
2. Browse through pets, filter by breed and age.
3. Adopt pets and save the adoption list to CSV or HTML.
4. View adoption statistics for pets in the system.

---

## Example Data

Sample data in `data.txt`:

```
Bella,Golden Retriever,3,https://example.com/dog-photo
Max,Labrador,2,https://example.com/dog-photo
```

---

## Extending the System

- **Add Features**: You can extend the system with additional functionality such as more advanced filtering options or support for exporting to different file formats.
- **Enhance the Model**: Add more attributes to `Pet` or introduce new entities like `Owner` or `AdoptionRecord` to track more detailed information about each pet.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Contributions

Contributions are welcome! Please feel free to submit issues, feature requests, or pull requests to help improve the project.

---

## Contact

For further information or questions, feel free to contact me.

---

## GitHub Repository Description

**Pet Adoption Management System**

A C++ application featuring a Qt-based GUI for managing pet adoptions. Admins can add, update, or remove pets, while users can browse and adopt pets. Supports CSV, HTML, and SQLite storage formats, and includes undo/redo functionality for admin actions.

---
