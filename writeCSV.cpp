#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
#include "writeCSV.h"
using namespace std;

size_t CSVWriter::linesCount = 0;

void CSVWriter::updateHash(int id, string hash, string from ,string to)
{
    std::vector<std::string> datalist = {to_string(id), hash, from, to};
    this->addDatainRow(datalist.begin(), datalist.end());
}

template<typename T>
void CSVWriter::addDatainRow(T first, T last)
{
    std::fstream file;
    // Open the file in truncate mode if first line else in Append Mode
    file.open(fileName, std::ios::out | (linesCount ? std::ios::app : std::ios::trunc));
    // Iterate over the range and add each lement to file seperated by delimeter.
    for (; first != last; )
    {
        file << *first;
        if (++first != last)
            file << delimeter;
    }
    file << "\n";
    linesCount++;
    // Close the file
    file.close();
}