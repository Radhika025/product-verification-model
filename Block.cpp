#include "Block.h"
#include "sha256.h"
#include<ctime>

Block::Block(uint32_t nIndexIn, const string &sDataFrom, const string &sDataTo) : _nIndex(nIndexIn), sFrom(sDataFrom), sTo(sDataTo)
{
    _nNonce = 0;
    _tTime = time(nullptr);

    sHash = _CalculateHash();
}

void Block::MineBlock(uint32_t nDifficulty)
{
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do
    {
        _nNonce++;
        sHash = _CalculateHash();
    }
    while (sHash.substr(0, nDifficulty) != str);
    {
        cout << "Block mined: " << "FROM " << sFrom << " " << "TO " << sTo << " " << sHash << endl;
        my_writer.updateHash(_nIndex, sHash, sFrom, sTo);
    }
    
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << sFrom << sTo << _nNonce;
    string hash = sha256(ss.str());
    return hash;
}


