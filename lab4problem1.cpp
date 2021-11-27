#include <iostream>
#include <cmath>

using namespace std;

int main () 
{
  double a_bar, b_bar, c_bar, sigma_a, sigma_b, sigma_c, sigma_peri;
  double del_cos_gamma_del_a, del_cos_gamma_del_b, del_cos_gamma_del_c, sigma_cos_gamma;

  cout << "\nPlease enter the average measurements for sides a, b, c: " << endl; 
	
  cout << "\na_bar = ";
  cin >> a_bar;

  cout << "\nb_bar = ";
  cin >> b_bar;

  cout << "\nc_bar = ";
  cin >> c_bar;


  cout << "\nPlease enter the individual standard deviations for measuring sides a, b, c: " << endl; 
	
  cout << "\nsigma_a = ";
  cin >> sigma_a;

  cout << "\nsigma_b = ";
  cin >> sigma_b;

  cout << "\nsigma_c = ";
  cin >> sigma_c;

  sigma_peri = sqrt( pow(sigma_a,2) + pow(sigma_b,2) + pow(sigma_c,2) ); // since perimeter = a + b + c

  cout << "\nThe standard deviation in computing the perimeter is: " << sigma_peri << "\n" << endl;
 
  del_cos_gamma_del_a = (pow(a_bar,2) - pow(b_bar,2) + pow(c_bar,2))/(2*pow(a_bar,2)*b_bar);
  del_cos_gamma_del_b = (pow(c_bar,2) - pow(a_bar,2) + pow(b_bar,2))/(2*pow(b_bar,2)*a_bar);
  del_cos_gamma_del_c = -c_bar/(a_bar*b_bar);

  sigma_cos_gamma = sqrt( pow(del_cos_gamma_del_a,2)*pow(sigma_a,2) + pow(del_cos_gamma_del_b,2)*pow(sigma_b,2) + pow(del_cos_gamma_del_c,2)*pow(sigma_c,2) );
  		
   cout << "\nThe standard deviation in computing the cosine of the angle opposite to c is: " << sigma_cos_gamma << "\n" << endl;

  return 0;
}
