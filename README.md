libstopwatch - a timer object in C++ that provides hi-res timer.


```c++
#include <iostream>

int main() {
	StopWatch sw;

	sw.start();

	std::cout << "time elapsed in microseonds: " << sw.timeInMicros() << st::endl;
	std::cout << "time elapsed in milliseonds: " << sw.timeInMillis() << st::endl;

	return 0;
}

```
