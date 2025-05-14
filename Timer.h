#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
    private:
    std::chrono::time_point<std::chrono::steady_clock>  last_time;

    public:
    Timer();
    double elapsed_seconds();
    void reset();


};

#endif