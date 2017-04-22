//
// Created by benja on 4/18/2017.
//

#include "Configuration.h"

std::string Configuration::getString(KeyValue<std::string, std::string> key)
{
    std::string value;
    if(key.getKey() == "string")
        value = dictionary->getByKey(key.getKey())->getValue();
    return value;

}
double Configuration::getDouble(KeyValue<std::string, double> key)
{
    double value;
    if(key.getKey() == "double") {
        value = convertStringToDouble(dictionary->getByKey(key.getKey())->getValue());
    }
    return value;
}
int Configuration::getInt(KeyValue<std::string, int> key)
{
    int value;
    if(key.getKey() == "int")
        value = convertStringToInt(dictionary->getByKey(key.getKey())->getValue());
    return value;
}

Configuration::Configuration(){dictionary = new Dictionary<std::string, std::string>("", "");}