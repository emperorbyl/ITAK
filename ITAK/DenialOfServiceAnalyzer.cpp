//
// Created by benja on 4/18/2017.
//

#include "DenialOfServiceAnalyzer.h"

ResultSet DenialOfServiceAnalyzer::run(std::ifstream& input)
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
            inputDictionary->add(pieces[1], Dictionary<int, int>(std::stoi(pieces[0]), 0));
        else if(success) {
            inputDictionary->add(pieces[1], Dictionary<int, int>(std::stoi(pieces[0]), count));
            count++;
        }
        std::getline(input, row);
    }
    // interpret configuration
    int timestamp = 0;
    int likelyThreshold = 0;
    int possibleThreshold = 0;
    Configuration config;
    // Loop through the configDictionary to get each value that is needed.
    for(int i = 0; i < configDictionary->getCount(); i++)
    {
        if(configDictionary->getByIndex(i)->getKey() == "Timeframe")
            timestamp = convertStringToInt(configDictionary->getByIndex(i)->getValue());
        if(configDictionary->getByIndex(i)->getKey() == "Likely Attack Message Count")
            likelyThreshold = convertStringToInt(configDictionary->getByIndex(i)->getValue());
        if(configDictionary->getByIndex(i)->getKey() == "Possible Attack Message Count")
            possibleThreshold = convertStringToInt(configDictionary->getByIndex(i)->getValue());
    }
    // run the algorithm
    ResultSet results;
    results.results->add("Likely Attackers", std::vector<std::string>());
    results.results->add("Possible Attackers", std::vector<std::string>());
    results.results->add("Attack Periods", std::vector<std::string>());
    results.results->add("Timeframe", std::vector<std::string>());
    for(int i = 0; i < inputDictionary->getCount(); i++)
    {
        for(int j = 0; j < inputDictionary->getByIndex(i)->getValue().getCount(); j++)
        {
            // Start at the current timestamp.
            int s = inputDictionary->getByIndex(i)->getValue().getByIndex(j)->getKey();
            int c = inputDictionary->getByIndex(i)->getValue().getByIndex(j)->getValue();
            // Loop through the timestamps that are within the time frame.
            for(int k = s; k < s + timestamp; k++)
                c+= inputDictionary->getByIndex(i)->getValue().getByIndex(k)->getValue();
            if(c >= likelyThreshold)
            {
                results.results->getByKey("Likely Attackers")->getValue().push_back(inputDictionary->getByIndex(i)->getKey());
                results.results->getByKey("Attack Periods")->getValue().push_back(std::to_string(s) + "-" + std::to_string(timestamp));
            }
            else if(c >=possibleThreshold)
            {
                results.results->getByKey("Possible Attackers")->getValue().push_back(inputDictionary->getByIndex(i)->getKey());
                results.results->getByKey("Attack Periods")->getValue().push_back(std::to_string(s) + "-" + std::to_string(timestamp));
            }

        }
    }
    return results;

}

DenialOfServiceAnalyzer::DenialOfServiceAnalyzer(){inputDictionary = new Dictionary<std::string, Dictionary<int, int>>("", Dictionary<int, int>(0,0));}