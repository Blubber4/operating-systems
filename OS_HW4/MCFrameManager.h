#pragma once
#include <vector>
#include <string>
#include <optional>
#include "MCFrame.h"

class MCFrameManager
{
public:
	enum class FrameMode { FIFO, LRU };

private:
	std::vector<MCFrame> frames;
	int num_frames;
	FrameMode mode;
	MCFrame* first_frame;
	int hit_sum;

	std::optional<MCFrame> get(int page);
	void pushFIFO(int page);
	void pushLRU(int page);

public:
	MCFrameManager(FrameMode mode, int num_frames);
	std::optional<int> getFrameContent(int frame_num);
	int getHitSum();
	void update();
	void push(int page);
};

