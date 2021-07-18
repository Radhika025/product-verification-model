#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "Blockchain.h"
using namespace std;
class CSVReader
{
    string fileName;
    string delimeter;
public:
    CSVReader(string filename, string delm = ",") : fileName(filename), delimeter(delm)
    { }
    // Function to fetch data from a CSV File
    vector<vector<string> > getData();
};
/*
* Parses through csv file line by line and returns the data
* in vector of vector of strings.
*/
vector<vector<string> > CSVReader::getData()
{
    ifstream file(fileName);
    vector<vector<string> > dataList;
    string line = "";
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        vector<string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
        dataList.push_back(vec);
    }
    // Close the File
    file.close();
    return dataList;
}

int main()
{
    Blockchain bChain = Blockchain();
    
    CSVReader reader("test.csv");
    vector<vector<string> > dataList = reader.getData();
    /*for(vector<string> pro_id : dataList)
    {
        for(string data : pro_id)
        {
            cout<<data << " ";
        }
        cout<<endl;
    }*/
    
    CSVReader reader1("blocknumber.csv");
    vector<vector<string> > pro_name = reader1.getData();
    /*for(vector<string> vec1 : pro_name)
    {
        for(string data : vec1)
        {
            cout<<data<< " ";
        }
        cout<<endl;
    }*/

    CSVReader reader2("manufacturer.csv");
    vector<vector<string> > manuname = reader2.getData();
    /*for(vector<string> vec2 : manuname)
    {
        for(string data : vec2)
        {
            cout<<data << " ";
        }
        cout<<endl;
    }*/

    CSVReader reader3("retailer.csv");
    vector<vector<string> > retailname = reader3.getData();
    /*for(vector<string> vec3 : retailname)
    {
        for(string data : vec3)
        {
            cout<<data << " ";
        }
        cout<<endl;
    }*/

    CSVReader reader4("wholesaler.csv");
    vector<vector<string> > wholesalername = reader4.getData();
    /*for(vector<string> vec4 : wholesalername)
    {
        for(string data : vec4)
        {
            cout<<data << " ";
        }
        cout<<endl;
    }*/

    
    CSVReader reader5("transaction.csv");
    vector<vector<string> > txnname = reader5.getData();
    for(vector<string> vec5 : txnname)
    {
        for(string data : vec5)
        {
            int pos1 = data.find("_");
            int t = stoi(data.substr(0,pos1));
            string txn_name = data.substr(pos1+1);
            int pos2 = txn_name.find("_");
            string from = txn_name.substr(0, pos2);
            string to = txn_name.substr(pos2+1);
            bChain.AddBlock(Block(t, from, to));
            
        }
        cout<<endl;
    }
    return 0;
}
