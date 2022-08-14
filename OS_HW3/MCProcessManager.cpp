#include "MCProcessManager.h"
#include <iostream>
#include <vector>

void MCProcessManager::pushAvailable(int x)
{
	this->available.push_back(x);
}

void MCProcessManager::pushProcess(MCProcess process)
{
	this->processes.push_back(process);
}

std::vector<MCProcess>::const_iterator MCProcessManager::terminateProcess(std::vector<MCProcess>::const_iterator process)
{
	std::vector<int> allocated = process->getAllocationVector();
	for (int i = 0; i < allocated.size(); i++)
	{
		this->available[i] += allocated[i];
	}
	return this->processes.erase(process);
}

void MCProcessManager::printProcesses()
{
	for (MCProcess process : this->processes)
	{
		std::cout << "P" << process.getID() << ", ";
	}
}

void MCProcessManager::terminateUnallocatedProcesses()
{
	std::vector<MCProcess>::const_iterator it = this->processes.begin();
	while (it != this->processes.cend())
	{
		if (!it->isAllocated())
		{
			it = terminateProcess(it);
		}
		else
		{
			++it;
		}
	}
}

bool MCProcessManager::isFulfillable(MCProcess process) const
{
	std::vector<int> requested = process.getRequestVector();
	for (int i = 0; i < requested.size(); i++)
	{
		if (this->available[i] < requested[i])
		{
			return false;
		}
	}
	return true;
}

bool MCProcessManager::checkDeadlockedProcesses()
{
	terminateUnallocatedProcesses();
	bool flag = true;
	while (this->processes.size() > 0 && flag)
	{
		flag = false;
		std::vector<MCProcess>::const_iterator it = this->processes.begin();
		while (it != this->processes.cend())
		{
			if (isFulfillable(*it))
			{
				it = terminateProcess(it);
				flag = true;
			}
			else
			{
				++it;
			}
		}
	}
	return !flag;
}