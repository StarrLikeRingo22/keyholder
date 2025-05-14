#ifndef VAULT_H
#define VAULT_H

#include "Credential.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Vault {
private:
    std::vector<std::shared_ptr<Credential>> credentials;  // shared_ptr for better memory management

public:
    Vault() = default;

    void addCredential(const Credential& cred); //safely add value

    void loadFromFile(const std::string& path); // csv line parsing

    void saveToFile(const std::string& path) const; // writes in correct format for output

    const std::vector<std::shared_ptr<Credential>>& getCredentials() const; //gets credentials using shared ptr

    void displayCredentials() const;

};

#endif