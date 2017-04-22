//
// Created by benja on 4/3/2017.
//

#include "TestingDictionary.h"
#include "../Dictionary.h"
void TestingDictionary::testAdd()
{
    Dictionary<std::string, std::string>* dictionary = new Dictionary<std::string, std::string>("hair", "brown");
    std::cout << "Testing Add function" << std::endl;
    dictionary->add("eye", "green");
    if(dictionary->getByKey("eye")->getValue() != "green")
        std::cout << "There is something wrong with the add function." << std::endl;
}
void TestingDictionary::testDictionary()
{
    std::cout << "Testing Dictionary Constructor with strings" << std::endl;
    Dictionary<std::string, std::string>* dictionary = new Dictionary<std::string, std::string>("hair", "brown");
    if(dictionary == nullptr)
        std::cout << "Something is wrong with the dictionary constructor." << std::endl;
    if(dictionary->getCount() != 1)
        std::cout << "Something is wrong with the dictionary constructor." << std::endl;
    if(dictionary->getByIndex(0)->getValue() != "brown")
        std::cout << "Something is wrong with the dictionary constructor." << std::endl;
    if(dictionary->getByKey("hair")->getKey() != "hair")
        std::cout << "Something is wrong with the dictionary constructor." << std::endl;
    Dictionary<int, std::string>* dictionary1 = new Dictionary<int, std::string>(1, "man");
    if(dictionary1->getCount() != 1)
        std::cout << "Something is wrong with the dictionary constructor." << std::endl;
    if(dictionary1->getByIndex(0)->getValue() != "man")
        std::cout << "Something is wrong with the dictionary constructor." << std::endl;
    if(dictionary1->getByKey(1)->getKey() != 1)
        std::cout << "Something is wrong with the dictionary constructor." << std::endl;
}
void TestingDictionary::testDictionaryWithIntDictionary()
{
    std::cout << "Testing Dictionary Constructor with size" << std::endl;
    Dictionary<std::string, std::string>* dictionary = new Dictionary<std::string, std::string>(100);
    if(dictionary->getCount() < 100)
        std::cout << "Something is wrong with the int constructor" << std::endl;
}
void TestingDictionary::testGetCount()
{
    std::cout << "Testing count method" << std::endl;
    Dictionary<std::string, std::string>* dictionary = new Dictionary<std::string, std::string>("hair", "brown");
    if(dictionary->getCount() != 1)
        std::cout << "There is something wrong with the getCount method." << std::endl;
}
void TestingDictionary::testGetByKey()
{
    std::cout << "Testing Dictionary getByKey method" << std::endl;
    Dictionary<std::string, std::string>* dictionary = new Dictionary<std::string, std::string>("hair", "brown");
    if(dictionary->getByKey("hair")->getKey() != "hair")
        std::cout << "There is something wrong in getting the keyValue by key." << std::endl;
}
void TestingDictionary::testGetByIndex()
{
    std::cout << "Testing Dictionary getByIndex method" << std::endl;
    Dictionary<std::string, std::string>* dictionary = new Dictionary<std::string, std::string>("hair", "brown");
    if(dictionary->getByIndex(0)->getKey() != "hair")
        std::cout << "There is something wrong in getting the keyValue by index." << std::endl;
}
void TestingDictionary::testRemoveByKey()
{
    std::cout << "Testing Dictionary removeByKey method" << std::endl;
    Dictionary<std::string, std::string>* dictionary = new Dictionary<std::string, std::string>("hair", "brown");
    dictionary->add("eye", "grey");
    dictionary->removeByKey("eye");
    if(dictionary->getCount() == 2)
        std::cout << "Something is wrong with removeByKey method" << std::endl;
}
void TestingDictionary::testRemoveByIndex()
{
    std::cout << "Testing Dictionary removeByIndex method" << std::endl;
    Dictionary<std::string, std::string>* dictionary = new Dictionary<std::string, std::string>("hair", "brown");
    dictionary->add("eye", "grey");
    dictionary->removeByIndex(1);
    for(int i = 0; i < dictionary->getCount(); i++) {
        if (dictionary->getByIndex(i)->getValue() == "grey")
            std::cout << "Something is wrong with removeByIndex method" << std::endl;
    }
}
void TestingDictionary::testDestructor()
{
    std::cout << "Testing Destructor method" << std::endl;
    Dictionary<std::string, std::string>* dictionary = new Dictionary<std::string, std::string>("hair", "brown");
    dictionary->~Dictionary();
    if(dictionary == nullptr)
        std::cout << "There is something wrong with the destructor." << std::endl;

}