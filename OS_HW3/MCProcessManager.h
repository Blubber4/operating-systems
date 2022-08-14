#pragma once
#include <vector>
#include "MCProcess.h"

class MCProcessManager
{
private:
	std::vector<int> available; // V available vector
	std::vector<MCProcess> processes; // contains A allocation and Q request vectors
	std::vector<MCProcess>::const_iterator terminateProcess(std::vector<MCProcess>::const_iterator process);
	void terminateUnallocatedProcesses();
	bool isFulfillable(MCProcess process) const;

public:
	void pushAvailable(int x);
	void pushProcess(MCProcess process);

	/* prints unmarked processes - run checkDeadlockedProcesses() first to ensure marks are up to date */
	void printProcesses();
	bool checkDeadlockedProcesses(); // checks for deadlocked processes, returns true if deadlock exists
};

