#include "MCStack.h"

MCStack::MCStack()
{
	this->stack = std::list<std::string>();
};

void MCStack::push(std::string val)
{
	this->stack.push_front(val);
}

std::string MCStack::pop()
{
	if (this->stack.empty())
	{
		throw "Pop request from empty stack";
	}
	std::string front = this->stack.front();
	this->stack.pop_front();
	return front;
}

std::ostream& operator<< (std::ostream& out, const MCStack& obj)
{
	std::list<std::string>::const_iterator it;
	for (it = obj.stack.begin(); it != obj.stack.end(); ++it) {
		out << *it + " ";
	}
	return out;
}