#include "MCProcess.h"
#include <iostream>

bool operator< (const MCProcess& p1, const MCProcess& p2)
{
	return p1.arrival_time < p2.arrival_time;
}

void MCProcess::update()
{
	this->slice_time++;
	this->total_time++;
	std::cout << this->process_name << ' ';
}

void MCProcess::suspend()
{
	this->slice_time = 0;
}

void MCProcess::finish(int time)
{
	this->finish_time = time;
}

bool MCProcess::isFinished()
{
	if (finish_time == std::nullopt)
	{
		return false;
	}
	return true;
}