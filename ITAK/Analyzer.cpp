//
// Created by benja on 4/18/2017.
//

#include "Analyzer.h"




/// This method will determine how the method needs to be run.
/// \param config The list of parameters.
void Analyzer::setConfig(Configuration& config)
{

    for(int i = 0; i < config.dictionary->getCount(); i++)
    {
        configDictionary->add(config.dictionary->getByIndex(i)->getKey(), config.dictionary->getByIndex(i)->getValue());
    }
}

Analyzer::Analyzer() {
    configDictionary = new Dictionary<std::string, std::string>("", "");
}