#include"Engine.h"
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"DirectXTK.lib")
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE preInstance,_In_ LPWSTR,_In_  int cmdShow)
{

	Engine engine;
	engine.Initilize(hInstance, "GameEngine", "Engine", 800, 600);
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		ErrorLogger::Log(hr, "Failed to coinit");
		return -1;
	}
	while (engine.ProcessMessages()==true)
	{
		engine.update();
		engine.RenderFrame();
		
	}
	return 0;
}