#include "qtui.h"
#include "ui_QtUi.h"
#include "extra/exceptions.h"
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QTableView>
using namespace std;

QtUi::QtUi(QWidget *parent, const PetService &petService) : QWidget(parent), ui(new Ui::QtUi), petService(petService) {
    this->ui->setupUi(this);

    this->pets = this->petService.getAll();

    this->adminWindow = new QWidget();
    this->userWindow = new QWidget();
    this->entryWindow = new QWidget();
    this->adoptionListWindow = new QWidget();

    // entry window

    this->entryLayout = new QGridLayout();
    this->adminButton = new QPushButton("Admin");
    this->userCSVButton = new QPushButton("User CSV");
    this->userHTMLButton = new QPushButton("User HTML");
    this->entryLayout->addWidget(this->adminButton, 0, 0);
    this->entryLayout->addWidget(this->userCSVButton, 1, 0);
    this->entryLayout->addWidget(this->userHTMLButton, 2, 0);

    // add the layout to the admin
    this->entryWindow->setLayout(this->entryLayout);

    // style admin
    this->entryWindow->setWindowTitle("Entry");
    this->entryWindow->setFixedSize(450, 475);

    // admin window

    // admin layout
    this->adminLayout = new QHBoxLayout();
    this->adminOutputLayout = new QVBoxLayout();
    this->adminCommandsLayout = new QVBoxLayout();
    this->adminAddLayout = new QGridLayout();
    this->adminRemoveLayout = new QGridLayout();
    this->adminUpdateLayout = new QGridLayout();

    // admin output elements
    this->adminList = new QListWidget();
    this->adminOutputLine = new QLineEdit();
    this->adminOutputLine->setReadOnly(true);

    // admin buttons
    this->adminAddButton = new QPushButton("Add");
    this->adminRemoveButton = new QPushButton("Remove");
    this->adminUpdateButton = new QPushButton("Update");
    this->adminBackButton = new QPushButton("Back");

    // admin add button fields
    this->adminAddNameLine = new QLineEdit();
    this->adminAddBreedLine = new QLineEdit();
    this->adminAddAgeLine = new QLineEdit();
    this->adminAddPhotoLine = new QLineEdit();

    // admin add labels
    this->adminAddNameLabel = new QLabel("Name");
    this->adminAddBreedLabel = new QLabel("Breed");
    this->adminAddAgeLabel = new QLabel("Age");
    this->adminAddPhotoLabel = new QLabel("Photo");

    // admin remove input fields
    this->adminRemoveNameLine = new QLineEdit();
    this->adminRemoveBreedLine = new QLineEdit();

    // admin remove labels
    this->adminRemoveNameLabel = new QLabel("Name");
    this->adminRemoveBreedLabel = new QLabel("Breed");

    // admin update input fields
    this->adminUpdateNameLine = new QLineEdit();
    this->adminUpdateBreedLine = new QLineEdit();
    this->adminUpdateAgeLine = new QLineEdit();
    this->adminUpdatePhotoLine = new QLineEdit();

    // admin update labels
    this->adminUpdateNameLabel = new QLabel("Name");
    this->adminUpdateBreedLabel = new QLabel("Breed");
    this->adminUpdateAgeLabel = new QLabel("Age");
    this->adminUpdatePhotoLabel = new QLabel("Photo");

    // add layouts to the form
    this->adminLayout->addLayout(this->adminOutputLayout);
    this->adminLayout->addLayout(this->adminCommandsLayout);
    this->adminCommandsLayout->addLayout(this->adminAddLayout);
    this->adminCommandsLayout->addLayout(this->adminRemoveLayout);
    this->adminCommandsLayout->addLayout(this->adminUpdateLayout);
    this->adminCommandsLayout->addWidget(this->adminBackButton);

    // add elements to the output layout
    this->adminOutputLayout->addWidget(this->adminList);
    this->adminOutputLayout->addWidget(this->adminOutputLine);

    // add elements to the add layout
    this->adminAddLayout->addWidget(this->adminAddNameLabel, 0, 0);
    this->adminAddLayout->addWidget(this->adminAddNameLine, 0, 1);
    this->adminAddLayout->addWidget(this->adminAddBreedLabel, 1, 0);
    this->adminAddLayout->addWidget(this->adminAddBreedLine, 1, 1);
    this->adminAddLayout->addWidget(this->adminAddAgeLabel, 2, 0);
    this->adminAddLayout->addWidget(this->adminAddAgeLine, 2, 1);
    this->adminAddLayout->addWidget(this->adminAddPhotoLabel, 3, 0);
    this->adminAddLayout->addWidget(this->adminAddPhotoLine, 3, 1);
    this->adminAddLayout->addWidget(this->adminAddButton, 4, 0, 1, 2);

    // add elements to the remove layout
    this->adminRemoveLayout->addWidget(this->adminRemoveNameLabel, 0, 0);
    this->adminRemoveLayout->addWidget(this->adminRemoveNameLine, 0, 1);
    this->adminRemoveLayout->addWidget(this->adminRemoveBreedLabel, 1, 0);
    this->adminRemoveLayout->addWidget(this->adminRemoveBreedLine, 1, 1);
    this->adminRemoveLayout->addWidget(this->adminRemoveButton, 2, 0, 1, 2);

    // add the elements to the update layout
    this->adminUpdateLayout->addWidget(this->adminUpdateNameLabel, 0, 0);
    this->adminUpdateLayout->addWidget(this->adminUpdateNameLine, 0, 1);
    this->adminUpdateLayout->addWidget(this->adminUpdateBreedLabel, 1, 0);
    this->adminUpdateLayout->addWidget(this->adminUpdateBreedLine, 1, 1);
    this->adminUpdateLayout->addWidget(this->adminUpdateAgeLabel, 2, 0);
    this->adminUpdateLayout->addWidget(this->adminUpdateAgeLine, 2, 1);
    this->adminUpdateLayout->addWidget(this->adminUpdatePhotoLabel, 3, 0);
    this->adminUpdateLayout->addWidget(this->adminUpdatePhotoLine, 3, 1);
    this->adminUpdateLayout->addWidget(this->adminUpdateButton, 4, 0, 1, 2);

    // add the layout to the admin window
    this->adminWindow->setLayout(this->adminLayout);

    // style the admin form
    this->adminWindow->setWindowTitle("Admin Window");
    this->adminWindow->setFixedSize(450, 475);

    // User window

    // user layout
    this->userLayout = new QHBoxLayout();
    this->userOutputLayout = new QVBoxLayout();
    this->userInputLayout = new QVBoxLayout();
    this->userNextLayout = new QGridLayout();
    this->userAdoptLayout = new QGridLayout();
    this->userFilterLayout = new QGridLayout();

    // user output elements
    this->userList = new QListWidget();
    this->userOutputLine = new QLineEdit();
    this->userOutputLine->setReadOnly(true);

    // user buttons
    this->userNextButton = new QPushButton("Next");
    this->userAdoptButton = new QPushButton("Adopt");
    this->userFilterButton = new QPushButton("Filter");
    this->userOpenButton = new QPushButton("Open");
    this->userBackButton = new QPushButton("Back");
    this->adoptionListButton = new QPushButton("View Adoption List");

    // user input fields
    this->userFilterBreedLine = new QLineEdit();
    this->userFilterAgeLine = new QLineEdit();

    // user input labels
    this->userFilterBreedLabel = new QLabel("Breed");
    this->userFilterAgeLabel = new QLabel("Age");

    // user view output fields
    this->userViewNameLine = new QLineEdit();
    this->userViewNameLine->setReadOnly(true);
    this->userViewAgeLine = new QLineEdit();
    this->userViewAgeLine->setReadOnly(true);
    this->userViewBreedLine = new QLineEdit();
    this->userViewBreedLine->setReadOnly(true);

    // user view labels
    this->userViewNameLabel = new QLabel("Name");
    this->userViewBreedLabel = new QLabel("Breed");
    this->userViewAgeLabel = new QLabel("Age");
    this->userViewPhotoLabel = new QLabel("Photo");

    // add layouts to the user layout
    this->userLayout->addLayout(this->userOutputLayout);
    this->userLayout->addLayout(this->userInputLayout);

    // add elements to the output layout
    this->userOutputLayout->addWidget(this->userList);
    this->userOutputLayout->addWidget(this->userOutputLine);

    // add elements to the input layout
    this->userInputLayout->addLayout(this->userNextLayout);
    this->userInputLayout->addLayout(this->userAdoptLayout);
    this->userInputLayout->addLayout(this->userFilterLayout);

    // add elements to the next layout
    this->userNextLayout->addWidget(this->userViewNameLabel, 0, 0);
    this->userNextLayout->addWidget(this->userViewNameLine, 0, 1);
    this->userNextLayout->addWidget(this->userViewBreedLabel, 1, 0);
    this->userNextLayout->addWidget(this->userViewBreedLine, 1, 1);
    this->userNextLayout->addWidget(this->userViewAgeLabel, 2, 0);
    this->userNextLayout->addWidget(this->userViewAgeLine, 2, 1);
    this->userNextLayout->addWidget(this->userViewPhotoLabel, 3, 0, 1, 2);
    this->userNextLayout->addWidget(this->userNextButton, 4, 0, 1, 2);

    // add elements to the adopt layout
    this->userAdoptLayout->addWidget(this->userAdoptButton, 0, 0);
    this->userAdoptLayout->addWidget(this->userOpenButton, 0, 1);

    // add elements to the filter layout
    this->userFilterLayout->addWidget(this->userFilterBreedLabel, 0, 0);
    this->userFilterLayout->addWidget(this->userFilterBreedLine, 0, 1);
    this->userFilterLayout->addWidget(this->userFilterAgeLabel, 1, 0);
    this->userFilterLayout->addWidget(this->userFilterAgeLine, 1, 1);
    this->userFilterLayout->addWidget(this->userFilterButton, 2, 0, 1, 2);
    this->userFilterLayout->addWidget(this->adoptionListButton, 3, 0, 1, 2);
    this->userFilterLayout->addWidget(this->userBackButton, 4, 0, 1, 2);

    // add the layout to the user window
    this->userWindow->setLayout(this->userLayout);

    // style the user form
    this->userWindow->setWindowTitle("User Window");
    this->userWindow->setFixedSize(800, 500);

    // adoption list window
    QVBoxLayout *adoptionListLayout = new QVBoxLayout();
    QTableView *adoptionTableView = new QTableView();
    adoptionListLayout->addWidget(adoptionTableView);
    this->adoptionListWindow->setLayout(adoptionListLayout);
    this->adoptionListWindow->setWindowTitle("Adoption List");
    this->adoptionListWindow->setFixedSize(600, 400);

    // Create undo/redo buttons and connect signals
    this->undoButton = new QPushButton("Undo");
    this->redoButton = new QPushButton("Redo");
    connect(this->undoButton, &QPushButton::clicked, this, &QtUi::undo);
    connect(this->redoButton, &QPushButton::clicked, this, &QtUi::redo);

    // Add undo/redo buttons to the layout (example for admin window)
    this->adminCommandsLayout->addWidget(this->undoButton);
    this->adminCommandsLayout->addWidget(this->redoButton);

    // Connections

    // form selection
    connect(this->adminButton, &QPushButton::clicked, this, &QtUi::showAdminWindow);
    connect(this->userCSVButton, &QPushButton::clicked, this, &QtUi::setAdoptionListToCSV);
    connect(this->userHTMLButton, &QPushButton::clicked, this, &QtUi::setAdoptionListToHTML);

    // admin commands
    connect(this->adminAddButton, &QPushButton::clicked, this, &QtUi::addPet);
    connect(this->adminRemoveButton, &QPushButton::clicked, this, &QtUi::removePet);
    connect(this->adminUpdateButton, &QPushButton::clicked, this, &QtUi::updatePet);
    connect(this->adminBackButton, &QPushButton::clicked, this, &QtUi::showEntryWindow);

    // user commands
    connect(this->userNextButton, &QPushButton::clicked, this, &QtUi::userNext);
    connect(this->userAdoptButton, &QPushButton::clicked, this, &QtUi::userAdopt);
    connect(this->userFilterButton, &QPushButton::clicked, this, &QtUi::userFilter);
    connect(this->userOpenButton, &QPushButton::clicked, this, &QtUi::userOpen);
    connect(this->adoptionListButton, &QPushButton::clicked, this, &QtUi::showAdoptionListWindow);
    connect(this->userBackButton, &QPushButton::clicked, this, &QtUi::showEntryWindow);

    showEntryWindow();
}

