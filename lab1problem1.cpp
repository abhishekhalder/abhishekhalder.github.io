#include<iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;	
	
	cout << "\nPlease enter an integer value for a: ";
	cin >> a;
	cout << "Please enter an integer value for b: ";
	cin >> b;

	a = a + b;
	b = a - b; // This results b = a
	a = a - b;
	
	cout << "\nSwapped values: \n" << endl;
	cout << "a = " << a << ", b = " << b << "\n" << endl;
}


