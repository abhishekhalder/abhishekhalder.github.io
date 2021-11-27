#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
  double A[10][10], b[10], x[10], Diag[10][10], InvDiag[10][10], OffDiag[10][10];
  double ProdVec[10], JacobiIterVector[10], JacobiIterMatrix[10][10], b_Predicted[10];
  double rel_err, tol = pow((double) 10.0, -4.0), SquareError = 0.0, OneNormError = 0.0, InfNormError = 0.0, b_TwoNormSquare = 0.0, b_oneNorm = 0.0, b_infNorm = 0.0;
  int n, i, j, k, iter = 1, MaxIter = 500;

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

  cout << "\nPlease input elements of vector b: " << endl;
  for(i=0;i<n;i++)
  {
	cin >> b[i];
  }
  cout << "\nPlease enter your initial guess for solution vector x: " << endl;
  for(i=0;i<n;i++)
  {
	cin >> x[i];
  }
	
  // Offline construction of JacobiMatrix
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
	if(i==j){
      	Diag[i][j] = A[i][j];
	InvDiag[i][j] = 1/(A[i][j]);
	}
	else{
	Diag[i][j] = 0; 
	InvDiag[i][j] = 0;
	}   
    } 
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      OffDiag[i][j] = A[i][j] - Diag[i][j]; 
 
   } 
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
	JacobiIterMatrix[i][j] = 0;
 	for(k=0; k<n; k++)  
	{   
 	 JacobiIterMatrix[i][j] += -InvDiag[i][k]*OffDiag[k][j]; 
	}   
     } 
  } 

  // Offline construction of JacobiVector
  for(i=0;i<n;i++)
  {
    JacobiIterVector[i] = b[i]/Diag[i][i];	
  } 

 ofstream myfile;

 myfile.open ("JacobiInfnorm.dat"); // Set filename according to the norm used in relative error

do{

  for(i=0;i<n;i++)
  {	
    ProdVec[i] = 0;
    for(j=0;j<n;j++)
    {
     ProdVec[i] += JacobiIterMatrix[i][j]*x[j];
   } 
  }	

  for(i=0;i<n;i++)
  {	
	x[i] = ProdVec[i] + JacobiIterVector[i]; // predict the solution vector
   }	
  // calculate error
  for(i=0;i<n;i++)
  {	
    b_Predicted[i] = 0;
    for(j=0;j<n;j++)
    {
     b_Predicted[i] += A[i][j]*x[j]; 
   } 
  }
  for(i=0;i<n;i++)
  {	
	SquareError += pow(b_Predicted[i] - b[i], 2.0); // square of 2-norm of the error vector
        OneNormError += fabs(b_Predicted[i] - b[i]); // 1-norm of the error vector 
	InfNormError = fabs(b_Predicted[0] - b[0]);
		if (fabs(b_Predicted[i] - b[i]) > InfNormError)
		{
			InfNormError = fabs(b_Predicted[i] - b[i]); // infinity-norm of the error vector
		}
        
        b_TwoNormSquare += pow(b[i], 2.0); // 2-norm of vector b
	b_oneNorm += fabs(b[i]); // 1-norm of vector b
	b_infNorm = fabs(b[0]);
		if (fabs(b[i]) > b_infNorm)
		{
			b_infNorm = fabs(b[i]); // infinity-norm of vector b
		}
   }
  //rel_err = sqrt(SquareError/b_TwoNormSquare); // relative error (in 2-norm)
  //rel_err = OneNormError/b_oneNorm; // relative error (in 1-norm)
  rel_err = InfNormError/b_infNorm; // relative error (in infinity-norm)

  myfile << iter << "\t\t" << rel_err << "\n" << endl; // write current iteration number and relative error in file 

  iter = iter + 1;

 } while ((rel_err > tol) && (iter <= MaxIter));

myfile.close();

cout << "\n\n" << "x1 = " << x[0] << ", x2 = " << x[1] << ", x3 = " << x[2] << endl; 

return 0;

}



