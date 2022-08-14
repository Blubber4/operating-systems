#include "MCFrameManager.h"
#include <iostream>

MCFrameManager::MCFrameManager(FrameMode mode, int num_frames)
{
	this->mode = mode;
	this->frames = std::vector<MCFrame>();
	this->num_frames = num_frames;

	for (int i = 0; i < num_frames; i++)
	{
		this->frames.push_back(MCFrame());
	}
	this->first_frame = &(this->frames[0]);
}

std::optional<MCFrame> MCFrameManager::get(int page)
{
	for (int i = 0; i < this->num_frames; i++)
	{
		if (frames[i].getPage() == page)
			return frames[i];
	}
	return std::nullopt;
}

void MCFrameManager::pushFIFO(int page)
{
	for (int i = 0; i < this->num_frames; i++)
	{
		MCFrame frame = this->frames[i];
		if (frame.getPage() == this->first_frame->getPage())
		{
			this->frames[i].swapPage(page);
			if (i+1 == this->num_frames)
			{
				this->first_frame = &(frames[0]);
				return;
			}
			(this->first_frame)++;
			return;
		}
	}
}

void MCFrameManager::pushLRU(int page)
{
	MCFrame* max_time_frame = &(this->frames[0]);
	int max_time = max_time_frame->getTimeSinceUsed(); // inf
	for (int i = 0; i < this->num_frames; i++)
	{
		MCFrame frame = this->frames[i];
		if (max_time < frame.getTimeSinceUsed())
		{
			max_time = frame.getTimeSinceUsed();
			max_time_frame = &this->frames[i];
		}
	}
	max_time_frame->swapPage(page);
}

std::optional<int> MCFrameManager::getFrameContent(int frame_num)
{
	return this->frames[frame_num].getPage();
}

int MCFrameManager::getHitSum()
{
	return this->hit_sum;
}

void MCFrameManager::update()
{
	for (int i = 0; i < num_frames; i++)
	{
		this->frames[i].update();
	}
}

void MCFrameManager::push(int page)
{
	update();
	// push immediately if any frames are empty or page is already in memory
	for (int i = 0; i < this->num_frames; i++)
	{
		MCFrame frame = this->frames[i];
		if (frame.getPage() == std::nullopt)
		{
			this->frames[i].swapPage(page);
			return;
		}
		if (frame.getPage() == page)
		{
			if (this->mode == FrameMode::LRU)
			{
				this->frames[i].use();
			}
			this->hit_sum++;
			return;
		}
	}

	if (this->mode == FrameMode::FIFO)
	{
		pushFIFO(page);
		return;
	}
	if (this->mode == FrameMode::LRU)
	{
		pushLRU(page);
		return;
	}

	if (this->mode == FrameMode::LRU)
	{
		MCFrame* LRU = NULL;
		int used = -1;
		for (int i = 0; i < this->num_frames; i++)
		{
			MCFrame* frame = &(this->frames[i]);
			if (LRU == NULL)
			{
				LRU = frame;
				used = frame->getTimeSinceUsed();
			}
				
		}
		return;
	}
}