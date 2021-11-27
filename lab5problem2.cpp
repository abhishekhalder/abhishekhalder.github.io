#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// declare functions
double f(double x);
double bisection(double a, double b, double tol, int maxIter);

int main () 
{
  double my_a, my_b, my_tol, my_root;
  int my_maxIter;
  ofstream myfile;

  cout << "\nPlease input begin of your initial interval (a): ";
  cin >> my_a;
  cout << "\nPlease input end of your initial interval (b): ";
  cin >> my_b;
  cout << "\nPlease input your tolerance (epsilon): ";
  cin >> my_tol;
  cout << "\nPlease input the maximum number of iterations: ";
  cin >> my_maxIter;
  cout << "\n\n" << endl;
  
  my_root = bisection(my_a, my_b, my_tol, my_maxIter); // find the root using bisection method

  cout << "\nThe root computed from bisection method is: "<< my_root << "\n" << endl;

  return 0;
}

double f(double x)
{
       double y;       

       y = 2*(sin(x)/x);

       return y;
}

double bisection(double a, double b, double tol, int maxIter)
{
	double c;	
	int IterationNumber = 1;	

        ofstream myfile;	
        myfile.open ("BisectionLoop.dat");	
	
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
	IterationNumber = IterationNumber + 1;
        myfile << c << "\t\t" << f(c) << "\n" << endl;
	}
	
	while( (fabs(f(c)) > tol) && (IterationNumber <= maxIter) );	
	
	myfile.close(); 

	return c;
}
