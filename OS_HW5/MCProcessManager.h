#pragma once
#include <vector>
#include <optional>
#include "MCProcess.h"

class MCProcessManager
{
private:
	enum class ProcessManagerMode
	{
		ROUND_ROBIN, SHORTEST_REMAINING
	};

	std::vector<MCProcess> ready_queue; // "live" process queue for use during simulation
	std::vector<MCProcess> unmanaged_processes; // contains all processes that will be simulated
	std::vector<MCProcess> finished_processes; // finished process container - for stats after simulation
	std::optional<MCProcess> running_process;
	int quantum; // -1 when mode does not require it - nullopt maybe better?
	ProcessManagerMode mode;
	int time;

	void update();

	// rr intended
	void updateRR();
	void changeRunningProcess();

	// srt intended
	void updateSRT();
	void swapRunningProcess(MCProcess process);
	int getFastestProcessPosition(); // returns position of fastest process: -1 if fastest process is currently running

	// generic
	bool isRunnableProcess();
	void updateReadyQueue(); // for use during simulation, pushes processes to ready queue at correct time.
	void finishRunningProcess();
	

public:
	MCProcessManager(int quantum)
		: ready_queue(std::vector<MCProcess>())
		, unmanaged_processes(std::vector<MCProcess>())
		, finished_processes(std::vector<MCProcess>())
		, running_process(std::nullopt)
		, quantum(quantum)
		, mode(ProcessManagerMode::ROUND_ROBIN)
		, time(0)
	{ }

	MCProcessManager()
		: ready_queue(std::vector<MCProcess>())
		, unmanaged_processes(std::vector<MCProcess>())
		, finished_processes(std::vector<MCProcess>())
		, running_process(std::nullopt)
		, quantum(-1)
		, mode(ProcessManagerMode::SHORTEST_REMAINING)
		, time(0)
	{ }

	void push(MCProcess process); // for initial storage of processes for future simulation
	void start();
	void printStatistics();
};

