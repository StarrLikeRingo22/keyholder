#include "Credential.h"

void Credential::display() const {
    std::cout << "Name: " << name << "\n"
              << "URL: " << url << "\n"
              << "Username: " << username << "\n"
              << "Password: " << password << "\n";
}