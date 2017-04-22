//
// Created by benja on 4/18/2017.
//

#ifndef ITAK_CONFIGURATION_H
#define ITAK_CONFIGURATION_H

#include <string>
#include "Dictionary.h"
#include "Utils.h"
#include "KeyValue.h"

class Configuration {

public:
    std::string getString(KeyValue<std::string, std::string> key);
    double getDouble(KeyValue<std::string, double> key);
    int getInt(KeyValue<std::string, int> key);
    Dictionary<std::string, std::string> *dictionary;
    Configuration();

};


#endif //ITAK_CONFIGURATION_H
