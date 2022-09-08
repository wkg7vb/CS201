#pragma once

#include <string>
using namespace std;

class LibraryBook
{
	public:
		LibraryBook();
		LibraryBook(string titleTS, string authorTS, string ISBNTS);
		string getTitle();
		string getAuthor();
		string getISBN();
		void checkOut();
		void checkIn();
		bool isCheckedOut();

	private:
		string title;
		string author;
		string ISBN;
		bool checkedOut;
};

