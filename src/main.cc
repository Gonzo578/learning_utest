#include <iostream>
using std::cout;
using std::endl;

#include "ToDo.h"

int main (int, char**) {
	ToDo list;

	cout << "Hello World!" << endl;

	list.addTask("write code");
	list.addTask("compile");
	list.addTask("test");

	cout << "Tasks:" << "\n";
	cout << "Tasks 1: " << list.getTask(size_t(0)) << "\n";
	cout << "Tasks 2: " << list.getTask(size_t(1)) << "\n";
	cout << "Tasks 3: " << list.getTask(size_t(2)) << "\n";

	return 0;
}
