#pragma once
#include <QWidget>
#include "service/PetService.h"
#include <qlayout.h>
#include <qline.h>
#include <QPainter>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qstackedlayout.h>
#include <QTableView>
#include <QAbstractTableModel>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include <stack>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class QtUi; }
QT_END_NAMESPACE

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class AddCommand : public Command {
    PetService& service;
    Pet pet;
public:
    AddCommand(PetService& service, const Pet& pet) : service(service), pet(pet) {}
    void execute() override { service.addPet(pet.getName(), pet.getBreed(), pet.getAge(), pet.getPhoto()); }
    void undo() override { service.removePet(pet.getName(), pet.getBreed()); }
};

class RemoveCommand : public Command {
    PetService& service;
    Pet pet;
public:
    RemoveCommand(PetService& service, const Pet& pet) : service(service), pet(pet) {}
    void execute() override { service.removePet(pet.getName(), pet.getBreed()); }
    void undo() override { service.addPet(pet.getName(), pet.getBreed(), pet.getAge(), pet.getPhoto()); }
};

class UpdateCommand : public Command {
    PetService& service;
    Pet oldPet;
    Pet newPet;
public:
    UpdateCommand(PetService& service, const Pet& oldPet, const Pet& newPet)
            : service(service), oldPet(oldPet), newPet(newPet) {}
    void execute() override { service.updatePet(newPet.getName(), newPet.getBreed(), newPet.getAge(), newPet.getPhoto()); }
    void undo() override { service.updatePet(oldPet.getName(), oldPet.getBreed(), oldPet.getAge(), oldPet.getPhoto()); }
};

class AdoptionListModel : public QAbstractTableModel {
Q_OBJECT

private:
    std::vector<Pet> pets;

public:
    explicit AdoptionListModel(const std::vector<Pet> &pets, QObject *parent = nullptr)
            : QAbstractTableModel(parent), pets(pets) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return static_cast<int>(pets.size());
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return 4; // Name, Breed, Age, Photo
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || role != Qt::DisplayRole)
            return QVariant();

        const Pet &pet = pets[static_cast<size_t>(index.row())];
        switch (index.column()) {
            case 0: return QString::fromStdString(pet.getName());
            case 1: return QString::fromStdString(pet.getBreed());
            case 2: return pet.getAge();
            case 3: return QString::fromStdString(pet.getPhoto());
            default: return QVariant();
        }
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return QString("Name");
                case 1: return QString("Breed");
                case 2: return QString("Age");
                case 3: return QString("Photo");
                default: return QVariant();
            }
        }
        return QVariant();
    }

    void updatePets(const std::vector<Pet> &newPets) {
        beginResetModel();
        pets = newPets;
        endResetModel();
    }
};

class Observer {
public:
    virtual void update() = 0;
};

class QtUi : public QWidget, public Observer {
Q_OBJECT

public:
    explicit QtUi(QWidget *parent = nullptr, const PetService &petService = PetService());

    ~QtUi() override;

    void update() override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::QtUi *ui;
    QWidget *entryWindow;
    QWidget *adminWindow;
    QWidget *userWindow;
    QWidget *adoptionListWindow;

    PetService petService;
    int currentPetIndex{};
    std::vector<Pet> pets;

    // entry layout
    QGridLayout *entryLayout;
    QPushButton *adminButton;
    QPushButton *userCSVButton;
    QPushButton *userHTMLButton;

    // admin layout
    QHBoxLayout *adminLayout;
    QVBoxLayout *adminOutputLayout;
    QVBoxLayout *adminCommandsLayout;
    QGridLayout *adminAddLayout;
    QGridLayout *adminRemoveLayout;
    QGridLayout *adminUpdateLayout;

    // admin widget list
    QListWidget *adminList;

    // admin output textbox for messages
    QLineEdit *adminOutputLine;

    // admin buttons
    QPushButton *adminAddButton;
    QPushButton *adminRemoveButton;
    QPushButton *adminUpdateButton;
    QPushButton *adminBackButton;

    // admin add input fields
    QLineEdit *adminAddNameLine;
    QLineEdit *adminAddBreedLine;
    QLineEdit *adminAddAgeLine;
    QLineEdit *adminAddPhotoLine;

    // admin add labels
    QLabel *adminAddNameLabel;
    QLabel *adminAddBreedLabel;
    QLabel *adminAddAgeLabel;
    QLabel *adminAddPhotoLabel;

    // admin remove input fields
    QLineEdit *adminRemoveNameLine;
    QLineEdit *adminRemoveBreedLine;

    // admin remove labels
    QLabel *adminRemoveNameLabel;
    QLabel *adminRemoveBreedLabel;

    // admin update input fields
    QLineEdit *adminUpdateNameLine;
    QLineEdit *adminUpdateBreedLine;
    QLineEdit *adminUpdateAgeLine;
    QLineEdit *adminUpdatePhotoLine;

    // admin update labels
    QLabel *adminUpdateNameLabel;
    QLabel *adminUpdateBreedLabel;
    QLabel *adminUpdateAgeLabel;
    QLabel *adminUpdatePhotoLabel;

    // user layout
    QHBoxLayout *userLayout;
    QVBoxLayout *userOutputLayout;
    QVBoxLayout *userInputLayout;
    QGridLayout *userNextLayout;
    QGridLayout *userAdoptLayout;
    QGridLayout *userFilterLayout;

    // user widget list
    QListWidget *userList;

    // user output textbox for messages
    QLineEdit *userOutputLine;

    // user buttons
    QPushButton *userNextButton;
    QPushButton *userAdoptButton;
    QPushButton *userFilterButton;
    QPushButton *userOpenButton;
    QPushButton *userBackButton;
    QPushButton *adoptionListButton;

    // user input fields
    QLineEdit *userFilterBreedLine;
    QLineEdit *userFilterAgeLine;

    // user labels
    QLabel *userFilterBreedLabel;
    QLabel *userFilterAgeLabel;

    // user view output fields
    QLineEdit *userViewNameLine;
    QLineEdit *userViewBreedLine;
    QLineEdit *userViewAgeLine;

    // user view labels
    QLabel *userViewNameLabel;
    QLabel *userViewBreedLabel;
    QLabel *userViewAgeLabel;
    QLabel *userViewPhotoLabel;

    // Undo/Redo stacks
    std::stack<std::unique_ptr<Command>> undoStack;
    std::stack<std::unique_ptr<Command>> redoStack;

    // UI elements for undo/redo
    QPushButton* undoButton;
    QPushButton* redoButton;

    void showEntryWindow();
    void showAdminWindow();
    void showUserWindow();
    void showAdoptionListWindow();
    void updateAdminList();
    void clearAdminInputFields();
    void clearUserInputFields();
    void executeCommand(std::unique_ptr<Command> command);

    void addPet();
    void removePet();
    void updatePet();

    void setAdoptionListToCSV();
    void setAdoptionListToHTML();

    void userNext();
    void userAdopt();
    void userFilter();
    void userOpen();
    void updateUserList();

private slots:
    void undo();
    void redo();
};
