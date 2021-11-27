#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// declare functions
double f(double x);
double bisection(double a, double b, double tol, int maxIter);

double secant(double a, double b, double tol, int maxIter);

double Regulafalsi(double a, double b, double tol, int maxIter);

int main () 
{
  double my_a, my_b, my_tol, my_root_bisection, my_root_secant, my_root_reg;
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
  
  my_root_bisection = bisection(my_a, my_b, my_tol, my_maxIter); // find the root using bisection method
  cout << "\nThe root computed from bisection method is: "<< my_root_bisection << "\n" << endl;

  my_root_secant = secant(my_a, my_b, my_tol, my_maxIter); // find the root using secant method
  cout << "\nThe root computed from secant method is: "<< my_root_secant << "\n" << endl;

  my_root_reg = Regulafalsi(my_a, my_b, my_tol, my_maxIter); // find the root using Regulafalsi method
  cout << "\nThe root computed from Regulafalsi method is: "<< my_root_reg << "\n" << endl;

  return 0;
}

double f(double x)
{
       double y;       

       y = 2.0*sin(x) - (exp(x)/4.0) - 1.0;

       return y;
}

//bisection method

double bisection(double a, double b, double tol, int maxIter)
{
	double c;	
	int IterationNumber = 0;	

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
        cout << "\nNumber of iteration in bisection method : "<< IterationNumber << "\n" << endl;	
	myfile.close(); 

	return c;
}


//Secant method

double secant(double x0, double x1, double tol, int maxIter)
{
	double x2;	
	int IterationNumber = 0;	

        ofstream myfile;	
        myfile.open ("SecantLoop.dat");	
         
        while(IterationNumber <= maxIter)
        {
          
	  x2 = x0 - ((f(x0) * (x1 - x0)) / (f(x1) - f(x0)));
    
          if (fabs(f(x2)) <= tol)
          { 
            break;
          }
          
          x0 = x1;
          x1 = x2;


        IterationNumber = IterationNumber + 1; 
        myfile << x2 << "\t\t" << f(x2) << "\n" << endl;
	}

	myfile.close();
        cout << "\nNumber of iteration in secant method : "<< IterationNumber << "\n" << endl;	
	return x2;
}

double Regulafalsi(double x0, double x1, double tol, int maxIter)
{
     int IterationNumber = 0;
     double x2;

     ofstream myfile;	
     myfile.open ("Regulafalsi.dat");
	
	do
         {
          x2 = x0 - ((x1 - x0)/(f(x1) - f(x0)))*f(x0);
            if ( f(x2)*f(x0) < 0 )
            {
               x1 = x0;
               x0 = x2;
            }
            else
            {
               x0 = x1;
               x1 = x2;
            }
	IterationNumber = IterationNumber + 1;
        myfile << x2 << "\t\t" << f(x2) << "\n" << endl;
	}
	
	while( (fabs(f(x2)) < tol) && (IterationNumber <= maxIter) );	
        cout << "\nNumber of iteration in regula-falsi method : "<< IterationNumber << "\n" << endl;	
	myfile.close(); 

	return x2;
}
