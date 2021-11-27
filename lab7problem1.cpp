#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// declare functions
double f(double x);
double Df(double x);
double D2f(double x);

double Newton(double a, double tol, int maxIter);
double QHalley(double a, double tol, int maxIter);

int main () 
{
  double my_a, my_tol, my_root_newton, my_root_halley;
  int my_maxIter;
  ofstream myfile;

  cout << "\nPlease input begin of your initial guess (a): ";
  cin >> my_a;
  cout << "\nPlease input your tolerance (epsilon): ";
  cin >> my_tol;
  cout << "\nPlease input the maximum number of iterations: ";
  cin >> my_maxIter;
  cout << "\n\n" << endl;
  
  my_root_newton = Newton(my_a, my_tol, my_maxIter); // find the root using newton method
  cout << "\nThe root computed from Newton method is: "<< my_root_newton << "\n" << endl;

  my_root_halley = QHalley(my_a, my_tol, my_maxIter); // find the root using halley method
  cout << "\nThe root computed from Halley method is: "<< my_root_halley << "\n" << endl;

  return 0;
}

double f(double x)
{
       double y;       

       y = (x*x*x) + (4*x*x) - 10.0;

       return y;
}

double Df(double x)
{
       double y;       

       y = (3.0*x*x) + (8.0*x);

       return y;
}

double D2f(double x)
{
       double y;       

       y = (6.0*x) + 8.0;

       return y;
}

//Newton method
// x0 = old value, x1 = new value

double Newton(double x0, double tol, int maxIter)
{
	double x1, e;	
	int IterationNumber = 0;	

        ofstream myfile;	
        myfile.open ("Newton.dat");	

        while(IterationNumber <= maxIter)
        {
          
	  x1 = x0 - (f(x0) / Df(x0));
    
          if (fabs(f(x1)) < tol)
          { 
            break;
          }
          e = fabs(x1-x0);  
          x0 = x1;
          
        IterationNumber = IterationNumber + 1; 
        myfile << x1 << "\t\t" << f(x1) << "\t\t"<< e << "\t\t"<< log(e) <<"\n" << endl;
	}

	myfile.close();
        cout << "\nNumber of iteration in Newton method : "<< IterationNumber << "\n" << endl;	
	return x1;
}



//Halley method

double QHalley(double x0, double tol, int maxIter)
{
	double x1, e;	
	int IterationNumber = 0;	

        ofstream myfile;	
        myfile.open ("QHalley.dat");	

        while(IterationNumber <= maxIter)
        {
          
	  x1 = x0 - ((2*f(x0)*Df(x0)) / (2*(pow(Df(x0),2.0)) - f(x0)*D2f(x0)));
    
          if (fabs(f(x1)) < tol)
          { 
            break;
          }
          e = fabs(x1-x0);  
          x0 = x1;
          
        IterationNumber = IterationNumber + 1; 
        myfile << x1 << "\t\t" << f(x1) << "\t\t"<< e << "\t\t"<< log(e) <<"\n" << endl;
	}

	myfile.close();
        cout << "\nNumber of iteration in Halley method : "<< IterationNumber << "\n" << endl;	
	return x1;
}
