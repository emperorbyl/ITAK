//
// Created by benja on 4/18/2017.
//
#include <iostream>
#include "TestingDictionary.h"
#include "TestingResultSet.h"
#include "TestAnalyzer.h"
#include "TestingAlgorithm.h"
#include "TestingConfiguration.h"
#include "TestingDenialOfService.h"
#include "TestingPortScan.h"

int main()
{
    std::cout << "Testing the Result Set methods" << std::endl;
    TestingResultSet testingResultSet;
    testingResultSet.testPrint();

    std::cout << "Testing the Dictionary methods" << std::endl;
    TestingDictionary testingDictionary;
    testingDictionary.testAdd();
    testingDictionary.testDestructor();
    testingDictionary.testDictionary();
    testingDictionary.testDictionaryWithIntDictionary();
    testingDictionary.testGetByIndex();
    testingDictionary.testGetByKey();
    testingDictionary.testGetCount();
    testingDictionary.testRemoveByIndex();
    testingDictionary.testRemoveByKey();

    std::cout << "Testing the Configuration Methods" << std::endl;
    TestingConfiguration testingConfiguration;
    testingConfiguration.testGetDouble();
    testingConfiguration.testGetInt();
    testingConfiguration.testGetString();

    std::cout << "Testing the Algorithm Methods" << std::endl;
    TestingAlgorithm testingAlgorithm;
    testingAlgorithm.testRun();

    std::cout << "Testing the Analyzer methods" << std::endl;
    TestAnalyzer testAnalyzer;
    testAnalyzer.testSetConfig();

    std::cout << "Testing the PortScan methods" << std::endl;
    TestingPortScan testingPortScan;

    std::cout << "Testing the Denial of Service methods" << std::endl;
    TestingDenialOfService testingDenialOfService;
    return 0;
}
