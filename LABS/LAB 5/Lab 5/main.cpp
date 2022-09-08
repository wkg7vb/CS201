#include "Header.h"
using namespace std;

int main()
{
	char input;
	bool another = false;
	vector <double> miles;
	vector <double> gallons;

	try
	{
		do
		{
			miles.push_back(GetMiles());
			gallons.push_back(GetGallons());
		} while (again());

		cout << "Your MPG is " << GetMPG(miles, gallons) << "." << endl;
	}
	catch (runtime_error &excpt)
	{
		cout << excpt.what() << endl;
	}
	catch (...)
	{
		cout << "Something very bad happened, please start over." << endl;
	}

	return 0;
}