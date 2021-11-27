#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// declare functions
void InterpPoly(int n, double x[50], double y[50], int nInterp);
void InterpSpline(int n, double x[50], double y[50], int nInterp, int DegreeOfSpline);

int main () 
{
  int n, nInterp, i;
  double x[50], y[50];

  cout << "\nPlease input the data size n" << endl;
  cin >> n;
  cout << "\nPlease input the interpolant size nInterp" << endl;
  cin >> nInterp;

  ifstream InputFile;
  InputFile.open("HW6problem2cData.dat"); // you can also do .txt

  for(i=0;i<n;i++)
     {
	InputFile >> x[i] >> y[i]; // read data from file
     } 
  
  InputFile.close();

  InterpPoly(n, x, y, nInterp); // single polynomial interpolation
  InterpSpline(n, x, y, nInterp, 1); // linear spline interplation
  InterpSpline(n, x, y, nInterp, 3); // cubic spline interplation 

  return 0;
}


void InterpPoly(int n, double x[50], double y[50], int nInterp)
{
	int i, j, k;
	double xInterp[nInterp], yInterp[nInterp], dx, l[n], den, LagrangeSum;
        
	ofstream myfile;
	myfile.open ("InterpPoly.dat");
  
  	den = double (nInterp - 1); //type-casting
  	dx = (x[n-1] - x[0])/den;

	for(k=0;k<nInterp;k++)
  	{
     		xInterp[k] = x[0] + (double (k))*dx;     // new grid over which the interpolant is to be evaluated
  	}

  	//Polynomial interpolation using Lagrange basis functions
  	for(k=0; k<nInterp; k++)
	{
		LagrangeSum = 0.0; //initialize
		for(i=0; i<n; i++)
		{
			l[i] = 1; //initialize
			for(j=0;j<n;j++)
			{		
				if(j != i)
				{				
					l[i] *= (xInterp[k] - x[j])/(x[i] - x[j]); // the i-th Lagrange basis function
				}
			}
			LagrangeSum += l[i]*y[i];
		}	
		yInterp[k] = LagrangeSum;
		myfile << xInterp[k] << "\t\t" << yInterp[k] << "\n" << endl;
	}
  	myfile.close();
}
	
void InterpSpline(int n, double x[50], double y[50], int nInterp, int DegreeOfSpline)
{
	int i, j, k;
	double xInterp[nInterp], yInterp[nInterp], dx, den, slope;
	double a[n], b[n-1], d[n-1], c[n], h[n-1], alpha[n-1], l[n], mu[n], z[n];

  	den = double (nInterp - 1); //type-casting
  	dx = (x[n-1] - x[0])/den;

	for(k=0;k<nInterp;k++)
  	{
     		xInterp[k] = x[0] + (double (k))*dx;     // new grid over which the interpolant is to be evaluated
  	}
        
	if (DegreeOfSpline == 1)	
	{
		ofstream SpLinfile;
		SpLinfile.open ("InterpSplineLinear.dat");
  
  		// Linear spline interpolation
  		for(k=0; k<nInterp; k++)
		{
			for (i=0; i < (n-1); i++)
			  {   			
				if ((x[i] <= xInterp[k]) && (xInterp[k] <= x[i+1]))
				{
					slope = (y[i+1] - y[i])/(x[i+1] - x[i]);
					yInterp[k] = y[i] + slope*(xInterp[k] - x[i]);
				}
			  } 	
			SpLinfile << xInterp[k] << "\t\t" << yInterp[k] << "\n" << endl;
		}
  		SpLinfile.close();
	}

	if (DegreeOfSpline == 3)	
	{
		ofstream SpCubicfile;
		SpCubicfile.open ("InterpSplineCubic.dat");
  
  		// Cubic spline interpolation (natural spline algorithm:
               // http://en.wikipedia.org/w/index.php?title=Spline_%28mathematics%29&oldid=288288033#Algorithm_for_computing_natural_cubic_splines)
		for (i=0; i < n; i++)
		{ 
			a[i] = y[i];
		}
		for (i=0; i < (n-1); i++)
		{
			h[i] = x[i+1] - x[i];
			
			alpha[i] = ((3/h[i])*(a[i+1] - a[i])) - ((3/h[i-1])*(a[i] - a[i-1]));
		}
		l[0] = 1;
		mu[0] = 0;
		z[0] = 0;
		for (i=1; i < (n-1); i++)
		{
			l[i] = 2*(x[i+1] - x[i-1]) - h[i-1]*mu[i-1];		
			mu[i] = h[i]/l[i];
			z[i] = (alpha[i] - h[i-1]*z[i-1])/l[i];
		}
		l[n-1] = 1;
		z[n-1] = 0;
		c[n-1] = 0;
		for (j=n-2; j >= 0; --j)
		{
			c[j] = z[j] - mu[j]*c[j+1];
			b[j] = ((a[j+1] - a[j])/h[j]) - ((h[j]/3)*(c[j+1] + 2*c[j]));
			d[j] = (c[j+1] - c[j])/(3*h[j]);			
		}
		// Now evaluate
  		for(k=0; k<nInterp; k++)
		{
			for (i=0; i < (n-1); i++)
			  {   			
				if ((x[i] <= xInterp[k]) && (xInterp[k] <= x[i+1]))
				{
				yInterp[k] = a[i] + b[i]*(xInterp[k] - x[i]) + c[i]*pow((xInterp[k] - x[i]),2.0) + d[i]*pow((xInterp[k] - x[i]),3.0);
				}
			  } 	
			SpCubicfile << xInterp[k] << "\t\t" << yInterp[k] << "\n" << endl;
		}
  		SpCubicfile.close();
	}



}	



