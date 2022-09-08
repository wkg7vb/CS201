#include "LibraryBook.h"

LibraryBook::LibraryBook()
{
	title = "";
	author = "";
	ISBN = "";
	checkedOut = false;
}

LibraryBook::LibraryBook(string titleTS, string authorTS, string ISBNTS)
{
	title = titleTS;
	author = authorTS;
	ISBN = ISBNTS;
	checkedOut = false;
}

string LibraryBook::getTitle()
{
	return(title);
}

string LibraryBook::getAuthor()
{
	return(author);
}

string LibraryBook::getISBN()
{
	return(ISBN);
}

void LibraryBook::checkOut()
{
	checkedOut = true;
}

void LibraryBook::checkIn()
{
	checkedOut = false;
}

bool LibraryBook::isCheckedOut()
{
	return(checkedOut);
}