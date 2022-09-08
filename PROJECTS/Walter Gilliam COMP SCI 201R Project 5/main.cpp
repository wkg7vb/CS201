#include "Media.h"
#include "Audio.h"
#include "Video.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	Media * file[200];
	Audio* tempA;
	Video* tempV;
	char type;

	ifstream inFS;
	ofstream outFS;
	
	int count = 0;

	cout << "Action\t\tNumber\tType" << endl;
	cout << setw(28) << setfill('*') << '*' << endl;

	inFS.open("Program5Data.txt");
	//inFS.open("TextFile1.txt");

	do
	{
		cout << "Reading\t\t" << count << "\t";
		inFS >> type;

		switch (type)
		{
			case 'A':
			{
				cout << "A";
				tempA = new Audio;
				tempA->ReadData(inFS);
				file[count++] = tempA;
				break;
			}
			case 'V':
			{
				cout << "V";
				tempV = new Video;
				tempV->ReadData(inFS);
				file[count++] = tempV;
				break;
			}
			default:
			{
				break;
			}
		}
		cout << endl;
	} while (!inFS.eof());

	tempA = NULL;
	tempV = NULL;
	delete tempA;
	delete tempV;

	inFS.close();

	cout << endl;

	//clearing previously existing files
	outFS.open("audio_output.txt", ofstream::trunc);
	outFS.close();
	outFS.open("video_output.txt", ofstream::trunc);
	outFS.close();

	for (unsigned int i = 0; i < count; ++i)
	{
		cout << "Writing\t\t" << i << "\t";
		
		if (file[i]->getType() == "Audio")
		{
			cout << "A";
			outFS.open("audio_output.txt", ios_base::app);
			file[i]->WriteData(outFS);
			outFS.close();
		}
		else if (file[i]->getType() == "Video")
		{
			cout << "V";
			outFS.open("video_output.txt", ios_base::app);
			file[i]->WriteData(outFS);
			outFS.close();
		}
		cout << endl;
	}

	return (0);
}