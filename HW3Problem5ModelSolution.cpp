

/* Gaussian Elimination */
#include <cmath>
#include <iostream>
using namespace std;

double a = 1/sqrt(2);

int main()
{
  int n = 17,i,count,j;
  double m,temp;

  
double A[17][17] = 
{
	-a, 0, 0, 1,  a, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	-a, 0, 1, 0,  a, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0 ,-1, 0, 0, 0 ,1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0 , 0,-1, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, -a, -1, 0, 0, a, 1, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, -a, 0, -1, 0, a, 0, 0, 0, 0, 0, 0, 0, 0,

	0, 0, 0, 0, 0, 0, 0, -1, -a, 0, 0, 1, a, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, -a, 0, 1, 0, a, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 

	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, a, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -a, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -a, -1, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -a, 0, -1, 0, 0,

	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -a, -1 
};


  double f1 = 10;
  double f2 = 15;
  double f3 = 0;
  double f4 = 10;
  
  double b[17] =
  {
	0, 0, 0, -f1, 0, 0, 0, -f2, 0, 0, 0, -f3, 0, 0, 0, -f4, 0
  };

  double x[17] =
  {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };

  /* Gaussian elimination */

  for(i=0;i<(n-1);i++)
  {

	  double max = A[i][i];
	  int maxindex = i;

	  for (int h = i+1; h < n; ++h)
	  {
		  if ( A[h][i] > max )
		  {
			  max = A[h][i];
			  maxindex = h;
		  }
	  }

	  if ( maxindex != i)
	  {
		  double temp;
		  // swap A
		  for ( int q = 0; q < 17; ++q)
		  {
			  temp = A[maxindex][q];
			  A[maxindex][q] = A[i][q];
			  A[i][q] = temp;
		  }
		  // swap B
		  temp = b[maxindex];
		  b[maxindex] = b[i];
		  b[i] = temp;
	  }

    for(j=(i+1);j<n;j++)
    {

		if (A[i][i] == 0)
		{
			int z= i+1;
			for(; z<n; ++z)
			{
				if ( A[z][i] != 0)
				{
					// swap
					double temp = 0;
					for (int q = 0; q < 17; ++q)
					{
						temp = A[i][q];
						A[i][q] = A[z][q];
						A[z][q] = temp;
					}

					temp = b[i];
					b[i] = b[z];
					b[z] = temp;
					break;
				}
			}
			if ( z== n) {
				printf("ERROR\n");
				while(1) ;
			}
		}
       m = A[j][i] / A[i][i];

	   
	   if ( A[i][i] == 0)
	   {
		   printf("the dividor 0 at (%d %d) so m == %f\n", i, i, m);
		   while(1) ;
	   }
	   

       for(count=i;count<n;count++) 
       {
         A[j][count] -= (m * A[i][count]);
       }
        b[j] -= (m * b[i]);
    }
   }

  cout << "\nMatrix after the forward elimination: " << endl;
  for (i=0;i<=n-1;i++)
  {
    for(j=0;j<n;j++)
    {
     cout << A[i][j]<< "  ";
        
    }
        cout<<"\n\n";
  }

  /* Back substitution */

  //if (A[n-1][n-1] != 0)
	x[n-1] = b[n-1] / A[n-1][n-1];

  for(i=(n-2);i>=0;i--)
  {
    temp = b[i];
    for(j=(i+1);j<n;j++)
    {
      temp -= (A[i][j] * x[j]);
    }
	
	//if ( A[i][i] != 0)
      x[i] = temp / A[i][i];
  }

  cout << "\nSolution x is: " << endl;
  for(i=0;i<n;i++)
  {
	  printf("f(%d) : %f\n", i+1, x[i]);
    //cout << x[i];
    //cout<<"\n";
  }

  while(1) ;
}