QtUi::~QtUi() {
    delete ui;
}

void QtUi::showEntryWindow() {
    this->userWindow->setVisible(false);
    this->adminWindow->setVisible(false);
    this->entryWindow->setVisible(true);
}

void QtUi::showAdminWindow() {
    this->updateAdminList();
    this->adminOutputLine->clear();
    this->clearAdminInputFields();
    this->userWindow->setVisible(false);
    this->entryWindow->setVisible(false);
    this->adminWindow->setVisible(true);
}

void QtUi::showUserWindow() {
    this->adminWindow->setVisible(false);
    this->entryWindow->setVisible(false);
    this->userWindow->setVisible(true);

    this->updateUserList();
}

void QtUi::showAdoptionListWindow() {
    auto model = new AdoptionListModel(this->petService.getAdoptionList());
    auto adoptionTableView = adoptionListWindow->findChild<QTableView*>();
    adoptionTableView->setModel(model);
    this->adoptionListWindow->show();
}

void QtUi::updateAdminList() {
    this->adminList->clear();
    for (const auto &pet : this->petService.getAll()) {
        this->adminList->addItem(QString::fromStdString(pet.toString()));
    }
}

void QtUi::clearAdminInputFields() {
    this->adminAddNameLine->clear();
    this->adminAddBreedLine->clear();
    this->adminAddAgeLine->clear();
    this->adminAddPhotoLine->clear();
    this->adminRemoveNameLine->clear();
    this->adminRemoveBreedLine->clear();
    this->adminUpdateNameLine->clear();
    this->adminUpdateBreedLine->clear();
    this->adminUpdateAgeLine->clear();
    this->adminUpdatePhotoLine->clear();
}

