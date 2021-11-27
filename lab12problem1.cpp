#include <iostream>
#include <cmath>
using namespace std;

// define structures
struct InputStructure 
{
	double vectorInput[10];
        int vectorLength;
	double matrixInput[10][10];
	int matrixRowLength;
	int matrixColLength;
};

struct OutputStructure 
{
	double vector_norm1, vector_norm2, vector_normInf;
        double matrix_norm1, matrix_norm2, matrix_normInf, matrix_normFro;
};

// define functions

OutputStructure ComputeNorm(struct InputStructure myArrayStruct);

int main()
{
  double x[10], A[10][10];
  int n, nRows, nCols, i, j;
  InputStructure ArrayObject;  
  OutputStructure NormStruct;


  // Let the user input the vector x
  cout << "\nPlease input the size of vector x" << endl;
  cin >> n;
  cout << "\nPlease input the elements of vector x" << endl;
  for(i=0;i<n;i++)
  {
      cin >> x[i]; 
  }

  // Let the user input the matrix A
  cout << "\nPlease input the number of rows for matrix A" << endl;
  cin >> nRows;
  cout << "\nPlease input the number of columns for matrix A" << endl;
  cin >> nCols;
  cout << "\nPlease input elements of matrix A by pressing enter key after each element: " << endl;
  for(i=0; i < nRows; i++)
  {
     cout << "\nRow " << i+1 << "\n";
    	for(j=0; j < nCols; j++)
    	{
      	   cin >> A[i][j];  
    	} 
  }

  // Compute the norms

  for(i=0;i<n;i++)
  {
      ArrayObject.vectorInput[i] = x[i];	
  }

  for(i=0;i<nRows;i++)
  {
	for(j=0; j < nCols; j++)
    	{
      	   ArrayObject.matrixInput[i][j] = A[i][j];	
  	}
   }

  ArrayObject.vectorLength = n;
  ArrayObject.matrixRowLength = nRows;
  ArrayObject.matrixColLength = nCols;

  NormStruct = ComputeNorm(ArrayObject);

  cout << "\nNorms for vector x:" << "\n" << endl;
  cout << "1-norm = " << NormStruct.vector_norm1 << ", " << "2-norm = " << NormStruct.vector_norm2 << ", " << "Inf-norm = " << NormStruct.vector_normInf << "\n" << endl;

  cout << "\nNorms for matrix A:" << "\n" << endl;
  cout << "1-norm = " << NormStruct.matrix_norm1 << ", " << "Inf-norm = " << NormStruct.matrix_normInf << ", " << "Frobenius-norm = " << NormStruct.matrix_normFro << ", " << "2-norm = " << NormStruct.matrix_norm2 <<"\n" << endl;

return 0;

}



