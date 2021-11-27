#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// declare functions
double f(double x);


int main () 
{
  
  double x = 0;
  double h, k;
  double f_prime_Exact, f_prime_Approx, RelativeError;
  
  ofstream myfile;

  myfile.open ("Lab2_double.dat");
  
  f_prime_Exact = 100; // exact value of the derivative
 
  for ( k = 20; k <= 200; k = k++ )
    {
	h = pow(2,-k/4); // step size	
	
	f_prime_Approx = (f(x + h) - f(x))/h; // approximate value of the derivative

	RelativeError = fabs((f_prime_Exact - f_prime_Approx)/f_prime_Exact); // relative error
  
  	myfile << h << "\t\t" << f_prime_Approx*h << "\t\t" << f_prime_Approx << "\t\t" << RelativeError << "\n" << endl;
     }
  
  myfile.close();
  
  return 0;
}


double f(double x)
{
	double y;	

	y = exp(100*x); // our function
	
	return y;
}