void QtUi::executeCommand(std::unique_ptr<Command> command) {
    command->execute();
    undoStack.push(std::move(command));
    while (!redoStack.empty()) {
        redoStack.pop();
    }
    updateAdminList(); // Update the list after executing the command
}

void QtUi::addPet() {
    try {
        Pet pet(this->adminAddNameLine->text().toStdString(), this->adminAddBreedLine->text().toStdString(),
                this->adminAddAgeLine->text().toInt(), this->adminAddPhotoLine->text().toStdString());
        auto command = std::make_unique<AddCommand>(petService, pet);
        executeCommand(std::move(command));
        this->adminOutputLine->setText("Pet added successfully!");
    } catch (ServiceException &exception) {
        this->adminOutputLine->setText(QString::fromStdString(exception.what()));
    }
}

void QtUi::removePet() {
    try {
        Pet pet(this->adminRemoveNameLine->text().toStdString(), this->adminRemoveBreedLine->text().toStdString(), 0, "");
        auto command = std::make_unique<RemoveCommand>(petService, pet);
        executeCommand(std::move(command));
        this->adminOutputLine->setText("Pet removed successfully!");
    } catch (ServiceException &exception) {
        this->adminOutputLine->setText(QString::fromStdString(exception.what()));
    }
}

void QtUi::updatePet() {
    try {
        Pet oldPet(this->adminUpdateNameLine->text().toStdString(), this->adminUpdateBreedLine->text().toStdString(), 0, "");
        Pet newPet(this->adminUpdateNameLine->text().toStdString(), this->adminUpdateBreedLine->text().toStdString(),
                   this->adminUpdateAgeLine->text().toInt(), this->adminUpdatePhotoLine->text().toStdString());
        auto command = std::make_unique<UpdateCommand>(petService, oldPet, newPet);
        executeCommand(std::move(command));
        this->adminOutputLine->setText("Pet updated successfully!");
    } catch (ServiceException &exception) {
        this->adminOutputLine->setText(QString::fromStdString(exception.what()));
    }
}

