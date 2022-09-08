#include "Video.h"
using namespace std;

Video::Video() : Media()
{
	resolution = "";
	format = "";
	quality = "";
}

Video::Video(string id, string name, int len, string res, string form, string qual) : Media(id, name, len)
{
	resolution = res;
	format = form;
	quality = qual;
}

void Video::ReadData(istream& in)
{
	Media::ReadData(in);
	getline(in, resolution);
	getline(in, format);
	getline(in, quality);
}

void Video::WriteData(ostream& out)
{
	Media::WriteData(out);
	out << resolution << endl
		<< format << endl
		<< quality << endl;
}

string Video::getType() const
{ 
	return("Video"); 
}