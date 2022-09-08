#include "Media.h"
using namespace std;

Media::Media()
{
	identifier = "";
	accountName = "";
	lengthSec = 0;
}

Media::Media(string id, string name, int length)
{
	identifier = id;
	accountName = name;
	lengthSec = length;
}

string Media::getID()
{
	return (identifier);
}

string Media::getAccName()
{
	return (accountName);
}

int Media::getLength()
{
	return(lengthSec);
}

void Media::setID(string id)
{
	identifier = id;
}

void Media::setAccName(string name)
{
	accountName = name;
}

void Media::setLength(int length)
{
	lengthSec = length;
}

void Media::ReadData(istream& in)
{
	stringstream SS;
	string buffer;

	in.ignore();
	getline(in, identifier);
	getline(in, accountName);
	getline(in, buffer);
	SS << buffer;
	SS >> lengthSec;
}

void Media::WriteData(ostream& out)
{
	out << setw(30) << setfill('_') << '_' << endl;
	out << identifier << endl
		<< accountName << endl
		<< lengthSec << endl;
}