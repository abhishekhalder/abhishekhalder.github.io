#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main () 
{
  string BinaryIn;
	
  cout << "\nPlease enter the binary string: ";
  
  getline (cin,BinaryIn);

  cout << "\nYour input is: " << BinaryIn << "\n" << endl;		

  return 0;
}

