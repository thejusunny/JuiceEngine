#include "Engine.h"
bool Engine::Initilize(HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int height, int width)
{
	timer.Start();
	keyboard.EnableAutoRepeatChars();
	if (!this->render_window.Initialize(this, hInstance, windowTitle, windowClass, height, width))
		return false;
	if (!this->gfx.Initialize(this->render_window.GetHWND(), width, height))
		return false;
	return true;
}
bool Engine::ProcessMessages()
{

	return this->render_window.ProcessMessages();
}
void Engine::update()
{
	
	float dt = timer.GetMillisecondsElapsed();
	timer.Restart();
	while (!keyboard.CharBufferIsEmpty())
	{
	
		
		unsigned char ch = keyboard.ReadChar();
		std::string output = "Char:";
		output += ch;
		output += "\n";
		OutputDebugStringA(output.c_str());
	
	}
	while (!keyboard.KeyBufferIsEmpty())
	{
	
		KeyboardEvent kbe = keyboard.ReadKey();
		unsigned char keycode = kbe.GetKeyCode();
		if (kbe.IsPress())
		{
			
			OutputDebugStringA("Pressed\n");
		}
		if (kbe.IsRelease())
		{
			OutputDebugStringA("Release\n");
		
		}
	/*	std::string output = "Char:";
		output += keycode;
		output += "\n";
		OutputDebugStringA(output.c_str());*/
	}
	while (!mouse.EventBufferIsEmpty())
	{
		MouseEvent me = mouse.ReadEvent();
		if (mouse.IsRightDown()&& me.GetType() == MouseEvent::EventType::RAW_MOVE)
		{
					
			this->gfx.camera.AdjustRotation((float)me.GetPosY()*0.005f, (float)me.GetPosX()*0.005f, 0);
		}
	
	}
	const float cameraSpeed = 0.005f;
	if (keyboard.KeyIsPressed('W'))
	{
		this->gfx.camera.AdjustPosition(this->gfx.camera.GetForwardVector()*cameraSpeed*dt);
	}
	if (keyboard.KeyIsPressed('S'))
	{
		this->gfx.camera.AdjustPosition(this->gfx.camera.GetBackwardVector()*cameraSpeed*dt);
	}
	if (keyboard.KeyIsPressed('A'))
	{
		this->gfx.camera.AdjustPosition(this->gfx.camera.GetLeftVector()*cameraSpeed*dt);
	}
	if (keyboard.KeyIsPressed('D'))
	{
		this->gfx.camera.AdjustPosition(this->gfx.camera.GetRightVector()*cameraSpeed*dt);
	}
	if (keyboard.KeyIsPressed(VK_SPACE))
	{
		this->gfx.camera.AdjustPosition(0.0f,cameraSpeed*dt,0.0f);
	}
	if (keyboard.KeyIsPressed('Z'))
	{
		this->gfx.camera.AdjustPosition(0.0f, -cameraSpeed * dt, 0.0f);
	}

	

}

void Engine::RenderFrame()
{
	gfx.RenderFrame();
}
