#pragma once
#include <string>
#include <chrono>

class Stopwatch
{
private:
    std::chrono::time_point<std::chrono::steady_clock> m_start;
    std::chrono::time_point<std::chrono::steady_clock> m_stop;
    // std::chrono::time_point<std::chrono::_V2::system_clock m_start;

public:
    
    void start();
    void stop();
    std::chrono::steady_clock::duration duration();

    int getMilliseconds();
    int getMicroseconds();
};
