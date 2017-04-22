//
// Created by benja on 4/18/2017.
//

#ifndef ITAK_RESULTSET_H
#define ITAK_RESULTSET_H


#include <vector>
#include "Dictionary.h"

class ResultSet {
public:
    Dictionary<std::string, std::vector<std::string>>* results;
    void print(std::ostream& out);
    ResultSet();
};


#endif //ITAK_RESULTSET_H
