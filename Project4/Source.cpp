/* Author:
 Creation Date: 3/28/22
 Last Modification Date: 3/29/22
 Purpose: 
 */

#include <iostream>

using namespace std;

//------------------------------- Prototypes
string WelcomeMessage();
char Menu();
float ComputeSum(float num1, float num2);
float ComputeSub(float num1, float num2);
float ComputeMul(float num1, float num2);
float ComputeDiv(float num1, float num2);
float ComputeRoot(float num1, int n);
float ComputePower(float num1, int index);
float ComputePerc(float num1, float perc);
int   ComputeLCM(int num1, int num2);
int   ComputeGCD(int num1, int num2);
float ComputeMod(int num1, int num2);
string ExitMessage();


int main() {

	string start = WelcomeMessage();
	string exit = ExitMessage();
	cout << start;

	return Menu();

	cout << endl << exit;

	return 0;
}
//-------------------------------------------------------------- Message
string WelcomeMessage() {
	string message;

	message = "---------------------------------------------------\n\tWELCOME TO THE CALCULATOR PROJECT\n-------------------------------------------------\n";

	return message;
}
//------------------------------------menu
char Menu() {
	char selection;
	float a, b;
	do {

	cout << "\nA.) Addition\n";
	cout << "B.) Subtraction\n";
	cout << "C.) Multiplication\n";
	cout << "D.) Division\n";
	cout << "E.) Roots(only positive numbers)\n";
	cout << "F.) Power(only positive numbers)\n";
	cout << "G.) Percentage\n";
	cout << "H.) Least Common Multiplier(only positive numbers)e\n";
	cout << "I.) Greatest Common Divisor(only positive numbers)\n";
	cout << "J.) Modulus(only positive numbers)\n";
	cout << "L.) Quit\n";

	cin >> selection;

	cout << "\n Select the first number to preform: ";
	cin >> a;
	cout << "\n Select the second number to preform: ";
	cin >> b;


	selection = toupper(selection);

		switch (toupper(selection)) {
		case 'A':
			cout << "Operation: " << a << " + " << b << " = " << ComputeSum(a, b) << endl;
			break;
		case 'B':
			cout << "Operation: " << a << " - " << b << " = " << ComputeSub(a, b) << endl;
			break;
		case 'C':
			cout << "Operation: " << a << " * " << b << " = " << ComputeMul(a, b) << endl;
			break;
		case 'D':
			cout << "Operation: " << a << " / " << b << " = " << ComputeDiv(a, b) << endl;
			break;
		case 'E':
			while (b < 0)
			{
				cout << "\nRoots can not be negative! Enter a non negative number: ";
				cin >> b;
			}
			while (a < 0)
			{
				cout << "\nRoots can not be negative! Enter a non negative number: ";
				cin >> a;
			}
			cout << "Operation: " << a << " root " << b << " = " << ComputeRoot(a, b) << endl;
			break;
		case 'F':
			while (b < 0)
			{
				cout << "\nPowers can not be negative! Enter a non negative number: ";
				cin >> b;
			}
			while (a < 0)
			{
				cout << "\nPowers can not be negative! Enter a non negative number: ";
				cin >> a;
			}
			cout << "Operation: " << a << " ^ " << b << " = " << ComputePower(a, b) << endl; ;
			break;
		case 'G':
			cout << "Operation: " << a << " % " << b << " = " << ComputePerc(a, b) << endl;
			break;
		case 'H':
			cout << "LCM: " << a << " and " << b << " = " << ComputeLCM(a, b) << endl;
			break;
		case 'I':
			cout << "GCD: " << a << " and " << b << " = " << ComputeGCD(a, b) << endl;
			break;
		case 'J':
			cout << "Modulus: " << a << " and " << b << " = " << ComputeMod(a, b);
			break;
		case 'L':
			cout << exit;
			break;
		default:
			cout << "INVALID SELECTION! Enter A through L";
			break;
		}

	} while (selection != 'L');


	return 0;
}

//----------------------------- Addition
float ComputeSum(float a, float b) {

	return (a + b);

}

//------------------------------ Subtraction
float ComputeSub(float a, float b) {

	return (a - b);

}

//--------------------------------- Multplication
float ComputeMul(float a, float b) {

	return (a * b);

}

//--------------------------------- Division

float ComputeDiv(float a, float b) {

	return (a / b);

}

//--------------------------------- Percentage

float ComputePerc(float a, float b) {

	return (a * b / 100);

}

//--------------------------------- root

float ComputeRoot(float root, int index) {

	float tp, mid, low = 0.0, high = root;

	do {

		mid = (low + high) / 2;

		if (ComputePower(mid, index) > root)

			high = mid;

		else

			low = mid;

		mid = (low + high) / 2;

		tp = (ComputePower(mid, index) - root);

		if (tp < 0) { //grab absolute value

			tp = -tp;

		}

	}

	while (tp > .000005); //accuracy of our root

	return mid;

}

//--------------------------------- power

float ComputePower(float x, int n) {

	float numProduct = 1.0;

	int i;

	for (i = 0; i < n; i++)

		numProduct *= x;

	return numProduct;

}

//--------------------------------- GCD

int ComputeGCD(int a, int b) {

	while (a != b) {

		if (a > b)

			a -= b;

		else

			b -= a;

	}

	return a;

}

//--------------------------------- LCM

int ComputeLCM(int a, int b) {

	return ((a * b) / ComputeGCD(a, b));

}
//---------------------------------------- MOD
float ComputeMod(int a, int b)
{
	return a % b;
}

//------------------------------------------------------------------ Exit message
string ExitMessage()
{
	string message = "\nThank you!Goodbye.\n";

	return message;
}