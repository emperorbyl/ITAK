//
// Created by benja on 4/18/2017.
//

#ifndef ITAK_ALGORITHM_H
#define ITAK_ALGORITHM_H

#include "PortScanAnalyzer.h"
#include "DenialOfServiceAnalyzer.h"
#include "Analyzer.h"
class Algorithm : public Analyzer{
public:
    ResultSet run(std::ifstream& input);
    std::string methodUsed;
    Algorithm();
};


#endif //ITAK_ALGORITHM_H
