#include <cstdint>
#include <iostream>
#include <sstream>
#include <fstream>
#include "writeCSV.h"

using namespace std;

class Block {
    uint32_t _nIndex;
    uint32_t _nNonce;
    string _sData;
    time_t _tTime;
    string sDataFrom;
    string sDataTo;
    string sFrom;
    string sTo;
    CSVWriter my_writer = CSVWriter("hashdetails.csv");
    string _CalculateHash() const;

public:
    string sHash;
    string sPrevHash;
    //ofstream myfile;
    Block(uint32_t nIndexIn, const string &sDataFrom, const string &sDataTo);

    void MineBlock(uint32_t nDifficulty);
   

};


