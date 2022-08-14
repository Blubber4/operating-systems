#pragma once
#include <string>
#include <list>
#include <iostream>
#include "MCpcb.h"

class MCQueue
{
	std::list<MCpcb> queue;

public:
	MCQueue();
	~MCQueue() { };
	void enqueue(MCpcb val);
	MCpcb dequeue();

	std::list<MCpcb> removeAll(int wait_id);
	bool isEmpty();
	friend std::ostream& operator<< (std::ostream& out, const MCQueue& obj);
};
