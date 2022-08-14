#pragma once
#include <string>
#include <optional>

class MCProcess
{
	std::string process_name;
	int arrival_time;
	int service_time;
	// holds running count of time slices for current time quantum, when
	// slice_time == quantum, time slice is up
	int slice_time;
	// holds total number of time steps currently run, when == to
	// service_time process is done
	int total_time;
	// holds time when process finishes, used to calculate final stats,
	// like T_r, T_r/T_s
	std::optional<int> finish_time;

public:
	MCProcess()
		: process_name("uninitialized process")
		, arrival_time(-1)
		, service_time(-1)
		, slice_time(-1)
		, total_time(-1)
		, finish_time(std::nullopt)
	{ }

	MCProcess(std::string process_name, int arrival_time, int service_time)
		: process_name(process_name)
		, arrival_time(arrival_time)
		, service_time(service_time)
		, slice_time(0)
		, total_time(0)
		, finish_time(std::nullopt)
	{ }

	friend bool operator< (const MCProcess& p1, const MCProcess& p2);

	std::string getName() { return process_name; }
	int getArrivaltime() { return arrival_time;  }
	int getServiceTime() { return service_time;  }
	int getSliceTime() { return slice_time; }
	int getTotalTime() { return total_time; }
	int getRemainingTime() { return service_time - total_time; }
	std::optional<int> getFinishtime() { return finish_time; }
	void update();
	void suspend();
	void finish(int time);
	bool isFinished();
};

