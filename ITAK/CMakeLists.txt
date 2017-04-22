cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Analyzer.cpp Analyzer.h DenialOfServiceAnalyzer.cpp DenialOfServiceAnalyzer.h PortScanAnalyzer.cpp PortScanAnalyzer.h Algorithm.cpp Algorithm.h Configuration.cpp Configuration.h Dictionary.h KeyValue.h Container.h ResultSet.cpp ResultSet.h Utils.cpp Utils.h )
add_executable(ITAK main.cpp ${SOURCE_FILES})

set(TEST_FILES
        Testing/TestingDictionary.cpp Testing/TestingDictionary.h Testing/TestingAlgorithm.cpp Testing/TestingAlgorithm.h Testing/TestAnalyzer.cpp Testing/TestAnalyzer.h Testing/TestingConfiguration.cpp Testing/TestingConfiguration.h Testing/TestingDenialOfService.cpp Testing/TestingDenialOfService.h Testing/TestingPortScan.cpp Testing/TestingPortScan.h Testing/TestingResultSet.cpp Testing/TestingResultSet.h Testing/testMain.cpp)
add_executable(Test Testing/testMain.cpp ${SOURCE_FILES} ${TEST_FILES})