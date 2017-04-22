//
// Created by benja on 4/18/2017.
//

#include "TestingAlgorithm.h"
#include "../Algorithm.h"

void TestingAlgorithm::testRun()
{
    std::cout << "Testing the run method" << std::endl;
    Algorithm algorithm;
    Configuration config;
    config.dictionary->add("TimeFrame", "1234565");
    config.dictionary->add("Likely Attack Message Count", "300");
    config.dictionary->add("Possible Attack Message Count", "200");
    algorithm.setConfig(config);
    std::string inputFile = "Testing/Data/sample1.txt";
    std::ifstream inputStream(inputFile);
    algorithm.run(inputStream);
    if(algorithm.methodUsed.compare("Denial Of Service") == 0)
        std::cout << "Something is wrong with the run method." << std::endl;
}
