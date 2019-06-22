#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <map>
#include <memory> // std::shared_ptr

#include "check.hpp"

#define INSTANTIATE_CLASS(classname) \
  template class classname<float>; \
  template class classname<double>; \
  template class classname<int>

namespace uslam {
	
using std::vector;
using std::string;
using std::map;
using std::shared_ptr;
	
}; // namespace uslam

#endif