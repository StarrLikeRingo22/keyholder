#include <iostream>
#include "Importer.h"

int main() {
    std::string path = "assets/passwords.csv"; 

    // Import credentials
    auto credentials = CSVImporter::importFromCSV(path);

    // Display imported credentials
    for (const auto& cred : credentials) { //range-based loop
        cred->display();
    }

    return 0;
}