void QtUi::clearUserInputFields() {
    this->userOutputLine->clear();
    this->userFilterBreedLine->clear();
    this->userFilterAgeLine->clear();
    this->userViewNameLine->clear();
    this->userViewAgeLine->clear();
    this->userViewBreedLine->clear();
}

void QtUi::userNext() {
    try {
        this->currentPetIndex++;
        if (this->currentPetIndex == this->pets.size()) {
            this->currentPetIndex = 0;
        }
        this->userViewNameLine->setText(QString::fromStdString(this->pets[this->currentPetIndex].getName()));
        this->userViewBreedLine->setText(QString::fromStdString(this->pets[this->currentPetIndex].getBreed()));
        this->userViewAgeLine->setText(QString::number(this->pets[this->currentPetIndex].getAge()));
    } catch (ServiceException &exception) {
        this->userOutputLine->setText(QString::fromStdString(exception.what()));
    }
}

void QtUi::userAdopt() {
    try {
        auto *name = new char [this->userViewNameLine->text().length() + 1];
        strcpy(name, this->userViewNameLine->text().toStdString().c_str());
        auto *breed = new char [this->userViewBreedLine->text().length() + 1];
        strcpy(breed, this->userViewBreedLine->text().toStdString().c_str());
        this->petService.addPetToAdoptionList(name, breed);
        this->userOutputLine->setText("Pet adopted successfully!");
    } catch (ServiceException &exception) {
        this->userOutputLine->setText(QString::fromStdString(exception.what()));
    }

    this->updateUserList();
}

