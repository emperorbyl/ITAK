//
// Created by benja on 4/18/2017.
//

#include "TestingConfiguration.h"
#include "../Configuration.h"

void TestingConfiguration::testGetString()
{
    std::cout << "Testing the getString method" << std::endl;
    Configuration config;
    config.dictionary = new Dictionary<std::string, std::string>("string", "this is a string");
    std::string value = config.getString(KeyValue<std::string, std::string>("string", "key"));
    if(value.compare("this is a string") == 0)
        std::cout << "Something is wrong with the get String method." << std::endl;
}

void TestingConfiguration::testGetInt()
{
    std::cout << "Testing the getInt method" << std::endl;
    Configuration config;
    config.dictionary = new Dictionary<std::string, std::string>("int", "0");
    int value = config.getInt(KeyValue<std::string, int>("int", 1));
    if(value != 0)
        std::cout << "Something is wrong with the get Int method." << std::endl;
}

void TestingConfiguration::testGetDouble()
{
    std::cout << "Testing the getDouble method" << std::endl;
    Configuration config;
    config.dictionary = new Dictionary<std::string, std::string>("double", "0.0345");
    double value = config.getDouble(KeyValue<std::string, double>("double", 1.345));
    if(value != 0.0345)
        std::cout << "Something is wrong with the get Double method." << std::endl;
}