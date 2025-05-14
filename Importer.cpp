#include "Importer.h"


std::vector<std::shared_ptr<Credential>> CSVImporter::importFromCSV(const std::string& path) {
    std::vector<std::shared_ptr<Credential>> creds;
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << path << std::endl;
        return creds;
    }

    std::string line;
    std::getline(file, line);  // Skip header
    if (line.empty()) {
        std::cerr << "Error: CSV file is empty or malformed." << std::endl;
        return creds;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, url, username, password;

        std::getline(ss, name, ',');
        std::getline(ss, url, ',');
        std::getline(ss, username, ',');
        std::getline(ss, password, ',');

        if (name.empty() || url.empty() || username.empty() || password.empty()) {
            std::cerr << "Error: Missing data in CSV file on line: " << line << std::endl;
            continue;
        }

        auto credential = std::make_shared<Credential>(name, url, username, password);
        creds.push_back(credential);
    }

    if (creds.empty()) {
        std::cerr << "Warning: No valid credentials found in the file." << std::endl;
    }

    return creds;
}