#pragma once
#include "Header.hpp"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

class maelstrom::dt
{
public:
	static string 
	current(string format)
	{
		auto now = std::chrono::system_clock::now();
		auto in_time_t = std::chrono::system_clock::to_time_t(now);

		stringstream ss;
		ss << std::put_time(std::localtime(&in_time_t), format.c_str());

		return ss.str();
	}
};