void QtUi::userFilter() {
    try {
        if (!this->userFilterBreedLine->text().isEmpty()) {
            this->pets.erase(std::remove_if(this->pets.begin(), this->pets.end(), [this](const Pet &pet) {
                return pet.getBreed() != this->userFilterBreedLine->text().toStdString();
            }), this->pets.end());
        }
        if (!this->userFilterAgeLine->text().isEmpty()) {
            this->pets.erase(std::remove_if(this->pets.begin(), this->pets.end(), [this](const Pet &pet) {
                return pet.getAge() != this->userFilterAgeLine->text().toInt();
            }), this->pets.end());
        }
        this->currentPetIndex = 0;
        this->updateUserList();
    } catch (ServiceException &exception) {
        this->userOutputLine->setText(QString::fromStdString(exception.what()));
    }
}

void QtUi::updateUserList() {
    this->userList->clear();
    vector<Pet> adoptionPets = this->petService.getAdoptionList();
    for (const auto &pet : adoptionPets) {
        this->userList->addItem(QString::fromStdString(pet.toString()));
    }
    if (!adoptionPets.empty()) {
        this->userViewNameLine->setText(QString::fromStdString(this->pets[this->currentPetIndex].getName()));
        this->userViewBreedLine->setText(QString::fromStdString(this->pets[this->currentPetIndex].getBreed()));
        this->userViewAgeLine->setText(QString::number(this->pets[this->currentPetIndex].getAge()));
    }
}

void QtUi::userOpen() {
    try {
        this->petService.modifyFileFormat("html");
        this->userOutputLine->setText("Adoption list saved as HTML!");
    } catch (ServiceException &exception) {
        this->userOutputLine->setText(QString::fromStdString(exception.what()));
    }
}

void QtUi::setAdoptionListToCSV() {
    try {
        this->petService.modifyFileFormat("csv");
        this->userOutputLine->setText("Adoption list saved as CSV!");
    } catch (ServiceException &exception) {
        this->userOutputLine->setText(QString::fromStdString(exception.what()));
    }
    this->showUserWindow();
}

void QtUi::setAdoptionListToHTML() {
    try {
        this->petService.modifyFileFormat("html");
        this->userOutputLine->setText("Adoption list saved as HTML!");
    } catch (ServiceException &exception) {
        this->userOutputLine->setText(QString::fromStdString(exception.what()));
    }
    this->showUserWindow();
}

void QtUi::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    int petsUnder3YearsCount = 0;
    int petsOver3YearsCount = 0;
    for (auto &pet : this->petService.getAll()) {
        if (pet.getAge() < 3) {
            petsUnder3YearsCount++;
        } else {
            petsOver3YearsCount++;
        }
    }
    int petsUnder3YearsAngle = petsUnder3YearsCount * 360 / this->petService.getAll().size();
    int petsOver3YearsAngle = 360 - petsUnder3YearsAngle;

    QRectF size = QRectF(82, 50, this->width() - 160, this->width() - 160);

    painter.setBrush(Qt::darkGreen);
    painter.drawPie(size, 0, petsUnder3YearsAngle * 16);
    painter.setBrush(Qt::darkCyan);
    painter.drawPie(size, petsUnder3YearsAngle * 16, petsOver3YearsAngle * 16);

    // Draw legend
    painter.setBrush(Qt::darkGreen);
    painter.drawRect(10, 20, 20, 20);
    painter.setBrush(Qt::darkCyan);
    painter.drawRect(10, 50, 20, 20);
    painter.setBrush(Qt::black);
    painter.drawText(40, 35, "Pets under 3 years");
    painter.drawText(40, 65, "Pets over 3 years");
}

void QtUi::keyPressEvent(QKeyEvent* event) {
    if (event->modifiers() == Qt::ControlModifier) {
        switch (event->key()) {
            case Qt::Key_Z:
                undo();
                break;
            case Qt::Key_Y:
                redo();
                break;
        }
    }
}

void QtUi::undo() {
    if (!undoStack.empty()) {
        auto command = std::move(undoStack.top());
        undoStack.pop();
        command->undo();
        redoStack.push(std::move(command));
        updateAdminList(); // Update the list after undoing the command
    }
}

void QtUi::redo() {
    if (!redoStack.empty()) {
        auto command = std::move(redoStack.top());
        redoStack.pop();
        command->execute();
        undoStack.push(std::move(command));
        updateAdminList(); // Update the list after redoing the command
    }
}