#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG // release
	return "assets/";
#else
	return "D:/Repos/LightYears/LightYearsGame/assets/";
#endif
}
