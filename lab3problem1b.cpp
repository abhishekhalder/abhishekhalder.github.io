#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> // in case we use setprecision
using namespace std;

// declare functions
string DecimalToBinary(double DecimalInput);

int main () 
{
  double DecimalIn;
	 
  cout << "\nPlease enter the decimal number: ";
  
  cin >> DecimalIn;
  	
  cout << "\nBinary conversion is: " << DecimalToBinary(DecimalIn) << "\n" << endl;

  return 0;
}


string DecimalToBinary(double DecimalInput)
{
	string BinaryOutput = "", BinOut_Int = "", BinOut_Frac = "";
	double DecimalIn_Int, DecimalIn_Frac, temp, temp_int, temp_frac;
	int temp_divisor;
        
        DecimalIn_Frac = modf(DecimalInput, &DecimalIn_Int); // Separate the interger and fractional part of the decimal input


	/* Convert the integer part of the decimal input */

	if (DecimalIn_Int == 0)
	 {
		BinOut_Int = "0";
	 }
	else if (DecimalIn_Int == 1)
	 {
		BinOut_Int = "1";
	 }
	else
	 {	temp_divisor = static_cast<int>(DecimalIn_Int); // casting the double as int (to enable integer divisions)
		
		while (temp_divisor >= 1)
		    {
			 if (temp_divisor % 2 == 0)
			  {
				BinOut_Int += "0";
			  }
			else // temp_divisor % 2 == 1
			  {
				BinOut_Int += "1";
			  }
			temp_divisor = temp_divisor/2; //For next iteration of the while loop
	             }			
	}
	BinOut_Int = string( BinOut_Int.rbegin(), BinOut_Int.rend() ); //Reverse the string BinOut_Int





       /* Convert the fractional part of the decimal input */

	while (DecimalIn_Frac > 0) //This while loop will be skipped when the fractional part of the decimal input is zero
	    {
		temp = DecimalIn_Frac*2;
		temp_frac = modf(temp, &temp_int);
		
		if (temp_int == 0)
		 {
			BinOut_Frac += "0";
		 }		
		else // temp_int = 1
		 {		
			BinOut_Frac += "1";
		 }
		
		DecimalIn_Frac = temp_frac; //For the next iteration
	    }

	BinaryOutput = BinOut_Int + "." + BinOut_Frac;	//Combined binary output

	return BinaryOutput;
}
