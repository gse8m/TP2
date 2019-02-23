// Copyright [2019] <SUN Hao, LIU Bohua, ZHAO Hairen>
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      elec4_util.h
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

#pragma once

#include<vector>

#define N 5

namespace ELEC4 {

class Spline {
 private:
  std::vector<double> as_;
  std::vector<double> bs_;
  std::vector<double> xs_;

 public:
   Spline(const std::vector<double> as = std::vector<double> (),
          const std::vector<double> bs = std::vector<double> (),
          const std::vector<double> xs = std::vector<double> ()):
     as_(as), bs_(bs), xs_(xs) {}

   double get_value(const double x) const {
    if (x <= 0.0 || x >= 1.0) {
      return bs_[0];
    }

    for (std::size_t i = 0; i < N; i++) {
      if ( x >= xs_[i] && x < xs_[i+1] )
        return bs_[i] + as_[i] * ( x - xs_[i] );
    }
  }
};

}  // namespace ELEC4
