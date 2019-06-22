#ifndef __CHECK_H__
#define __CHECK_H__

namespace uslam {

enum CHECK_TYPE {
	CHECK_TYPE_EQ,
	CHECK_TYPE_NE,
	CHECK_TYPE_GT,
	CHECK_TYPE_GE,
	CHECK_TYPE_LT,
	CHECK_TYPE_LE
};

void do_check_(int num, int limit, CHECK_TYPE check_type, std::string &log);	

void CHECK_LE(int num, int limit, std::string log);
void CHECK_EQ(int num, int limit, std::string log);
void CHECK_NE(int num, int limit, std::string log);
void CHECK_LT(int num, int limit, std::string log);
void CHECK_GT(int num, int limit, std::string log);
void CHECK_GE(int num, int limit, std::string log);

void CHECK_PTR(void *ptr, std::string log);
	
} // namespace uslam

#endif