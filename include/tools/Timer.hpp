#pragma once
#include <chrono>
class Timer
{
    private:
        std::chrono::high_resolution_clock::time_point startTime;
    public:
    private:
    public:
        Timer();
        ~Timer();
        double elapsedTime();
        void reset();

};