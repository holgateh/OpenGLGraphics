#include <tools/Timer.hpp>

Timer::Timer()
{
    startTime = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{

}

double Timer::elapsedTime()
{
    return ((std::chrono::duration<double>)(std::chrono::high_resolution_clock::now() - startTime)).count();
}

void Timer::reset()
{
    startTime = std::chrono::high_resolution_clock::now();
}