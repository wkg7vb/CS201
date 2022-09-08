#pragma once

#include "Media.h"
using namespace std;

class Audio :
    public Media
{
    public:
        Audio();
        Audio(string id, string name, int len, string form, string qual);
        virtual void ReadData(istream& in);
        virtual void WriteData(ostream& out);
        virtual string getType() const;

    private:
        string format;
        string quality;
};