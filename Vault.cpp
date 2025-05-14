#include "Vault.h"


// Add a credential
void Vault::addCredential(const Credential& cred) {
    credentials.push_back(std::make_shared<Credential>(cred)); //insert into back container
}

// Load from a file
void Vault::loadFromFile(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << path << std::endl;
        return;
    }

    std::string line;
    credentials.clear();

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, url, username, password;

        std::getline(ss, name, ',');
        std::getline(ss, url, ',');
        std::getline(ss, username, ',');
        std::getline(ss, password, ',');


        if (name.empty() || url.empty() || username.empty() || password.empty()) {
            std::cerr << "Error: Malformed entry detected and skipped: " << line << std::endl;
            continue;
        }

        credentials.push_back(std::make_shared<Credential>(name, url, username, password));
    }

    if (credentials.empty()) {
        std::cerr << "Warning: No valid credentials found in the file." << std::endl;
    }
}

void Vault::saveToFile(const std::string& path) const {
    std::ofstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for saving: " << path << std::endl;
        return;
    }

    for (const auto& c : credentials) {
        file << c->getName() << ','
            << c->getUrl() << ','
            << c->getUsername() << ','
            << c->getPassword() << '\n';
    }

    std::cout << "Credentials saved successfully to " << path << std::endl;
}

const std::vector<std::shared_ptr<Credential>>& Vault::getCredentials() const {
    return credentials;
}

void Vault::displayCredentials() const {
    for (const auto& cred : credentials) {
        cred->display();
    }
}
