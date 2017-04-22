//
// Created by benja on 4/18/2017.
//

#include "PortScanAnalyzer.h"

ResultSet PortScanAnalyzer::run(std::ifstream& input)
{
    // interpret the input
    int count = 1;
    while(!input.eof())
    {
        // make the address the key in the input dictionary and have the timestamp, source port, and des port as the value.
        std::string row;
        std::getline(input, row);
        std::string pieces[4];
        bool success = split(row, ',', pieces, 4);
        bool add = false;
        for(int i = 0; i < inputDictionary->getCount(); i++)
        {
            if(pieces[1] == inputDictionary->getByIndex(i)->getKey())
                add = true;
        }
        if(!add && success)
            inputDictionary->add(pieces[1], std::vector<int>{0});
        else if(success)
            inputDictionary->add(pieces[1], std::vector<int>{count});
        std::getline(input, row);
        count++;
    }
    // interpret configuration
    int likelyThreshold = 0;
    int possibleThreshold = 0;
    int portCount = 0;
    // Loop through the configDictionary to get each value that is needed.
    for(int i = 0; i < configDictionary->getCount(); i++)
    {
        if(configDictionary->getByIndex(i)->getKey() == "Likely Attack Message Count")
            likelyThreshold = convertStringToInt(configDictionary->getByIndex(i)->getValue());
        if(configDictionary->getByIndex(i)->getKey() == "Possible Attack Message Count")
            possibleThreshold = convertStringToInt(configDictionary->getByIndex(i)->getValue());
    }
    ResultSet results;
    results.results->add("Likely Attackers", std::vector<std::string>());
    results.results->add("Possible Attackers", std::vector<std::string>());
    results.results->add("Port Count",  std::vector<std::string>());

    // run the algorithm
    for(int i = 0; i < inputDictionary->getCount(); i++)
    {
        std::string src = inputDictionary->getByIndex(i)->getKey();
        int c = inputDictionary->getByIndex(i)->getValue().size();
        for(int j = 0; j < inputDictionary->getByIndex(i)->getValue().size(); j++)
            portCount += inputDictionary->getByIndex(i)->getValue().at(j);
        if(c >= likelyThreshold)
            results.results->getByKey("Likely Attackers")->getValue().push_back(src);
        if(portCount >= possibleThreshold)
            results.results->getByKey("Possible Attackers")->getValue().push_back(src);
    }
    return results;
}

PortScanAnalyzer::PortScanAnalyzer() {inputDictionary = new Dictionary<std::string, std::vector<int>>("", std::vector<int>());}