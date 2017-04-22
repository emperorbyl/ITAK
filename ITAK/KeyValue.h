//
// Created by benja on 4/18/2017.
//

#ifndef ITAK_KEYVALUE_H
#define ITAK_KEYVALUE_H
#include <string>
template <typename T, typename X>
class KeyValue {
public:
    KeyValue(T key, X value);
    T getKey();
    X getValue();
private:
    T key;
    X value;
};

template <typename T, typename X>
KeyValue<T, X>::KeyValue(T newKey, X newValue)
{
    key = newKey;
    value = newValue;
}

template <typename T, typename X>
T KeyValue<T, X>::getKey()
{
    return key;
}
template <typename T, typename X>
X KeyValue<T, X>::getValue()
{
    return value;
}

#endif //ITAK_KEYVALUE_H
