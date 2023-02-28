#pragma once
#include <chrono>

using std::chrono::steady_clock;
using std::chrono::milliseconds;
using std::chrono::time_point;
using std::chrono::duration_cast;

class Timer
{
public:
	void start()
	{
		m_StartTime = steady_clock::now();
		m_bRunning = true;
	}

	void stop()
	{
		m_EndTime = steady_clock::now();
		m_bRunning = false;
	}

	constexpr long long elapsedMilliseconds()
	{
		time_point<steady_clock> endTime;

		if (m_bRunning)
			endTime = steady_clock::now();
		else
			endTime = m_EndTime;

		return duration_cast<milliseconds>(endTime - m_StartTime).count();
	}

private:
	time_point<steady_clock> m_StartTime;
	time_point<steady_clock> m_EndTime;
	bool m_bRunning = false;
};
