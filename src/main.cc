#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <string>
using std::string;

#include <boost/program_options.hpp>
namespace po = boost::program_options;
#include <boost/version.hpp>

#include "ToDo/includes/ToDo.h"

int main (int argc, char** argv) {
	ToDo list;

	po::options_description desc("Options");
	desc.add_options()
		("help,h", "display this help")
		("add,a", po::value<string>(), "add a new entry to the To Do list");

	bool parseError = false;
	po::variables_map vm;

	try {
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);
	} catch (po::error& error) {
		cerr << "Error: " << error.what() << "\n" << endl;
		parseError = true;
	}

	if(parseError || vm.count("help")) {
		cout << "todo: A simple To Do list program" << "\n";
		cout										<< "\n";
		cout << "Usage:"							<< "\n";
		cout << "  "  << argv[0] << " [options]"	<< "\n";
		cout										<< "\n";
		cout << desc								<< "\n";
		cout										<< "\n";
		cout << "Boost Version: " << BOOST_LIB_VERSION << "\n";

		if(parseError) {
			return 64;
		} else {
			return 0;
		}
	}

	cout << "Hello World!" << endl;

	list.addTask("write code");
	list.addTask("compile");
	list.addTask("test");

	cout << "Tasks:" << "\n";
	cout << "Tasks 1: " << list.getTask(size_t(0)) << "\n";
	cout << "Tasks 2: " << list.getTask(size_t(1)) << "\n";
	cout << "Tasks 3: " << list.getTask(size_t(2)) << "\n";

	if(vm.count("add")) {
		list.addTask(vm["add"].as<string>());
	}

	for (size_t i=0; i<list.size(); i++) {
		cout << list.getTask(i) << "\n";
	}


	return 0;
}
