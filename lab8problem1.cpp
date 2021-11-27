#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// declare functions
double g1(double x);
double g2(double x);
double g3(double x);
double g4(double x);
double g5(double x);

double Fixedpoint(double x0, double tol, int maxIter);


int main () 
{
  double my_x0, my_tol;
  int my_maxIter;
  ofstream myfile;

  cout << "\nPlease input begin of your initial guess (x0): ";
  cin >> my_x0;
  cout << "\nPlease input your tolerance (epsilon): ";
  cin >> my_tol;
  cout << "\nPlease input the maximum number of iterations: ";
  cin >> my_maxIter;
  cout << "\n\n" << endl;
  
  Fixedpoint(my_x0, my_tol, my_maxIter); // find the root using fixed point method

  return 0;
}

double g1(double x)
{
       double y;       

       y = x-pow(x,3.0)-4*pow(x,2.0)+10.0;

       return y;
}

double g2(double x)
{
       double y;       

       y = sqrt((10.0-(4*pow(x,2)))/x);

       return y;
}

double g3(double x)
{
       double y;       

       y = 0.5*sqrt(10-pow(x,3.0));

       return y;
}

double g4(double x)
{
       double y;       

       y = sqrt(10.0/(x+4.0));

       return y;
}

double g5(double x)
{
       double y;       

       y = x-((pow(x,3.0)+4.0*pow(x,2.0)-10.0)/(3.0*pow(x,2.0)+(8.0*x)));

       return y;
}

// fixedpoint method
// x0 = old value, x1 = new value

double Fixedpoint(double x_old, double tol, int maxIter)
{
	double x1, x0;	
	int IterationNumber = 0;	
        
        ofstream myfile;

      //g1 equation
        x0 = x_old;
        myfile.open ("g1.dat");	

        while(IterationNumber < maxIter)
        {
          
	  x1 = g1(x0);
    
          if (fabs(g1(x1)) < tol)
          { 
            break;
          }
          x0 = x1;
          
        IterationNumber = IterationNumber + 1; 
        myfile << x1 << "\t\t" << g1(x1) << "\n" << endl;
	}

	myfile.close();
        cout << "\nThe root computed from fixedpoint method for equation g1: "<< x1 << "\n" << endl;
        cout << "Number of iteration in Fixedpoint method for equation g1: "<< IterationNumber << "\n" << endl;	


      //g2 equation
        x0 = x_old;
        IterationNumber = 0;	

        myfile.open ("g2.dat");	

        while(IterationNumber < maxIter)
        {
          
	  x1 = g2(x0);
    
          if (fabs(g2(x1)) < tol)
          { 
            break;
          }
          x0 = x1;
          
        IterationNumber = IterationNumber + 1; 
        myfile << x1 << "\t\t" << g2(x1) << "\n" << endl;
	}

	myfile.close();
        cout << "\nThe root computed from fixedpoint method for equation g2: "<< x1 << "\n" << endl;
        cout << "Number of iteration in Fixedpoint method for equation g2: "<< IterationNumber << "\n" << endl;	


      //g3 equation
        x0 = x_old;
        IterationNumber = 0;	

        myfile.open ("g3.dat");	

        while(IterationNumber < maxIter)
        {
          
	  x1 = g3(x0);
    
          if (fabs(g3(x1)) < tol)
          { 
            break;
          }
          x0 = x1;
          
        IterationNumber = IterationNumber + 1; 
        myfile << x1 << "\t\t" << g3(x1) << "\n" << endl;
	}

	myfile.close();
        cout << "\nThe root computed from fixedpoint method for equation g3: "<< x1 << "\n" << endl;
        cout << "Number of iteration in Fixedpoint method for equation g3: "<< IterationNumber << "\n" << endl;	


      //g4 equation
        x0 = x_old;
        IterationNumber = 0;	

        myfile.open ("g4.dat");	

        while(IterationNumber < maxIter)
        {
          
	  x1 = g4(x0);
    
          if (fabs(g4(x1)) < tol)
          { 
            break;
          }
          x0 = x1;
          
        IterationNumber = IterationNumber + 1; 
        myfile << x1 << "\t\t" << g4(x1) << "\n" << endl;
	}

	myfile.close();
        cout << "\nThe root computed from fixedpoint method for equation g4: "<< x1 << "\n" << endl;
        cout << "Number of iteration in Fixedpoint method for equation g4: "<< IterationNumber << "\n" << endl;	


      //g5 equation
        x0 = x_old;
        IterationNumber = 0;	

        myfile.open ("g5.dat");	

        while(IterationNumber < maxIter)
        {
          
	  x1 = g5(x0);
    
          if (fabs(g5(x1)) < tol)
          { 
            break;
          }
          x0 = x1;
          
        IterationNumber = IterationNumber + 1; 
        myfile << x1 << "\t\t" << g5(x1) << "\n" << endl;
	}

	myfile.close();
        cout << "\nThe root computed from fixedpoint method for equation g5: "<< x1 << "\n" << endl;
        cout << "Number of iteration in Fixedpoint method for equation g5: "<< IterationNumber << "\n" << endl;	

	return 0;
}




