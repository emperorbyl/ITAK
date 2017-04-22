//
// Created by benja on 4/18/2017.
//

#include "TestingResultSet.h"
#include "../ResultSet.h"

void TestingResultSet::testPrint()
{
    std::cout << "Testing the print function" << std::endl;
    ResultSet resultSet;
    resultSet.results->add("120.56.45.563", new std::vector<std::string>{"port"});
    resultSet.print(std::cout);
    if(std::cout.bad())
        std::cout << "Something is wrong with the print function." << std::endl;
}