//
// Created by benja on 4/18/2017.
//

#ifndef ITAK_ANALYZER_H
#define ITAK_ANALYZER_H

#include "Dictionary.h"
#include "Configuration.h"
#include <fstream>
#include "Utils.h"
#include "ResultSet.h"

class Analyzer {
public:
    Dictionary<std::string, std::string> *configDictionary;
    virtual ResultSet run(std::ifstream& input);
    void setConfig(Configuration& config);
    Analyzer();
};


#endif //ITAK_ANALYZER_H
