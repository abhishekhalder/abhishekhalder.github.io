
/* Gaussian Elimination */
#include <cmath>
#include <iostream>
using namespace std;

main()
{
  double A[3][3],b[3],x[3];
  int n =3,i,count,j;
  double m,temp;

  /* Read in A and b */
  cout << "\nPlease input the size of matrix A" << endl;
  cin >> n;

  cout << "\nPlease input elements of matrix A by pressing enter key after each element (along each row): " << endl;

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      cin >> A[i][j]; 
    
   } 
  }

  cout << "\nPlease input vector b: " << endl;
  for(i=0;i<n;i++)
  {
    cin >> b[i]; 
  }

  cout << "\nMatrix A is: " << endl;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      cout << A[i][j] << "  ";

    }
    cout<<"\n";
  }

  cout << "\nVector b is: " << endl;
  for(i=0;i<n;i++)
  {
    cout << b[i];
    cout<<"\n";
  }

  /* Gaussian elimination */

  for(i=0;i<(n-1);i++)
  {
    for(j=(i+1);j<n;j++)
    {
       m = A[j][i] / A[i][i];

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

  x[n-1] = b[n-1] / A[n-1][n-1];
  for(i=(n-2);i>=0;i--)
  {
    temp = b[i];
    for(j=(i+1);j<n;j++)
    {
      temp -= (A[i][j] * x[j]);
    }
      x[i] = temp / A[i][i];
  }

  cout << "\nSolution x is: " << endl;
  for(i=0;i<n;i++)
  {
    cout << x[i];
    cout<<"\n";
  }
}

