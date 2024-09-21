#include <QApplication>
#include <QPushButton>
#include "repository/file_repository/TxtRepository.h"
#include "domain/file_adoption_list/CsvAdoptionList.h"
#include "service/PetService.h"
#include "qtui.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TxtRepository repository("../files/data.txt");
    repository.readFromFile();
    PetService petService(repository, nullptr);
    QtUi ui(nullptr, petService);
    ui.show();
    return QApplication::exec();
}