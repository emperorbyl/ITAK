//
// Created by benja on 4/18/2017.
//

#include "ResultSet.h"

void ResultSet::print(std::ostream& out)
{
    for(int i = 0; i< results->getCount(); i++)
    {
        out << "Key: " << results->getByIndex(i)->getKey() << std::endl;
        out << "Value: ";
        for(int j = 0; j < results->getByIndex(i)->getValue().size(); j++)
        {
            out << " " + results->getByIndex(i)->getValue().at(j) + " " + results->getByIndex(i)->getValue().at(j);
        }
        out << std::endl;
    }
}

ResultSet::ResultSet(){results = new Dictionary<std::string, std::vector<std::string>>(std::string(), std::vector<std::string>());}