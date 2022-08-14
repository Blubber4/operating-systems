#include "ProcessManager.h"
#include <iostream>

ProcessManager::ProcessManager(int timeslice)
{
	this->ready_process_queue = MCQueue();
	this->blocked_process_queue = MCQueue();
	this->running_process = std::nullopt;
	this->time = 1;
	this->timeslice = timeslice;
	this->next_process_id = 1;
}
/*
	I spent like 5 hours trying to figure out why this was giving wrong answers.
	Time has to update --after-- every CPU instruction is run, --start from T=1--, and the start time
	of a process is decided --at the time that its created--
	Any other variation of those 3 combinations except that exact one will give wrong answers.
*/
void ProcessManager::update(Command command)
{	
	switch (command)
	{
	case Command::CPU:
		if (!isRunningProcess())
		{
			nextProcessToRunning();
		}
		run();
		printState();
		this->time++;
		break;

	case Command::DONE:
		if (isRunningProcess())
		{
			killRunningProcess();
		}
		break;

	case Command::NEW:
		createNewProcess();
		break;

	default: // UNKNOWN COMMAND - ERROR
		break;
	}
	
}

void ProcessManager::update(Command command, int arg)
{
	switch (command)
	{
	case Command::WAIT:
		if (isRunningProcess())
		{
			blockRunningProcess(arg);
		}
		break;

	case Command::EVENT:
		eventTrigger(arg);
		break;

	default: // UNKNOWN COMMAND - ERROR
		break;
	}
}

void ProcessManager::run()
{
	if (timeout())
	{
		readyRunningProcess();
		nextProcessToRunning();
	}
	if (isRunningProcess())
	{
		running_process->run();
	}
	
}

void ProcessManager::createNewProcess()
{
	MCpcb process = MCpcb(this->next_process_id, this->time, this->timeslice);
	next_process_id++;
	readyNewProcess(process);
}

void ProcessManager::readyNewProcess(MCpcb process)
{
	process.setProcessState(MCpcb::ProcessState::READY);
	this->ready_process_queue.enqueue(process);
}

void ProcessManager::nextProcessToRunning()
{
	try {
		MCpcb process = ready_process_queue.dequeue();
		process.start();
		running_process = std::make_optional(process);
	}
	catch (const char* msg)
	{
		std::cout << msg << std::endl;
	}
}

void ProcessManager::readyRunningProcess()
{
	if (isRunningProcess())
	{
		running_process->setProcessState(MCpcb::ProcessState::READY);
		ready_process_queue.enqueue(*running_process);
		running_process = std::nullopt;
	}
}

void ProcessManager::blockRunningProcess(int wait_id)
{
	if (isRunningProcess())
	{
		running_process->block(wait_id);
		blocked_process_queue.enqueue(*running_process);
		running_process = std::nullopt;
	}
}

void ProcessManager::killRunningProcess()
{
	running_process = std::nullopt;
}

// helper function for readying blocked processes on eventTrigger()
void ProcessManager::readyProcess(MCpcb process)
{
	process.setProcessState(MCpcb::ProcessState::READY);
	this->ready_process_queue.enqueue(process);
}

void ProcessManager::eventTrigger(int id)
{
	std::list<MCpcb> processes = this->blocked_process_queue.removeAll(id);
	std::list<MCpcb>::iterator it;
	for (it = processes.begin(); it != processes.end(); ++it)
	{
		it->unblock();
		this->ready_process_queue.enqueue(*it);
	}
}

void ProcessManager::printState()
{
	std::cout << "Time: " << this->time << std::endl;
	std::cout << "   CPU (currently running):" << std::endl;
	if (isRunningProcess())
	{
		MCpcb process = *this->running_process;
		std::cout << process << std::endl;
		//std::cout << "      pid=", process->getID(), ", state=", process->getStringState(),
					 //", start=1, slice=", process->getExecutedTime(), ",";
	}
	else
	{
		std::cout << "      IDLE" << std::endl;
	}

	std::cout << "   Ready Queue:" << std::endl;
	std::cout << this->ready_process_queue;

	std::cout << "   Blocked Queue:" << std::endl;
	std::cout << this->blocked_process_queue << std::endl;
}

bool ProcessManager::isRunningProcess()
{
	if (this->running_process == std::nullopt)
	{
		return false;
	}
	return true;
}

bool ProcessManager::timeout()
{
	if (this->running_process->getExecutedTime() == 0) return false;
	return !(this->running_process->getExecutedTime() % timeslice);
}