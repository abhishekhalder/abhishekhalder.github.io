#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// declare functions
double f(double x);
double bisection(double a, double b, double tol);

int main () 
{
  double x_min = -2.0, x_max = 15.0, N = 1000.0;
  double delta_x, j, xj, L5;
  double my_a, my_b, my_tol, my_root;

  delta_x = (x_max - x_min)/N;
 // length of each interval along x-axis

  ofstream myfile;

  myfile.open ("Laguerre.dat");

  for ( j = 1; j <= N+1; j++ )
    {
	xj = x_min + (j - 1)*delta_x; // grid points along x-axis	
	
	L5 =  f(xj); // L5(x) evaluated at grid points
  
  	myfile << xj << "\t\t" << L5 << "\n" << endl;
     }
  
  myfile.close();
  

  cout << "\nPlease input begin of your initial interval (a): ";
  cin >> my_a;
  cout << "\nPlease input end of your initial interval (b): ";
  cin >> my_b;
  cout << "\nPlease input your tolerance (epsilon): ";
  cin >> my_tol;
  cout << "\n\n" << endl;
  
  

  my_root = bisection(my_a, my_b, my_tol); // find the root using bisection method

  cout << "\n\nThe root computed from bisection method is: "<< my_root << "\n" << endl;

  return 0;
}

double f(double x)
{
       double y;       

       y = ( - pow(x,5) + 25*pow(x,4) - 200*pow(x,3) + 600*pow(x,2) - 600*x + 120 )/120;

       return y;
}


double bisection(double a, double b, double tol)
{
	double c;
        
	ofstream myfile;	
        myfile.open ("BisectionLoopRoot1.dat");

	do
         {
          c = (a+b)/2.0;
            if ( f(a)*f(c) < 0 )
            {
               b = c;
            }
            else
            {
               a = c;
            }
          myfile << c << "\t\t" << f(c) << "\n" << endl;
	}
	while( fabs(f(c)) > tol );	
	
	myfile.close();

	return c;
}

