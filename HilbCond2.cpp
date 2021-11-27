#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// declare functions
double MatrixNorm2(double M[40][40],int n);
double factorial(int n);
double BinomialCoefficient(int n, int k);

int main()
{
  double H[40][40], invH[40][40], HilbNorm2, invHilbNorm2, cond2[10];
  int n, i, j, k, ii, jj;
  double den, Term;

  ofstream myfile;

  myfile.open ("HilbertCond2.dat");

  for(k=0; k<=5; k++)
  {
	n = pow(2,k);
	// Hilbert matrix
  	for(i=0.0;i<n;i++)
  	{
		ii = i+1;
    		for(j=0.0;j<n;j++)
    		{
			jj = j+1;
        		den = double (ii + jj - 1);  // type-casting int as double   
        		H[i][j] =  1/den; 
    		} 
  	}
	// Inverse Hilbert matrix
  	for(i=0.0;i<n;i++)
  	{
		ii = i+1;
    		for(j=0.0;j<n;j++)
    		{
			jj = j+1;
        		Term = double ((pow(-1, ii+jj))*(ii + jj - 1)); // type-casting int as double  
        		invH[i][j] = Term*(BinomialCoefficient(n+ii-1, n-jj))*(BinomialCoefficient(n+jj-1, n-ii))*(pow(BinomialCoefficient(ii+jj-2, ii-1), 2.0)); 
    		} 
  	}
	// Compute 2-norms
	HilbNorm2 = MatrixNorm2(H,n);
	invHilbNorm2 = MatrixNorm2(invH,n);
	// Condition number
	cond2[k] = HilbNorm2*invHilbNorm2;

	myfile << k << "\t\t" << cond2[k] << "\n" << endl;
  }


  return 0;

}


//Function to compute 2-norm of a matrix M of size n-by-n//
double MatrixNorm2(double M[40][40],int n)
{
	int i, j, k, iter = 1, MaxIter = 500;
	double M_Transpose[40][40], ProductMatrix[40][40], dominant_EigenVector[40], tmp[40], NewTemp[40], err[40];
	double norm_sq = 0.0, Vector2Norm, lambda_max = 0.0, error_sos = 0.0, err_norm, tol = 0.0001, norm2;
	
	for (i=0; i < n; i++) 	
	{
		for (j=0; j < n; j++)
		{
			M_Transpose[i][j] = M[j][i]; // compute transpose matrix
		}
	}
	for (i=0; i < n; i++) 	
	{
		for (j=0; j < n; j++)
		{
			ProductMatrix[i][j] = 0.0;
			for (k=0; k < n; k++)
			{
				ProductMatrix[i][j] += M[i][k]*M_Transpose[k][j]; // ProductMatrix = matrix*transpose
			}
		}
	}

	for (i=0; i < n; i++) 	
	{
		dominant_EigenVector[i] = 1.0/(sqrt(n)); // initial guess for the dominant eigenvector of the ProductMatrix
	}

	// Power iteration to estimate maximum absolute eigenvalue for ProductMatrix
	do{	
		for (i=0; i < n; i++) 	
		{
			tmp[i] = 0.0;
			for (j=0; j < n; j++)
			{
				tmp[i] += ProductMatrix[i][j]*dominant_EigenVector[j];			
			}
		}	
		for (i=0; i < n; i++) 	
		{
			norm_sq += tmp[i]*tmp[i]; 
		}
		Vector2Norm = sqrt(norm_sq);
		for (i=0; i < n; i++) 	
		{
			dominant_EigenVector[i] = tmp[i]/Vector2Norm;	// normalized eigenvector
		}
		for (i=0; i < n; i++) 	
		{
			NewTemp[i] = 0.0;
			for (j=0; j < n; j++)
			{
				lambda_max += dominant_EigenVector[i]*ProductMatrix[i][j]*dominant_EigenVector[j]; // max. eigenvalue for ProductMatrix
				NewTemp[i] += ProductMatrix[i][j]*dominant_EigenVector[j];			
			}
		}
		for (i=0; i < n; i++) 	
		{
			err[i] = lambda_max*dominant_EigenVector[i] - NewTemp[i]; // prediction error		
			error_sos += err[i]*err[i];
		}
		err_norm = sqrt(error_sos);
		iter = iter + 1;
							
	} while ((iter <= MaxIter) && (err_norm < tol)); // convergence criteria
	
	norm2 = sqrt(lambda_max); // 2-norm of the original matrix
	
	return norm2;
	
}


double factorial(int n) // recursive factorial
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


double BinomialCoefficient(int n, int k) // compute n choose k
{
	return factorial(n)/(factorial(k)*factorial(n-k));
}





