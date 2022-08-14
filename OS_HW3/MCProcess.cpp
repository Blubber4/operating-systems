#include "MCProcess.h"

const std::vector<int> MCProcess::getAllocationVector() const
{
	return this->allocated;
}

const std::vector<int> MCProcess::getRequestVector() const
{
	return this->requested;
}

const int MCProcess::getID() const
{
	return this->id;
}

void MCProcess::mark()
{
	this->flag = true;
}

const bool MCProcess::isMarked() const
{
	return this->flag;
}

const bool MCProcess::isAllocated() const
{
	for (int res : this->allocated)
	{
		if (res != 0)
		{
			return true;
		}
	}
	return false;
}