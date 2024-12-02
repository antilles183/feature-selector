#include "Stopwatch.h"



void Stopwatch::start()
{
    m_start = std::chrono::steady_clock::now();
    // auto s = std::chrono::steady_clock::now();
    // auto t = std::chrono::high_resolution_clock::now();

}


void Stopwatch::stop()
{
    m_stop = std::chrono::steady_clock::now();

}

std::chrono::steady_clock::duration Stopwatch::duration()
{
    return (m_stop - m_start);
}

int Stopwatch::getMilliseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>( m_stop - m_start ).count();
}


int Stopwatch::getMicroseconds()
{
    return std::chrono::duration_cast<std::chrono::microseconds>( m_stop - m_start ).count();
}