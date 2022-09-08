#pragma once

#include "Media.h"
using namespace std;

class Video :
    public Media
{
    public:
        Video();
        Video(string id, string name, int len, string res, string form, string qual);
        virtual void ReadData(istream& in);
        virtual void WriteData(ostream& out);
        virtual string getType() const;

    private:
        string resolution;
        string format;
        string quality;
};