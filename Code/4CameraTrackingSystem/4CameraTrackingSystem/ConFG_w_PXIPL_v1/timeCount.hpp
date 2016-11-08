#ifndef _TIME_COUNT_HPP
#define _TIME_COUNT_HPP

#include <iostream>
#include <chrono>

typedef std::chrono::steady_clock::time_point	TimeT;

#define TIME_NOW		std::chrono::steady_clock::now ()
#define TIME_SEC		std::chrono::duration_cast< std::chrono::seconds >
#define TIME_MSEC		std::chrono::duration_cast< std::chrono::milliseconds >
#define TIME_MICROSEC	std::chrono::duration_cast< std::chrono::microseconds >
#define TIME_NANOSEC	std::chrono::duration_cast< std::chrono::nanoseconds >


#endif //_TIME_COUNT_HPP