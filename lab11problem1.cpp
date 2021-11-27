#include <iostream>
#include <cmath>
using namespace std;

void lu(double A[10][10], double L[10][10], double U[10][10], int n);
void PrintMatrix(double x[10][10],int n);

int main()
{
  double A[10][10], L[10][10], U[10][10];
  double detL = 1;
  int n, i, j;

  /* Let the user input the matrix A */
  cout << "\nPlease input the size of matrix A" << endl;
  cin >> n;

  cout << "\nPlease input elements of matrix A by pressing enter key after each element: " << endl;

  for(i=0;i<n;i++)
  {
	cout << "\nRow " << i+1 << "\n";

    for(j=0;j<n;j++)
    {
      cin >> A[i][j]; 
    
   } 
  }

  cout << "\nMatrix A is: " << endl;
  PrintMatrix(A,n);
	
  //Perform LU decomposition//
  lu(A,L,U,n); 
  	
  cout << "\nMatrix L is: " << endl;
  PrintMatrix(L,n);
  cout << "\nMatrix U is: " << endl;
  PrintMatrix(U,n);

//Compute determinant
for(i=0; i<n; i++)
{
	detL *= L[i][i]; 
}

cout << "\ndet(A) = det(LU) = det(L) = " << detL << "\n" << endl;

return 0;

}

//Function to perform LU decomposition using Crout's method (see http://en.wikipedia.org/wiki/Crout_matrix_decomposition)
void lu(double A[10][10], double L[10][10], double U[10][10], int n)
{
	int i=0,j=0,k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j<i)
				L[j][i]=0;
			else
			{
				L[j][i]=A[j][i];
				for(k=0;k<i;k++)
				{
					L[j][i]=L[j][i]-L[j][k]*U[k][i];
				}
			}			
		}
		for(j=0;j<n;j++)
		{
			if(j<i)
				U[i][j]=0;
			else if(j==i)
				U[i][j]=1;
			else
			{
				U[i][j]=A[i][j]/L[i][i];
				for(k=0;k<i;k++)
				{
					U[i][j]=U[i][j]-((L[i][k]*U[k][j])/L[i][i]);	
				}
			}
		}
	}		
}

//Function to print a matrix//
void PrintMatrix(double x[10][10],int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout << x[i][j] << " ";
		}
		cout << "\n";
	}
}


