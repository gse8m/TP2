// Copyright [2019] <SUN Hao, LIU Bohua, ZHAO Hairen>
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      test_spline.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \author    SUN, LIU, ZHAO
//
// \copyright Copyright ng2goodies 2015
//            Distributed under the MIT License
//            See http://opensource.org/licenses/MIT
//
//////////////////////////////////////////////////////////////////////////////////
// header-end
//


// C++ version
// Compilation with g++ 5.3.0 & g++ 6.3.0
// mingwin: g++ -std=c++14 -O3 -o mean_and_median mean_and_median.cpp

// Compilation with g++ 4.9.3
// cygwin:  g++ -D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_DYNAMIC -std=c++14 -O3 ...

// Other tool chain
// msvc:    ok!
// clang:   ok!

#include<iostream>
#include<Eigen/Dense>
#include<vector>
#include"elec4_util.h"

#define N 5

int main(int argc, char *argv[]) {
  std::vector<double> xs { 0. , 0.16, 0.42, 0.6425, 0.8575, 1};
  std::vector<double> ys {100., 183., 235., 40.   , 15.   , 100};

  Eigen::MatrixXd deltX(N, N);
  Eigen::VectorXd deltY(N);

  for (std::size_t i = 0; i < N; i++) {
    deltX(i, i) = xs[i+1] - xs[i];
    deltY(i) = ys[i+1] - ys[i];
  }
  Eigen::VectorXd as_ = deltX.colPivHouseholderQr().solve(deltY);
  std::cout << "as_ :" << std::endl << as_ << std::endl << std::endl;

  std::vector<double> as {as_[0], as_[1], as_[2], as_[3], as_[4]};
  ELEC4::Spline spline_r(as, ys, xs);
  for (double x = 0.0 ; x <= 1.0 ; x += 0.1) {
    std::cout << "Value for " << x << " is " << spline_r.get_value(x);
    std::cout << std::endl;
  }
}
