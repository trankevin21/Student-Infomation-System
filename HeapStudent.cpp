#include "HSHeader.h"


void simplerList(std::string firstName, std::string lastName) {//prints the names only to shortReport.txt
    std::ofstream shortFile;
    shortFile.open("shortReport.txt", std::ios::app);

    shortFile << firstName << " " << lastName << "\n";

}

void fullReport(std::string firstName, std::string lastName, std::string streetAddress, std::string streetAddress2, std::string city, std::string state, std::string zipcode, std::string birthday, std::string graduation, std::string gpa, std::string creditHours) {//prints out all the categories to fullReport.txt
    std::ofstream fullFile;
    fullFile.open("fullReport.txt", std::ios::app);

    fullFile << "Name: " << firstName << " " << lastName << "\n\n";
    fullFile << "Address: " << streetAddress << "," << streetAddress2 << " " << city << ", " << state << " " << zipcode << "\n";
    fullFile << "Birthday: " << birthday << "\n";
    fullFile << "Graduation Date: " << graduation << "\n";
    fullFile << "GPA: " << gpa << "\n";
    fullFile << "Credit Hours: " << creditHours << "\n";

    int i;
    for (i = 0; i < 50; i++) {
        fullFile << "-";
    }
    fullFile << "\n";
}

int main() {
    std::ifstream dataFile;//Opens all txt files
    dataFile.open("studentsdat.txt");
    std::ofstream fullFile;
    fullFile.open("fullReport.txt");
    std::ofstream shortFile;
    shortFile.open("shortReport.txt");

    if (dataFile.fail()) {
        std::cout << "Input File Not Found!\n\n";
        return 1;
    }
    else {
        std::cout << "Input File Found!\n\n";
    }


    int i;
    for (i = 0; i < 50; i++) {//Sorts through each variable for 50 lines
        std::stringstream word;
        std::string line, firstName, lastName, streetAddress, streetAddress2, city, state, zipcode, birthday, graduation, gpa, creditHours;

        getline(dataFile, line);
        word << line;

        std::getline(word, lastName, ',');
        std::getline(word, firstName, ',');
        std::getline(word, streetAddress, ',');
        std::getline(word, streetAddress2, ',');
        std::getline(word, city, ',');
        std::getline(word, state, ',');
        std::getline(word, zipcode, ',');
        std::getline(word, birthday, ',');
        std::getline(word, graduation, ',');
        std::getline(word, gpa, ',');
        std::getline(word, creditHours, ',');
	//Pushes all the info to simplerList and fullReport functions as it sorts. 
        simplerList(firstName, lastName);
        fullReport(firstName, lastName, streetAddress, streetAddress2, city, state, zipcode, birthday, graduation, gpa, creditHours);
    }

    std::cout << "Simpler List Complete!\n";
    std::cout << "Full Report Complete!\n";
    return 0;
}

