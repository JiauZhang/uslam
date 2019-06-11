#ifndef __IO_H__
#define __IO_H__

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

namespace uslam {
	
void read_parameter_from_file(const std::string &file_name, 
							  std::map<std::string, std::map<std::string, std::string>> &parameters);

} // namespace uslam

#endif