#pragma once
#include <string>
#include <list>
#include <iostream>

class MCStack
{
	std::list<std::string> stack;

public:
	MCStack();
	~MCStack() { };
	void push(std::string val);
	std::string pop();
	friend std::ostream& operator<< (std::ostream& out, const MCStack& obj);
};
