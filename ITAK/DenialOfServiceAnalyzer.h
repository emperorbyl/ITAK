//
// Created by benja on 4/18/2017.
//

#ifndef ITAK_DOSANALYZER_H
#define ITAK_DOSANALYZER_H


#include "Analyzer.h"
#include <string>
#include <vector>
class DenialOfServiceAnalyzer : Analyzer{
public:
    ResultSet run(std::ifstream& input);
    Dictionary<std::string, Dictionary<int, int>>* inputDictionary;
    DenialOfServiceAnalyzer();
};


#endif //ITAK_DOSANALYZER_H
