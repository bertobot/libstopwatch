#ifndef __StopWatch_h_
#define __StopWatch_h_

#include <sys/time.h>
#include <stdio.h>

class StopWatch {
    private:
        timeval t;
        timeval t_result;
        bool started;
        double interval;

	/**
	 * This method takes the timeval structure and derives a double result.
	 * @param e - timeval structure representing the 'end' time.
	 * @param s - timeval structure representing the 'start' time.
	 */
        timeval calcTimeval(const timeval&, const timeval&);

	/**
	 * converts the timeval structure into a double.
	 */
        double convertToDouble(const timeval &);
        
        
    public:
        StopWatch();

	/**
	 * Start the stopwatch.
	 */
        void start();

	/**
	 * stops the stopwatch.
	 */ 	
        void stop();

	/**
	 * TODO: obsolete? 	
	 * returns the time elapsed after stop has been called.
	 */ 	
        double getInterval();
        timeval getTimeval();

	/**
	 * returns the elapsed time since start() was called.  returns high-resolution time.
	 */
        double timeSoFar();

        bool isStarted();

        virtual ~StopWatch();
};

#endif
