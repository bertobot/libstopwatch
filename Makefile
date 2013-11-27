CC=g++ -Wall ${CCFLAGS}
OBJ=\
StopWatch.o 

all: $(OBJ)
	ar rs libstopwatch.a $(OBJ)

install: all
	mkdir -p /usr/local/include/stopwatch
	install  -m 666 *.h /usr/local/include/stopwatch
	install  -m 666 libstopwatch.a /usr/local/lib

uninstall:
	rm -rf /usr/local/include/stopwatch
	rm -rf /usr/local/lib/libstopwatch.a

.cpp.o:
	$(CC) -c $<

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf libstopwatch.a

