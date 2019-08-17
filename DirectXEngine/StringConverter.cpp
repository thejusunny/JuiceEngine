#include "StringConverter.h"

std::wstring StringConverter::StringToWide(std::string string)
{

	std::wstring wide_string(string.begin(), string.end());
	return wide_string;
}