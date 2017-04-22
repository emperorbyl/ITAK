//
// Created by benja on 4/18/2017.
//

#include "Algorithm.h"

/// This method will determine which algorithm to run and how to run it.
ResultSet Algorithm::run(std::ifstream& input)
{
    bool dos = false;
    for(int i = 0; i < configDictionary->getCount(); i++)
    {
        if(configDictionary->getByIndex(i)->getKey() == "TimeFrame")
            dos = true;
    }
    if(dos) {
        // Run the denial of service
        methodUsed = "Denial Of Service";
        DenialOfServiceAnalyzer denied;
        return denied.run(input);
    }
    else {
        // Run port scan
        methodUsed = "Port Scan";
        PortScanAnalyzer port;
        return port.run(input);
    }
}

Algorithm::Algorithm(){methodUsed = "";}