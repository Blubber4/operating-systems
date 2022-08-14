#pragma once
#include <string>
#include <list>
#include <iostream>

class MCQueue
{
	std::list<int> queue;

public:
	MCQueue();
	~MCQueue() { };
	void enqueue(int val);
	int dequeue();
	friend std::ostream& operator<< (std::ostream& out, const MCQueue& obj);
};
