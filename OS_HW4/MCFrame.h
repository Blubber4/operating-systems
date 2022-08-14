#pragma once
#include <optional>
class MCFrame
{
	std::optional<int> page;
	int time_since_used;

public:
	MCFrame()
		: page(std::nullopt)
		, time_since_used(0)
	{ }
	std::optional<int> getPage();
	int getTimeSinceUsed();
	void swapPage(int page);
	void use();
	void update();
};

