//
// Created by benja on 4/18/2017.
//

#include "TestAnalyzer.h"
#include "../Analyzer.h"

void TestAnalyzer::testSetConfig()
{
    std::cout << "Testing the setConfig method." << std::endl;
    Analyzer analyzer;
    Configuration config;
    config.dictionary->add("TimeFrame", "1234565");
    config.dictionary->add("Likely Attack Message Count", "300");
    config.dictionary->add("Possible Attack Message Count", "200");
    analyzer.setConfig(config);
    if(analyzer.configDictionary->getByIndex(0)->getKey() != "TimeFrame")
        std::cout << "There is something wrong with the setConfig method." << std::endl;
}
