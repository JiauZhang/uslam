#include "io.hpp"

class TestParameter {
public:
	TestParameter(): test_a(-1), test_b(-1) {}
	int test_a ;
	int test_b;
	std::string type;
};

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./test_io file_name" << std::endl;
		return -1;
	}
	
	const std::string file_name(argv[1]);

	std::map<std::string, std::map<std::string, std::string>> parameters;

	uslam::read_parameter_from_file(file_name, parameters);
	
	std::cout << "main output:\n";
	for(auto it_begin = parameters.begin(); it_begin != parameters.end(); it_begin++) {
		std::map<std::string, std::string> &parameter = it_begin->second;
		std::cout << it_begin->first;
		std::cout << " size: " << it_begin->first.size() << std::endl;
		for (auto it_=parameter.begin(); it_!=parameter.end(); it_++) {
			std::cout << "key: " << it_->first; 
			std::cout << " size: " << it_->first.size();
			std::cout << "---value: " << it_->second;
			std::cout << " size: " << it_->second.size() << std::endl;
		}
	}
	
	TestParameter test;
	
	if (parameters.count("[test]")) {
		std::cout << "has test class parameter" << std::endl;
		std::map<std::string, std::string> &test_parameter = parameters["[test]"];
		if (test_parameter.count("test_a") == 1) {
			test.test_a = std::stoi(test_parameter["test_a"]);
			std::cout << "has test_a value" << std::endl;
		}
		
		if (test_parameter.count("test_b")) {
			test.test_b = std::stoi(test_parameter["test_b"]);
			std::cout << "has test_b value" << std::endl;
		}
		
		if (test_parameter.count("type")) {
			test.type = test_parameter["type"];
			std::cout << "has type value" << std::endl;
		}
		
		std::cout << "initial parameter from file\n";
		std::cout << "test_a = " << test.test_a \
				  << " test_b = " << test.test_b \
				  << " type = " << test.type << std::endl;
	}
	
	return 0;
}