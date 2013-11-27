#include "StopWatch.h"
/////////////////////////////////////////////////
StopWatch::StopWatch() {
    t.tv_sec = 0;
    t.tv_usec = 0;

    started = false;

    interval = 0.0;
}
/////////////////////////////////////////////////
void StopWatch::start() {
    gettimeofday(&t, NULL);
    started = true;
}
/////////////////////////////////////////////////
void StopWatch::stop() {
    timeval now;
    gettimeofday(&now, NULL);

    t_result = calcTimeval(now, t);
    interval = convertToDouble(t_result);
    started = false;
}
/////////////////////////////////////////////////
bool StopWatch::isStarted() {
    return started;
}
/////////////////////////////////////////////////
double StopWatch::getInterval() {
    return interval;
}
/////////////////////////////////////////////////
timeval StopWatch::getTimeval() {
    return t_result;
}
/////////////////////////////////////////////////
double StopWatch::timeSoFar() {
    timeval now;
    gettimeofday(&now, NULL);

    return convertToDouble(calcTimeval(now, t) );
}
/////////////////////////////////////////////////
timeval StopWatch::calcTimeval(const timeval &e, const timeval &s) {
    timeval result;
    result.tv_sec = e.tv_sec - s.tv_sec;
    result.tv_usec = e.tv_usec - s.tv_usec;

    return result;
}
/////////////////////////////////////////////////
double StopWatch::convertToDouble(const timeval &r) {
    // 1 million microseconds in 1 second
    double result = r.tv_sec + (r.tv_usec / 1000000.0);
    return result;
}
/////////////////////////////////////////////////
StopWatch::~StopWatch() {

}
/////////////////////////////////////////////////
