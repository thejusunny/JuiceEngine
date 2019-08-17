#include "ErrorLogger.h"
#include<comdef.h>
#include "StringConverter.h"
void ErrorLogger::Log(std::string message)
{
	std::string error_message = "Error " + message;
	MessageBoxA(NULL, error_message.c_str(), "Error", MB_ICONERROR);
}
void ErrorLogger::Log(HRESULT hr, std::string message)
{
	_com_error err(hr);
	std::wstring error_message = L"Error" + StringConverter::StringToWide(message) + L"\n" + err.ErrorMessage();
	MessageBoxW(NULL, error_message.c_str(),L"Error", MB_ICONERROR);

}

void ErrorLogger::Log(HRESULT hr, std::wstring message)
{

	_com_error err(hr);
	std::wstring error_message = L"Error" + (message) + L"\n" + err.ErrorMessage();
	MessageBoxW(NULL, error_message.c_str(), L"Error", MB_ICONERROR);
}
