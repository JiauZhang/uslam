#include "io.hpp"

namespace uslam {

bool char_is_legal(char &c)
{
	// A-Z || a-z || _ || 0-9
	if ((c >= 0x40 && c <= 0x5A) || \
		(c >= 0x61 && c <= 0x7A) || \
		(c == 0x5F) || \
		(c >= 0x30 && c <= 0x39)) {
		return true;	
	}
	
	return false;
}

bool delete_leading_spaces_(std::string &s)
{
	unsigned int index;
	index = 0;
	
	while (s.size() > index && s[index] == ' ') {
		index += 1;
	}
	
	s.erase(0, index);
	
	if (char_is_legal(s[0]) || s[0] == '[')
		return true;
	
	return false;
}

bool read_object_(std::string &s, std::string &object_)
{
	std::cout << "object: " << s << std::endl;
	
	object_ += s[0];
	unsigned int index_ = 1;

	while (index_ < s.size() && char_is_legal(s[index_])) {
		object_ += s[index_];
		index_++;
	}
	
	try {
		if (s[index_] != ']')
			throw s;
		else
			object_ += s[index_];
	} catch (std::string &str_) {
		std::cout << "error syntax: " << s << std::endl;
		exit(1);
	}
	
	return true;
}

bool read_parameter_(std::string &s, std::string &object_, std::map<std::string, std::map<std::string, std::string>> &parameters)
{
	if (s[0] == '[')
		return true;

	std::cout << "parameter: " << s << std::endl;
	
	std::string key_;
	std::string value_;
	
	unsigned int index_ = 0;
	while (index_ < s.size() && s[index_] != ' ' && s[index_] != '=') {
		key_ += s[index_];
		index_++;
	}
	
	while (index_ < s.size() && s[index_] == ' ') {
		index_++;
	}
	
	try {
		if (s[index_] != '=') {
			//std::cout << s[index_] << std::endl;
			throw s;
		} else {
			index_++;
			while (index_ < s.size() && s[index_] == ' ') {
				index_++;
			}
		}
	} catch (std::string &str) {
		std::cout << "error syntax:\n" << str << std::endl;
		exit(1);
	}
	
	while (index_ < s.size() && s[index_] != ' ' && s[index_] != 13) {
		value_ += s[index_];
		index_++;
	}
	
	std::map<std::string, std::string> &key_value = parameters[object_];
	key_value[key_] = value_;
	
	return false;
}
	
void read_parameter_from_file(const std::string &file_name, std::map<std::string, std::map<std::string, std::string>> &parameters)
{
	std::ifstream in(file_name);
	std::string s;
	
	bool has_object, has_param;
	std::string object_;
	
	while (std::getline(in, s)) {
		has_object = false;
		has_param = delete_leading_spaces_(s);
		
		// skip blank line, Enter == 13
		if (s[0] == 13)
			continue;
		
		// skip comment
		if (s[0] == '#')
			continue;
		
		has_param = delete_leading_spaces_(s);
		if (has_param) {
			has_object = read_parameter_(s, object_, parameters);
		}
		if (has_object) {
			object_.clear();
			read_object_(s, object_);
		}
	}
}	
	
}