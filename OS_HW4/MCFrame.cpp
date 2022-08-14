#include "MCFrame.h"

std::optional<int> MCFrame::getPage()
{
	return this->page;
}

int MCFrame::getTimeSinceUsed()
{
	if (this->page == std::nullopt)
		return -1;
	return this->time_since_used;
}

void MCFrame::swapPage(int page)
{
	this->page = page;
	use();
}

void MCFrame::use()
{
	this->time_since_used = 0;
}

void MCFrame::update()
{
	this->time_since_used++;
}