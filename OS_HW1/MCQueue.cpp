#include "MCQueue.h"

MCQueue::MCQueue() {
	this->queue = std::list<int>();
}

void MCQueue::enqueue(int val)
{
	this->queue.push_back(val);
}

int MCQueue::dequeue()
{
	if (this->queue.empty())
	{
		throw "Dequeue request from empty queue";
	}
	int front = this->queue.front();
	this->queue.pop_front();
	return front;
}

std::ostream& operator<< (std::ostream& out, const MCQueue& obj)
{
	std::list<int>::const_iterator it;
	for (it = obj.queue.begin(); it != obj.queue.end(); ++it) {
		out << std::to_string(*it) + " ";
	}
	return out;
}
