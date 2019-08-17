#pragma once
#include "ErrorLogger.h"
class WindowContainer;
class RenderWindow
{

public :
	bool Initialize(WindowContainer *container, HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int height, int width);
	bool ProcessMessages();
	HWND GetHWND()const;
	~RenderWindow();
private:
	void RegisterWindowClass();
	
	HWND handle= NULL; //Handle to this window
	HINSTANCE hInstance = NULL;//Handle to application 
	std::string window_title;
	std::wstring window_title_wide=L"";
	std::string window_class = "";
	std::wstring  window_class_wide =L"";
	int width = 0;
	int height = 0;



};