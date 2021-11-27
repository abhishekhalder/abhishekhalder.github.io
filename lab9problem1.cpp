#include <iostream>
#include <cmath>
using namespace std;

#define pi 3.14159
     
int main () 
{
  int i, j, k=0;
  int ii, jj, dim = 3;
  double Vector_LocalFrame[dim], Vector_InertialFrame[dim], Vector_LocalFrame_AfterCoversion[dim], RotAngle[dim];
  double R21[dim][dim], R321[dim][dim], R321Tran[dim][dim];
  double R1[3][3], R2[3][3], R3[3][3];	
  double Deg2Rad = pi/180;

  cout << "\nConverting from local (i,j,k) frame to inertial (n,e,d) frame" << "\n" << endl;

  cout << "\nPlease input the local (aircraft-fixed) coordinate vector (i, j, k)" << endl;

  for (ii = 0; ii < dim; ii++)
      { 	
	cin >> Vector_LocalFrame[ii]; 
      }

  cout << "\nNow input the rotation angles (phi, theta, psi) in degrees" << endl;

  for (jj = 0; jj < dim; jj++)
      { 	
	cin >> RotAngle[jj]; 
      }

  //Rotation matrix for rotation (roll) about x axis (axis 1)
  R1[0][0] = 1;
  R1[0][1] = 0;
  R1[0][2] = 0;	
  R1[1][0] = 0;
  R1[1][1] = cos(RotAngle[0]*Deg2Rad);
  R1[1][2] = -sin(RotAngle[0]*Deg2Rad);
  R1[2][0] = 0;
  R1[2][1] = sin(RotAngle[0]*Deg2Rad);
  R1[2][2] = cos(RotAngle[0]*Deg2Rad);
 
  //Rotation matrix for rotation (pitch) about y axis (axis 2)
  R2[0][0] = cos(RotAngle[1]*Deg2Rad);
  R2[0][1] = 0;
  R2[0][2] = sin(RotAngle[1]*Deg2Rad);	
  R2[1][0] = 0;
  R2[1][1] = 1;
  R2[1][2] = 0;
  R2[2][0] = -sin(RotAngle[1]*Deg2Rad);
  R2[2][1] = 0;
  R2[2][2] = cos(RotAngle[1]*Deg2Rad);

  //Rotation matrix for rotation (yaw) about z axis (axis 3)
  R3[0][0] = cos(RotAngle[2]*Deg2Rad);
  R3[0][1] = -sin(RotAngle[2]*Deg2Rad);
  R3[0][2] = 0;	
  R3[1][0] = sin(RotAngle[2]*Deg2Rad);
  R3[1][1] = cos(RotAngle[2]*Deg2Rad);
  R3[1][2] = 0;
  R3[2][0] = 0;
  R3[2][1] = 0;
  R3[2][2] = 1;	        
 
  for(i=0;i< dim;i++)
  {
    for(j=0;j< dim;j++)
    {
      R21[i][j] = 0;
      for(k=0;k< dim;k++)
      {
        R21[i][j] = R21[i][j] + R2[i][k] * R1[k][j];
      }
   } 
  } 

  for(i=0;i< dim;i++)
  {
   for(j=0;j< dim;j++)
   {
     R321[i][j] = 0;
     for(k=0;k< dim;k++)
     {
       R321[i][j] = R321[i][j] + R3[i][k] * R21[k][j];
     }
   } 
  }

  for(i=0;i< dim;i++)
  {
     Vector_InertialFrame[i] = 0;
   for(k=0;k< dim;k++)
   {
     Vector_InertialFrame[i] = Vector_InertialFrame[i] + R321[i][k] * Vector_LocalFrame[k];
   }
  }
        
  // display the inertial ned vector
  cout << "\nThe inertial (Earth-fixed) coordinate vector (n, e, d): " << "\n" << endl;

  for (i=0; i<dim; i++)
  {
    std::cout << Vector_InertialFrame[i] << "  ";
    std::cout<<"\n \n";
  } 

  for(i=0;i< dim;i++)
  {
   for(j=0;j< dim;j++)
   {
       R321Tran[j][i] = R321[i][j];
   }
  }
 
  for(i=0;i< dim;i++)
  {
   Vector_LocalFrame_AfterCoversion[i] = 0;
   for(k=0;k< dim;k++)
   {
     Vector_LocalFrame_AfterCoversion[i] =  Vector_LocalFrame_AfterCoversion[i] + R321Tran[i][k] * Vector_InertialFrame[k];
   }
  }
        
  // display the local (aircraft-fixed) coordinate vector, after converting back
  cout << "\nConverting from local (n,e,d) frame back to inertial (i,j,k) frame: " << "\n" << endl;

  for (i=0; i<dim; i++)
  {
    std::cout << Vector_LocalFrame_AfterCoversion[i] <<"  ";
    std::cout<<"\n \n";
  }

  return 0;
	
}







