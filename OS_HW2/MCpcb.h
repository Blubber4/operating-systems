#pragma once
#include <string>
#include <iostream>

class MCpcb
{
public:
	enum class ProcessState
	{
		NEW,
		RUNNING,
		READY,
		BLOCKED,
	};

private:
	int id;
	int start_time;
	int alloted_timeslice;
	int timeslice; // time steps executed in this time slice
	int wait_id;
	ProcessState process_state;

public:
	MCpcb(int id, int start_time, int timeslice)
		: id(id)
		, start_time(start_time)
		, alloted_timeslice(timeslice)
		, timeslice(0)
		, wait_id(-1)
		, process_state(ProcessState::NEW)
	{ }
	void setProcessState(ProcessState state);
	void setWaitID(int id);
	void block(int id);
	void unblock();
	int getID() const;
	int getWaitID() const;
	int getExecutedTime();
	void start();
	std::string getStringState() const;

	void run();
	friend std::ostream& operator<< (std::ostream& out, const MCpcb& obj);
};

