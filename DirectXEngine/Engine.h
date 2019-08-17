#pragma once
#include "WindowContainer.h"
#include "Timer.h"
class Engine :WindowContainer
{

public:
	bool Initilize(HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int height, int width);
	bool ProcessMessages();
	void update();
	void RenderFrame();
private:
	Timer timer;
};