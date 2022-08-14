#include "MCpcb.h"
#include <iomanip>

void MCpcb::setProcessState(ProcessState state)
{
	this->process_state = state;
	this->timeslice = 0;
}

int MCpcb::getID() const
{
	return this->id;
}

int MCpcb::getWaitID() const
{
	return this->wait_id;
}

int MCpcb::getExecutedTime()
{
	return this->timeslice;
}

void MCpcb::start()
{
	this->timeslice = 0;
	setProcessState(ProcessState::RUNNING);
}

std::string MCpcb::getStringState() const
{
	switch (this->process_state)
	{
	case ProcessState::BLOCKED:
		return "BLOCKED";
		break;

	case ProcessState::NEW:
		return "NEW";
		break;

	case ProcessState::READY:
		return "READY";
		break;

	case ProcessState::RUNNING:
		return "RUNNING";
		break;

	default:
		return "???";
		break;
	}
}

void MCpcb::setWaitID(int id)
{
	this->wait_id = id;
}

void MCpcb::block(int id)
{
	this->wait_id = id;
	this->process_state = ProcessState::BLOCKED;
}

void MCpcb::unblock()
{
	this->wait_id = -1;
	this->process_state = ProcessState::READY;
}

void MCpcb::run()
{
	this->timeslice++;
}

std::ostream& operator<< (std::ostream& out, const MCpcb& obj)
{
	out << std::setw(12) << std::right << "pid=" + std::to_string(obj.getID()) + ",";
	out << std::setw(16) << std::left << " state=" + obj.getStringState() + ", ";
	out << std::setw(10) << std::left << "start=" + std::to_string(obj.start_time) + ",";
	out << std::setw(9) << std::left << " slice=" + std::to_string(obj.timeslice) + ",";
	if (obj.wait_id > 0)
	{
		out << std::setw(15) << std::left << " event=" + std::to_string(obj.wait_id);
	}
	return out;
}