#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
/*
 * A class to create and write data in a csv file.
 */
class CSVWriter
{
    std::string fileName;
    std::string delimeter;
    static size_t linesCount;
public:
    CSVWriter(std::string filename, std::string delm = ",") :
            fileName(filename), delimeter(delm)
    {}
    /*
     * Member function to store a range as comma seperated value
     */
    template<typename T>
    void addDatainRow(T first, T last);
    void updateHash(int id, std::string hash, std::string from, std::string to);
};
/*
 * This Function accepts a range and appends all the elements in the range
 * to the last row, seperated by delimeter (Default is comma)
 */
