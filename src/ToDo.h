/*
 * ToDo.h
 *
 *  Created on: 13.11.2017
 *      Author: gonzo
 */

#ifndef TODO_H_
#define TODO_H_

#include <string>
#include <vector>

class ToDo {
public:
	ToDo();
	~ToDo();

	size_t size() const;

	void addTask(const std::string& task);
	std::string getTask(size_t index) const;

private:
	std::vector<std::string> this_tasks;
};

#endif /* TODO_H_ */
