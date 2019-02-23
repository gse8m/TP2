#include<iostream>
#include<Eigen/Dense>
#include<vector>

using namespace Eigen;
using namespace std;

class Spling {
private:
  vector<doule> as_;
  vector<double> bs_;
  vector<double> xs_;
public:
  Spline(vector<double> as, vector<double> bs, vector<double> xs) {
    xs_ = xs;
    bs_ = bs;
    for (size_t i = 1 ; i < xs_.size()-1 ; ++i) {
      as_[i] = ( bs_[i+1] - bs_[i] ) / ( xs_[i+1] - xs_[i] ); 
  }
  
  }

  double get_value(const double x) const {
    if (x <= 0.0 || x >= 1.0) {
      return bs_[0];
    }
    for (size_t i = 1)
  }


};

int main(int argc, char *argv[]) {
 vector<double> xs{ 0., 0.16, 0.42, 0.6425, 0.8575};
 vector<double> ys{100., 183. , 235. , 40. , 15. };
 Spline spline1...
 for (double x = 0.0 ; x <= 1.0 ; x += 0.1) {
 std::cout << "Value for " << x << " is " << spline1.get_value(x) << std::endl;
 }
}
