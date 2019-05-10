#include <boost/program_options.hpp>
#include <boost/program_options/errors.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char **argv)
{
	opt::options_description desc("All options");
	desc.add_options()
		("freq,f", opt::value<int>()->default_value(20), "data stream frequency")
		("name", opt::value<std::string>()->default_value("uslam"), "system name")
		("help", "show help message")
	;

	opt::variables_map vm;
	opt::store(opt::parse_command_line(argc, argv, desc), vm);
	opt::notify(vm);

	if (vm.count("help")) {
		std::cout << desc << std::endl;
		return 1;
	}

	try {
		opt::store(opt::parse_config_file<char>("system.cfg", desc), vm);
	} catch (const opt::reading_file &e) {
		std::cout << "Failed to open file 'system.cfg': \n" << e.what();
		return 1;
	}
	opt::notify(vm);

	if (vm.count("name")) {
		std::cout << "configuring " << vm["name"].as<std::string>() << std::endl;
	}

	std::cout << "frequency: " << vm["freq"].as<int>() << std::endl;

	std::cout << "configuration is done !" << std::endl;

	return 0;
}
