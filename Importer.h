#ifndef IMPORTER_H
#define IMPORTER_H

#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Credential.h"

class CSVImporter {
public:
    static std::vector<std::shared_ptr<Credential>> importFromCSV(const std::string& path);
};

#endif