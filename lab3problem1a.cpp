#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib> // needed for atof()
using namespace std;

// declare functions
double BinaryToDecimal(string BinaryInput);

int main () 
{
  string BinaryIn;
  double DecimalIn;
	
  cout << "\nPlease enter the binary string: ";
  
  getline (cin,BinaryIn);
  
  cout << "\nDecimal conversion is: " << BinaryToDecimal(BinaryIn) << "\n" << endl;		

  return 0;
}


double BinaryToDecimal(string BinaryInput)
{
	double DecimalOut_Int = 0, DecimalOut_Frac = 0, DecimalOutput = 0;	
	int DotPosition, BinLength_Int, BinLength_Frac;

	DotPosition = BinaryInput.find('.'); //Position of the dot in the input string, counting from 0 at the leftmost

	if (DotPosition != string::npos) //The input string has dot
          {    
		BinLength_Int = DotPosition; //Length of integer part of binary string
        	BinLength_Frac = BinaryInput.length() - BinLength_Int - 1; //Length of fractional part of binary string

		for (int i=1; i <= BinLength_Int; i++)
	  	{		
			DecimalOut_Int += atof(BinaryInput.substr(i-1,1).c_str())*pow(2,BinLength_Int-i); //Integer part of the decimal output	
	  	}

		for (int j=1; j <= BinLength_Frac; j++)
	  	{		
			DecimalOut_Frac += atof(BinaryInput.substr(DotPosition+j,1).c_str())/pow(2,j);	//Fractional part of the decimal output
	  	}
	
		DecimalOutput = DecimalOut_Int + DecimalOut_Frac;	//Combined decimal output
	    }
	
	else //The input string has no dot
	    {
		for (int k=1; k <= BinaryInput.length(); k++)
	  	{		
			DecimalOutput += atof(BinaryInput.substr(k-1,1).c_str())*pow(2,BinaryInput.length()-k);	
	  	}
	    }

  return DecimalOutput;
}



