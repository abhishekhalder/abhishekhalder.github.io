#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
  double H[40][40];
  int n, i, j, ii, jj;
  double den;

  for(n=2; n<=32; n *= 2)
  {
	ostringstream myfilename;
	myfilename << "Hilbert" << n << ".dat"; // For example, for 2-by-2 Hilbert matrix, filename will be "Hilbert2.dat" etc.

	ofstream file(myfilename.str().c_str());

  	for(i=0.0;i<n;i++)
  	{
		ii = i+1;
    		for(j=0.0;j<n;j++)
    		{
			jj = j+1;
        		den = double (ii + jj - 1);  // type-casting int as double   
        		H[i][j] =  1/den; 
        
        		file << H[i][j] << "\t\t";
    		} 
		file << "\n";
  	}
  }
  

  return 0;

}
