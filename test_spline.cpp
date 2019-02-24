#include<iostream>
#include<Eigen/Dense>
#include<vector>

using namespace Eigen;
using namespace std;

class Spline {
private:
  vector<double> as_;
  vector<double> bs_;
  vector<double> xs_;

public:
  Spline(const vector<double> as = vector<double> (),
	 const vector<double> bs = vector<double> (),
	 const vector<double> xs = vector<double> ()):
    as_(as), bs_(bs), xs_(xs) {}
  
  double get_value(const double x) const {
    if (x <= 0.0 || x >= 1.0) {
      return bs_[0];
    }
    for (size_t i = 0; i<4; i++) {
      if ( x >= xs_[i] && x <= xs_[i+1] )
	return bs_[i] + as_[i] * ( x - xs_[i] );;
    }
  }  
};

int main(int argc, char *argv[]) {
  vector<double> xs { 0. , 0.16, 0.42, 0.6425, 0.8575 };
  vector<double> ys {100., 183., 235., 40.   , 15.    };
  MatrixXd deltX(4,4);
  VectorXd deltY(4);

  for (size_t i=0; i<4; i++) {
    deltX(i,i) = xs[i+1] - xs[i];
    deltY(i) = ys[i+1] - ys[i];
  }
  VectorXd as_ = deltX.colPivHouseholderQr().solve(deltY);
  cout << "as_ :" << endl << as_ <<endl;
  vector<double> as {as_[0], as_[1], as_[2], as_[3]};
  
  Spline spline1(as, ys, xs);
  
  for (double x = 0.0 ; x <= 1.0 ; x += 0.1) {
    std::cout << "Value for " << x << " is " << spline1.get_value(x) << std::endl;
  }
}
