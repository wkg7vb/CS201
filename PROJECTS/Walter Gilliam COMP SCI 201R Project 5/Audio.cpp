#include "Audio.h"
using namespace std;

Audio::Audio() : Media()
{
	format = "";
	quality = "";
}

Audio::Audio(string id, string name, int len, string form, string qual) : Media(id, name, len)
{
	format = form;
	quality = qual;
}

void Audio::ReadData(istream& in)
{
	Media::ReadData(in);
	getline(in, format);
	getline(in, quality);
}

void Audio::WriteData(ostream& out)
{
	Media::WriteData(out);
	out << format << endl
		<< quality << endl;
}

string Audio::getType() const
{ 
	return ("Audio"); 
}