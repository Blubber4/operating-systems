#pragma once
#include "MCQueue.h"
#include <optional>
#include <map>

class ProcessManager
{
	MCQueue ready_process_queue;
	MCQueue blocked_process_queue;
	std::optional<MCpcb> running_process;
	int time;
	int timeslice;
	int next_process_id; // would need a smarter way of doing ids for extremely large numbers of processes (exceeding int size)

public:
	ProcessManager(int timeslice = 1);
	enum class Command
	{
		CPU, NEW, DONE, WAIT, EVENT, EXIT
	};
	void update(Command command); // tick one process timestep
	void update(Command command, int arg);

private:
	void run();
	void createNewProcess();
	void nextProcessToRunning();
	void readyRunningProcess();
	void readyNewProcess(MCpcb process);
	void blockRunningProcess(int wait_id);
	void killRunningProcess();

	void readyProcess(MCpcb process);
	void eventTrigger(int id);
	void printState();

	bool isRunningProcess();
	bool timeout();
};

