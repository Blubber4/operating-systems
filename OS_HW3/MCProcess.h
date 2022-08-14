#pragma once
#include <vector>

class MCProcess
{ 
private:
	int id;
	bool flag; // marker for use by process manager
	std::vector<int> allocated; // A allocation vector
	std::vector<int> requested; // Q request vector

public:
	MCProcess(int id, std::vector<int> allocated, std::vector<int> requested)
		: id(id)
		, allocated(allocated)
		, requested(requested)
		, flag(false)
	{ }
	const std::vector<int> getAllocationVector() const;
	const std::vector<int> getRequestVector() const;
	const int getID() const;

	void mark();

	const bool isMarked() const;
	const bool isAllocated() const;
};

