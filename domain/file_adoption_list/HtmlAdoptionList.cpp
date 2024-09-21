#include <fstream>
#include <string>
#include "HtmlAdoptionList.h"
#include "../../extra/exceptions.h"
#include <regex>
using namespace std;

using std::string;


void HtmlAdoptionList::writeToFile() {
    ofstream file(this->fileName.c_str());
    if (!file.is_open()) {
        throw FileException("Could not open file");
    }

    file << R"(<!DOCTYPE html>)" << endl;
    file << R"(<html>)" << endl;
    file << R"(<head>)" << endl;
    file << R"(<title>Adoption List</title>)" << endl;
    file << R"(</head>)" << endl;
    file << R"(<body>)" << endl;
    file << R"(<table border="1">)" << endl;
    file << R"(<tr>)" << endl;
    file << R"(<th>Name</th>)" << endl;
    file << R"(<th>Breed</th>)" << endl;
    file << R"(<th>Age</th>)" << endl;
    file << R"(<th>Photo</th>)" << endl;
    file << R"(</tr>)" << endl;

    for (const auto &pet: this->getAll()) {
        file << R"(<tr>)" << endl;
        file << R"(<td>)" << pet.getName() << R"(</td>)" << endl;
        file << R"(<td>)" << pet.getBreed() << R"(</td>)" << endl;
        file << R"(<td>)" << pet.getAge() << R"(</td>)" << endl;
        file << R"(<td><a href=")" << pet.getPhoto() << R"(">Link</a></td>)" << endl;
        file << R"(</tr>)" << endl;
    }

    file << R"(</table>)" << std::endl;
    file << R"(</body>)" << std::endl;
    file << R"(</html>)" << std::endl;

    file.close();
}


void HtmlAdoptionList::displayAdoptionList() {
    std::string command = "open -a \""
                          "Safari\" " + this->fileName;
    std::system(command.c_str());
}


void HtmlAdoptionList::readFromFile() {
    ifstream HTMLInputFile(this->fileName.c_str());

    if (!HTMLInputFile.is_open())
        throw FileException("The HTML file could not be opened!");

    std::string line;
    std::string html_content;
    while (getline(HTMLInputFile, line)) {
        html_content += line + "\n";
    }

    regex row_pattern(R"lit(<tr>\s*<td>([^<]*)</td>\s*<td>([^<]*)</td>\s*<td>([^<]*)</td>\s*<td><a href="([^"]*)">[^<]*</a></td>\s*</tr>)lit");
    smatch match;

    while (std::regex_search(html_content, match, row_pattern) && match.size() > 4) {
        string name = match.str(1);
        string breed = match.str(2);
        string age = match.str(3);
        string photo = match.str(4);

        Pet pet(name, breed, stoi(age), photo);
        AdoptionList::addPet(pet);

        html_content = match.suffix().str();
    }

    HTMLInputFile.close();
}


void HtmlAdoptionList::addPet(const Pet &pet) {
    AdoptionList::addPet(pet);
    this->writeToFile();
}


