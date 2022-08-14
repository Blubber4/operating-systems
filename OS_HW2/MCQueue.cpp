#include "MCQueue.h"

MCQueue::MCQueue() {
	this->queue = std::list<MCpcb>();
}

void MCQueue::enqueue(MCpcb val)
{
	this->queue.push_back(val);
}

MCpcb MCQueue::dequeue()
{
	if (this->queue.empty())
	{
		throw "Dequeue request from empty queue";
	}
	MCpcb front = this->queue.front();
	this->queue.pop_front();
	return front;
}

/* removes from queue all processec with arg id, returns std::list of removed processes */
std::list<MCpcb> MCQueue::removeAll(int id)
{
	std::list<MCpcb> processes;
	std::list<MCpcb>::const_iterator it = this->queue.begin();
	while (it != this->queue.cend())
	{
		if (it->getWaitID() == id)
		{
			processes.push_back(*it);
			it = this->queue.erase(it);
		}
		else
		{
			++it;
		}
	}
	return processes;
}

bool MCQueue::isEmpty()
{
	return this->queue.empty();
}

std::ostream& operator<< (std::ostream& out, const MCQueue& obj)
{
	std::list<MCpcb>::const_iterator it;
	for (it = obj.queue.begin(); it != obj.queue.end(); ++it)
	{
		out << *it << '\n';
	}
	if (obj.queue.empty())
	{
		out << "      EMPTY" << std::endl;
	}
	return out;
}
