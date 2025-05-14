#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <string>
#include <iostream>

class Vault; // forward declaration

class Credential {
private: //credentials are inaccessible when defined private. need getters and setters. or a friend
    std::string name, url, username, password;

    friend class Vault;

public:
      Credential() : name(""), url(""), username(""), password("") {}

        // Parameterized constructor
        Credential(const std::string& n, const std::string& u, const std::string& un, const std::string& pass)
            : name(n), url(u), username(un), password(pass) {}

        const std::string& getName() const { return name; }
        const std::string& getUrl() const { return url; }
        const std::string& getUsername() const { return username; }
        const std::string& getPassword() const { return password; }

    // Function to display credential information
    void display() const;

};

#endif // CREDENTIAL_H