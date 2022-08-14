#include "MCProcessManager.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void MCProcessManager::update()
{
	if (this->mode == ProcessManagerMode::ROUND_ROBIN)
	{
		updateRR();
	}
	if (this->mode == ProcessManagerMode::SHORTEST_REMAINING)
	{
		updateSRT();
	}
}

/////////////////
void MCProcessManager::updateRR()
{
	updateReadyQueue();
	std::optional<MCProcess> process = this->running_process;
	if (process == std::nullopt)
	{
		if (this->ready_queue.empty())
		{
			return;
		}
		changeRunningProcess();
	}
	else if (process->getTotalTime() >= process->getServiceTime())
	{
		finishRunningProcess();
		changeRunningProcess();
	}
	else if (process->getSliceTime() >= this->quantum)
	{
		this->running_process->suspend();
		changeRunningProcess();
	}

	if (this->running_process != std::nullopt)
	{
		this->running_process->update();
	}
	this->time++;
}

void MCProcessManager::changeRunningProcess()
{
	if (this->running_process != std::nullopt)
	{
		this->running_process->suspend();
		this->ready_queue.push_back(*this->running_process);
	}
	if (this->ready_queue.empty())
	{
		return;
	}
	this->running_process = ready_queue.front(); // a queue might make more sense than vector bc of this but its fine
	ready_queue.erase(ready_queue.begin());
}

/////////////////
void MCProcessManager::updateSRT()
{
	updateReadyQueue();
	std::optional<MCProcess> process = this->running_process;
	if (process == std::nullopt)
	{
		if (this->ready_queue.empty())
		{
			return;
		}
		int pos = getFastestProcessPosition();
		swapRunningProcess(ready_queue[pos]);
	}
	else if (process->getTotalTime() >= process->getServiceTime())
	{
		finishRunningProcess();
		int pos = getFastestProcessPosition();
		if (pos != -1)
		{
			swapRunningProcess(ready_queue[pos]);
		}
	}
	else if (this->getFastestProcessPosition() != -1)
	{
		int pos = getFastestProcessPosition();
		swapRunningProcess(ready_queue[pos]);
	}

	if (this->running_process != std::nullopt)
	{
		this->running_process->update();
	}
	this->time++;
}

void MCProcessManager::swapRunningProcess(MCProcess process)
{
	for (int i = 0; i < ready_queue.size(); i++)
	{
		if (ready_queue[i].getName() == process.getName())
		{
			if (this->running_process == std::nullopt)
			{
				this->running_process = process;
				ready_queue.erase(ready_queue.begin()+i);
				return;
			}
			MCProcess temp = ready_queue[i];
			ready_queue[i] = this->running_process.value();
			this->running_process = temp;
			return;
		}
	}
}

int MCProcessManager::getFastestProcessPosition()
{
	int pos = -1;
	int shortest_time = 99999999; // would need to make this infinity if larger numbers being used
	if (running_process != std::nullopt)
	{
		shortest_time = running_process->getRemainingTime();
	}
	else if (ready_queue.size() > 0)
	{
		shortest_time = ready_queue[0].getRemainingTime();
		pos = 0;
	}

	for (int i = 0; i < ready_queue.size(); i++)
	{
		if (ready_queue[i].getRemainingTime() < shortest_time)
		{
			shortest_time = ready_queue[i].getRemainingTime();
			pos = i;
		}
	}
	return pos;
}

/////////////////
// returns true if there is any process being run, or any process that has not finished in the ready queue.
bool MCProcessManager::isRunnableProcess()
{
	if (this->running_process != std::nullopt)
	{
		return true;
	}
	for (MCProcess process : this->ready_queue)
	{
		if (!process.isFinished())
		{
			return true;
		}
	}
	return false;
}

// for use during simulation - pushes processes at the time designated by their arrival time
void MCProcessManager::updateReadyQueue()
{
	for (int i = 0; i < unmanaged_processes.size(); i++)
	{
		if (unmanaged_processes[i].getArrivaltime() == time)
		{
			ready_queue.push_back(unmanaged_processes[i]);
		}
	}
}

void MCProcessManager::finishRunningProcess()
{
	if (this->running_process == std::nullopt)
	{
		return;
	}
	this->running_process->finish(time);
	this->finished_processes.push_back(this->running_process.value());
	this->running_process = std::nullopt;
}

void MCProcessManager::push(MCProcess process)
{
	this->unmanaged_processes.push_back(process);
}

void MCProcessManager::start()
{
	do {
		update();
	}
	while (isRunnableProcess());
}

void MCProcessManager::printStatistics()
{
	// < operator overloaded to sort by arrival time
	std::sort(this->finished_processes.begin(), this->finished_processes.end());

	// header
	std::cout << std::endl << std::setfill(' ') << std::left << std::setfill(' ')
			  << std::setw(5) << "Name" << std::right << std::setw(4) << "Fnsh"
			  << std::setw(4) << "T_r" << std::setw(9) << "T_r/T_s" << std::endl;
	std::cout << std::setfill('-') << std::setw(22) << '-' << std::endl;

	for (MCProcess process : this->finished_processes)
	{
		std::string name = process.getName();
		int fnsh = process.getFinishtime().value();
		int t_r = process.getFinishtime().value() - process.getArrivaltime();
		double ratio = (double) t_r / (double) process.getServiceTime();

		std::cout << std::setfill(' ') << std::left << std::setprecision(6)
			      << std::setw(5) << name << std::right << std::setw(4) << fnsh
				  << std::setw(4) << t_r << std::setw(9) << ratio << std::endl;
	}
}