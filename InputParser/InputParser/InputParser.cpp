#include "InputParser.h"

int main ()
{
	long long wholeNumber = 0;
	long double floatingPoint = 0.0;
	bool isInt = true;
	bool isFloat = true;
	string input = "";

	cout << "Input a number: ";
	cin >> input;
	cin.ignore();

	//Attempt to convert both, then figure out which type it is.
	try { floatingPoint = stold(input); }
	catch (invalid_argument ex) { isFloat = false; }
	catch (out_of_range big)	{ isFloat = false; } //Might still convert to int
	try { wholeNumber = stoll(input); }
	catch (invalid_argument err) { isInt = false; }
	catch (out_of_range tooBig) { cout << tooBig.what(); cin.get(); return EXIT_SUCCESS; }

	//If the types exist and match, it's an int.
	if (floatingPoint == wholeNumber)
		isFloat = false;

	cout << endl;

	if (!isFloat)
	{
		if (!isInt)
			cout << "Cannot convert " + input;
		else
			cout << "Whole number = " << wholeNumber;
	}
	else
		cout << "Floating point = " << floatingPoint;

	cin.get();//Hold the door.

	return EXIT_SUCCESS;
}