#include<iostream>
#include <cmath>

using namespace std;

// declare functions
float factorial(int n);
float nthDerivative(int n, float a);



int main()
{
	int nTerms = 4;
	float x = 2.5;
	float a = 2;
	float TaylorSum = 0;
        float jthTerm, TrueFuncValue, AbsError, RelError; 


	for ( int j = 1; j <= nTerms; j++ )
    	{
            jthTerm = nthDerivative(j-1,a)*pow(x-a,j-1)/factorial(j-1);
	    
	    TaylorSum = TaylorSum + jthTerm; // same as TaylorSum += jthTerm
    	}
	
	TrueFuncValue = 1/x;

	AbsError = fabs(TrueFuncValue - TaylorSum);
	RelError = fabs((TrueFuncValue - TaylorSum)/TrueFuncValue);

	cout<<"\n True value of f(x) is " << TrueFuncValue << "\n" << endl;
	
	cout<<"\n Taylor series approximation of f(x)=1/x exapnded about a = "<< a << ", evaluated at x = " << x << ", is " << TaylorSum << "\n" << endl;

	cout<< "Absolute error = " << AbsError << "\n" << endl;
	cout<< "Relative error = " << RelError << "\n" << endl;



	return 0;
}



float factorial(int n) // recursive factorial
{
	if(n<=1)
	{
		return 1; // takes care of negatives, zero and unity	
	}
	else
	{
		return n*factorial(n-1);
	}
}


/*
float factorial(int n) // iterative factorial
{
    float fact = 1; // initialize

    for ( int i = 1; i <= n; i++ )
    {
        fact = fact * i; // same as fact*=i
    }

    return fact;
}
*/



float nthDerivative(int n, float a)
{
	float ans;	

	ans = pow(-1,n)*factorial(n)*pow(a,-n-1); // n-th derivative of 1/x evaluated at x=a
	return ans;
}



