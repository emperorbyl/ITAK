//
// Created by benja on 4/18/2017.
//

#ifndef ITAK_PORTANALYZER_H
#define ITAK_PORTANALYZER_H

#include <vector>
#include "Analyzer.h"
class PortScanAnalyzer : Analyzer{
public:
    ResultSet run(std::ifstream& input);
    Dictionary<std::string, std::vector<int>>* inputDictionary;
    PortScanAnalyzer();
};


#endif //ITAK_PORTANALYZER_H