// Function to compute the vector and matrix norms
OutputStructure ComputeNorm(struct InputStructure myArrayStruct)
{
	int i, j, k;
	double MaxAbs=fabs(myArrayStruct.vectorInput[0]), temp_sum, SumOfSquares=0.0, ElementwiseSumOfSquares=0.0;	
	double AbsRowSum[myArrayStruct.matrixRowLength], AbsColSum[myArrayStruct.matrixColLength];
	double norm_sq=0.0, lambda_max=0.0, error_sos = 0.0, err_norm, tol=0.00001, lambda_old = 0.0;
	int iter=1, MaxIter=500; 
	double tmp[myArrayStruct.matrixRowLength], dominant_EigenVector[myArrayStruct.matrixRowLength], err[myArrayStruct.matrixRowLength];
	double matrixInput_Transpose[myArrayStruct.matrixColLength][myArrayStruct.matrixRowLength], Vector2Norm;
	double ProductMatrix[myArrayStruct.matrixRowLength][myArrayStruct.matrixRowLength], NewTemp[myArrayStruct.matrixRowLength];
	OutputStructure NormOutput;

	// initialize
	NormOutput.vector_norm1 = 0.0; 
        NormOutput.vector_norm2 = 0.0; 
        NormOutput.vector_normInf = 0.0;
	NormOutput.matrix_norm1 = 0.0; 
        NormOutput.matrix_norm2 = 0.0; 
        NormOutput.matrix_normInf = 0.0;
	NormOutput.matrix_normFro = 0.0; 

	// Compute vector norms
	for(i=0; i < myArrayStruct.vectorLength; i++)
	{
	    NormOutput.vector_norm1 += fabs(myArrayStruct.vectorInput[i]); // vector 1-norm
	
	    SumOfSquares += pow(myArrayStruct.vectorInput[i],2.0);

		if(fabs(myArrayStruct.vectorInput[i]) > MaxAbs)
		{
	    		NormOutput.vector_normInf = fabs(myArrayStruct.vectorInput[i]); // vector infinity-norm
		}
	}
	    NormOutput.vector_norm2 = sqrt(SumOfSquares); // vector 2-norm

	// Compute matrix norms
	//====================================================================
	// matrix 1-norm
	//====================================================================
	for (j=0; j < myArrayStruct.matrixColLength; j++) 	
	{
		for (i=0; i < myArrayStruct.matrixRowLength; i++)
		{
			AbsColSum[j] += fabs(myArrayStruct.matrixInput[i][j]); 
		}
	}

	NormOutput.matrix_norm1 = AbsColSum[0];

	for (j=0; j < myArrayStruct.matrixColLength; j++) 	
	{
		if(AbsColSum[j] > NormOutput.matrix_norm1)
		{
			NormOutput.matrix_norm1 = AbsColSum[j]; 
		}
	}
	//====================================================================
	// matrix infinity-norm
	//====================================================================
	for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
	{
		for (j=0; j < myArrayStruct.matrixColLength; j++)
		{
			AbsRowSum[i] += fabs(myArrayStruct.matrixInput[i][j]); 
		}
	}

	NormOutput.matrix_normInf = AbsRowSum[0];

	for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
	{
		if(AbsRowSum[i] > NormOutput.matrix_normInf)
		{
			NormOutput.matrix_normInf = AbsRowSum[i]; 
		}
	}
	//====================================================================
	// matrix Frobenius-norm
	//====================================================================
	for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
	{
		for (j=0; j < myArrayStruct.matrixColLength; j++)
		{
			ElementwiseSumOfSquares += pow(myArrayStruct.matrixInput[i][j],2.0); 
		}
	}
	
	NormOutput.matrix_normFro = sqrt(ElementwiseSumOfSquares);
	//====================================================================
	// matrix 2-norm
	//====================================================================
	for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
	{
		for (j=0; j < myArrayStruct.matrixColLength; j++)
		{
			matrixInput_Transpose[i][j] = myArrayStruct.matrixInput[j][i]; // compute transpose matrix
		}
	}
	for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
	{
		for (j=0; j < myArrayStruct.matrixColLength; j++)
		{
			ProductMatrix[i][j] = 0.0;
			for (k=0; k < myArrayStruct.matrixRowLength; k++)
			{
				ProductMatrix[i][j] += myArrayStruct.matrixInput[i][k]*matrixInput_Transpose[k][j]; // ProductMatrix = matrix*transpose
			}
		}
	}

	for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
	{
		dominant_EigenVector[i] = 1.0/(sqrt(myArrayStruct.matrixRowLength)); // initial guess for the dominant eigenvector of the ProductMatrix
	}	

	/* Power iteration to estimate maximum absolute eigenvalue for ProductMatrix
	// In theory, matrix 2-norm should be less than Frobenius norm
	// But the following approximation may result slightly larger than Frobenius norm (depends on convergence criteria)
	do{	
		for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
		{
			tmp[i] = 0.0;
			for (j=0; j < myArrayStruct.matrixRowLength; j++)
			{
				tmp[i] += ProductMatrix[i][j]*dominant_EigenVector[j];			
			}
		}	
		for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
		{
			norm_sq += tmp[i]*tmp[i]; 
		}
		Vector2Norm = sqrt(norm_sq);
		for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
		{
			dominant_EigenVector[i] = tmp[i]/Vector2Norm;	// normalized eigenvector
		}
		for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
		{
			for (j=0; j <  myArrayStruct.matrixRowLength; j++)
			{
				lambda_max += dominant_EigenVector[i]*ProductMatrix[i][j]*dominant_EigenVector[j];
			}
		}
		iter = iter + 1;
		if (fabs((lambda_max - lambda_old)/lambda_max) < tol)
		{
			NormOutput.matrix_norm2 = sqrt(lambda_max); // 2-norm of the original matrix
		}			
		lambda_old = lambda_max;
	} while (iter <= MaxIter); */

	
	// Power iteration to estimate maximum absolute eigenvalue for ProductMatrix
	// Different convergence criteria
	do{	
		for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
		{
			tmp[i] = 0.0;
			for (j=0; j < myArrayStruct.matrixRowLength; j++)
			{
				tmp[i] += ProductMatrix[i][j]*dominant_EigenVector[j];			
			}
		}	
		for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
		{
			norm_sq += tmp[i]*tmp[i]; 
		}
		Vector2Norm = sqrt(norm_sq);
		for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
		{
		dominant_EigenVector[i] = tmp[i]/Vector2Norm;	// normalized eigenvector
		}
		for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
		{
			NewTemp[i] = 0.0;
			for (j=0; j < myArrayStruct.matrixRowLength; j++)
			{
				lambda_max += dominant_EigenVector[i]*ProductMatrix[i][j]*dominant_EigenVector[j]; // max. eigenvalue for ProductMatrix
				NewTemp[i] += ProductMatrix[i][j]*dominant_EigenVector[j];			
			}
		}
		for (i=0; i < myArrayStruct.matrixRowLength; i++) 	
		{
			err[i] = lambda_max*dominant_EigenVector[i] - NewTemp[i]; // prediction error		
			error_sos += err[i]*err[i];
		}
		err_norm = sqrt(error_sos);
		iter = iter + 1;
							
	} while ((iter <= MaxIter) && (err_norm < tol)); // convergence criteria*/
	NormOutput.matrix_norm2 = sqrt(lambda_max); // 2-norm of the original matrix
	
	return NormOutput;
}




