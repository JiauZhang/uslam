#include "common.hpp"

namespace uslam {

void do_check_(int num, int limit, CHECK_TYPE check_type, std::string &log)
{
	bool res = false;
	switch (check_type) {
		case CHECK_TYPE_EQ:
			if (num != limit)
				res = true;
			break; 
		case CHECK_TYPE_NE:
			if (num == limit)
				res = true;
			break; 
		case CHECK_TYPE_GT:
			if (num <= limit)
				res = true;
			break; 
		case CHECK_TYPE_GE:
			if (num < limit)
				res = true;
			break; 
		case CHECK_TYPE_LT:
			if (num >= limit)
				res = true;
			break; 
		case CHECK_TYPE_LE:
			if (num > limit)
				res = true;
			break;		
	}
	
	try {
		if (res)
			throw num;
	} catch (int e_) {
		std::cout << "CHECK failed ! CHECK_TYPE: " << check_type << std::endl;
		std::cout << log << std::endl;
		exit(1);
	}
}

void CHECK_LE(int num, int limit, std::string log)
{
	do_check_(num, limit, CHECK_TYPE_LE, log);
}	

void CHECK_EQ(int num, int limit, std::string log)
{
	do_check_(num, limit, CHECK_TYPE_EQ, log);
}

void CHECK_NE(int num, int limit, std::string log)
{
	do_check_(num, limit, CHECK_TYPE_NE, log);
}

void CHECK_LT(int num, int limit, std::string log)
{
	do_check_(num, limit, CHECK_TYPE_LT, log);
}

void CHECK_GT(int num, int limit, std::string log)
{
	do_check_(num, limit, CHECK_TYPE_GT, log);
}

void CHECK_GE(int num, int limit, std::string log)
{
	do_check_(num, limit, CHECK_TYPE_GE, log);
}

void CHECK_PTR(void *ptr, std::string log)
{
	if (ptr == NULL)
		do_check_(0, 0, CHECK_TYPE_NE, log);
}
	
} // namespace uslam