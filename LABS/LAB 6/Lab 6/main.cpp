#include "LibraryBook.h"
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	string Tname, Tauthor, TISBN;
	vector <LibraryBook> shelves;
	ifstream fin;
	ofstream fout;

	cout << "READING BOOKS FROM BOOKS.TXT ... ";
	fin.open("books.txt");

	while (!fin.eof())
	{
		getline(fin, Tname);
		getline(fin, Tauthor);
		getline(fin, TISBN);
		
		shelves.push_back(LibraryBook(Tname, Tauthor, TISBN));
	}

	fin.close();
	cout << "COMPLETE" << endl;

	cout << "SCANNING ISBNS FROM ISBNS.TXT ... ";
	fin.open("isbns.txt");

	while (!fin.eof())
	{
		fin >> TISBN;

		for (int i = 0; i < shelves.size(); ++i)
		{
			if (shelves.at(i).getISBN() == TISBN)
			{
				if (shelves.at(i).isCheckedOut())
				{
					shelves.at(i).checkIn();
				}
				else
				{
					shelves.at(i).checkOut();
				}
			}
		}
	}

	fin.close();
	cout << "COMPLETE" << endl;

	cout << "WRITING CHECKOUT BOOKS TO CHECKEDOUT.CSV ... ";
	fout.open("checkedout.csv");

	fout << "\"Title\", \"Author\", \"ISBN\"" << endl;

	for (int i = 0; i < shelves.size(); ++i)
	{
		if (shelves.at(i).isCheckedOut())
		{
			fout << "\"" << shelves.at(i).getTitle() << "\", \"" << shelves.at(i).getAuthor() << "\", \"" << shelves.at(i).getISBN() << "\"" << endl;
		}
	}

	fout.close();
	cout << "COMPLETE" << endl;

	return(0);
}